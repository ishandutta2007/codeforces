#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
string s[3];
int k=0, l=0;
	for(int i=0; i<3; i++){
		cin >> s[i];
		for(int j=0; j<3; j++)
			if(s[i][j]=='X'){
				k++;
			}
			else if(s[i][j]=='0') l++;
	}
if(k-l==1){
	for(int i=0; i<3; i++){
		if(s[i]=="000" || s[1][1]=='0' && s[0][i]=='0' && s[2][2-i]=='0'||s[0][i]=='0'&&s[1][i]=='0' && s[2][i]=='0'){
			cout << "illegal";
			return 0;							
		}
    }    

	for(int i=0; i<3; i++){
		if(s[i]=="XXX" || s[1][1]=='X' && s[0][i]=='X' && s[2][2-i]=='X'||s[0][i]=='X'&&s[1][i]=='X' && s[2][i]=='X'){
			cout << "the first player won";
			return 0;							
		}
    }
    if(k+l==9) cout << "draw";
    else cout << "second";
}
else if(k==l){

	for(int i=0; i<3; i++){
		if(s[i]=="XXX" || s[1][1]=='X' && s[0][i]=='X' && s[2][2-i]=='X'||s[0][i]=='X'&&s[1][i]=='X' && s[2][i]=='X'){
			cout << "illegal";
			return 0;							
		}
    }

	for(int i=0; i<3; i++){
		if(s[i]=="000" || s[1][1]=='0' && s[0][i]=='0' && s[2][2-i]=='0'||s[0][i]=='0'&&s[1][i]=='0' && s[2][i]=='0'){
			cout << "the second player won";
			return 0;							
		}
    }
       
    cout << "first";        
}
else cout << "illegal";
return 0;
}