#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	std::vector<int> sz(n);
	std::vector<int> id;
	long long ans = 0;
	std::function<void(int, int)> dfs = [&](int u, int fa) {
		id.push_back(u);
		sz[u] = 1;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
				sz[u] += sz[v];
				ans += std::min(n - sz[v], sz[v]) * 2;
			}
		}
	};
	dfs(0, -1);

	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[id[i]] = id[(i + n / 2) % n];
	}
	std::cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		std::cout << p[i] + 1 << " \n"[i == n - 1];
	}
}