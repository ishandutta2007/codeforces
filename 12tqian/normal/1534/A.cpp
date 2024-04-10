#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	int t = 0;
	for (int i = 0; i < n; ++i) {
		string line;
		cin >> line;
		for (int j = 0; j < m; ++j) {
			if (line[j] == '.') {	
				g[i][j] = 0;
			} else if (line[j] == 'R') {
				t = (i + j) % 2;
				g[i][j] = -1;
			} else {
				t = (i + j) % 2;
				t ^= 1;
				g[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((i + j) % 2 == t) {
				if (g[i][j] == 1) {
					cout << "NO" << '\n';
					return;
				} else if (g[i][j] == -1) {

				} else {
					g[i][j] = -1;
				}
			} else {
				if (g[i][j] == 1) {

				} else if (g[i][j] == -1) {
					cout << "NO" << '\n';
					return;
				} else {
					g[i][j] = 1;
				}
			}
		}
	}
	cout << "YES" << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == -1) {
				cout << "R";
			} else {
				cout << "W";
			}
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; 
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc); 
	}
	return 0;
}