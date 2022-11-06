#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <unordered_set>

int n, m;
std::vector<std::pair<long long, int>> adj[100001];
std::unordered_set<int> times[100001];
std::pair<int, int> dist[100001];

int dijkstra() {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> nodes;
	std::memset(dist, 127, sizeof dist);
	dist[1] = { 0, 0 };
	while (times[1].count(dist[1].second))
		++dist[1].second;
	nodes.push({ dist[1].second, 1 });
	while (!nodes.empty()) {
		int u = nodes.top().second;
		if (u == n)
			return dist[n].first;
		int d = nodes.top().first;
		nodes.pop();
		if (d != dist[u].second)
			continue;
		for (auto e : adj[u]) {
			int v = e.first;
			int w = e.second;
			d = dist[u].second + w;
			if (d >= dist[v].first)
				continue;
			int oldFirst = dist[v].first;
			dist[v].first = d;
			while (times[v].count(d))
				if (++d >= oldFirst)
					break;
			if (d < oldFirst)
				nodes.push({ dist[v].second = d, v });
		}
	}
	return -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		static int a, b, c;
		std::cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; ++i) {
		static int k;
		std::cin >> k;
		times[i].reserve(k << 2);
		for (; k > 0; --k) {
			static int time;
			std::cin >> time;
			times[i].insert(time);
		}
	}
	std::cout << dijkstra();
	return 0;
}