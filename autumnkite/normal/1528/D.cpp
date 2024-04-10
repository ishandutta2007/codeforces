#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(n, INF));
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		a[u][v] = w;
	}

	std::vector<std::vector<int>> w(n, std::vector<int>(n, INF));
	for (int u = 0; u < n; ++u) {
		for (int v = 0; v < n; ++v) {
			for (int b = 0; b < n; ++b) {
				w[u][v] = std::min(w[u][v], a[u][b] + (v + n - b) % n);
			}
		}
	}

	auto Dijkstra = [&](int s, std::vector<int> &dis) {
		dis = std::vector<int>(n, INF);
		std::vector<bool> vis(n);
		dis[s] = 0;
		for (int k = 0; k < n; ++k) {
			int u = -1;
			for (int v = 0; v < n; ++v) {
				if (!vis[v] && (u == -1 || dis[v] < dis[u])) {
					u = v;
				}
			}
			vis[u] = true;
			for (int v = 0; v < n; ++v) {
				if (!vis[v]) {
					int tw = w[u][(v - dis[u] % n + n) % n];
					dis[v] = std::min(dis[v], dis[u] + tw);
				}
			}
		}
	};

	for (int i = 0; i < n; ++i) {
		std::vector<int> dis;
		Dijkstra(i, dis);
		for (int j = 0; j < n; ++j) {
			std::cout << dis[j] << " ";
		}
		std::cout << "\n";
	}
}