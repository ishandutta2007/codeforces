#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::map<int, int> all;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		++all[a[i]];
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	std::vector<int> fa(n);
	std::vector<bool> f(n), g(n);
	std::vector<std::map<int, int>> mp(n);

	auto merge = [&](std::map<int, int> &A, std::map<int, int> &B) {
		if (A.size() < B.size()) {
			A.swap(B);
		}
		for (auto p : B) {
			A[p.first] += p.second;
		}
		B.clear();
	};

	std::function<void(int)> dfs = [&](int u) {
		f[u] = true;
		for (int v : E[u]) {
			if (v != fa[u]) {
				fa[v] = u;
				dfs(v);
				f[u] = f[u] && f[v];
				g[v] = mp[v][a[u]] == all[a[u]] - 1;
				merge(mp[u], mp[v]);
			}
		}
		++mp[u][a[u]];
		f[u] = f[u] && mp[u][a[u]] == 1;
	};

	fa[0] = -1, dfs(0);

	std::function<void(int)> get_g = [&](int u) {
		int cnt = !g[u];
		for (int v : E[u]) {
			if (v != fa[u]) {
				cnt += !f[v];
			}
		}
		for (int v : E[u]) {
			if (v != fa[u]) {
				fa[v] = u;
				g[v] = g[v] && cnt - !f[v] == 0;
				get_g(v);
			}
		}
	};

	g[0] = true, get_g(0);
	
	int ans = 0;
	for (int u = 0; u < n; ++u) {
		ans += f[u] && g[u] && all[a[u]] == 1;
	}
	std::cout << ans << "\n";
}