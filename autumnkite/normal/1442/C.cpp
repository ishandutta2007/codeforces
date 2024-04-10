#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	int LG = 0;
	while ((1 << LG) < n) {
		++LG;
	}
	++LG;
	std::vector<std::vector<int>> E(n * LG);
	std::vector<std::vector<std::pair<int, int>>> G(n * 2);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		int tu = u, tv = v;
		for (int j = 0; j < LG; ++j) {
			E[tu * LG + j].push_back(tv * LG + j);
			if (j + 1 < LG) {
				E[tv * LG + j].push_back(tu * LG + j + 1);
			}
			std::swap(tu, tv);
		}
		G[u << 1].emplace_back(v << 1, 1);
		G[v << 1 | 1].emplace_back(u << 1 | 1, 1);
		G[v << 1].emplace_back(u << 1 | 1, n + 1);
		G[u << 1 | 1].emplace_back(v << 1, n + 1);
	}

	auto Dijkstra = [&](int s) {
		std::vector<long long> dis(n * 2, 1ll * n * n);
		std::vector<bool> vis(n * 2);
		std::priority_queue<std::pair<long long, int>> Q;
		dis[s] = 0, Q.emplace(0, s);
		while (!Q.empty()) {
			int u = Q.top().second;
			Q.pop();
			if (vis[u]) {
				continue;
			}
			vis[u] = true;
			for (auto [v, w] : G[u]) {
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					Q.emplace(-dis[v], v);
				}
			}
		}
		return dis;
	};

	std::vector<long long> disG(Dijkstra(0));

	auto BFS = [&](int s) {
		std::vector<int> dis(n * LG, n);
		std::vector<int> Q;
		dis[s] = 0;
		Q.push_back(s);
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			for (int v : E[u]) {
				if (dis[v] == n) {
					dis[v] = dis[u] + 1;
					Q.push_back(v);
				}
			}
		}
		return dis;
	};

	std::vector<int> disE(BFS(0));
	int ans = n + (1 << LG);
	for (int k = 0; k < LG; ++k) {
		if (disE[(n - 1) * LG + k] < n) {
			ans = std::min(ans, disE[(n - 1) * LG + k] + (1 << k) - 1);
		}
	}
	if (ans == n + (1 << LG)) {
		long long mn = std::min(disG[(n - 1) << 1], disG[(n - 1) << 1 | 1]);
		ans = 1;
		for (int i = 0; i < mn / n; ++i) {
			ans = ans * 2 % P;
		}
		ans = (ans + P - 1) % P;
		ans = (ans + mn % n) % P;
	}
	std::cout << ans << "\n";
}