#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;
ll a[MxN + 9];
set<int> adj[MxN + 9];

int Dijkstra(const int start, const int dest) {
	static ll dist[MxN + 9];
	memset(dist, 120, sizeof dist);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	pq.emplace(dist[start] = 0, start);

	while (!pq.empty()) {
		const ll du = pq.top().first;
		const int u = pq.top().second;
		pq.pop();
		if (du != dist[u])
			continue;
		if (u == dest)
			return (int) dist[u];

		for (const int v : adj[u]) {
			const int w = 1;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
	return (int) 1e9 + 9;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	n = remove(a, a + n, 0) - a;

	{
		vector<int> occ(64, 0);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 62; ++j)
				if (a[i] & (1LL << j))
					if (++occ[j] >= 3) {
						cout << 3;
						return 0;
					}
	}

	assert(n <= 500);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i] & a[j]) {
				adj[i].insert(j);
				adj[j].insert(i);
			}

	const int Inf = (int) 1e9;
	int ans = Inf;

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (adj[i].count(j)) {
				adj[i].erase(j);
				adj[j].erase(i);

				const int d = Dijkstra(i, j);
				assert(d > 1);
				ans = min(ans, d + 1);

				adj[i].insert(j);
				adj[j].insert(i);
			}

	cout << (ans >= Inf ? -1 : ans);
	return 0;
}