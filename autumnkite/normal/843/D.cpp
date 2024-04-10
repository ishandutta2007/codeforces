#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

struct edge {
	int u, v, w;

	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<edge> edge;
	std::vector<std::vector<int>> G(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		edge.emplace_back(u, v, w);
		G[u].emplace_back(i);
	}
	auto Dijkstra = [&](int s) {
		std::vector<long long> dis(n, INF);
		std::vector<bool> vis(n);
		std::priority_queue<std::pair<long long, int>> Q;
		dis[s] = 0;
		Q.emplace(0, s);
		while (!Q.empty()) {
			int u = Q.top().second;
			Q.pop();
			if (vis[u]) {
				continue;
			}
			vis[u] = true;
			for (int id : G[u]) {
				int v = edge[id].v, w = edge[id].w;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					Q.emplace(-dis[v], v);
				}
			}
		}
		return dis;
	};
	auto dis = Dijkstra(0);

	auto BFS = [&](int s, int W) {
		std::vector<long long> dis_(n, INF);
		std::vector<bool> vis(n);
		std::vector<std::vector<int>> Q(W + 1);
		dis_[s] = 0;
		Q[0].push_back(s);
		for (int k = 0; k <= W; ++k) {
			for (int i = 0; i < (int)Q[k].size(); ++i) {
				int u = Q[k][i];
				if (vis[u]) {
					continue;
				}
				vis[u] = true;
				for (int id : G[u]) {
					int v = edge[id].v, w = edge[id].w;
					if (dis_[v] > dis_[u] + w) {
						dis_[v] = dis_[u] + w;
						if (dis_[v] - dis[v] <= W) {
							Q[dis_[v] - dis[v]].push_back(v);
						}
					}
				}
			}
		}
		return dis_;
	};

	int now = 0;
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int v;
			std::cin >> v;
			--v;
			dis = BFS(0, now);
			if (dis[v] == INF) {
				std::cout << -1 << "\n";
			} else {
				std::cout << dis[v] << "\n";
			}
			now = 0;
		} else {
			int c;
			std::cin >> c;
			for (int i = 0; i < c; ++i) {
				int x;
				std::cin >> x;
				--x;
				++edge[x].w;
			}
			now += c;
		}
	}
}