#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 7, MAXCOMP = 1000 * 1000 + 7;

char c[MAXN][MAXN];
bool used[MAXN][MAXN];
int cmp[MAXN][MAXN];
int comp[MAXCOMP];
int cur;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool check(int a, int b) {
	return (0 <= a && 0 <= b && a < n && b < m);
}

void dfs(int x, int y) {
	cmp[x][y] = cur;
	used[x][y] = true;
	for (int t = 0; t < 4; t++) {
		if (check(x + dx[t], y + dy[t])) {
			if (c[x + dx[t]][y + dy[t]] == '*') {
				comp[cur]++;
			} else if (!used[x + dx[t]][y + dy[t]]) {
				dfs(x + dx[t], y + dy[t]);
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	int q, a, b;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '.' && !used[i][j]) {
				cur++;
				dfs(i, j);
			}
		}
	}
	while (q--) {
		cin >> a >> b;
		a--, b--;
		cout << comp[cmp[a][b]] << endl;
	}
}