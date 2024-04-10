#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> G(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	std::vector<std::vector<int>> dis(n, std::vector<int>(n, n));
	auto bfs = [&](int s) {
		std::vector<int> Q(1, s);
		dis[s][s] = 0;
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			for (int v : G[u]) {
				if (dis[s][v] == n) {
					dis[s][v] = dis[s][u] + 1;
					Q.push_back(v);
				}
			}
		}
	};
	for (int i = 0; i < n; ++i) {
		bfs(i);
	}

	std::vector<std::vector<int>> f(n, std::vector<int>(n));
	for (int s = 0; s < n; ++s) {
		for (int t = s; t < n; ++t) {
			std::vector<bool> vis(n);
			int u = t;
			bool flag = true;
			while (u != s) {
				vis[u] = true;
				int cnt = 0, id = 0;
				for (int v : G[u]) {
					if (dis[s][v] + 1 == dis[s][u]) {
						++cnt;
						id = v;
					}
				}
				if (cnt != 1) {
					flag = false;
					break;
				}
				u = id;
			}
			if (!flag) {
				continue;
			}
			vis[u] = true;
			int ans = 1;
			for (int u = 0; u < n; ++u) {
				if (!vis[u]) {
					int cnt = 0;
					for (int v : G[u]) {
						if (dis[s][v] + 1 == dis[s][u] && dis[t][v] + 1 == dis[t][u]) {
							++cnt;
						}
					}
					ans = 1ll * ans * cnt % P;
				}
			}
			f[s][t] = f[t][s] = ans;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << f[i][j] << " ";
		}
		std::cout << "\n";
	}
}