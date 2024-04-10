#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>

// 10:25

int n, m, u;
std::vector<std::tuple<int, int, long long>> adj[300001];
std::pair<int, long long> prev[300001] = { {0, 0} };
long long dist[300001];

void dijkstra() {
	std::memset(dist, 127, sizeof dist);
	std::priority_queue <std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> nodes;
	nodes.push({ dist[u] = 0, u });
	while (!nodes.empty()) {
		int u = nodes.top().second;
		long long d = nodes.top().first;
		nodes.pop();
		if (d != dist[u])
			continue;
		for (auto e : adj[u]) {
			const int &id = std::get<0>(e);
			const int &v = std::get<1>(e);
			const long long &w = std::get<2>(e);
			d = dist[u] + w;
			if (d > dist[v])
				continue;
			if (d < dist[v]) {
				dist[v] = d;
				nodes.push({ d, v });
				prev[v] = { id, w };
				continue;
			}
			if (prev[v].first == 0 || w < prev[v].second)
				prev[v] = { id, w };
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		static int u, v;
		static long long w;
		std::cin >> u >> v >> w;
		adj[u].push_back({ i, v, w });
		adj[v].push_back({ i, u, w });
	}
	std::cin >> u;
	dijkstra();
	long long length = 0;
	for (int i = 1; i <= n; ++i)
		length += prev[i].second;
	std::cout << length << '\n';
	for (int i = 1; i <= n; ++i)
		if (prev[i].first != 0)
			std::cout << prev[i].first << ' ';
	return 0;
}