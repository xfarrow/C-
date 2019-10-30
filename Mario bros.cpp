//SCRITTO DA ALESSANDRO FERRO
#include<iostream>
#include "stdio.h" 
#include "conio.h" 
#include <stdlib.h>
using namespace std;
int coins=0;
int lifes=3;
void life(){
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                 | x "<<lifes<<endl;
}
void stampa(char m[5][100]){
	for(int y=0;y<5;y++){
		for(int x=0;x<100;x++){
			if(y==0 and x==98){
				cout<<"Coins: "<<coins<<"/3";
			}
			cout<<m[y][x];
		}
	cout<<endl;
	}
}
void play(char m[5][100]){
	int key;
	bool flag=false;
	key=getch();
	if (key == 224) { 
	key = getch();
	if(key==75){   //Freccia sinistra
		for(int y=0;y<5;y++){
			for(int x=0;x<100;x++){
				if(m[y][x]=='|'){
					if(x!=0){
						m[y][x]=' ';
						m[y][x-1]='|';
					}
					if(m[y+1][x-1]==' '){
						lifes--;
						system("cls");
						life();
						_sleep(1000);
						m[3][0]='|';
						m[y][x-1]=' ';
					}
				}
			}
		}	
	}
	else if(key==77){       //Destra
		for(int y=0 ; y<5 and flag==false ; y++){
			for(int x=0 ; x<100 and flag==false ; x++){
				if(m[y][x]=='|'){
					if(x!=99){
						m[y][x]=' ';
						m[y][x+1]='|';
						flag=true;
						if(m[y+1][x+1]==' '){
							lifes--;
							system("cls");
							life();
							_sleep(1000);
							m[3][0]='|';
							m[y][x+1]=' ';
						}
						if(x==98){
						lifes=-1;
					} 
					}
	}
}}}
	else if(key==72){          //Sopra
		for(int y=0;y<5;y++){
			for(int x=0;x<100;x++){
				if(m[y][x]=='|'){
					if(m[y-1][x]=='O'){
						coins++;
					}
					m[y][x]=' ';
					m[y-1][x]='|';
					system("cls");
					stampa(m);
					_sleep(50);
					m[y-1][x]=' ';
					m[y][x]='|';
				}
			}
		}
	}
	else if(key==134){            //F12
		for(int y=0;y<5;y++){
			for(int x=0;x<100;x++){
			if(m[y][x]=='|' and flag==false){
				if(m[y-1][x+1]=='O' and x<=97){
					coins++;
				}
				  if(x<=97){
				  	m[y][x]=' ';
				  	m[y-1][x+1]='|';
					system("cls");
					stampa(m);
					_sleep(50);
					m[y-1][x+1]=' ';
					m[y][x+2]='|';
				  	flag=true;
				  	if(m[y+1][x+2]==' '){
				  		lifes--;
				  		system("cls");
				  		life();
				  		_sleep(1000);
				  		m[3][0]='|';
				  		m[y][x+2]=' ';
					  }
					  if(x==97){
						lifes=-1;
					}
				  }
				
				}
			}
			}
			flag=false;
	}
	else if(key==133){       //F11
	for(int y=0; y<5; y++){
		for(int x=0; x<100; x++){
			if(m[y][x]=='|' and x>=2){
				if(m[y-1][x-1]=='O'){
					coins++;
				}
				m[y][x]=' ';
				m[y-1][x-1]='|';
				system("cls");
				stampa(m);
				_sleep(50);
				m[y-1][x-1]=' ';
				m[y][x-2]='|';
				if(m[y+1][x-2]==' '){
					lifes--;
					system("cls");
					life();
					_sleep(1000);
					m[3][0]='|';
					m[y][x-2]=' ';
				}
			}
		}
	}
	}
}
}





main(){
	char m[5][100];
	for(int y=0;y<5;y++){
		for(int x=0;x<100;x++){
			if(y==4){
				m[y][x]='-';
			}
			else{
				m[y][x]=' ';
			}
		}
	}
	m[3][0]='|'; //mario
	m[2][15]='O'; m[2][37]='O'; m[2][48]='O';            //Soldi
	m[4][7]=' '; m[4][18]=' '; m[4][24]=' '; m[4][47]=' '; m[4][88]=' ';
	cout<<"Super Mario Bros ASCII version"<<endl<<endl;	
	cout<<"Usa le frecce per muoverti. Usa F12 per fare un doppio salto in avanti e F11 per doppio salto all'indietro"<<endl;
	
	system("pause");                                   
	system("cls");
	cout<<"Questo gioco e' ottimizzato per Windows 8 e successivi. Se stai utilizzando questo gioco con versioni inferiori, troverai difficile giocarci, causa dimensione finestra CMD non ridimensionabile e caratteri ASCII riscritti da Windows 8 in poi."<<endl;
	system("pause");
	system("cls");
	life();
	_sleep(1000);
	system("cls");
	do{
	stampa(m);
	play(m);
	system("cls");
}while(lifes>=0);
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                 GAME OVER "<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
system("pause");
}
