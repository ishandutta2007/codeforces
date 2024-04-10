#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

long long n, m, k;
std::vector<std::pair<int, long long>> adj[100001];
long long dist[100001];
bool tReachable[100001];
int ans = 0;
#define INFinity (LLONG_MAX >> 2)

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	std::cin >> n >> m >> k;
	std::fill(dist, dist + n + 1, INFinity);
	dist[1] = 0;
	for (long long i = 0; i < m; ++i) {
		static long long u, v, x;
		std::cin >> u >> v >> x;
		adj[u].push_back({ v, x });
		adj[v].push_back({ u, x });
	}
	std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<std::pair<long long, long long>>> nodes;
	nodes.push({ 0, 1 });
	for (long long i = 0; i < k; ++i) {
		static long long s, y;
		std::cin >> s >> y;
		if (!tReachable[s]) {
			tReachable[s] = true;
			dist[s] = y;
		} else {
			dist[s] = std::min(dist[s], y);
			++ans;
		}
	}
	for(int i = 1; i <= n; ++i)
		if (tReachable[i])
			nodes.push({ dist[i], i });

	while (!nodes.empty()) {
		int u = nodes.top().second;
		long long d = nodes.top().first;
		nodes.pop();
		if (d != dist[u])
			continue;
		for (auto e : adj[u]) {
			int v = e.first;
			long long w = e.second;
			d = dist[u] + w;
			if (d > dist[v])
				continue;
			if (tReachable[v]) {
				++ans;
				tReachable[v] = false;
			}
			if (d < dist[v]) {
				dist[v] = d;
				nodes.push({ d, v });
			}
		}
	}
	std::cout << ans;
	return 0;
}