#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v)  << #v << " = " << (v) << endl;

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; ++i)
			parent[i] = i;
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

const int MxN = (int) 1e5 + 9;
vector<int> adj[MxN + 9];

struct Edge {
	int u, v, w;

	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

int n, m;
ll f(vector<Edge> edges) {
	sort(edges.begin(), edges.end());

	ll res = 0;
	DSU dsu(n + 1);
	for (Edge e : edges)
		if (dsu.merge(e.u, e.v))
			res += e.w;

	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	vector<Edge> edges(m);
	for (auto &&e : edges)
		cin >> e.u >> e.v >> e.w;


	edges[0].w = 0;
	const ll res1 = f(edges);
	edges[0].w = (int)1e9;
	const ll res2 = f(edges);
	cout << res2 - res1;

	return 0;
}