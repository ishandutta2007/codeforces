#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;

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
			// assert(hist[x].size() <= 30 && (1 << (int )hist[x].size()) <= n);
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

struct Edge {
	int u, v, w, id;
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};
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
	for (int i = 0; i < m; ++i)
		taken[i] = dsu.merge(edges[i].u, edges[i].v, i);

	vector<pair<int, int>> ans;
	for (int i = 0; i < m; ++i)
		if (!taken[i]) {
			const int t = dsu.mergeTime(edges[i].u, edges[i].v);
			assert(taken[t]);
			ans.push_back( { edges[i].id, edges[t].w });
		}

	sort(ans.begin(), ans.end());
	for (const pair<int, int> &p : ans)
		cout << p.second << '\n';
	return 0;
}