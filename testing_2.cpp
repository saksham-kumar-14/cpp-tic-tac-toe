#include <iostream>
#include <vector>
using namespace std; 


class Board{
private:
	vector<vector<string>> body; 

public:
	Board(){
		vector<vector<string>> b; 
		for(int i=0;i<3;i++){
			vector<string> col; 
			for(int j=0;j<3;j++){
				col.push_back(" "); 
			}
			b.push_back(col); 
			col.clear(); 
		}
		body = b; 
	}

	void draw(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(j==2){
					cout << body[i][j]; 
				}
				else{
					cout << body[i][j] << "|";
				}
			}
			cout << endl; 
			if(i!=2){
				cout << "------" << endl; 
			}
		}
	}

	void change(string s,vector<int>pos){
		body[pos[0]][pos[1]] = s; 
	}

	string win_check(){
		if(body[0][0] == body[0][1] && body[0][0] == body[0][2] && body[0][0] == "X"){
			return "Player 1"; 
		}
		else if(body[0][0] == body[0][1] && body[0][0] == body[0][2] && body[0][0] == "O"){
			return "Player 2"; 
		}
		else if(body[1][0] == body[1][1] && body[1][0] == body[1][2] && body[1][0] == "X"){
			return "Player 1"; 
		}
		else if(body[1][0] == body[1][1] && body[1][0] == body[1][2] && body[1][0] == "O"){
			return "Player 2"; 
		}
		else if(body[2][0] == body[2][1] && body[2][0] == body[2][2] && body[2][0] == "X"){
			return "Player 1"; 
		}
		else if(body[2][0] == body[2][1] && body[2][0] == body[2][2] && body[2][0] == "O"){
			return "Player 2"; 
		}

		else if(body[0][0] == body[1][0] && body[0][0] == body[2][0] && body[0][0] == "X"){
			return "Player 1";
		}
		else if(body[0][0] == body[1][0] && body[0][0] == body[2][0] && body[0][0] == "O"){
			return "Player 2";
		}
		else if(body[0][2] == body[1][2] && body[0][2] == body[2][2] && body[0][2] == "X"){
			return "Player 1";
		}
		else if(body[0][2] == body[1][2] && body[0][2] == body[2][2] && body[0][2] == "O"){
			return "Player 2";
		}
		else if(body[0][1] == body[1][1] && body[0][1] == body[2][1] && body[0][1] == "X"){
			return "Player 1";
		}
		else if(body[0][1] == body[1][1] && body[0][1] == body[2][1] && body[0][1] == "O"){
			return "Player 2";
		}
		else if(body[0][0] == body[1][1] && body[0][0] == body[2][2] && body[0][0] == "X"){
			return "Player 1";
		}
		else if(body[0][0] == body[1][1] && body[0][0] == body[2][2] && body[0][0] == "O"){
			return "Player 2"; 
		}

		return "None";
	}

	bool is_full(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(body[i][j] == " "){
					return false; 
				}
			}
		}
		return true; 
	}

	bool pos_occupied(vector<int> pos){
		if(body[pos[0]][pos[1]]==" "){
			return false;
		}
		return true; 
	}

}; 





int main(){
	Board board; 
	board.draw(); 
	string current_player = "Player 1"; 

	while(true){
		cout << current_player << " provide insert position : "; 
		int rank; cin >> rank; 
		vector<int> pos; 
		string s; 

		if(9>=rank>=1){
			if(rank == 3 || rank == 1 || rank == 2){
				pos.push_back(0); 
				pos.push_back(rank-1);
			}
			else if(rank == 4 || rank == 5 || rank == 6){
				pos.push_back(1);
				pos.push_back(rank-4);
			}
			else if(rank == 7 || rank == 8 || rank ==9){
				pos.push_back(2);
				pos.push_back(rank-7);
			}

			if(!board.pos_occupied(pos)){

				if(current_player == "Player 1"){
					current_player = "Player 2";
					s = "X"; 
				}
				else{
					current_player = "Player 1";
					s = "O";
				}

				board.change(s,pos); 
				board.draw(); 
				pos.clear(); 

				//checking for win for draw
				string temp = board.win_check();  
				if(temp != "None"){
					cout << temp << " won" << endl; 
					break; 
				}
				else if(board.is_full()){
					cout << "Game Drawn" << endl; 
					break; 
			}

			}
		}
		else{
			cout << "Invalid Position Provided " << endl; 
		}
	}

}