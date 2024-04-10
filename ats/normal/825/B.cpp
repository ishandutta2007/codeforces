#include <bits/stdc++.h>
using namespace std;
int dx[4] = { 1,0,1,-1 };
int dy[4] = { 0,1,1,1 };
bool check(string s[10]) {
	int x, y;
	bool f;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 4; k++) {
				f = true;
				for (int t = 0; t < 5; t++) {
					x = i + dx[k] * t;
					y = j + dy[k] * t;
					if ((x >= 0) && (x < 10) && (y >= 0) && (y < 10) && (s[x][y]=='X')) {
						
					}
					else {
						f = false;
					}
				}
				if (f)return true;
			}
		}
	}
	return false;
}
int main() {
	string s[10];
	for (int i = 0; i < 10; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (s[i][j] == '.') {
				s[i][j] = 'X';
				if (check(s)) {
					cout << "YES" << endl;
					return 0;
				}
				s[i][j] = '.';
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}