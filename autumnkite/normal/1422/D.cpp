#include <bits/stdc++.h>

struct Node {
	int x, y, id;
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int m, n;
	std::cin >> m >> n;
	std::vector<Node> a(n + 1);
	std::cin >> a[n].x >> a[n].y;
	a[n].id = n;
	int tx, ty;
	std::cin >> tx >> ty;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}

	std::vector<std::vector<std::pair<int, int>>> E(n + 1);
	std::sort(a.begin(), a.end(), [&](Node a, Node b) {
		return a.x < b.x;
	});
	for (int i = 1; i < (int)a.size(); ++i) {
		E[a[i - 1].id].emplace_back(a[i].id, a[i].x - a[i - 1].x);
		E[a[i].id].emplace_back(a[i - 1].id, a[i].x - a[i - 1].x);
	}
	std::sort(a.begin(), a.end(), [&](Node a, Node b) {
		return a.y < b.y;
	});
	for (int i = 1; i < (int)a.size(); ++i) {
		E[a[i - 1].id].emplace_back(a[i].id, a[i].y - a[i - 1].y);
		E[a[i].id].emplace_back(a[i - 1].id, a[i].y - a[i - 1].y);
	}
	
	auto Dijkstra = [&](int s) {
		std::vector<long long> dis(n + 1, 2 * m);
		std::vector<bool> vis(n + 1);
		std::priority_queue<std::pair<long long, int>> Q;
		dis[s] = 0, Q.emplace(0, s);
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
		return dis;
	};

	auto dis = Dijkstra(n);
	std::sort(a.begin(), a.end(), [&](Node a, Node b) {
		return a.id < b.id;
	});
	long long ans = abs(a[n].x - tx) + abs(a[n].y - ty);
	for (int i = 0; i < n; ++i) {
		ans = std::min(ans, dis[i] + abs(a[i].x - tx) + abs(a[i].y - ty));
	}
	std::cout << ans << "\n";
}