#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, grid[N][N];
char c;
int taken = 0, tot = 0;
vector <int> ro, col;

bool check (int x, int y) {
	int now = 0;
	for (int i = 1; i <= m; ++i) if (grid[x][i]) ++now;
	for (int i = 1; i <= n; ++i) if (i != x and grid[i][y]) ++now;
	return tot == now;
}

int main (int argc, char const *argv[]) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> c;
			if (c == '*') {
				grid[i][j] = 1;
				tot++;
				if (taken == 0) {
					ro.push_back(i);
					col.push_back(j);
					taken++;
				} else if (taken == 1) {
					if (ro[0] != i and col[0] != j) {
						ro.push_back(i);
						col.push_back(j);
						taken++;
					}
				}
			}
		}
	}
	
	if (taken == 0) {
		cout << "YES\n1 1\n";
		return 0;
	} else if (taken == 1) {
		cout << "YES\n" << ro[0] << " " << col[0] << '\n';
		return 0;
	} else {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (check(ro[i], col[j])) {
					cout << "YES\n" << ro[i] << " " << col[j] << '\n';
					return 0;
				}
			}
		}
	}
	
	cout << "NO\n";
	return 0;
}