/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

char g = '#', h = '.';
int n;

bool check(char ar[100][100]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ar[i][j] == g) {
				if (j == 0 || j == n - 1 || i > n - 3)
					return false;
				if (ar[i + 1][j] == h || ar[i + 1][j - 1] == h
						|| ar[i + 1][j + 1] == h || ar[i + 2][j] == h)
					return false;
				ar[i][j] = h;
				ar[i+1][j] = h;
				ar[i+2][j] = h;
				ar[i+1][j-1] = h;
				ar[i+1][j+1] = h;
			}
		}
	}
	return true;
}

int main() {
	//freopen("a.in", "r", stdin); freopen("a.out","w",stdout);
	cin >> n;
	char ar[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ar[i][j];
		}
	}
	if (check(ar)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}