#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 1e5;

vector<pair<int, int>> adj[MaxN + 1];
ll dist[MaxN + 1];
int parent[MaxN + 1]; // shortest path tree parent

void Dijkstra(const int start) {
	memset(dist, 120, sizeof dist);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.emplace(dist[start] = 0, start);

	while (!pq.empty()) {
		const ll du = pq.top().first;
		const int u = pq.top().second;
		pq.pop();
		if (du != dist[u])
			continue;

		for (const pair<int, int> &e : adj[u]) {
			const int v = e.first;
			const int w = e.second;
			if (dist[v] > dist[u] + w) {
				parent[v] = u;
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	Dijkstra(1);
	if (!parent[n])
		cout << "-1\n";
	else {
		int u = n;
		vector<int> path = {n};
		while (parent[u])
			path.push_back(u = parent[u]);
		assert(u == 1);
		reverse(path.begin(), path.end());
		for(auto &&x : path)
			cout << x <<  ' ';
	}
	return 0;
}