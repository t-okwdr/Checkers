/*
10 - project - video game(s)
Author: Taya
Date: Feb 29, 2024
Create a video game from the following list (marks will be given based on difficulty level of coding)
*/
#include <iostream> 	// include library for input and output
#include <math.h>		// include library for math functions
#include <windows.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>		// include library for changing text modes
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;	// Makes life slightly easier


void Center_text(string text);		//Declares a string function to output any text in the center of the screen

//Checkers Functions
void checkers(int gamemode);
char reverse_char(char board[8][8],int x, int y);
int generate_moves(char board[8][8], char color);
void create_checkers(char board[8][8]);
bool checkers_move_from_check(string move, char board[8][8], char color);
int checkers_move_to_check(string move, char board[8][8], char color, int x1, int y1);
int negamax(char board[8][8], int depth, int color);
int multimax(char board[8][8], int depth, int color, string move_from);
void save_game(char board[8][8], int turn, int capture, int red_cpu, int black_cpu);
int load_settings(int option);
char load_board(int x, int y);
/* test game (Checkers)
A6 B5 A6 B5 B5 A4 B5 A4 B7 A6 B7 A6 A8 B7 A8 B7 E6 F5 E6 D5 F5 D3 F7 D5 A4 C2 E8 G6 F7 E6 A4 C2 E8 G6 A6 B5 A6 B5 B5 A4 B5 A4 A4 C2 A4 C2 G8 E6 C6 B5 C2 D1 B7 C6 C6 B5 H7 G6 D1 C2 E6 F5 B5 D3 D7 F5 C2 A4 F5 G4 A4 C6 G8 H7 H7 G6 H7 G6 C6 B5 G6 F5 B5 D3 C8 B7 B7 A6 B7 A6 D5 E4 C6 E4 C2 D7 E6 C2 D1 G6 H5 B5 C4 E6 G4 A6 C4 D3 C2 D1 C2 C2 B1 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A6 B5 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 C4 B3 C8 B7 B3 C2 B7 A6 C2 B1 A2 B3 A2 B3 H5 G4 B1 C2 B5 C4 C2 D1 C4 D3 B3 A4 D3 C2 A4 C6 B3 A4 D1 C2 C2 B1 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 A6 B5 B1 C2 B1 A2 C6 B5 A4 B3 C2 B3 A2 B1 B3 A2 B1 A2 B5 C6 A2 B1 C6 D7 B3 A4 A2 B1 A4 B3 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 B3 C4 B1 C2 C4 D5 C2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 D7 C6 D5 C4 C6 B5 B5 A4 B5 C6 A2 B3 C6 D7 B3 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B3 A4 B3 B3 C2 B3 C2 C2 D1 A2 B1 D1 C2 B1 A2 C2 B1 A2 B1 D7 C6 C2 D1 C6 B5 B1 A2 B1 A2 D1 C2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B5 A6 B1 A2 A6 B5 A2 B1 B5 A6 C4 D3 A6 B7 D3 E2 B7 C6 E2 G4 B1 C2 G4 H5 C2 D3 H5 G6 D3 E4 B1 A2 E4 D5 G6 F5 D5 B3 C2 B1 B3 C2 A2 B3 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 B3 C2 A2 B1 C2 B1 B1 A2 A2 B3 A2 B3 B1 C2 B3 C2 C2 D1 C2 D1 B3 A2 D1 C2 A2 B1 C2 B1 B1 A2 B1 A2 D1 C2 A2 B1 A2 B1 B1 C2 B1 A2 C2 D1 A2 B3 D1 C2 B3 A4 C2 B3 A4 B3 B3 A4 C2 D3 A4 B3 B3 A4 B3 A2 D3 C2 A2 B1 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 C2 A2 B3 C2 D1 B3 C2 D1 C2 C2 B1 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B3 B1 C2 B3 C2 C2 D1 A4 B5 D1 E2 B5 C6 E2 G4 C2 B3 G4 F5 B3 D5
*/

int main(){
	int menu_choice;
	int game_choice;
	int rules_choice;
	SetConsoleOutputCP(CP_UTF8);		//Sets the console mode to U8 (allows unicode & emojis)
	srand(time(0));			//Initializes the randomization seed 
	do{
		Center_text("  ,----..    ,---,                              ,-.                                 \n");
		Center_text(" /   /   \\ ,--.' |                          ,--/ /|                                 \n");
		Center_text("|   :     :|  |  :                        ,--. :/ |             __  ,-.             \n");
		Center_text(".   |  ;. /:  :  :                        :  : ' /            ,' ,'/ /|  .--.--.    \n");
		Center_text(".   ; /--` :  |  |,--.   ,---.     ,---.  |  '  /      ,---.  '  | |' | /  /    '   \n");
		Center_text(";   | ;    |  :  '   |  /     \\   /     \\ '  |  :     /     \\ |  |   ,'|  :  /`./   \n");
		Center_text("|   : |    |  |   /' : /    /  | /    / ' |  |   \\   /    /  |'  :  /  |  :  ;_     \n");
		Center_text(".   | '___ '  :  | | |.    ' / |.    ' /  '  : |. \\ .    ' / ||  | '    \\  \\    `.  \n");
		Center_text("'   ; : .'||  |  ' | :'   ;   /|'   ; :__ |  | ' \\ \\'   ;   /|;  : |     `----.   \\ \n");
		Center_text("'   | '/  :|  :  :_:,''   |  / |'   | '.'|'  : |--' '   |  / ||  , ;    /  /`--'  / \n");
		Center_text("|   :    / |  | ,'    |   :    ||   :    :;  |,'    |   :    | ---'    '--'.     /  \n");
		Center_text(" \\   \\ .'  `--''       \\   \\  /  \\   \\  / '--'       \\   \\  /            `--'---'   \n");
		Center_text("  `---`                 `----'    `----'              `----'                        \n");
		cout<<"\n\nHow do you want to play (Enter 1, 2, etc.): ";		//Tells the user what they can do
		cout<<"\n\tHuman vs Human ---------------- 1";			//Outputs the option of removing a contact
		cout<<"\n\tHuman vs CPU (You first) ------ 2";			//Outputs the option of searching for a contact
		cout<<"\n\tHuman vs CPU (CPU first) ------ 3";			//Outputs the option of editing a contact
		cout<<"\n\tCPU vs CPU -------------------- 4";			//Outputs the option of editing a contact
		cout<<"\n\tInstructions ------------------ 5";			//Outputs the option of editing a contact
		cout<<"\n\tBack to main menu ------------- 6\n";			//Outputs the option of showing all of the contacts
		cin>>game_choice;
		while (game_choice<1 or game_choice>6){
			cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
			cout<<"How do you want to play (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cin>>game_choice;		//Prompts the user to input
		}
		if (game_choice==1){
			checkers(1);	
		}
		else if (game_choice==2){
			checkers(2);
		}
		else if (game_choice==3){
			checkers(3);
		}
		else if (game_choice==4){
			checkers(4);
		}
		else if (game_choice==5){
			cout<<flush;			//Flushes the output stream
			system ("CLS");			//Clear the screen
		
			//Rules
			cout<<"                   __  __                   __            ____   __             \n";				//Rules Title Card ASCII Art
			cout<<"                  / / / /____  _      __   / /_ ____     / __ \\ / /____ _ __  __\n";			//More Rules Title Card ASCII Art
			cout<<"                 / /_/ // __ \\| | /| / /  / __// __ \\   / /_/ // // __ `// / / /\n";			//More Rules Title Card ASCII Art
			cout<<"                / __  // /_/ /| |/ |/ /  / /_ / /_/ /  / ____// // /_/ // /_/ / \n";				//More Rules Title Card ASCII Art
			cout<<"               /_/ /_/ \\____/ |__/|__/   \\__/ \\____/  /_/    /_/ \\__,_/ \\__, /  \n";		//More Rules Title Card ASCII Art
			cout<<"                                                                       /____/   ";				//More Rules Title Card ASCII Art
			cout<<"\n-----------------------------------------------------------------------------------------------\n";		//Line of Separation
			
			cout<<"Object of the Game:\n";				//Rules of Blackjack
			cout<<"\tA player wins once all of their opponent's pieces are captured. They can also win if their piece has no moves available.\n";				//Rules of Blackjack
			
			cout<<"\nThe Play:\n";				//Rules of Blackjack
			cout<<"\tThe Black player starts by moving one of the first row pieces.";
			cout<<"\n\tThe red player does the same and the turns alternate.\n";
			
			cout<<"\nSingles:\n";				//Rules of Blackjack
			cout<<"\tCan only be moved forward, diagonally, one spot, for normal moves.";
			cout<<"\n\tCan \"capture\" an opposing piece if they are adjacent to that piece and there is an empty space directly behind it.";
			cout<<"\n\tIt will jump over that piece, land, and the opponent's jumped piece will be removed from the board.";
			cout<<"\n\tCan capture multiple opponent pieces if they are adjacent to the first piece and there's a spot open directly behind it.\n";
	
			cout<<"\nKings:\n";
			cout<<"\tSingles Get promoted to a king when they reach the opponent's back row.";
			cout<<"\n\tKings can move diagonally and capture in any direction.\n";
	
			cout<<"\nRules:\n";				//Rules of Blackjack
			cout<<"\tPlayers must move a checker during their turn. No passing.";
			cout<<"\n\tPlay is always diagonal in direction, on the darker spaces.";
			cout<<"\n\tOnly kings can move in either direction (forward and backward). Single checkers may only move forward.";
			cout<<"\n\tYou may only capture an opponent's piece if you are adjacent (diagonally) to it and the spot directly behind it is open.";
			cout<<"\n\tYou MUST capture if a capture move is available. This includes additional captures in a multi-capture move.";
			cout<<"\n\tIf multiple captures are available, you may choose which one.\n";
			
			cout<<"\nExtra:\n";				//Rules of Blackjack
			cout<<"\tEnter save to save the game for later.";
			cout<<"\n\tEnter load during a different game to load a saved game.";
			cout<<"\n\tEnter \"quit\" to quit a game.\n\n";
			system ("PAUSE");		//Pause the program until the user presses a key
			
			cout<<flush; 		//flushes the output stream
			system ("CLS");		//Clear the screen
			
			//Strategy
			cout<<"                  _____  __                __                     \n";				//Strategy Title Card ASCII Art
			cout<<"                 / ___/ / /_ _____ ____ _ / /_ ___   ____ _ __  __\n";				//More Strategy Title Card ASCII Art
			cout<<"                 \\__ \\ / __// ___// __ `// __// _ \\ / __ `// / / /\n";				//More Strategy Title Card ASCII Art
			cout<<"                ___/ // /_ / /   / /_/ // /_ /  __// /_/ // /_/ / \n";				//More Strategy Title Card ASCII Art
			cout<<"               /____/ \\__//_/    \\__,_/ \\__/ \\___/ \\__, / \\__, /  \n";				//More Strategy Title Card ASCII Art
			cout<<"                                                  /____/ /____/   ";				//More Strategy Title Card ASCII Art
			cout<<"\n---------------------------------------------------------------------------------\n";		//Line of separation
			
			cout<<"Control the Center:\n";
			cout<<"\tOccupy the center by moving your pieces into it.";
			cout<<"\n\tJump toward the center when you have the option of jumping more than one way.";
			cout<<"\n\tThe central squares are more critical to control than the edges.";
			cout<<"\n\tAll the squares are important, and a well-placed piece on the side of the board is beneficial.";
			cout<<"\n\tIf you have a choice between moving or jumping to the side or to the center, go toward the center.\n";
			
			cout<<"\nProtect Your King Row:\n";
			cout<<"\tGetting the first king is a huge advantage among less-skilled players.";
			cout<<"\n\tIf you don't move your back four pieces, that leaves you 8 pieces to fight up possibly 10 or 12.";
			cout<<"\n\tThis could easily leave you on the wrong side of some exchanges.";
			cout<<"\n\tThe general strategy used by experts is to advance two of the four back pieces.";
			cout<<"\n\tThis gives you an attacking force of 10 while leaving the 2nd and 4th back row pieces to slow down any Kinging attempts.";
			cout<<"\n\tLeave those two as long as you reasonably can and bring the other two into your attack.\n";
			
			cout<<"\nKeep a Strong Formation:\n";
			cout<<"\tPieces grouped together tend to be stronger than ones that are separated.";
			cout<<"\n\tAdvance your pieces collectively, using the ones behind to support the ones in front.";
			cout<<"\n\tA solid mass of pieces isn't as vulnerable to double or triple jumping attacks.";
			cout<<"\n\tAmateurs often exchange pieces randomly just to simplify the game. ";
			cout<<"\n\tWhen this happens, you'll find that your superior formation leaves you in a stronger position.\n\n";
			system("PAUSE");
		}
		else{
		    cout<<flush;		//flushes the output stream
			system ("CLS");		//clears the screen
			cout<<"   ______                   __ __                  __\n";		//Goodbye Title Card ASCII Art
			cout<<"  / ____/____   ____   ____/ // /_   __  __ ___   / /\n";		//Goodbye Title Card ASCII Art
			cout<<" / / __ / __ \\ / __ \\ / __  // __ \\ / / / // _ \\ / / \n";	//Goodbye Title Card ASCII Art
			cout<<"/ /_/ // /_/ // /_/ // /_/ // /_/ // /_/ //  __//_/  \n";		//Goodbye Title Card ASCII Art
			cout<<"\\____/ \\____/ \\____/ \\__,_//_.___/ \\__, / \\___/(_)   \n";	//Goodbye Title Card ASCII Art
			cout<<"                                  /____/             \n";			//Goodbye Title Card ASCII Art
			break;		//breaks out of the do-while loop
		}
		cout<<flush;
		system("CLS");
	} while (game_choice!=6);
	return 0;	// Ends the program
}
	
void Center_text(string text){		//Defines a function for outputting text to the center of the screen
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo); // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize; // Gets the size of the screen
	NewSBSize.X+=0;		//Increases the screen size by 4		
	if (NewSBSize.X > text.size() and (NewSBSize.X-text.size())>0) {
	    int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
	    for (int i = 0; i < newpos; i++) cout << " "; // Prints the spaces
	}
	cout<<text;		//Outputs the text
}
	
	
//Checkers	

int negamax(char board[8][8], int depth, int color){
	int total=0;
	int val;
	int spot_value;
	char og_board[8][8];
	vector<vector <string>> legal_spots(5);
	vector <int> move_count;
	int moves[8];
	string move_from;
	string move_to;
	int x1,y1,x2,y2;
	int best_move;
	int move;
	char char_color;
	bool attack=false;
	vector <string> attack_moves;
    int best = -2147483647;
	
	if (color==1){
		char_color='B';
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				board[i][k]=reverse_char(og_board,i,k);
			}
		}
	}
	else{
		char_color='R';
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				board[i][k]=reverse_char(og_board,i,k);
			}
		}
	}
	
    if (depth<=0){
    	for (int i=0;i<8;i++){
    		for (int j=0;j<8;j++){
    			if (i==0 or i==7 or j==0 or j==7){
    				spot_value=4;
				}
				else if (i==1 or i==6 or j==1 or j==6){
					spot_value=3;
				}
				else if (i==2 or i==5 or j==2 or j==5){
					spot_value=2;
				}
				else if (i==3 or i==4 or j==3 or j==4){
					spot_value=1;
				}
    			if (board[i][j]=='b'){
    				total+=1*spot_value;
				}
				else if (board[i][j]=='B'){
    				total+=2*spot_value;
				}
				else if (board[i][j]=='r'){
    				total-=1*spot_value;
				}
				else if (board[i][j]=='R'){
    				total-=2*spot_value;
				}
			}
		}
//		cout<<"total: "<<total*color<<endl;
        return total*color;
	}

//    GenerateLegalMoves();
	cout.setstate(ios_base::failbit);
	for (int i=0;i<8;i++){
		for (int k=0;k<8;k++){
			if (board[i][k]==tolower(char_color) or board[i][k]==char_color){
				legal_spots[0].push_back(char(k+1+64)+to_string(i+1));
					
			}
		}
	}
	legal_spots.resize(5);
	for (int i=0;i<5;i++){
	    legal_spots[i].resize(legal_spots[0].size());
	}
	move_count.resize(legal_spots[0].size(),1);
	for (int i=0;i<legal_spots[0].size();i++){
//		cout<<i<<" ";
		y1=(legal_spots[0][i].at(0)-64)-1;
		x1=(legal_spots[0][i].at(1)-'0')-1;	
		moves[0]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1-1+1),board,char_color,x1,y1);
		if (moves[0]!=-1){
			legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1-1+1);
			move_count[i]++;
		}
		moves[1]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1-1+1),board,char_color,x1,y1);
		if (moves[1]!=-1){
			legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1-1+1);
			move_count[i]++;
		}
		moves[2]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1+1+1),board,char_color,x1,y1);
		if (moves[2]!=-1){
			legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1+1+1);
			move_count[i]++;
		}
		moves[3]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1+1+1),board,char_color,x1,y1);
		if (moves[3]!=-1){
			legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1+1+1);
			move_count[i]++;
		}
		moves[4]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
		if (moves[4]!=-1){
			legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
			move_count[i]++;
		}
		moves[5]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
		if (moves[5]!=-1){
			legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
			move_count[i]++;
		}
		moves[6]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
		if (moves[6]!=-1){
			legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
			move_count[i]++;
		}
		moves[7]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
		if (moves[7]!=-1){
			legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
			move_count[i]++;
		}
	}
	for (int i=0;i<legal_spots[0].size();i++){
		for (int k=1;k<move_count[i];k++){
			if (legal_spots[k][i].back()=='-'){
				move_count.clear();
				attack_moves.push_back(legal_spots[0][i]);
//				break;
			}
		}	
	}
	if (attack_moves.empty()!=true){
		cout<<"hi\n";
		legal_spots.clear();
		legal_spots.resize(5);
		for (int i=0;i<attack_moves.size();i++){
			legal_spots[0].push_back(attack_moves[i]);
		}
		legal_spots.resize(5);
		for (int i=0;i<5;i++){
		    legal_spots[i].resize(legal_spots[0].size());
		}
		move_count.resize(legal_spots[0].size(),1);
		for (int i=0;i<legal_spots[0].size();i++){
			y1=(legal_spots[0][i].at(0)-64)-1;
			x1=(legal_spots[0][i].at(1)-'0')-1;	
			moves[0]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
			if (moves[0]>0){
				legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1);
				move_count[i]++;
			}
			moves[1]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
			if (moves[1]>0){
				legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1);
				move_count[i]++;
			}
			moves[2]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
			if (moves[2]>0){
				legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1);
				move_count[i]++;
			}
			moves[3]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
			if (moves[3]>0){
				legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1);
				move_count[i]++;
			}
		}
		for (int i=0;i<legal_spots[0].size();i++){
			for (int j=0;j<move_count[i]-1;j++){
				if (legal_spots[i][j].back()=='-'){
					legal_spots[i][j].pop_back();
				}
			}
		}
	}
	cout.clear();
	
//    while (MovesLeft()) {
    for (int i=0;i<legal_spots[0].size();i++) {
    	for (int j=1;j<move_count[i];j++){
    		attack=false;
//			cout<<i<<" "<<j<<"--\n";
//			cout<<"depth: "<<depth<<endl;
    		copy(&board[0][0], &board[8][8],&og_board[0][0]);
    		move_from=legal_spots[0][i];
			y1=(move_from.at(0)-64)-1;
			x1=(move_from.at(1)-'0')-1;	
    		move_from=legal_spots[j][i];
    		cout.setstate(ios_base::failbit);
			move=checkers_move_to_check(move_from,board,char_color,x1,y1);
			cout.clear();
			y2=(move_from.at(0)-64)-1;
			x2=(move_from.at(1)-'0')-1;
//	        MakeNextMove();
			if (move>0){
				board[(move%10)-1][(move/10)-1]=' ';
			}
			board[x2][y2]=board[x1][y1];
			board[x1][y1]=' ';
			for (int i=0;i<8;i++){
				if (board[0][i]==tolower(char_color)){
					board[0][i]=char_color;
				}
			}
			if (attack_moves.empty()!=true){
				cout.setstate(ios_base::failbit);
				moves[0]=checkers_move_to_check(char(y2-2+1+64)+to_string(x2-2+1),board,char_color,x2,y2);
				moves[1]=checkers_move_to_check(char(y2+2+1+64)+to_string(x2-2+1),board,char_color,x2,y2);
				moves[2]=checkers_move_to_check(char(y2-2+1+64)+to_string(x2+2+1),board,char_color,x2,y2);
				moves[3]=checkers_move_to_check(char(y2+2+1+64)+to_string(x2+2+1),board,char_color,x2,y2);
				cout.clear();
				if (moves[0]>0 or moves[1]>0 or moves[2]>0 or moves[3]>0){
					attack=true;		
				}
			}
			if (attack==true){
				val = multimax(board,depth,color,move_from);
			}
			else{
	        	val = -negamax(board,depth-1,-color); // Note the minus sign here.
			}
//	        cout<<"depth: "<<depth<<"  val: "<<val<<"  best: "<<best<<endl;
//	        UnmakeMove();
	    	copy(&og_board[0][0], &og_board[8][8],&board[0][0]);
			if (val > best){
	        	best_move=((y1+1)*1000)+((x1+1)*100)+((y2+1)*10)+x2+1;
//				cout<<"best move: "<<best_move<<endl<<char(y1+1+64)<<to_string(x1+1)<<" "<<char(y2+1+64)<<to_string(x2+1)<<"  depth: "<<depth<<"  best val: "<<best<<endl;
			} 	
	        best=max(best,val);
		}
    }
//    cout<<"hi\n";
//	best_move=((y1+1)*1000)+((x1+1)*100)+((y2+1)*10)+x1+1;
//	cout<<"best move: "<<best_move<<endl;
    return best_move;
}

int multimax(char board[8][8], int depth, int color, string move_from){
	int total=0;
	int val;
	int spot_value;
	char og_board[8][8];
	vector<vector <string>> legal_spots(5);
	vector <int> move_count;
	int moves[4];
	string move_to;
	int x1,y1,x2,y2;
	int best_move;
	int move;
	char char_color;
	vector <string> attack_moves;
    int best = -2147483647;
	
	if (color==1){
		char_color='B';
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				board[i][k]=reverse_char(og_board,i,k);
			}
		}
	}
	else{
		char_color='R';
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				board[i][k]=reverse_char(og_board,i,k);
			}
		}
	}
	
    if (depth<=0){
    	for (int i=0;i<8;i++){
    		for (int j=0;j<8;j++){
    			if (i==0 or i==7 or j==0 or j==7){
    				spot_value=4;
				}
				else if (i==1 or i==6 or j==1 or j==6){
					spot_value=3;
				}
				else if (i==2 or i==5 or j==2 or j==5){
					spot_value=2;
				}
				else if (i==3 or i==4 or j==3 or j==4){
					spot_value=1;
				}
    			if (board[i][j]=='b'){
    				total+=1*spot_value;
				}
				else if (board[i][j]=='B'){
    				total+=2*spot_value;
				}
				else if (board[i][j]=='r'){
    				total-=1*spot_value;
				}
				else if (board[i][j]=='R'){
    				total-=2*spot_value;
				}
			}
		}
//		cout<<"total: "<<total*color<<endl;
        return total*color;
	}
	
//    GenerateLegalMoves();
	cout.setstate(ios_base::failbit);
	legal_spots[0].push_back(move_from);
	legal_spots.resize(5);
	for (int i=1;i<5;i++){
		legal_spots[i].resize(1);
	}
	legal_spots[0].resize(1);
	move_count.resize(1,1);
	y1=(move_from.at(0)-64)-1;
	x1=(move_from.at(1)-'0')-1;	
	
	moves[0]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
	if (moves[0]!=-1){
		legal_spots[move_count[0]][0]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
		move_count[0]++;
	}
	moves[1]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
	if (moves[1]!=-1){
		legal_spots[move_count[0]][0]=char(y1+2+1+64)+to_string(x1-2+1)+'-';
		move_count[0]++;
	}
	moves[2]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
	if (moves[2]!=-1){
		legal_spots[move_count[0]][0]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
		move_count[0]++;
	}
	moves[3]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
	if (moves[3]!=-1){
		legal_spots[move_count[0]][0]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
		move_count[0]++;
	}
	

	for (int k=1;k<move_count[0];k++){
		if (legal_spots[k][0].back()=='-'){
			move_count.clear();
			attack_moves.push_back(legal_spots[0][0]);
//			break;
		}
	}
	cout.clear();
	
//    while (MovesLeft()) {
//cout<<move_count[0];
	for (int j=1;j<move_count[0];j++){
//    	cout<<"hi\n";
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		if (attack_moves.empty()!=true){
//			cout<<0<<" "<<j<<"--";
			move_from=legal_spots[0][0];
			y1=(move_from.at(0)-64)-1;
			x1=(move_from.at(1)-'0')-1;	
			move_from=legal_spots[j][0];
			cout.setstate(ios_base::failbit);
			move=checkers_move_to_check(move_from,board,char_color,x1,y1);
			cout.clear();
			y2=(move_from.at(0)-64)-1;
			x2=(move_from.at(1)-'0')-1;
	//	    MakeNextMove();
			if (move>0){
				board[(move%10)-1][(move/10)-1]=' ';
			}
			board[x2][y2]=board[x1][y1];
			board[x1][y1]=' ';
			for (int i=0;i<8;i++){
				if (board[0][i]==tolower(char_color)){
					board[0][i]=char_color;
				}
			}
	        val = multimax(board,depth,color,move_from);
		}
		else{	
			val = negamax(board,depth,color); // Note the minus sign here.	
			y1=(val/1000)-1;
			x1=((val/100)%10)-1;	
			move_from=char(((val/10)%10)+64)+to_string(val%10);
			cout.setstate(ios_base::failbit);
			move=checkers_move_to_check(move_from,board,char_color,x1,y1);
			cout.clear();
			y2=(move_from.at(0)-64)-1;
			x2=(move_from.at(1)-'0')-1;
	//	    MakeNextMove();
			if (move>0){
				board[(move%10)-1][(move/10)-1]=' ';
			}
			board[x2][y2]=board[x1][y1];
			board[x1][y1]=' ';
			for (int i=0;i<8;i++){
				if (board[0][i]==tolower(char_color)){
					board[0][i]=char_color;
				}
			}
//			cout<<"nega: ";
		}
//    	cout<<"hi\n";
//	    cout<<"depth: "<<depth<<"  val: "<<val<<"  best: "<<best<<endl;
//	        UnmakeMove();
    	copy(&og_board[0][0], &og_board[8][8],&board[0][0]);
		if (val > best){
        	best_move=((y2+1)*10)+x2+1;
//        	cout<<endl<<x1<<"+"<<y1<<"->"<<x2<<"+"<<y2<<endl<<"from: "<<move_from<<endl;
//			cout<<"best move: "<<best_move<<endl<<char(y1+1+64)<<to_string(x1+1)<<" "<<char(y2+1+64)<<to_string(x2+1)<<"  depth: "<<depth<<"  best val: "<<best<<endl;
		} 	
        best=max(best,val);
	}
//    cout<<"hi\n";
//	best_move=((y2+1)*10)+x2+1;
//        	cout<<endl<<x1<<"+"<<y1<<"->"<<x2<<"+"<<y2<<endl<<"from: "<<move_from<<endl;
//	cout<<"\nbest move: "<<best_move<<endl;
    return best_move;
}

void checkers(int gamemode){				// starts the program
	bool red_player;
	bool black_player;
	int save=0;
	int load=0;
	string move_from;
	string move_to;
	int move,move2,move3,move4;
	int x1,y1,x2,y2;
	string all_moves="";
	int capture_count=0;
	bool black_win=false;
	bool red_win=false;
	char og_board[8][8];
	char pieces[8][8]={
		{' ','r',' ','r',' ','r',' ','r'},
		{'r',' ','r',' ','r',' ','r',' '},
		{' ','r',' ','r',' ','r',' ','r'},
		{' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' '},
		{'b',' ','b',' ','b',' ','b',' '},	
		{' ','b',' ','b',' ','b',' ','b'},
		{'b',' ','b',' ','b',' ','b',' '}
	};
//	char pieces[8][8]={
//		{' ','r',' ','B',' ',' ',' ',' '},
//		{'b',' ',' ',' ',' ',' ','r',' '},
//		{' ',' ',' ',' ',' ',' ',' ',' '},
//		{' ',' ',' ',' ',' ',' ',' ',' '},
//		{' ',' ',' ',' ',' ',' ',' ','b'},
//		{' ',' ',' ',' ',' ',' ','b',' '},	
//		{' ',' ',' ',' ',' ',' ',' ',' '},
//		{'b',' ','b',' ',' ',' ','b',' '}
//	}; 
	//AI STUFF
	int red_level=0;
	int black_level=0;
	char cpu_check;
	vector<vector <string>> legal_spots(5);
	vector <int> move_count;
	int moves[8];
	int rand_move;
	int black_rand=4;
	int red_rand=4;
	bool attack=false;
	vector <string> attack_moves;
	
	cout<<flush;
	system("CLS");
	do{
		cpu_check='Y';
		if (gamemode==1){
			red_player=true;
			black_player=true;
		}
		else if (gamemode==2){
			red_player=false;
			cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cout<<"\n\tEasy -------- 1";			//Outputs the option of removing a contact
			cout<<"\n\tMedium ------ 2";			//Outputs the option of removing a contact
			cout<<"\n\tHard -------- 3\n";			//Outputs the option of editing a contact
			cin>>red_level;
			while (red_level<1 or red_level>3){
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
				cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cin>>red_level;		//Prompts the user to input
			}
			black_player=true;
		}
		else if (gamemode==3){
			red_player=true;
			black_player=false;
			cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cout<<"\n\tEasy -------- 1";			//Outputs the option of removing a contact
			cout<<"\n\tMedium ------ 2";			//Outputs the option of removing a contact
			cout<<"\n\tHard -------- 3\n";			//Outputs the option of editing a contact
			cin>>black_level;
			while (black_level<1 or black_level>3){
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
				cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cin>>black_level;		//Prompts the user to input
			}
		}
		else{
			red_player=false;
			cout<<"What CPU difficulty do you want for Red (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cout<<"\n\tEasy -------- 1";			//Outputs the option of removing a contact
			cout<<"\n\tMedium ------ 2";			//Outputs the option of removing a contact
			cout<<"\n\tHard -------- 3\n";			//Outputs the option of editing a contact
			cin>>red_level;
			while (red_level<1 or red_level>3){
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
				cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cin>>red_level;		//Prompts the user to input
			}
			
			black_player=false;
			cout<<"What CPU difficulty do you want for Black (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cout<<"\n\tEasy -------- 1";			//Outputs the option of removing a contact
			cout<<"\n\tMedium ------ 2";			//Outputs the option of removing a contact
			cout<<"\n\tHard -------- 3\n";			//Outputs the option of editing a contact
			cin>>black_level;
			while (black_level<1 or black_level>3){
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
				cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cin>>black_level;		//Prompts the user to input
			}
		}
		if (black_level==3 and red_level==3){
			cout<<endl<<"WARNING! A level 3 bot match will ALWAYS TIE. It will end up in a situation where both CPUs repeat the same move.\n";
			cout<<"\nAre you sure that you want to continue (Y or N): ";
			cin>>cpu_check;
			while (toupper(cpu_check)!='N' and toupper(cpu_check)!='Y'){
				cout<<"Invalid Input! Retry\n";
				cout<<"\nAre you sure that you want to continue (Y or N): ";
				cin>>cpu_check;
			}
			if (toupper(cpu_check)=='N'){
				cout<<flush;
				system("CLS");
			}
		}
	} while (toupper(cpu_check)=='N');
	
	for (int j=0;j>-1;j++){
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				if (pieces[i][k]=='r' or pieces[i][k]=='R'){
					i=8;
					break;
				}
				else if (k==7 and i==7){
					j=-2;
				}
			}
		}
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				if (pieces[i][k]=='b' or pieces[i][k]=='B'){
					i=8;
					break;
				}
				else if (k==7 and i==7){
					j=-3;
				}
			}
		}	
		if (j>0){
			copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
			for (int i=0;i<8;i++){
				for (int k=0;k<8;k++){
					pieces[i][k]=reverse_char(og_board,i,k);
				}
			}
		}
		create_checkers(pieces);
		if (black_win==true){
			cout<<"BLACK WINS!\n";
			break;
			
		}
		else if (red_win==true){
			cout<<"RED WINS!\n";
			break;
		}
		else if (capture_count==60){
			cout<<"DRAW!\n";
			break;
		}
		if (j%2==0){
			if (black_player==true){
				if (red_player==false){	
					cout<<"YOUR TURN (BLACK)\n";
				}
				else{
					cout<<"BLACK TURN\n";
				}
				while (j>-1){
					cout.setstate(ios_base::failbit);
					if (generate_moves(pieces,'B')==0){
						j=-3;
						cout.clear();
						break;
					}
					cout.clear();
					cout<<"Enter the location of the piece you want to move (Ex. A7): ";
					cin>>move_from;
					if (move_from=="quit"){
						j=-2;
						break;
					}
					if (move_from=="save"){
						save_game(pieces, j%2, capture_count, red_level, black_level);
						save=1;
						cout<<"Game Saved!\n";
						cout.setstate(ios_base::failbit);
					}
					if (move_from=="load" and save==0){
						ifstream saved;			//Create a file object for reading
			    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
					    if (saved){		//If the file opens
							j=(load_settings(1))+1;
							capture_count=(load_settings(2));
							black_level=(load_settings(3));
							if (black_level>0){
								black_player==false;
							}
							red_level=(load_settings(4));
							if (red_level>0){
								red_player==false;
							}
							for (int i=1;i<=8;i++){
								for (int k=1;k<=8;k++){
									pieces[i-1][k-1]=load_board(i,k);
								}
						    }
						    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
							for (int i=0;i<8;i++){
								for (int k=0;k<8;k++){
									pieces[i][k]=reverse_char(og_board,i,k);
								}
							}
							load=1;
						    break;
						}
						else{
							cout<<"There is no saved game!\n";
						}
			    		saved.close();		//closes the file object (just in case)
					}
					move_from.at(0)=toupper(move_from.at(0));
					while (checkers_move_from_check(move_from,pieces,'B')==false){
						cout.clear();
						cout<<"Enter the location of the piece you want to move: ";
						cin>>move_from;
						if (move_from=="quit"){
							j=-2;
							break;
						}
						if (move_from=="save"){
							save_game(pieces, j%2, capture_count, red_level, black_level);
							save=1;
							cout<<"Game Saved!\n";
							continue;
						}
						if (move_from=="load" and save==0){
							ifstream saved;			//Create a file object for reading
				    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
						    if (saved){		//If the file opens
								j=(load_settings(1))+1;
								capture_count=(load_settings(2));
								black_level=(load_settings(3));
								if (black_level>0){
									black_player==false;
								}
								red_level=(load_settings(4));
								if (red_level>0){
									red_player==false;
								}
								for (int i=1;i<=8;i++){
									for (int k=1;k<=8;k++){
										pieces[i-1][k-1]=load_board(i,k);
									}
							    }
							    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								load=1;
							    break;
							}
							else{
								cout<<"There is no saved game!\n";
							}
				    		saved.close();		//closes the file object (just in case)
						}
						move_from.at(0)=toupper(move_from.at(0));
					}
					if (move_from=="quit"){
						j=-2;
						break;
					}
					if (move_from=="load" and save==0){
						break;
					}
					y1=(move_from.at(0)-64)-1;
					x1=(move_from.at(1)-'0')-1;
					
					all_moves+=move_from;
					all_moves+=" ";
					
					do{
						cout<<"Enter the location you want to move to (or 00 to reselect): ";
						cin>>move_to;
						if (move_to=="00"){
							break;
						}
						if (move_to=="quit"){
							j=-2;
							break;
						}
						if (move_to=="save"){
							save_game(pieces, j%2, capture_count, red_level, black_level);
							save=1;
							cout<<"Game Saved!\n";
							continue;
						}
						if (move_to=="load" and save==0){
							ifstream saved;			//Create a file object for reading
				    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
						    if (saved){		//If the file opens
								j=(load_settings(1))+1;
								capture_count=(load_settings(2));
								black_level=(load_settings(3));
								if (black_level>0){
									black_player==false;
								}
								red_level=(load_settings(4));
								if (red_level>0){
									red_player==false;
								}
								for (int i=1;i<=8;i++){
									for (int k=1;k<=8;k++){
										pieces[i-1][k-1]=load_board(i,k);
									}
							    }
							    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								load=1;
							    break;
							}
							else{
								cout<<"There is no saved game!\n";
							}
				    		saved.close();		//closes the file object (just in case)
						}
						move_to.at(0)=toupper(move_to.at(0));
						move=checkers_move_to_check(move_to,pieces,'B',x1,y1);
						while (move==-1){
							cout<<"Enter the location you want to move to (or 00 to reselect): ";
							cin>>move_to;
							if (move_to=="00"){
								break;
							}
							if (move_to=="save"){
								save_game(pieces, j%2, capture_count, red_level, black_level);
								save=1;
								cout<<"Game Saved!\n";
								continue;
							}	
							if (move_to=="load" and save==0){
								ifstream saved;			//Create a file object for reading
					    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
							    if (saved){		//If the file opens
									j=(load_settings(1))+1;
									capture_count=(load_settings(2));
									black_level=(load_settings(3));
									if (black_level>0){
										black_player==false;
									}
									red_level=(load_settings(4));
									if (red_level>0){
										red_player==false;
									}
									for (int i=1;i<=8;i++){
										for (int k=1;k<=8;k++){
											pieces[i-1][k-1]=load_board(i,k);
										}
								    }
								    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
									for (int i=0;i<8;i++){
										for (int k=0;k<8;k++){
											pieces[i][k]=reverse_char(og_board,i,k);
										}
									}
									load=1;
								    break;
								}
								else{
									cout<<"There is no saved game!\n";
								}
					    		saved.close();		//closes the file object (just in case)
							}
							move_to.at(0)=toupper(move_to.at(0));
							move=checkers_move_to_check(move_to,pieces,'B',x1,y1);
						}
						if (move_to=="00"){
							break;
						}
						if (move_to=="load" and save==0){
							break;
						}
						y2=(move_to.at(0)-64)-1;
						x2=(move_to.at(1)-'0')-1;
						if (move>0){
							pieces[(move%10)-1][(move/10)-1]=' ';
							capture_count=0;
						}
						else{
							capture_count++;
						}
						
						all_moves+=move_to;
						all_moves+=" ";
						pieces[x2][y2]=pieces[x1][y1];
						pieces[x1][y1]=' ';
						
						for (int i=0;i<8;i++){
							if (pieces[0][i]=='b'){
								pieces[0][i]='B';
							}
						}
						if (move<=0){
							break;
						}
						move_from=move_to;
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;	
						
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						move2=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						move3=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						move4=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						cout.clear();
//						cout<<move<<" "<<move2<<" "<<move3<<" "<<move4;
						if (move>0 or move2>0 or move3>0 or move4>0){
							system("PAUSE");
							cout<<flush;
							system("CLS");
							create_checkers(pieces);
							cout<<"STILL BLACK TURN\n";
						}
					} while (move>0 or move2>0 or move3>0 or move4>0);
					
					if (move_to=="00"){
						continue;
					}
					if (move_to=="load" and save==0){
						break;
					}
					break;
				}
				
			}
			else{
				cout<<"COMPUTER'S TURN (BLACK)\n";
				legal_spots.clear(); 
				attack_moves.clear();
				legal_spots.resize(5); 
				move_count.clear();
				while (j>-1){	
					for (int i=0;i<8;i++){
						for (int k=0;k<8;k++){
							if (pieces[i][k]=='b' or pieces[i][k]=='B'){
								legal_spots[0].push_back(char(k+1+64)+to_string(i+1));
//								cout<<legal_spots[0][legal_spots[0].size()-1]<<" ";
									
							}
						}
					}
//					cout<<endl;
					legal_spots.resize(5);
					for (int i=0;i<5;i++){
					    legal_spots[i].resize(legal_spots[0].size());
					}
//					cout<<legal_spots[0].size();
					move_count.resize(legal_spots[0].size(),1);
					cout.setstate(ios_base::failbit);
					for (int i=0;i<legal_spots[0].size();i++){
						y1=(legal_spots[0][i].at(0)-64)-1;
						x1=(legal_spots[0][i].at(1)-'0')-1;	
						moves[0]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1-1+1),pieces,'B',x1,y1);
						if (moves[0]!=-1){
							legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1-1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[1]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1-1+1),pieces,'B',x1,y1);
						if (moves[1]!=-1){
							legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1-1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[2]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1+1+1),pieces,'B',x1,y1);
						if (moves[2]!=-1){
							legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1+1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[3]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1+1+1),pieces,'B',x1,y1);
						if (moves[3]!=-1){
							legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1+1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[4]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						if (moves[4]!=-1){
							legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[5]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						if (moves[5]!=-1){
							legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[6]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						if (moves[6]!=-1){
							legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[7]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						if (moves[7]!=-1){
							legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						cout.clear();
//						cout<<endl;
						cout.setstate(ios_base::failbit);
					}
						
					for (int i=1;i<5;i++){
						if (legal_spots[i].empty()!=true){
							break;
						}
						else if (i==4){
							j=-3;
						}
					}
					if (j==-3){
						break;
					}
					if (black_level==1){
						do{
							rand_move=rand()%legal_spots[0].size();
	//						rand_move=0;
							for (int i=0;i<legal_spots[0].size();i++){
								for (int k=1;k<move_count[i];k++){
									if (legal_spots[k][i].back()=='-'){
										attack_moves.push_back(legal_spots[0][i]);
										break;
									}
								}	
							}	
						} while (legal_spots[1][rand_move].empty() or legal_spots[0][rand_move].empty());
						move_from=legal_spots[0][rand_move];
						if (attack_moves.size()>0){
							move_from=attack_moves[rand()%attack_moves.size()];
							for (int i=0;i<legal_spots[0].size();i++){
								if (move_from==legal_spots[0][i]){
									rand_move=i;
									break;
								}
							}
						}
						all_moves+=move_from;
						all_moves+=" ";
						cout.clear();
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;
						move=1;
					}
					else if (black_level==2){
						black_rand=rand()%4;
						if (black_rand==0){		//BABY MODE (RANDOM)
							do{
								rand_move=rand()%legal_spots[0].size();
		//						rand_move=0;
								for (int i=0;i<legal_spots[0].size();i++){
									for (int k=1;k<move_count[i];k++){
										if (legal_spots[k][i].back()=='-'){
											attack_moves.push_back(legal_spots[0][i]);
											break;
										}
									}	
								}
							} while (legal_spots[1][rand_move].empty() or legal_spots[0][rand_move].empty());
							move_from=legal_spots[0][rand_move];
							if (attack_moves.size()>0){
								move_from=attack_moves[rand()%attack_moves.size()];
								for (int i=0;i<legal_spots[0].size();i++){
									if (move_from==legal_spots[0][i]){
										rand_move=i;
										break;
									}
								}
							}
							all_moves+=move_from;
							all_moves+=" ";
							cout.clear();
							y1=(move_from.at(0)-64)-1;
							x1=(move_from.at(1)-'0')-1;
							move=1;
						}
						else{		//Hard Mode (REAL AI)
							cout.clear();
							copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
							for (int i=0;i<8;i++){
								for (int k=0;k<8;k++){
									pieces[i][k]=reverse_char(og_board,i,k);
								}
							}
							move=negamax(pieces,3,1);
//							cout<<"max: "<<move<<"\n";
							move_from=(move/1000)+64;
							move_from+=to_string((move/100)%10);
							for (int i=0;i<legal_spots[0].size();i++){
								if (move_from==legal_spots[0][i]){
									rand_move=i;
									break;
								}
							}
							y1=(move_from.at(0)-64)-1;
							x1=(move_from.at(1)-'0')-1;
							all_moves+=move_from;
							all_moves+=" ";
							move_to=((move/10)%10)+64;
							move_to+=to_string(move%10);	
						}
					}
					else{		//Hard Mode (REAL AI)
						cout.clear();
						copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
						for (int i=0;i<8;i++){
							for (int k=0;k<8;k++){
								pieces[i][k]=reverse_char(og_board,i,k);
							}
						}
						move=negamax(pieces,5,1);
//						cout<<"max: "<<move<<"\n";
						move_from=(move/1000)+64;
						move_from+=to_string((move/100)%10);
						for (int i=0;i<legal_spots[0].size();i++){
							if (move_from==legal_spots[0][i]){
								rand_move=i;
								break;
							}
						}
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;
						all_moves+=move_from;
						all_moves+=" ";
						move_to=((move/10)%10)+64;
						move_to+=to_string(move%10);
					}
//					cout<<rand_move+1<<"=";
//					cout<<move_from<<" ";
					if (move==0){
						j=-3;
						all_moves.erase(all_moves.size()-4);
						break;
					}
					cout<<"MOVE: "<<move_from<<" to ";
					do{
						if (black_level==1 or black_rand==0){	
							move=(rand()%(move_count[rand_move]-1))+1;	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									while (legal_spots[move][rand_move].back()!='-'){
										move=(rand()%(move_count[rand_move]-1))+1;
									}
									break;
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							move_to=legal_spots[move][rand_move];
						}
						else if (black_level==2){
							//BIG BOI
							if (attack==true){
								copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								move_to=to_string(multimax(pieces,3,1,move_from));
								move_to.at(0)=char(move_to.at(0)-'0'+64);
//								cout<<"to: "<<move_to<<endl;
							}
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move]==move_to){
									move=i;
									break;
								}
							}
						}
						else if (black_level==3){
							//BIG BOI
							if (attack==true){
								copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								move_to=to_string(multimax(pieces,5,1,move_from));
//								cout<<"to: "<<move_to<<endl;
								move_to.at(0)=char(move_to.at(0)-'0'+64);
								
							}
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move]==move_to){
									move=i;
									break;
								}
							}
						}
//						cout<<move<<"="<<move_to<<endl;
						cout<<move_to<<endl;
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(move_to,pieces,'B',x1,y1);
						cout.clear();
						y2=(move_to.at(0)-64)-1;
						x2=(move_to.at(1)-'0')-1;
//						cout<<"move: "<<move<<endl;
//						cout<<"piece: "<<pieces[x2][y2]<<" "<<x2<<"="<<y2<<endl;
						if (move>0){
							pieces[(move%10)-1][(move/10)-1]=' ';
							capture_count=0;
						}
						else{
							capture_count++;
						}
						
						all_moves+=move_to;
						all_moves+=" ";
						pieces[x2][y2]=pieces[x1][y1];
						pieces[x1][y1]=' ';
						
						for (int i=0;i<8;i++){
							if (pieces[0][i]=='b'){
								pieces[0][i]='B';
							}
						}
						if (move<=0){
							break;
						}
						move_from=move_to;
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;	
						
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						move2=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						move3=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						move4=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						cout.clear();
						if (move>0 or move2>0 or move3>0 or move4>0){
							system("PAUSE");
							cout<<flush;
							system("CLS");
							create_checkers(pieces);
							cout<<"STILL BLACK TURN\n";
							move_count[rand_move]=1;
							for (int i=1;i<5;i++){
								legal_spots[i][rand_move].clear();
							}
							if (move!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move2!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move3!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move4!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							cout.clear();
							cout<<"MOVE: "<<move_from<<" to ";
							attack=true;
						}
					} while (move>0 or move2>0 or move3>0 or move4>0);	
					attack=false;
					break;
				}
				cout.clear();
			}
		}
		else{
			if (red_player==true){
				if (black_player==false){	
					cout<<"YOUR TURN (RED)\n";
				}
				else{
					cout<<"RED TURN\n";
				}
				while (j>-1){
					cout.setstate(ios_base::failbit);
					if (generate_moves(pieces,'R')==0){
						j=-2;
						cout.clear();
						break;
					}
					cout.clear();
					cout<<"Enter the location of the piece you want to move (Ex. A7): ";
					cin>>move_from;
					if (move_from=="quit"){
						j=-2;
						break;
					}
					if (move_from=="save"){
						save_game(pieces, j%2, capture_count, red_level, black_level);
						save=1;
						cout<<"Game Saved!\n";
						cout.setstate(ios_base::failbit);
					}
					if (move_from=="load" and save==0){
						ifstream saved;			//Create a file object for reading
			    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
					    if (saved){		//If the file opens
							j=(load_settings(1))+1;
							capture_count=(load_settings(2));
							black_level=(load_settings(3));
							if (black_level>0){
								black_player==false;
							}
							red_level=(load_settings(4));
							if (red_level>0){
								red_player==false;
							}
							for (int i=1;i<=8;i++){
								for (int k=1;k<=8;k++){
									pieces[i-1][k-1]=load_board(i,k);
								}
						    }
						    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
							for (int i=0;i<8;i++){
								for (int k=0;k<8;k++){
									pieces[i][k]=reverse_char(og_board,i,k);
								}
							}
							load=1;
						    break;
						}
						else{
							cout<<"There is no saved game!\n";
						}
			    		saved.close();		//closes the file object (just in case)
					}
					move_from.at(0)=toupper(move_from.at(0));
					while (checkers_move_from_check(move_from,pieces,'R')==false){
						cout.clear();
						cout<<"Enter the location of the piece you want to move: ";
						cin>>move_from;
						if (move_from=="quit"){
							j=-2;
							break;
						}
						if (move_from=="save"){
							save_game(pieces, j%2, capture_count, red_level, black_level);
							save=1;
							cout<<"Game Saved!\n";
							continue;
						}
						if (move_from=="load" and save==0){
							ifstream saved;			//Create a file object for reading
				    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
						    if (saved){		//If the file opens
								j=(load_settings(1))+1;
								capture_count=(load_settings(2));
								black_level=(load_settings(3));
								if (black_level>0){
									black_player==false;
								}
								red_level=(load_settings(4));
								if (red_level>0){
									red_player==false;
								}
								for (int i=1;i<=8;i++){
									for (int k=1;k<=8;k++){
										pieces[i-1][k-1]=load_board(i,k);
									}
							    }
							    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								load=1;
							    break;
							}
							else{
								cout<<"There is no saved game!\n";
							}
				    		saved.close();		//closes the file object (just in case)
						}
						move_from.at(0)=toupper(move_from.at(0));
					}
					if (move_from=="quit"){
						j=-2;
						break;
					}
					if (move_from=="load" and save==0){
						break;
					}
					y1=(move_from.at(0)-64)-1;
					x1=(move_from.at(1)-'0')-1;
					
					all_moves+=move_from;
					all_moves+=" ";
					
					do{
						cout<<"Enter the location you want to move to (or 00 to reselect): ";
						cin>>move_to;
						if (move_to=="00"){
							break;
						}
						if (move_to=="quit"){
							j=-2;
							break;
						}
						if (move_to=="save"){
							save_game(pieces, j%2, capture_count, red_level, black_level);
							save=1;
							cout<<"Game Saved!\n";
							continue;
						}
						if (move_to=="load" and save==0){
							ifstream saved;			//Create a file object for reading
				    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
						    if (saved){		//If the file opens
								j=(load_settings(1))+1;
								capture_count=(load_settings(2));
								black_level=(load_settings(3));
								if (black_level>0){
									black_player==false;
								}
								red_level=(load_settings(4));
								if (red_level>0){
									red_player==false;
								}
								for (int i=1;i<=8;i++){
									for (int k=1;k<=8;k++){
										pieces[i-1][k-1]=load_board(i,k);
									}
							    }
							    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								load=1;
							    break;
							}
							else{
								cout<<"There is no saved game!\n";
							}
				    		saved.close();		//closes the file object (just in case)
						}
						move_to.at(0)=toupper(move_to.at(0));
						move=checkers_move_to_check(move_to,pieces,'R',x1,y1);
						while (move==-1){
							cout<<"Enter the location you want to move to (or 00 to reselect): ";
							cin>>move_to;
							if (move_to=="00"){
								break;
							}
							if (move_to=="save"){
								save_game(pieces, j%2, capture_count, red_level, black_level);
								save=1;
								cout<<"Game Saved!\n";
								continue;
							}
							if (move_to=="load" and save==0){
								ifstream saved;			//Create a file object for reading
					    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
							    if (saved){		//If the file opens
									j=(load_settings(1))+1;
									capture_count=(load_settings(2));
									black_level=(load_settings(3));
									if (black_level>0){
										black_player==false;
									}
									red_level=(load_settings(4));
									if (red_level>0){
										red_player==false;
									}
									for (int i=1;i<=8;i++){
										for (int k=1;k<=8;k++){
											pieces[i-1][k-1]=load_board(i,k);
										}
								    }
								    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
									for (int i=0;i<8;i++){
										for (int k=0;k<8;k++){
											pieces[i][k]=reverse_char(og_board,i,k);
										}
									}
									load=1;
								    break;
								}
								else{
									cout<<"There is no saved game!\n";
								}
					    		saved.close();		//closes the file object (just in case)
							}
							move_to.at(0)=toupper(move_to.at(0));
							move=checkers_move_to_check(move_to,pieces,'R',x1,y1);
						}
						if (move_to=="00"){
							break;
						}
						if (move_to=="load" and save==0){
							break;
						}
						y2=(move_to.at(0)-64)-1;
						x2=(move_to.at(1)-'0')-1;
						if (move>0){
							pieces[(move%10)-1][(move/10)-1]=' ';
							capture_count=0;
						}
						else{
							capture_count++;
						}
						
						all_moves+=move_to;
						all_moves+=" ";
						pieces[x2][y2]=pieces[x1][y1];
						pieces[x1][y1]=' ';
						
						for (int i=0;i<8;i++){
							if (pieces[0][i]=='r'){
								pieces[0][i]='R';
							}
						}
						if (move<=0){
							break;
						}
						move_from=move_to;
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;	
						
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						move2=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						move3=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						move4=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						cout.clear();
//						cout<<move<<" "<<move2<<" "<<move3<<" "<<move4;
						if (move>0 or move2>0 or move3>0 or move4>0){
							system("PAUSE");
							cout<<flush;
							system("CLS");
							create_checkers(pieces);
							cout<<"STILL RED TURN\n";
						}
					} while (move>0 or move2>0 or move3>0 or move4>0);
					
					if (move_to=="00"){
						continue;
					}
					if (move_to=="load" and save==0){
						break;
					}
					break;
				}
			}
			else{
				cout<<"COMPUTER'S TURN (RED)\n";
				legal_spots.clear(); 
				attack_moves.clear();
				legal_spots.resize(5); 
				move_count.clear();
				while (j>-1){	
					for (int i=0;i<8;i++){
						for (int k=0;k<8;k++){
							if (pieces[i][k]=='r' or pieces[i][k]=='R'){
								legal_spots[0].push_back(char(k+1+64)+to_string(i+1));
//								cout<<legal_spots[0][legal_spots[0].size()-1]<<" ";
									
							}
						}
					}
//					cout<<endl;
					legal_spots.resize(5);
					for (int i=0;i<5;i++){
					    legal_spots[i].resize(legal_spots[0].size());
					}
//					cout<<legal_spots[0].size();
					move_count.resize(legal_spots[0].size(),1);
					cout.setstate(ios_base::failbit);
					for (int i=0;i<legal_spots[0].size();i++){
						y1=(legal_spots[0][i].at(0)-64)-1;
						x1=(legal_spots[0][i].at(1)-'0')-1;	
						moves[0]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1-1+1),pieces,'R',x1,y1);
						if (moves[0]!=-1){
							legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1-1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[1]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1-1+1),pieces,'R',x1,y1);
						if (moves[1]!=-1){
							legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1-1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[2]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1+1+1),pieces,'R',x1,y1);
						if (moves[2]!=-1){
							legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1+1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[3]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1+1+1),pieces,'R',x1,y1);
						if (moves[3]!=-1){
							legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1+1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[4]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						if (moves[4]!=-1){
							legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[5]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						if (moves[5]!=-1){
							legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[6]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						if (moves[6]!=-1){
							legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[7]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						if (moves[7]!=-1){
							legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						cout.clear();
//						cout<<endl;
						cout.setstate(ios_base::failbit);
					}
					for (int i=1;i<5;i++){
						if (legal_spots[i].empty()!=true){
							break;
						}
						else if (i==4){
							j=-2;
						}
					}
					if (j==-2){
						break;
					}
					if (red_level==1){
						do{
							rand_move=rand()%legal_spots[0].size();
	//						rand_move=0;
							for (int i=0;i<legal_spots[0].size();i++){
								for (int k=1;k<move_count[i];k++){
									if (legal_spots[k][i].back()=='-'){
										attack_moves.push_back(legal_spots[0][i]);
										break;
									}
								}	
							}
//							for (int i=1;i<move_count[rand_move];i++){
//								if (legal_spots[i][rand_move].back()=='-'){
//									legal_spots[i][rand_move].pop_back();
//								}
//							}	
						} while (legal_spots[1][rand_move].empty() or legal_spots[0][rand_move].empty());
						move_from=legal_spots[0][rand_move];
						if (attack_moves.size()>0){
							move_from=attack_moves[rand()%attack_moves.size()];
							for (int i=0;i<legal_spots[0].size();i++){
								if (move_from==legal_spots[0][i]){
									rand_move=i;
									break;
								}
							}
						}
						all_moves+=move_from;
						all_moves+=" ";
						cout.clear();
//						cout<<rand_move+1<<"=";
//						cout<<move_from;
	//					cout.setstate(ios_base::failbit);
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;
						move=1;
					}
					else if (red_level==2){
						red_rand=rand()%4;
						if (red_rand==0){		//BABY MODE (RANDOM)
							do{
								rand_move=rand()%legal_spots[0].size();
//								rand_move=0;
								for (int i=0;i<legal_spots[0].size();i++){
									for (int k=1;k<move_count[i];k++){
										if (legal_spots[k][i].back()=='-'){
											attack_moves.push_back(legal_spots[0][i]);
											break;
										}
									}	
								}
							} while (legal_spots[1][rand_move].empty() or legal_spots[0][rand_move].empty());
							move_from=legal_spots[0][rand_move];
							if (attack_moves.size()>0){
								move_from=attack_moves[rand()%attack_moves.size()];
								for (int i=0;i<legal_spots[0].size();i++){
									if (move_from==legal_spots[0][i]){
										rand_move=i;
										break;
									}
								}
							}
							all_moves+=move_from;
							all_moves+=" ";
							cout.clear();
		//					cout.setstate(ios_base::failbit);
							y1=(move_from.at(0)-64)-1;
							x1=(move_from.at(1)-'0')-1;
							move=1;
						}
						else{		//Hard Mode (REAL AI)
							cout.clear();
							copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
							for (int i=0;i<8;i++){
								for (int k=0;k<8;k++){
									pieces[i][k]=reverse_char(og_board,i,k);
								}
							}
							move=negamax(pieces,3,-1);
//							cout<<"max: "<<move<<"\n";
							move_from=(move/1000)+64;
							move_from+=to_string((move/100)%10);
							for (int i=0;i<legal_spots[0].size();i++){
								if (move_from==legal_spots[0][i]){
									rand_move=i;
									break;
								}
							}
							y1=(move_from.at(0)-64)-1;
							x1=(move_from.at(1)-'0')-1;
							all_moves+=move_from;
							all_moves+=" ";
							move_to=((move/10)%10)+64;
							move_to+=to_string(move%10);
						}
					}
					else{		//Hard Mode (REAL AI)
						cout.clear();
						copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
						for (int i=0;i<8;i++){
							for (int k=0;k<8;k++){
								pieces[i][k]=reverse_char(og_board,i,k);
							}
						}
//						cout<<all_moves<<endl;
						move=negamax(pieces,5,-1);
//						cout<<"hi";
//						cout<<"max: "<<move<<"\n";
						move_from=(move/1000)+64;
						move_from+=to_string((move/100)%10);
						for (int i=0;i<legal_spots[0].size();i++){
							if (move_from==legal_spots[0][i]){
								rand_move=i;
								break;
							}
						}
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;
						all_moves+=move_from;
						all_moves+=" ";
						move_to=((move/10)%10)+64;
						move_to+=to_string(move%10);
					}
//					cout<<rand_move+1<<"=";
					if (move==0){
						j=-2;
						all_moves.erase(all_moves.size()-4);
						break;
					}
					cout<<"MOVE: "<<move_from<<" to ";
					do{
						if (red_level==1 or red_rand==0){	
							move=(rand()%(move_count[rand_move]-1))+1;	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									while (legal_spots[move][rand_move].back()!='-'){
										move=(rand()%(move_count[rand_move]-1))+1;
									}
									break;
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							move_to=legal_spots[move][rand_move];
						}
						else if (red_level==2){
							//BIG BOI
							if (attack==true){
								copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								move_to=to_string(multimax(pieces,3,-1,move_from));
								move_to.at(0)=char(move_to.at(0)-'0'+64);
//								cout<<"to: "<<move_to<<endl;
							}
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move]==move_to){
									move=i;
									break;
								}
							}
						}
						else if (red_level==3){
							//BIG BOI
							if (attack==true){
								copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								move_to=to_string(multimax(pieces,5,-1,move_from));
								move_to.at(0)=char(move_to.at(0)-'0'+64);
//								cout<<"to: "<<move_to<<endl;
							}
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move]==move_to){
									move=i;
									break;
								}
							}
						}
//						cout<<move<<"="<<move_to<<endl;
						cout<<move_to<<endl;
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(move_to,pieces,'R',x1,y1);
						cout.clear();
						y2=(move_to.at(0)-64)-1;
						x2=(move_to.at(1)-'0')-1;
//						cout<<"move: "<<move<<endl;
//						cout<<"piece: "<<pieces[x2][y2]<<" "<<x2<<"="<<y2<<endl;
						if (move>0){
							pieces[(move%10)-1][(move/10)-1]=' ';
							capture_count=0;
						}
						else{
							capture_count++;
						}
						
						all_moves+=move_to;
						all_moves+=" ";
						pieces[x2][y2]=pieces[x1][y1];
						pieces[x1][y1]=' ';
						
						for (int i=0;i<8;i++){
							if (pieces[0][i]=='r'){
								pieces[0][i]='R';
							}
						}
						if (move<=0){
							break;
						}
						move_from=move_to;
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;	
						
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						move2=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						move3=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						move4=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						cout.clear();
						if (move>0 or move2>0 or move3>0 or move4>0){
							system("PAUSE");
							cout<<flush;
							system("CLS");
							create_checkers(pieces);
							cout<<"STILL RED TURN\n";
							move_count[rand_move]=1;
							for (int i=1;i<5;i++){
								legal_spots[i][rand_move].clear();
							}
							if (move!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move2!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move3!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move4!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							cout.clear();
							cout<<"MOVE: "<<move_from<<" to ";
							attack=true;
						}
					} while (move>0 or move2>0 or move3>0 or move4>0);	
					attack=false;
					break;
				}
				cout.clear();
			}
		}
		system("PAUSE");
		if (j==-2){
			black_win=true;
			j=-1;
		}
		if (j==-3){
			red_win=true;
			j=0;
		}
	}
	if (load==0){
		cout<<"\nYou can recreate a game by pasting in these moves in Human v Human mode.";
		cout<<"\nAll moves: "<<all_moves<<endl;
	}
	system("PAUSE");
}

char reverse_char(char board[8][8],int x, int y){
	char r_char;
	r_char=board[7-x][7-y];
	return r_char;
}

void save_game(char board[8][8], int turn, int capture, int red_cpu, int black_cpu){
	fstream save;									//Create a file object for reading/writing
    save.open("Checkers_save.txt");					// attempt to open the highscore file
    if (!save){										//If the file does not open
        save.open("Checkers_save.txt", ios::out);		//Create and open a highscore file for writing
    }	
    save<<turn<<","<<capture<<","<<black_cpu<<","<<red_cpu<<endl;					//Write to the highscore file
    for (int j=0;j<8;j++){
    	for (int k=0;k<8;k++){
    		save<<board[j][k];
		}
		save<<endl;
	}
    save.close();
}

int load_settings(int option){
	string phrase;
	int comma1,comma2,comma3;
	
    ifstream file2("Checkers_save.txt");			//opens the highscore file for input
	file2>>phrase;		//Reads in a line from the spreadsheet
	file2.close();
	comma1=phrase.find(',');
	comma2=phrase.find(',', comma1+1);
	comma3=phrase.find(',', comma2+1);
	if (option==1){
		return (stoi(phrase.substr(0,comma1)));
	}
	else if (option==2){
		return stoi(phrase.substr(comma1+1,comma2));
	}
	else if (option==3){
		return stoi(phrase.substr(comma2+1,comma3));
	}
	else{
		return stoi(phrase.substr(comma3+1)); 
	}
}

char load_board(int x, int y){
	string phrase;
	
    ifstream file2("Checkers_save.txt");			//opens the highscore file for input
    for (int i=0;i<9;i++){		//Until the current row reaches the total row count
		getline(file2,phrase);		//Reads in a line from the spreadsheet
		if (phrase.at(0)=='0' or phrase.at(0)=='1'){
			continue;
		}
		else{		//If its not the first line
			if (x==i){
//					cout<<y-1;
				return phrase.at(y-1);
			}
		}
	}
	file2.close();
	
	if (x==7 and y==7){
		remove("Checkers_save.txt");		//Delete the highscore file
	}
}

int generate_moves(char board[8][8], char color){
	vector<vector <string>> legal_spots(5);
	vector <int> move_count;
	int moves[8];
	int x1,y1;
	
	legal_spots.resize(5); 
	for (int i=0;i<8;i++){
		for (int k=0;k<8;k++){
			if (toupper(board[i][k])==color){
				legal_spots[0].push_back(char(k+1+64)+to_string(i+1));
					
			}
		}
	}
	legal_spots.resize(5);
	for (int i=0;i<5;i++){
	    legal_spots[i].resize(legal_spots[0].size());
	}
	move_count.resize(legal_spots[0].size(),1);
	cout.setstate(ios_base::failbit);
	for (int i=0;i<legal_spots[0].size();i++){
		y1=(legal_spots[0][i].at(0)-64)-1;
		x1=(legal_spots[0][i].at(1)-'0')-1;	
		moves[0]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1-1+1),board,color,x1,y1);
		if (moves[0]!=-1){
			legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1-1+1);
			move_count[i]++;
			return 1;
		}
		moves[1]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1-1+1),board,color,x1,y1);
		if (moves[1]!=-1){
			legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1-1+1);
			move_count[i]++;
			return 1;
		}
		moves[2]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1+1+1),board,color,x1,y1);
		if (moves[2]!=-1){
			legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1+1+1);
			move_count[i]++;
			return 1;
		}
		moves[3]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1+1+1),board,color,x1,y1);
		if (moves[3]!=-1){
			legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1+1+1);
			move_count[i]++;
			return 1;
		}
		moves[4]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),board,color,x1,y1);
		if (moves[4]!=-1){
			legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
			move_count[i]++;
			return 1;
		}
		moves[5]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),board,color,x1,y1);
		if (moves[5]!=-1){
			legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
			move_count[i]++;
			return 1;
		}
		moves[6]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),board,color,x1,y1);
		if (moves[6]!=-1){
			legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
			move_count[i]++;
			return 1;
		}
		moves[7]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),board,color,x1,y1);
		if (moves[7]!=-1){
			legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
			move_count[i]++;
			return 1;
		}
	}
	
	return 0;
}

bool checkers_move_from_check(string move, char board[8][8], char color){
	int x,y;
	vector <string> attack_pieces;
	int move1,move2,move3,move4;
	bool attacker=false;
	
	if (move.length()!=2){
		cout<<"That is not a legal spot! Retry.\n";
		return false;
	}
	if (isalpha(move.at(0))==false){
		cout<<"That is not a legal spot! Retry.\n";
		return false;
	}
	if (isdigit(move.at(1))==false){
		cout<<"That is not a legal spot! Retry.\n";
		return false;
	}
	y=(move.at(0)-64)-1;
	x=(move.at(1)-'0')-1;
	if (y<0 or y>7 or x<0 or x>7){
		cout<<"That is not a legal spot! Retry.\n";
		return false;
	}
	if (color=='B'){
		if (board[x][y]!='b' and board[x][y]!='B'){
			cout<<"That is not a legal spot! Retry.\n";
			return false;
		}
	}
	else{
		if (board[x][y]!='r' and board[x][y]!='R'){
			cout<<"That is not a legal spot! Retry.\n";
			return false;
		}
	}
	cout.setstate(ios_base::failbit);
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			if (toupper(board[i][j])==color){	
				move1=checkers_move_to_check(char(j-2+1+64)+to_string(i-2+1),board,color,i,j);
				move2=checkers_move_to_check(char(j+2+1+64)+to_string(i-2+1),board,color,i,j);
				move3=checkers_move_to_check(char(j-2+1+64)+to_string(i+2+1),board,color,i,j);
				move4=checkers_move_to_check(char(j+2+1+64)+to_string(i+2+1),board,color,i,j);
				if (move1>0 or move2>0 or move3>0 or move4>0){
					attack_pieces.push_back(char(j+1+64)+to_string(i+1));
//					cout<<attack_pieces[attack_pieces.size()-1]<<" "<<move1<<" "<<move2<<" "<<move3<<" "<<move4<<endl;
				}
			}
		}
	}
	cout.clear();
	if (attack_pieces.size()>0){
		for (int i=0;i<attack_pieces.size();i++){
			if (move==attack_pieces[i]){
				attacker=true;
				break;
			}
		}
		if (attacker==false){
			cout<<"You must attack if you can! Retry.\n";
			return false;
		}
	}
	
	return true;
}

int checkers_move_to_check(string move, char board[8][8], char color, int x1, int y1){
	int x2,y2;
	bool attack[5];
	for (int i=0;i<5;i++){
		attack[i]=false;
	}
	
	if (move.length()!=2){
		cout<<"That is not a legal spot! Retry.\n";
		return -1;
	}
	if (isalpha(move.at(0))==false){
		cout<<"That is not a legal spot! Retry.\n";
		return -1;
	}
	if (isdigit(move.at(1))==false){
		cout<<"That is not a legal spot! Retry.\n";
		return -1;
	}
	y2=(move.at(0)-64)-1;
	x2=(move.at(1)-'0')-1;
	if (board[x2][y2]!=' '){
		cout<<"You can't land on other pieces! Retry.\n";
		return -1;
	}
	
	if (y2<0 or y2>7 or x2<0 or x2>7){
		cout<<"That is not a legal spot! Retry.\n";
		return -1;
	}
	if (!(abs(x2-x1)==abs(y2-y1))){
		cout<<"You can only move diagonally! Retry.\n";
		return -1;
	}
	if (x2<=x1 and islower(board[x1][y1]!=false)){
		cout<<"You can only move diagonally forwards! Retry.\n";
		return -1;
	}
	if (isupper(board[x1][y1])!=false){		//BIG BOI		(Work on this after normal movement for smol boi)
		if (color=='B'){
			if ((board[x1-1][y1+1]=='r' or board[x1-1][y1+1]=='R') and board[x1-2][y1+2]==' '){
				if (x1-2>=0 and x1-2<8 and y1+2>=0 and y1+2<8){	
					attack[0]=true;
					attack[4]=true;
				}		//Up-Right
			}
			if ((board[x1-1][y1-1]=='r' or board[x1-1][y1-1]=='R') and board[x1-2][y1-2]==' '){
				if (x1-2>=0 and x1-2<8 and y1-2>=0 and y1-2<8){	
					attack[1]=true;
					attack[4]=true;
				}		//Up-Left
			}
			if ((board[x1+1][y1+1]=='r' or board[x1+1][y1+1]=='R') and board[x1+2][y1+2]==' '){
				if (x1+2>=0 and x1+2<8 and y1+2>=0 and y1+2<8){	
					attack[2]=true;
					attack[4]=true;	
				}		//Down-Right
			}
			if ((board[x1+1][y1-1]=='r' or board[x1+1][y1-1]=='R') and board[x1+2][y1-2]==' '){
				if (x1+2>=0 and x1+2<8 and y1-2>=0 and y1-2<8){	
					attack[3]=true;
					attack[4]=true;
				}		//Down-Left
			}	
		}
		if (color=='R'){
			if ((board[x1-1][y1+1]=='b' or board[x1-1][y1+1]=='B') and board[x1-2][y1+2]==' '){
				if (x1-2>=0 and x1-2<8 and y1+2>=0 and y1+2<8){		
					attack[0]=true;
					attack[4]=true;
				}		//Up-Right
			}
			if ((board[x1-1][y1-1]=='b' or board[x1-1][y1-1]=='B') and board[x1-2][y1-2]==' '){
				if (x1-2>=0 and x1-2<8 and y1-2>=0 and y1-2<8){	
					attack[1]=true;
					attack[4]=true;
				}		//Up-Left
			}
			if ((board[x1+1][y1+1]=='b' or board[x1+1][y1+1]=='B') and board[x1+2][y1+2]==' '){
				if (x1+2>=0 and x1+2<8 and y1+2>=0 and y1+2<8){	
					attack[2]=true;
					attack[4]=true;
				}		//Down-Right
			}
			if ((board[x1+1][y1-1]=='b' or board[x1+1][y1-1]=='B') and board[x1+2][y1-2]==' '){
				if (x1+2>=0 and x1+2<8 and y1-2>=0 and y1-2<8){		
					attack[3]=true;
					attack[4]=true;
				}		//Down-Left
			}	
		}
//		cout<<attack[0]<<" "<<attack[1]<<" "<<attack[2]<<" "<<attack[3]<<" "<<attack[4];
//		cout<<endl<<x1+2<<"="<<x2<<"&"<<y1-2<<"="<<y2<<endl<<x1+1<<"+"<<y1-1<<"=="<<board[x1+1][y1-1]<<endl;
		if (attack[4]==true){
			if (!((x2==x1+2 or x2==x1-2) and (y2==y1+2 or y2==y1-2))){
				cout<<"You must attack if you can! Retry.\n";
				return -1;
			}
			if (attack[0]==true and x1-2==x2 and y1+2==y2){	
//				cout<<" "<<(y1+1+1)*10+(x1-1+1);
				return (y1+2)*10+(x1);
			}
			if (attack[1]==true and x1-2==x2 and y1-2==y2){	
//				cout<<" "<<(y1-1+1)*10+(x1-1+1);
				return (y1)*10+(x1);
			}
			if (attack[2]==true and x1+2==x2 and y1+2==y2){	
//				cout<<" "<<(y1+1+1)*10+(x1+1+1);
				return (y1+2)*10+(x1+2);
			}
			if (attack[3]==true and x1+2==x2 and y1-2==y2){	
//				cout<<" "<<(y1-1+1)*10+(x1+1+1);
				return (y1)*10+(x1+2);
			}
			attack[4]=false;
//			cout<<"hi";
		}
		if (attack[4]==false){		//Normal Movement
			if ((x2!=x1+1 and x2!=x1-1) or (y2!=y1+1 and y2!=y1-1)){
				cout<<"You can only move diagonally! Retry.\n";
				return -1;
			}
		}
	}
	else{		//SMOL BOI
		if (color=='B'){
			if ((board[x1-1][y1+1]=='r' or board[x1-1][y1+1]=='R') and board[x1-2][y1+2]==' '){
				if (x1-2>=0 and x1-2<8 and y1+2>=0 and y1+2<8){	
					attack[0]=true;
					attack[4]=true;
				}		//Up-Right
			}
			if ((board[x1-1][y1-1]=='r' or board[x1-1][y1-1]=='R') and board[x1-2][y1-2]==' '){
				if (x1-2>=0 and x1-2<8 and y1-2>=0 and y1-2<8){	
					attack[1]=true;
					attack[4]=true;
				}		//Up-Left
			}	
		}
		if (color=='R'){
			if ((board[x1-1][y1+1]=='b' or board[x1-1][y1+1]=='B') and board[x1-2][y1+2]==' '){
				if (x1-2>=0 and x1-2<8 and y1+2>=0 and y1+2<8){		
					attack[0]=true;
					attack[4]=true;
				}		//Up-Right
			}
			if ((board[x1-1][y1-1]=='b' or board[x1-1][y1-1]=='B') and board[x1-2][y1-2]==' '){
				if (x1-2>=0 and x1-2<8 and y1-2>=0 and y1-2<8){	
					attack[1]=true;
					attack[4]=true;
				}		//Up-Left
			}	
		}
//		cout<<attack[4];
//		cout<<endl<<x1-2<<"="<<x2<<"&"<<y1-2<<"="<<y2<<endl<<x1-1<<"+"<<y1-1<<"=="<<board[x1-1][y1-1]<<endl;
		if (attack[4]==true){
			if (!((x2==x1+2 or x2==x1-2) and (y2==y1+2 or y2==y1-2))){
				cout<<"You must attack if you can! Retry.\n";
				return -1;
			}
			if (attack[0]==true and x1-2==x2 and y1+2==y2){	
//				cout<<" "<<(y1+1+1)*10+(x1-1+1);
				return (y1+2)*10+(x1);
			}
			if (attack[1]==true and x1-2==x2 and y1-2==y2){	
//				cout<<" "<<(y1-1+1)*10+(x1-1+1);
				return (y1)*10+(x1);
			}
			attack[4]=false;
//			cout<<"hi";
		}
		if (attack[4]==false){		//Normal Movement
			if (x2!=x1-1 or (y2!=y1+1 and y2!=y1-1)){
				cout<<"You can only move diagonally forwards! Retry.\n";
				return -1;
			}
		}
	}
	return 0;
}

void create_checkers(char board[8][8]){
	int row,col,color;
	wstring row_num;
	ostringstream hex_bg;
	string back, back2;
	int bg=0;
	int bg2=0;
	wchar_t piece;
	
	row_num=L"  \uFF10";
	
	cout<<flush;
	system("CLS");
	_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
	wcout<<L"\u2503     \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F     \u2503\n";
	wcout<<L"\u2503  \uFF21 \u2595\u258F \uFF22 \u2595\u258F \uFF23 \u2595\u258F \uFF24 \u2595\u258F \uFF25 \u2595\u258F \uFF26 \u2595\u258F \uFF27 \u2595\u258F \uFF28  \u2503\n";
	wcout<<L"\u2503     \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F     \u2503\n";
	_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
	
	while (bg==15 or bg==0){
		bg=rand()%16;
	}
	bg=7;
	hex_bg<<"0x"<<hex<<bg;
	back=hex_bg.str()+"0";
	hex_bg.str("");
	hex_bg.clear();
	
	while (bg2==bg or bg2==15 or bg2==0){
		bg2=rand()%16;
	}
	bg2=8;
	hex_bg<<"0x"<<hex<<bg2;
	back2=hex_bg.str()+"0";
	
	bg=stoi(back,nullptr,0);
	bg2=stoi(back2,nullptr,0);
	
	
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );                                  // h is your link to the console
	_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
	wcout<<L"\u250F";
	for (int i=0;i<48;i++){
		wcout<<L"\u2501";	
	}
	wcout<<L"\u2513";
	wcout<<L"\u2501\u2501\u2501\u2501\u2501\u2501";
	_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
	
	cout<<endl;
	for (int j=0;j<8;j++){
		for (int k=0;k<3;k++){
			
			SetConsoleTextAttribute( h, 7 | 0x00 );
			_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
			wcout<<L"\u2503";	
			_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
			
			for (int i=0;i<4;i++){
				if ((j<2 or j>5) and k==1){					
					if (j<2){
						color=15;
					}
					else{
						color=0;
					}
				}
				if (j%2==0){
					SetConsoleTextAttribute( h, color | bg );
					_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
					wcout<<L"      ";	
					_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
					SetConsoleTextAttribute( h, color | bg2 );
					_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
					wcout<<L"      ";	
					_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
				}
				else{
					SetConsoleTextAttribute( h, color | bg2 );
					_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
					wcout<<L"      ";	
					_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
					SetConsoleTextAttribute( h, color | bg );
					_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
					wcout<<L"      ";	
					_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
				}			
			}
			
			SetConsoleTextAttribute( h, 7 | 0x00 );
			_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
			wcout<<L"\u2503";
			if (k==1){
				row_num.back()++;
				wcout<<row_num;
			}
			if (k==2 and j<7){
				wcout<<L"\u2581\u2581\u2581\u2581\u2581\u2581";
			}
			_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
			cout<<endl;
		}
	}
	
	SetConsoleTextAttribute( h, 7 | 0x00 );
	
	_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
	wcout<<L"\u2517";
	for (int i=0;i<48;i++){
		wcout<<L"\u2501";	
	}
	wcout<<L"\u251B";
	wcout<<L"\u2501\u2501\u2501\u2501\u2501\u2501";
	_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
	
	
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			if (board[i][j]=='r'){
				color=4;
				piece=L'\u26C2';
			}
			else if (board[i][j]=='R'){
				color=4;
				piece=L'\u26C3';
			}
			else if (board[i][j]=='b'){
				color=0;
				piece=L'\u26C2';
			}
			else if (board[i][j]=='B'){
				color=0;
				piece=L'\u26C3';
			}
			else{
				continue;
			}
			row=i+1;
			col=j+1;
			
			if (row%2==1){
				if (col%2==1){
					bg=stoi(back,nullptr,0);
				}
				else{
					bg=stoi(back2,nullptr,0);
				}
			}
			else{
				if (col%2==1){
					bg=stoi(back2,nullptr,0);
				}
				else{
					bg=stoi(back,nullptr,0);
				}
			}
			cout<<"\x1b[s";
			cout<<"\x1b[4;"<<((col-1)*6)+5<<"H\x1b["<<row*3-1<<"B\b";
				
			_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
			SetConsoleTextAttribute( h, color | bg );
			wcout<<piece;
			SetConsoleTextAttribute( h, 0 | 0x00 );
			_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
			
			cout<<"\x1b[u";
		}
	}
	

	cout<<endl;
}
