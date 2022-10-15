/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	string s[4];
	for (int i = 0; i < 4; i++)
		cin >> s[i];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int white = 0, black = 0;
			if (s[i][j] == '.')
				white++;
			else
				black++;
			if (s[i + 1][j] == '.')
				white++;
			else
				black++;
			if (s[i][j + 1] == '.')
				white++;
			else
				black++;
			if (s[i + 1][j + 1] == '.')
				white++;
			else
				black++;
			if (max(white, black) >= 3){
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}