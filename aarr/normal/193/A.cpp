#include <iostream>
using namespace std;

int n, m;

int a[55][55];
int mark[55][55];
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
	if (mark[x][y] == 1)
		return;
	mark[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		if (a[x + dirx[i]][y + diry[i]])
			dfs(x + dirx[i], y + diry[i]);
	}
}
bool connected() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mark[i][j] = 0;
		}
	}
	int c, d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				c = i;
				d = j;
			}
		}
	}
	dfs(c, d);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] && !mark[i][j])
				return false;
		}
	}
	return true;
}
int main() {
	int s = 0;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == '#') {
				a[i][j] = 1;
				s++;
			}
				
		}
	}
	if (s <= 2) {
		cout << -1 << endl;
		return 0;
	}
		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 1) {
				a[i][j] = 0;
				if (!(connected())) {
					cout << 1;
					return 0;
				}
				a[i][j] = 1;
			}
		}
	}
	cout << 2;
	return 0;
}