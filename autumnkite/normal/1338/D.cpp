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

	std::vector<int> f(n), g(n);
	int ans = 0;
	std::function<void(int, int)> dfs = [&](int u, int fa) {
		std::vector<int> a, b;
		int cnt = 0;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
				a.push_back(f[v]);
				b.push_back(std::max(f[v], g[v]));
				++cnt;
			}
		}
		std::sort(a.begin(), a.end(), std::greater<int>());
		std::sort(b.begin(), b.end(), std::greater<int>());
		if (cnt == 0) {
			f[u] = 0, g[u] = 1;
			return;
		} else {
			f[u] = b[0] + cnt - 1, g[u] = a[0] + 1;
			if (cnt > 1) {
				ans = std::max(ans, a[0] + a[1] + 1);
				ans = std::max(ans, b[0] + b[1] + (int)E[u].size() - 2);
			}
		}
	};
	dfs(0, -1);
	std::cout << std::max(ans, std::max(f[0], g[0])) << "\n";
}