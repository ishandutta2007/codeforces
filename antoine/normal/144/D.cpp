#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <set>
#include <climits>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <functional>

static std::vector<std::pair<int, int>> adj[100001];
static long long dist[100001];
int n, m, s, l;

bool given(int u, int v, int w) {
	if (dist[u] == l || dist[v] == l)
		return true;
	if (dist[u] < l && l - dist[u] < w && w - (l - dist[u]) + dist[v] > l)
		return true;
	if (dist[v] < l && l - dist[v] < w && w - (l - dist[v]) + dist[u] > l)
		return true;
	if (dist[v] < l && dist[u] < l && dist[u] + dist[v] + w == 2 * l)
		return true;
	return false;
}

int dijekstra() {
	int count = 0;
	std::fill(dist + 1, dist + 1 + n, l + 1);
	//for (int i = 0; i <= n; ++i)
	//	dist[i] = l + 1;
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> nodes;
	nodes.push({ dist[s] = 0, s });
	while (!nodes.empty()) {
		int u = nodes.top().second;
		long long d = nodes.top().first;
		nodes.pop();
		if (d != dist[u])
			continue;
		if (d == l)
			count++;
		for (auto e : adj[u]) {
			int v = e.first;
			int w = e.second;
			d = dist[u] + w;
			if (d < dist[v]) {
				dist[v] = d;
				nodes.push({ d, v });
			}
		}
	}
	for (int u = 1; u <= n; ++u)
		for (auto e : adj[u]) {
			int v = e.first;
			int w = e.second;
			//if (given(u, v, w))
				//std::cout << "given\n";
		
			if (u > v)
				continue;
			if (dist[u] >= l && dist[v] >= l)
				continue;
			if (dist[u] > l || dist[v] > l) {
				++count;
			//	std::cout << "Type 1: " << u << ' ' << v << ' ' << w << '\n';
				continue;
			}
			int delta = std::abs(dist[u] - dist[v]);
			if ((w - delta) + 2 * std::max(dist[u], dist[v]) >= 2 * l) {
				//std::cout << "Type 2: " << u << ' ' << v << ' ' << w << ' ' << dist[u] << ' ' << dist[v] << '\n';
				int d1 = (dist[u] != l && dist[v] != l);
				int d2 = ((w - delta) + 2 * std::max(dist[u], dist[v]) > 2 * l);
				//std::cout << d1 << ' ' << d2 << '\n';
				count += d1 + d2;
				continue;
			}
		}
	return count;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		static int u, v, w;
		std::cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	std::cin >> l;
	std::cout << dijekstra();
	return 0;
}