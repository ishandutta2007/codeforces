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

using namespace std; // E

template<class T, class U> struct LazyST {
	int n;
	int stOffset;
	int stHi;
	vector<T> st;
	vector<U> lazy;

	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		lazy.resize(st.size());
		stHi = st.size() - 1 - stOffset;
	}

	LazyST(const int n, istream &in) : LazyST(n) { // O(n)
		for (int i = 0; i < n; ++i)
			in >> st[i + stOffset];
		for (int si = stOffset - 1; si; --si)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
	}

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = U(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = U(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = U();
	}

	T query(const int i, const int j, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (i <= lo && hi <= j)
			return st[si];
		auto mid = (lo + hi) >> 1;
		if (j <= mid)
			return query(i, j, si << 1, lo, mid);
		if (mid < i)
			return query(i, j, si << 1 | 1, mid + 1, hi);
		return T(query(i, j, si << 1, lo, mid), query(i, j, si << 1 | 1, mid + 1, hi));
	}

	T query(const int i, const int j) {
		return (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : T();
	}

	void update(const int i, const int j, const U &u, const int si, const int lo, const int hi) {
		if (i <= lo && hi <= j) {
			lazy[si] = U(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < i || j < lo)
				return;
			int mid = (lo + hi) >> 1;
			update(i, j, u, si << 1, lo, mid);
			update(i, j, u, si << 1 | 1, mid + 1, hi);
			st[si] = T(st[si << 1], st[si << 1 | 1]);
		}
	}

	void update(const int i, const int j, const U u) {
		if (i <= j)
			update(i, j, u, 1, 0, stHi);
	}

	// remove and return all non-zero values in a range, assuming all values >= 0
	void remAll(const int i, const int j, const int si, const int lo, const int hi, vector<int> &res) {
		updateLazy(si, lo, hi);
		if (!st[si] || hi < i || j < lo)
			return;
		if (lo == hi) {
			res.push_back(si - stOffset);
			st[si] = 0;
		}
		else {
			int mid = (lo + hi) >> 1;
			remAll(i, j, si << 1, lo, mid, res);
			remAll(i, j, si << 1 | 1, mid + 1, hi, res);
			st[si] = T(st[si << 1], st[si << 1 | 1]);
		}
	}

	vector<int> remAll(const int i, const int j) { // ^^
		vector<int> res;
		remAll(i, j, 1, 0, stHi, res);
		return res;
	}

	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			int mid = (lo + hi) >> 1;
			updateAllLazy(si >> 1, lo, mid);
			updateAllLazy(si >> 1 | 1, mid + 1, hi);
		}
	}

	void updateAllLazy() {
		updateAllLazy(1, 0, stHi);
	}

	const T * const retreive() {
		updateAllLazy();
		return &st[stOffset];
	}

	vector<T> retreiveVector() {
		updateAllLazy();
		return vector<T>(&st[stOffset], &st[stOffset + n]);
	}
};

struct StVal { // define
	long long v = 0;
	StVal() {}
	StVal(const long long v) : v(v) {}
	StVal(const StVal &v1, const StVal &v2) {
		v = v1 + v2;
	}
	operator long long() const {
		return v;
	}
};

struct StUpdate { // define
	long long v = 0;
	StUpdate() {}
	StUpdate(const long long v) : v(v) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		v = u1 + u2;
	}
	operator long long() const {
		return v;
	}
	void apply(StVal &v, const int lo, const int hi) {
		v.v += this->v * (hi - lo + 1);
	}
};

struct Path {
	int u, v, w;
	bool operator<(const Path &other) const { return w < other.w; }
};

struct Graph;
struct Tree;
struct GraphInfo;

struct Graph {
	vector<vector<int>> adj;
	Graph(const int);
	void addBidirectionalEdges(vector<pair<int, int>>);
	void addDirectionalEdges(vector<pair<int, int>>);
	Graph transpose();
	friend Graph intersection(const Graph, const Graph);
	friend Graph merge(const Graph, const Graph);
	void dfsInfo(int, GraphInfo &, int &, vector<int> &, stack<int> &);
	GraphInfo dfsInfo(int);
	void filterNodes(vector<int> &);
	void remNodes(vector<int> &);
	void print(ostream &);
};

struct Tree : public Graph { // directed or undirected
	int root;
	vector<int> depth;
	vector<vector<int>> parent;
	Tree(int n, int root) : Graph(n), root(root) {}
	void dfsPrec(const int u, const int p); // pre-compute depth[] and parent[][]
	void dfsPrec(); // ^^
	int lca(int u, int v);
	int lca2(int u, int v);
	int dist(const int u, const int v);
	int dfsDiam(int u, int p, Path &path); // find diameter of tree, return deepest node
	Path dfsDiam();
};

struct GraphInfo {
	vector<int> disc;
	vector<int> fin;
	vector<int> parent;
	Graph * Gptr;
	vector<int> reachable;
	Tree tree;
	vector<int> comp;
	vector<vector<int>> comps;
	GraphInfo(Graph *, int, int);
};

Graph::Graph(const int n) {
	adj.resize(n);
}

void Graph::addBidirectionalEdges(vector<pair<int, int>> edges) {
	for (auto &&e : edges) {
		adj[e.first].push_back(e.second);
		adj[e.second].push_back(e.first);
	}
}

void Graph::addDirectionalEdges(vector<pair<int, int>> edges) {
	for (auto &&e : edges)
		adj[e.first].push_back(e.second);
}

Graph Graph::transpose() {
	Graph res(adj.size());
	for (int u = 0; u < adj.size(); ++u)
		for (auto &&v : adj[u])
			res.adj[v].push_back(u);
	return res;
}

Graph intersection(const Graph G1, const Graph G2) {
	Graph G3(min(G1.adj.size(), G2.adj.size()));
	for (int i = 0; i < G3.adj.size(); ++i) {
		set<int> s(G2.adj[i].begin(), G2.adj[i].end());
		for (auto &&x : G1.adj[i])
			if (s.count(x))
				G3.adj[i].push_back(x);
	}
	return G3;
}

Graph merge(const Graph G1, const Graph G2) {
	Graph G3(max(G1.adj.size(), G2.adj.size()));
	for (int i = 0; i < G3.adj.size(); ++i) {
		if (i >= G1.adj.size())
			G3.adj[i] = G2.adj[i];
		else if (i >= G2.adj.size())
			G3.adj[i] = G2.adj[i];
		else {
			set<int> s(G1.adj[i].begin(), G1.adj[i].end());
			s.insert(G2.adj[i].begin(), G2.adj[i].end());
			G3.adj[i] = vector<int>(s.begin(), s.end());
		}
	}
	return G3;
}

void Graph::filterNodes(vector<int> &nodes) {
	vector<bool> occ(adj.size());
	set<int> s(nodes.begin(), nodes.end());
	for (int i = 0; i < adj.size(); ++i)
		if (!s.count(i))
			adj[i].clear();
	for (int i = 0; i < adj.size(); ++i) {
		adj[i].erase(remove_if(adj[i].begin(), adj[i].end(), [&](const int &x) {
			return !s.count(x);
		}), adj[i].end());
	}
}

void Graph::remNodes(vector<int> &nodes) {
	for (auto &&x : nodes)
		adj[x].clear();
	set<int> s(nodes.begin(), nodes.end());
	for (int i = 0; i < adj.size(); ++i)
		adj[i].erase(remove_if(adj[i].begin(), adj[i].end(), [&](const int &x) {
		return s.count(x);
	}), adj[i].end());
}

void Graph::dfsInfo(const int u, GraphInfo &info, int &t, vector<int> &low, stack<int> &st) {
	info.disc[u] = t++;
	info.reachable.push_back(u);
	st.push({ low[u] = u });

	for (auto &&v : adj[u])
		if (info.disc[v] == -1) {
			info.parent[v] = u;
			info.tree.adj[u].push_back(v);
			dfsInfo(v, info, t, low, st);
			low[u] = min(low[u], low[v]);
		}
		else if (info.comp[v] == -1)
			low[u] = min(low[u], info.disc[v]);

	if (low[u] == info.disc[u]) {
		info.comp[u] = info.comps.size();
		info.comps.push_back({ u });
		while (st.top() != u) {
			info.comps.back().push_back(st.top());
			info.comp[st.top()] = info.comp[u];
			st.pop();
		}
		st.pop();
	}
	info.fin[u] = t - 1;
}

GraphInfo Graph::dfsInfo(const int root) {
	GraphInfo info(this, adj.size(), root);

	int t = 0;
	vector<int> low(adj.size(), -1); // for scc
	stack<int> st;

	if (root != -1)
		dfsInfo(root, info, t, low, st);
	else
		for (int i = 0; i < adj.size(); ++i)
			if (info.disc[i] == -1)
				dfsInfo(i, info, t, low, st);
	return info;
}

void Graph::print(ostream &out) {
	out << "Graph edges:\n";
	for (int i = 0; i < adj.size(); ++i) {
		for (auto &&j : adj[i]) {
			out << i << " -> " << j << '\n';
		}
	}
}

void Tree::dfsPrec(const int u, const int p) {
	for (auto &&v : adj[u])
		if (v != p) {
			depth[v] = depth[u] + 1;
			parent[v] = { u };
			for (int i = 0; i < parent[parent[v][i]].size(); ++i)
				parent[v].push_back(parent[parent[v][i]][i]);
			dfsPrec(v, u);
		}
}

void Tree::dfsPrec() {
	depth.resize(adj.size());
	parent.resize(adj.size());
	depth[root] = 0;
	dfsPrec(root, -1);
}

int Tree::lca(int u, int v) {
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

int Tree::lca2(int u, int v) {
	auto w = lca(u, v);
	for (int i = parent[u].size() - 1; i >= 0; --i)
		if (depth[parent[u][i]] > depth[w]) {
			u = parent[u][i];
			i = min(i, (int)parent[u].size());
		}
	return u;
}

int Tree::dist(const int u, const int v) {
	return depth[u] + depth[v] - (depth[lca(u, v)] << 1);
}

// find diameter of tree, return deepest node
int Tree::dfsDiam(int u, int p, Path &path) {
	int best = u, secondBest = u;
	for (auto &&v : adj[u])
		if (v != p) {
			v = dfsDiam(v, u, path);
			if (depth[v] >= depth[best]) {
				secondBest = best;
				best = v;
			}
			else if (depth[v] > depth[secondBest])
				secondBest = v;
		}
	path = max(path, { secondBest, best, depth[best] + depth[secondBest] - (depth[u] << 1) });
	return best;
}

Path Tree::dfsDiam() {
	Path path = { 0, 0, 0 };
	dfsDiam(0, -1, path);
	return path;
}

GraphInfo::GraphInfo(Graph * Gptr, const int n, const int root) : Gptr(Gptr), tree(n, root) {
	disc.resize(n, -1);
	fin.resize(n, -1);
	parent.resize(n, -1);
	comp.resize(n, -1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	Tree T(n, 0);

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		T.adj[u].push_back(v);
		T.adj[v].push_back(u);
	}

	T.dfsPrec();
	auto info = T.dfsInfo(0);


	LazyST<StVal, StUpdate> st(n);
	for (int i = 0; i < n; ++i)
		st.update(info.disc[i], info.disc[i], a[i]);

	int root = 0;
	while (q-- > 0) {
		int type;
		cin >> type;

		switch (type) {
		case 1:
			cin >> root;
			--root;
			break;
		case 2:
			int u, v, x;
			cin >> u >> v >> x;
			--u; --v;
			if (T.dist(u, v) == T.dist(u, root) + T.dist(root, v))
				st.update(0, n - 1, x);
			else {
				int w = T.lca(u, v);
				if (info.disc[w] <= info.disc[root] && info.fin[root] <= info.fin[w]) { // below
					int o1 = T.lca2(root, u);
					int o2 = T.lca2(root, v);
					int o = T.depth[o1] > T.depth[o2] ? o1 : o2;
					st.update(0, n - 1, x);
					st.update(info.disc[o], info.fin[o], -x);
				}
				else { // above
					st.update(info.disc[w], info.fin[w], x);
				}
			}
			break;
		case 3:
			cin >> v;
			--v;
			if (root == v)
				cout << st.query(0, n - 1) << '\n';
			else if (info.disc[v] <= info.disc[root] && info.fin[root] <= info.fin[v]) {
				int o = T.lca2(root, v);
				cout << st.query(0, n - 1) - st.query(info.disc[o], info.fin[o]) << '\n';
			}
			else
				cout << st.query(info.disc[v], info.fin[v]) << '\n';
		}
	}
	return 0;
}