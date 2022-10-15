//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int r, c;
	cin >> r >> c;
	bool ar[r][c];
	bool b1[r];
	bool b2[c];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			ar[i][j] = false;
	for (int i = 0; i < r; i++)
		b1[i] = false;
	for (int j = 0; j < c; j++)
		b2[j] = false;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == 'S') {
				b1[i] = true;
				b2[j] = true;
			}
		}
	}
	long sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!b2[j]) {
				for (int x = 0; x < r; x++) {
					if (!ar[x][j]) {
						ar[x][j] = true;
						sum++;
					}
				}
			}
			if (!b1[i]) {
				for (int y = 0; y < c; y++) {
					if (!ar[i][y]) {
						ar[i][y] = true;
						sum++;
					}
				}
			}
		}

	}
	cout << sum;

}