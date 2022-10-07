#include <bits/stdc++.h>

const int N = 1005;

int n;
char a[N][N], b[N][N];

int col[N * 2];

bool dfs(int u, int c) {
	if (col[u] != -1) {
		return col[u] == c;
	}
	col[u] = c;
	if (u <= n) {
		for (int v = 1; v <= n; ++v) {
			int nc = c ^ (a[u][v] != b[u][v]);
			if (!dfs(v + n, nc)) {
				return false;
			}
		}
	} else {
		u -= n;
		for (int v = 1; v <= n; ++v) {
			int nc = c ^ (a[v][u] != b[v][u]);
			if (!dfs(v, nc)) {
				return false;
			}
		}
	}
	return true;
}

void solve() {
	std::cin >> n;
	std::fill(col + 1, col + 1 + 2 * n, -1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> (a[i] + 1);
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> (b[i] + 1);
	}
	for (int i = 1; i <= 2 * n; ++i) {
		if (col[i] == -1) {
			if (!dfs(i, 0)) {
				std::cout << "NO\n";
				return;
			}
		}
	}
	std::cout << "YES\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}