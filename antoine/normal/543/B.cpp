#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <queue>

int n, m;
int s1, t1, l1, s2, t2, l2;
std::vector<int> adj[3000];
int dist[3000][3000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		static int a, b;
		std::cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	std::cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	--s1; --t1; --s2; --t2;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = INT_MAX;

	for (int i = 0; i < n; ++i) {
		std::queue<int> nodes;
		dist[i][i] = 0;
		nodes.push(i);
		while (!nodes.empty()) {
			int u = nodes.front();
			nodes.pop();
			for (int v : adj[u]) {
				if (dist[i][v] == INT_MAX) {
					dist[i][v] = dist[i][u] + 1;
					nodes.push(v);
				}
			}
		}
	}

	if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
		std::cout << -1;
		return 0;
	}
	int count = dist[s1][t1] + dist[s2][t2];
	for (int u = 1; u < n; ++u)
		for (int v = 0; v < u; ++v) {
			int c = dist[u][v];
			int e1 = std::min(dist[s1][u] + dist[v][t1], dist[s1][v] + dist[u][t1]);
			if (e1 + c > l1) continue;
			int e2 = std::min(dist[s2][u] + dist[v][t2], dist[s2][v] + dist[u][t2]);
			if (e2 + c > l2) continue;
			count = std::min(count, e1 + e2 + c);
		}
	std::cout << m - count;
	return 0;
}