#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		E[u].emplace_back(v, w);
	}

	int idx = 0;
	std::vector<int> dfn(n, -1), low(n);
	std::vector<int> sta;
	std::vector<bool> vis(n);
	int cnt = 0;
	std::vector<int> col(n);
	std::vector<long long> dis(n), g(n);
 
	std::function<void(int)> tarjan = [&](int u) {
		dfn[u] = low[u] = idx++;
		sta.push_back(u), vis[u] = true;
		g[u] = 0;
		for (auto p : E[u]) {
			int v = p.first, w = p.second;
			if (dfn[v] == -1) {
				dis[v] = dis[u] + w;
				tarjan(v);
				low[u] = std::min(low[u], low[v]);
			} else if (vis[v]) {
				low[u] = std::min(low[u], dfn[v]);
				g[u] = std::__gcd(g[u], dis[u] - dis[v] + w);
			}
		}
		if (dfn[u] == low[u]) {
			int v = -1;
			while (v != u) {
				v = sta.back();
				sta.pop_back();
				vis[v] = false;
				col[v] = cnt;
			}
			++cnt;
		}
	};
 
	for (int i = 0; i < n; ++i) {
		if (dfn[i] == -1) {
			dis[i] = 0;
			tarjan(i);
		}
	}
	std::vector<long long> ans(cnt);
	for (int i = 0; i < n; ++i) {
		ans[col[i]] = std::__gcd(ans[col[i]], g[i]);
	}

	int q;
	std::cin >> q;
	while (q--) {
		int u;
		long long s, t;
		std::cin >> u >> s >> t;
		--u;
		if (s % std::__gcd(t, ans[col[u]]) == 0) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}