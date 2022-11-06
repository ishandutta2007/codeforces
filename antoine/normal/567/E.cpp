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

int n, m;

void dijekstra(int s, int t, std::vector<std::pair<int, int>> adj[], long long dist[], std::set<std::tuple<int, int, int>> * unique = nullptr) {
	std::fill(dist + 1, dist + 1 + n, LLONG_MAX >> 2);
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> nodes;
	nodes.push({ dist[s] = 0 , s });
	while (!nodes.empty()) {
		int u = nodes.top().second;
		long long d = nodes.top().first;
		if (u == t)
			break;
		nodes.pop();
		if (d != dist[u])
			continue;
		for (auto e : adj[u]) {
			int v = e.first;
			int w = e.second;
			d = dist[u] + w;
			if (d < dist[v]) {
				dist[v] = d;
				nodes.push({ d, v });
				if (unique != nullptr && nodes.size() == 1 && adj[u].size() == 1)
					unique->insert({ u, v, w });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	static int s, t;
	std::cin >> n >> m >> s >> t;
	static std::vector<std::pair<int, int>> adj[100001];
	static std::vector<std::pair<int, int>> adj_t[100001];
	struct Edge { int u, v, w; };
	static Edge edges[100000];
	for (int i = 0; i < m; ++i) {
		std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
		adj[edges[i].u].push_back({ edges[i].v, edges[i].w });
		adj_t[edges[i].v].push_back({ edges[i].u, edges[i].w });
	}
	static long long distS[100001];
	static long long distT[100001];
	dijekstra(s, t, adj, distS);
	dijekstra(t, s, adj_t, distT);
	static std::vector<std::pair<int, int>> adj_o[100001];
	static long long distO[100001];
	static std::set<std::tuple<int, int, int>> unique;
	for (int i = 0; i < m; ++i) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		if (distS[u] + w + distT[v] == distS[t])
			adj_o[u].push_back({ v, w });
	}
	dijekstra(s, t, adj_o, distO, &unique);
	for (int i = 0; i < m; ++i) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		if (unique.count({ u, v, w })) {
			std::cout << "YES\n";
			continue;
		}
		long long change = distS[u] + distT[v] + w - distS[t] + 1;
		if (change >= w)
			std::cout << "NO\n";
		else
			std::cout << "CAN " << change << '\n';
	}
	return 0;
}