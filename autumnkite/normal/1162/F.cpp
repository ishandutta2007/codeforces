#include <bits/stdc++.h>

const int N = 1005, P = 998244353;

int n;
char s[N];
int a[N];

std::vector<std::pair<int, int>> E[N * 2];
int col[N * 2];

void addEdge(int u, int v, int w) {
	E[u].push_back({v, w});
	E[v].push_back({u, w});
}

bool dfs(int u, int c) {
	if (col[u] != -1) {
		return col[u] == c;
	}
	col[u] = c;
	for (auto p : E[u]) {
		int v = p.first, w = p.second;
		if (!dfs(v, c ^ w)) {
			return false;
		}
	}
	return true;
}

int solve(int x) {
	for (int i = 0; i < 2 * n; ++i) {
		col[i] = -1;
		E[i].clear();
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] < 2) {
			addEdge(i, n + i, a[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		addEdge(n + i, n + n - i - 1, 0);
	}
	for (int i = x; i < n; ++i) {
		addEdge(i, n - (i - x) - 1, 0);
	}
	for (int i = 0; i < x; ++i) {
		if (!dfs(i, 0)) {
			return 0;
		}
	}
	if (!dfs(x, 1)) {
		return 0;
	}
	int ans = 1;
	for (int i = 0; i < 2 * n; ++i) {
		if (col[i] == -1) {
			ans = 2ll * ans % P;
			dfs(i, 0);
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> s;
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			a[i] = 2;
		} else {
			a[i] = s[i] ^ '0';
		}
	}

	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans = (ans + solve(i)) % P;
	}
	std::cout << ans << "\n";
}