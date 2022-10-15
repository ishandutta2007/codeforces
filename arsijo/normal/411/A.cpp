/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	//65 90 97 122 48
	string s;
	cin >> s;
	bool isNum = false, isSmall = false, isBig = false;
	for(int i = 0; i < s.length(); i++){
		int a = s[i];
		if (a >= 48 && a <= 57)
			isNum = true;
		if (a >= 65 && a <= 90)
			isBig = true;
		if (a >= 97 && a <= 122)
			isSmall = true;
	}

	if(s.length() >= 5 && isSmall && isBig && isNum)
		cout << "Correct";
	else
		cout << "Too weak";

}