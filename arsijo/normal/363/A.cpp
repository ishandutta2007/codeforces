/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

string getAns(int a) {
	string s = "";
	if (a < 5){
		s += "O-";
	}else{
		s += "-O";
	}
	s += "|";
	a %= 5;
	for(int i = 0; i < a; i++){
		s += "O";
	}
	s += "-";
	for(int i = 0; i < (4 - a); i++){
		s += "O";
	}
	return s;
}

int main() {
	int a;
	cin >> a;
	if (a == 0){
		cout << getAns(a) << endl;
		return 0;
	}
	while(a != 0){
		cout << getAns(a % 10) << endl;
		a /= 10;
	}
}