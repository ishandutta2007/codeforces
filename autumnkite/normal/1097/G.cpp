#include <bits/stdc++.h>

const int P = 1000000007;

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

	std::vector<std::vector<int>> S(m + 1, std::vector<int>(m + 1));
	S[0][0] = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= i; ++j) {
			S[i][j] = (S[i - 1][j - 1] + 1ll * S[i - 1][j] * j) % P;
		}
	}

	std::vector<int> sz(n);
	std::vector<int> ans(m + 1);
	std::vector<std::vector<int>> f(n);
	std::function<void(int, int)> dfs = [&](int u, int fa) {
		f[u].resize(1);
		f[u][0] = 2;
		sz[u] = 1;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
				std::vector<int> g(std::min(sz[u] + sz[v], m + 1));
				for (int i = 0; i < std::min(sz[u], m + 1); ++i) {
					for (int j = 0; j <= std::min(sz[v], m - i); ++j) {
						g[i + j] = (g[i + j] + 1ll * f[u][i] * f[v][j]) % P;
					}
				}
				for (int i = 0; i <= std::min(sz[v], m); ++i) {
					ans[i] = (ans[i] + P - f[v][i]) % P;
				}
				f[u].swap(g);
				sz[u] += sz[v];
			}
		}
		for (int i = 0; i < std::min(sz[u], m + 1); ++i) {
			ans[i] = (ans[i] + f[u][i]) % P;
		}
		f[u].resize(std::min(sz[u], m) + 1);
		for (int i = std::min(sz[u], m); i >= 1; --i) {
			f[u][i] = (f[u][i] + f[u][i - 1]) % P;
		}
		f[u][1] = (f[u][1] + P - 1) % P;
	};
	dfs(0, -1);
	int fac = 1, Ans = 0;
	for (int i = 0; i <= m; ++i) {
		if (i > 0) {
			fac = 1ll * fac * i % P;
		}
		Ans = (Ans + 1ll * ans[i] * S[m][i] % P * fac) % P;
	}
	std::cout << Ans << "\n";
}