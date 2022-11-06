#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};

const int MxN = 70;
vector<pair<int, int>> adj[MxN + 9];
int pos[MxN + 9];
int dist[MxN + 9][1 << (MxN / 4)];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, costA, costB;
	cin >> n >> m >> costA >> costB;
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back( { v, c });
		adj[v].push_back( { u, c });
	}

	{
		DSU dsu(n + 1);
		for (int i = 1; i <= n; ++i)
			for (const pair<int, int> &entry : adj[i])
				if (entry.second == costA)
					dsu.merge(i, entry.first);

		memset(pos, -1, sizeof pos);

		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (dsu.find(i) == i && dsu.size(i) >= 4) {
				DBG(i)
				pos[i] = cnt++;
			}
		assert(cnt <= MxN / 4);
		for (int i = 1; i <= n; ++i) {
			pos[i] = pos[dsu.find(i)];
			adj[i].erase(remove_if(adj[i].begin(), adj[i].end(), [&](const pair<int, int> &entry) {
				return entry.second == costB && dsu.find(i) == dsu.find(entry.first);
			}), adj[i].end());
		}
	}

	memset(dist, 120, sizeof dist);

	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;

	{
		const int mask = pos[1] == -1 ? 0 : 1 << pos[1];
		pq.push(array<int, 3> { dist[1][mask] = 0, 1, mask });
	}

	while (!pq.empty()) {
		const int d = pq.top()[0];
		const int u = pq.top()[1];
		const int mask = pq.top()[2];
		pq.pop();
		if (d > dist[u][mask])
			continue;
		for (const pair<int, int> &entry : adj[u]) {
			const int v = entry.first;
			const int w = entry.second;
			int mask2 = mask;
			if (pos[v] != -1 && pos[v] != pos[u]) {
				const int m = 1 << pos[v];
				if (mask & m)
					continue;
				mask2 |= m;
			}
			if (dist[v][mask2] > d + w) {
				dist[v][mask2] = d + w;
				pq.push(array<int, 3> { d + w, v, mask2 });
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << *min_element(begin(dist[i]), end(dist[i])) << ' ';
	return 0;
}