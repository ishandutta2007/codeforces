/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt","w",stdout);
	string s1, s2;
	cin >> s1 >> s2;
	int a = 0, b = 0;
	for(int i = 0; i < (s1.length() / 2); i++){
		char c1 = s1[i*2];
		char c2 = s2[i*2];
		char c3 = ' ';
		if (c1 == c2)
			continue;

		if(c1 == '[')
			c3 = '(';
		else if (c1 == '8')
			c3 = '[';
		else
			c3 = '8';
		if (c2 == c3)
			a++;
		else
			b++;
	}
	if (a > b){
		cout << "TEAM 1 WINS";
	}else if (a < b){
		cout << "TEAM 2 WINS";
	}else{
		cout << "TIE";
	}

}