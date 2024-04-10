#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

char c[N][N];
bool mark[N][N];


int main() {
	ios :: sync_with_stdio(false);
	int n, m, c1 = 0, c2 = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		bool b = false;
		for (int j = 1; j <= m; j++) {
			if (c[i][j] == '#' && j > 1 && b && c[i][j - 1] == '.') {
				cout << -1;
				return 0;
			}
			if (c[i][j] == '#') {
				b = true;
			}
		}
		if (b) {
			c1++;
		}
	}
	for (int j = 1; j <= m; j++) {
		bool b = false;
		for (int i = 1; i <= n; i++) {
			if (c[i][j] == '#' && i > 1 && b && c[i - 1][j] == '.') {
				cout << -1;
				return 0;
			}
			if (c[i][j] == '#') {
			//	cout << "41 " << i << " " << j << endl;
				b = true;
			}
		}
		if (b) {
			c2++;
		}
	}	
	if ((c1 == n && c2 < m) || (c1 < n && c2 == m)) {
		cout << -1;
		return 0;
	}
//	cout << "73 " << c1 << " " << c2 << endl;
	for (int i = 2; i <= n; i++) {
		bool b = false;
		for (int j = 1; j <= m; j++) {
			if (c[i][j] == '#' && c[i - 1][j] == '#') {
				b = true;
			}
		}
		if (b) {
			c1--;
		}
	}
	cout << c1;
	return 0;
}