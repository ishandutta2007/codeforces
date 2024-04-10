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
	std::function<void(int, int)> get_sz = [&](int u, int fa) {
		sz[u] = 1;
		for (int v : E[u]) {
			if (v != fa) {
				get_sz(v, u);
				sz[u] += sz[v];
			}
		}
	};
	get_sz(0, -1);
	std::vector<int> rt;
	std::vector<bool> vis(n);
	for (int x = 0; x < n; ++x) {
		int mx = n - sz[x];
		for (int v : E[x]) {
			if (sz[v] < sz[x]) {
				mx = std::max(mx, sz[v]);
			}
		}
		if (mx <= n / 2) {
			rt.push_back(x);
			vis[x] = true;
		}
	}
	std::vector<std::tuple<int, int, int>> ans;
	std::function<void(int, int, int, int, int &)> dfs = [&](int u, int fa, int rt, int fa_rt, int &ad) {
		if (u != rt) {
			ans.emplace_back(fa_rt, ad, u);
			ans.emplace_back(u, fa, rt);
			ad = u;
		}
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u, rt, fa_rt, ad);
			}
		}
	};
	for (int x : rt) {
		for (int v : E[x]) {
			if (!vis[v]) {
				int ad = v;
				dfs(v, x, v, x, ad);
				ans.emplace_back(x, ad, v);
			}
		}
	}
	std::cout << ans.size() << "\n";
	for (auto [x, v, p] : ans) {
		std::cout << x + 1 << " " << v + 1 << " " << p + 1 << "\n";
	}
}