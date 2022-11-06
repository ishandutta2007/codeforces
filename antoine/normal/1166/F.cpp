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
map<int, int> adj[MxN + 9];
set<int> dadj[MxN + 9];

DSU dsu(MxN + 9);

set<int> merge(set<int> &s1, set<int> &s2) {
	if (s1.size() > s2.size())
		swap(s1, s2);
	s2.insert(s1.begin(), s1.end());
	return move(s2);
}

void merge(int u, int v) {
	u = dsu.find(u);
	v = dsu.find(v);
	if (u == v)
		return;
	set<int> s = merge(dadj[u], dadj[v]);
	dsu.merge(u, v);
	dadj[dsu.find(u)] = move(s);
}

void addEdge(const int x, const int y, const int z) {
	if (dsu.find(x) != dsu.find(y))
		dadj[dsu.find(x)].insert(y);

	if (!adj[x].count(z)) {
		adj[x][z] = y;
	} else
		merge(adj[x][z], y);
}
void addEdges() {
	int x, y, z;
	cin >> x >> y >> z;
	addEdge(x, y, z);
	addEdge(y, x, z);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, _c, q;
	cin >> n >> m >> _c >> q;

	for (int i = 0; i < m; ++i)
		addEdges();
	while (q--) {
		char type;
		cin >> type;
		if (type == '+')
			addEdges();
		else {
			assert(type == '?');
			int x, y;
			cin >> x >> y;
			x = dsu.find(x);
			const bool ok = x == dsu.find(y) || dadj[x].count(y);
			cout << (ok ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}