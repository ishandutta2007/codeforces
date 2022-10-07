#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	std::vector<std::vector<int>> f(n);
	std::function<void(int, int)> dfs = [&](int u, int fa) {
		f[u].resize(1);
		f[u][0] = 1;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
				std::vector<int> g(std::max(f[u].size(), f[v].size() + 1));
				for (int i = 0; i < (int)f[u].size(); ++i) {
					for (int j = 0; j < (int)f[v].size(); ++j) {
						if (i + j + 1 <= m) {
							g[std::max(i, j + 1)] = (g[std::max(i, j + 1)] + 1ll * f[u][i] * f[v][j]) % P;
						}
						g[i] = (g[i] + 1ll * f[u][i] * f[v][j]) % P;
					}
				}
				f[u].swap(g);
			}
		}
	};

	dfs(0, -1);
	std::cout << std::accumulate(f[0].begin(), f[0].end(), 0ll) % P << "\n";
}