#include <iostream>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

int n, m;
std::unordered_map<long long, bool> edges;
std::vector<std::pair<int, bool>> adj[100001];
int ancestor[100001];
std::pair<int, int> dist[100001] = { { 0, 0 } };

void bfs() {
	for (int i = 1; i <= n; ++i)
		dist[i].first = INT_MAX;
	std::queue<int> queue;
	dist[1].first = 0;
	queue.push(1);
	for(;;) {
		int u = queue.front();
		if (u == n)
			return;
		queue.pop();
		for (auto e : adj[u]) {
			int &v = e.first;
			bool &w = e.second;
			if (dist[v].first > dist[u].first + 1) {
				dist[v] = { dist[u].first + 1, dist[u].second + w };
				ancestor[v] = u;
				queue.push(v);
			} else if (dist[v].first == dist[u].first + 1 && dist[v].second < dist[u].second + w) {
				dist[v].second = dist[u].second + w;
				ancestor[v] = u;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m;
	edges.reserve(m << 1);
	
	int totalWorking = 0;

	for (int i = 0; i < m; ++i) {
		static int u, v, w;
		std::cin >> u >> v >> w;
		if (u > v)
			std::swap(u, v);
		totalWorking += w;
		edges[((long long)u << 32) | v] = w != 0;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	bfs();
	std::cout << totalWorking - dist[n].second + dist[n].first - dist[n].second << '\n';
	for (int i = n; i != 1; i = ancestor[i]) {
		int u = i;
		int v = ancestor[i];
		if (u > v)
			std::swap(u, v);
		auto it = edges.find(((long long)u << 32) | v);
		if (!(it->second))
			std::cout << u << ' ' << v << ' ' << 1 << '\n';
		edges.erase(it);
	}
	for (auto e : edges)
		if (e.second)
			std::cout << (int)e.first << ' ' << (e.first >> 32) << ' ' << 0 << '\n';
	return 0;
}