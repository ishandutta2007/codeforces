#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct DSU {

	int n;
	vector<int> parent;
	vector<vector<int>> children; // including self
	vector<vector<int>> hist; // times when parent changed ([!] smaller component only)

	DSU(const int _n) :
			n(_n) {
		parent.resize(n);
		children.resize(n);
		hist.resize(n);
		for (int i = 0; i < n; ++i)
			children[i].push_back( { parent[i] = i });
	}

	bool merge(int u, int v, const int t) {
		if ((u = parent[u]) == (v = parent[v]))
			return false;
		if (children[u].size() < children[v].size())
			swap(u, v);
		for (const int x : children[v]) {
			parent[x] = u;
			children[u].push_back(x);
			hist[x].push_back(t);
			// hist[x].shrink_to_fit();
		}
		children[v].clear();
		return true;
	}

	int mergeTime(int u, int v) const {
		assert(u != v);
		assert(parent[u] == parent[v]);
		if (hist[u].size() > hist[v].size())
			swap(u, v);
		int lo = 0;
		int hi = (int) min(hist[u].size(), hist[v].size());
		while (lo < hi) {
			const int mid = (lo + hi) >> 1;
			if (*(hist[u].rbegin() + mid) == *(hist[v].rbegin() + mid))
				lo = mid + 1;
			else
				hi = mid;
		}
		assert(lo < (int )hist[v].size());
		int t = *(hist[v].rbegin() + lo);
		if (lo < (int) hist[u].size())
			t = max(t, *(hist[u].rbegin() + lo));
		return t;
	}
};

struct DSU2 {
	vector<int> rank;
	vector<int> parent;

	DSU2(int n) {
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

struct Edge {
	int u, v, w, id;
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

const int MxN = (int) 1e5 + 9;
vector<pair<int, int>> adj[MxN + 9];
int parent[MxN + 9];
int peId[MxN + 9];
int depth[MxN + 9];
int start[MxN + 9];
int fin[MxN + 9];

void dfs(const int u, int &t) {
	start[u] = t++;
	for (const pair<int, int> &e : adj[u]) {
		const int v = e.first;
		const int eid = e.second;
		if (v != parent[u]) {
			parent[v] = u;
			peId[v] = eid;
			depth[v] = depth[u] + 1;
			dfs(v, t);
		}
	}
	fin[u] = t++;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<Edge> edges(m);
	for (Edge &e : edges)
		cin >> e.u >> e.v >> e.w;
	for (int i = 0; i < m; ++i)
		edges[i].id = i;
	sort(edges.begin(), edges.end());

	DSU dsu(n + 1);
	vector<bool> taken(m, false);
	for (int i = 0; i < m; ++i) {
		const int u = edges[i].u;
		const int v = edges[i].v;
		if ((taken[i] = dsu.merge(u, v, i))) {
			adj[u].push_back( { v, edges[i].id });
			adj[v].push_back( { u, edges[i].id });
		}
	}

	{
		int t = 0;
		dfs(1, t);
		assert(t == 2 * n);
	}

	vector<int> ans(m, (int) 1e9);
	vector<int> anc(n + 1);
	iota(anc.begin(), anc.end(), 0);
	DSU2 dsu2(n + 1);

	for (int i = 0; i < m; ++i) {
		if (taken[i])
			continue;

		{
			const int t = dsu.mergeTime(edges[i].u, edges[i].v);
			assert(taken[t]);
			ans[edges[i].id] = edges[t].w;
		}

		int u = edges[i].u;
		int v = edges[i].v;

		for (;;) {
			u = anc[dsu2.find(u)];
			v = anc[dsu2.find(v)];
			if (u == v)
				break;
			if (depth[u] < depth[v])
				swap(u, v);
			assert(depth[u] > 0);

			ans[peId[u]] = edges[i].w;
			const int x = anc[dsu2.find(parent[u])];
			dsu2.merge(u, x);
			anc[dsu2.find(x)] = x;
		}

	}

	for (const int x : ans)
		cout << x << '\n';
	return 0;
}