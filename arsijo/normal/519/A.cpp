/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
//#define x first
//#define y second
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	int white = 0, black = 0;
	int g = 8;
	while (g--) {
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'Q')
				white += 9;
			if (s[i] == 'R')
				white += 5;
			if (s[i] == 'B')
				white += 3;
			if (s[i] == 'N')
				white += 3;
			if (s[i] == 'P')
				white += 1;
			if (s[i] == 'q')
				black += 9;
			if (s[i] == 'r')
				black += 5;
			if (s[i] == 'b')
				black += 3;
			if (s[i] == 'n')
				black += 3;
			if (s[i] == 'p')
				black += 1;
		}
	}

	if(white > black)
		cout << "White";
	else if (white < black)
		cout << "Black";
	else
		cout << "Draw";

}