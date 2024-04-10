#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::array<int, 2>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i][0] >> a[i][1];
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	std::vector<std::array<long long, 2>> f(n);

	std::function<void(int, int)> dfs = [&](int u, int fa) {
		f[u][0] = f[u][1] = 0;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
				for (int i = 0; i < 2; ++i) {
					f[u][i] += std::max(f[v][0] + abs(a[u][i] - a[v][0]), f[v][1] + abs(a[u][i] - a[v][1]));
				}
			}
		}
	};

	dfs(0, -1);
	std::cout << std::max(f[0][0], f[0][1]) << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}