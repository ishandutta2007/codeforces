#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> E(n << 2);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		for (int S = 0; S < 4; ++S) {
			for (int T = S; T < 4; ++T) {
				if ((S & T) == S) {
					int tw = w;
					if ((S ^ T) & 1) {
						tw -= w;
					}
					if ((S ^ T) & 2) {
						tw += w;
					}
					E[u << 2 | S].emplace_back(v << 2 | T, tw);
					E[v << 2 | S].emplace_back(u << 2 | T, tw);
				}
			}
		}
	}

	std::vector<bool> vis(n << 2);
	std::vector<long long> dis(n << 2, INF);
	std::priority_queue<std::pair<long long, int>> Q;
	dis[0] = 0;
	Q.emplace(0, 0);
	while (!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		for (auto [v, w] : E[u]) {
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				Q.emplace(-dis[v], v);
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		std::cout << dis[i << 2 | 3] << " ";
	}
	std::cout << "\n";
}