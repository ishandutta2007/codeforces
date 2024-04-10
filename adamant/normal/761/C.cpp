#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s[n];
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int d[n + 1][2][2][2];
	memset(d, 0x3F, sizeof(d));
	d[0][0][0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int a = 0; a <= 1; a++) {
			for(int b = 0; b <= 1; b++) {
				for(int c = 0; c <= 1; c++) {
					for(int j = 0; j < m; j++) {
						int na = a || isdigit(s[i][j]);
						int nb = b || isalpha(s[i][j]);
						int nc = c || s[i][j] == '#' || s[i][j] == '*' || s[i][j] == '&';
						d[i + 1][na][nb][nc] = min(d[i + 1][na][nb][nc], d[i][a][b][c] + min(j, m - j));
					}
				}
			}
		}
	}
	cout << d[n][1][1][1] << endl;
	return 0;
}