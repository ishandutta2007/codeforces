#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

struct Edge {
	int u, v, w;
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

namespace DSU {
	int n;
	int parent[(int)1e5];

	void init(int _n) {
		n = _n;
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(int u) {
		return parent[u] == u ? u : parent[u] = find(parent[u]);
	}

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		if (rand() & 1) swap(u, v);
		parent[u] = v;
		return true;
	}
};

int n, m, k = 0;
vector<Edge> gAdj[(int)1e5];
vector<Edge> tAdj[(int)1e5];
ll gDist[25][(int)1e5];
ll tDist[(int)1e5];
vector<int> parent[(int)1e5];
int depth[(int)1e5];
Edge edges[(int)1e5];


void MST() {
	sort(edges, edges + m);

	DSU::init(n);

	for (int i = 0; i < m; ++i) {
		const int u = edges[i].u;
		const int v = edges[i].v;
		const int w = edges[i].w;
		if (!DSU::merge(u, v))
			edges[k++] = edges[i];
		else {
			tAdj[u].push_back({ u, v, w });
			tAdj[v].push_back({ v, u, w });
		}
	}

	assert(k == m - (n - 1));
}

void Dijkstra(const int start, ll dist[]) {
	fill(dist, dist + m, 1LL << 50);
	priority_queue<pair<ll, int>> pq;
	pq.emplace(dist[start] = 0, start);
	while (!pq.empty()) {
		const int u = pq.top().second;
		assert(pq.top().first >= dist[u]);
		if (pq.top().first != dist[u]) {
			pq.pop();
			continue;
		}
		pq.pop();
		for (const Edge &e : gAdj[u]) {
			assert(u == e.u);
			const int &v = e.v;
			const int &w = e.w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
}

void dfs(const int u) {
	for (const Edge &e : tAdj[u]) {
		assert(e.u == u);
		const int &v = e.v;
		if (!parent[u].empty() && v == parent[u][0]) continue;
		tDist[v] = tDist[u] + e.w;
		depth[v] = depth[u] + 1;

		parent[v] = { u };
		for (int i = 0; i < parent[parent[v][i]].size(); ++i)
			parent[v].push_back(parent[parent[v][i]][i]);

		dfs(v);
	}
}

int lca(int u, int v) {
	int diff = depth[u] - depth[v];
	if (diff < 0) {
		swap(u, v);
		diff = -diff;
	}
	for (int i = 0; diff; ++i)
		if (diff & (1 << i)) {
			diff ^= 1 << i;
			u = parent[u][i];
		}

	if (u == v)
		return u;

	for (int i = parent[u].size() - 1; i >= 0; --i)
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
			i = min(i, (int)parent[u].size());
		}

	return parent[u][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		edges[i] = { u, v, w };
		gAdj[u].push_back({ u, v, w });
		gAdj[v].push_back({ v, u, w });
	}


	MST();
	for (int i = 0; i < k; ++i)
		Dijkstra(edges[i].u, gDist[i]);
	
	tDist[0] = depth[0] = 0;
	dfs(0);

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;

		ll ans = tDist[u] + tDist[v] - 2 * tDist[lca(u, v)];
		for (int i = 0; i < k; ++i)
			ans = min(ans, gDist[i][u] + gDist[i][v]);

		cout << ans << '\n';
	}
	return 0;
}