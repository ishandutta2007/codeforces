#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Dijkstra

struct Edge {
	int v, w, i;
};

const int MaxN = (int) 3e5 + 9;
vector<Edge> adj[MaxN + 1];
ll dist[MaxN + 1];
int parent[MaxN + 1];
vector<int> edges;

void Dijkstra() {
	memset(dist, 120, sizeof dist);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.emplace(dist[1] = 0, 1);

	while (!pq.empty()) {
		const ll du = pq.top().first;
		const int u = pq.top().second;
		pq.pop();
		if (du != dist[u])
			continue;

		if (u != 1)
			edges.emplace_back(parent[u]);

		for (const auto &e : adj[u]) {
			const int v = e.v;
			const int w = e.w;
			if (dist[v] > dist[u] + w) {
				parent[v] = e.i;
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back( { v, w, i });
		adj[v].push_back( { u, w, i });
	}

	Dijkstra();

	while ((int) edges.size() > k)
		edges.pop_back();

	cout << edges.size() << '\n';

	for (const int x : edges)
		cout << x << ' ';
	return 0;

}