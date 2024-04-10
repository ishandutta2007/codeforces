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
#include <stack>

//#pragma comment(linker, "/STACK:124000111")

using namespace std; // ipsc graph problem

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
	info.reachable.push_back(u);
	low[u] = info.disc[u] = t++; // [!] 3 in 1
	st.push(u);

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
	info.fin[u] = t++;
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

vector<int> intersection(const vector<int> &a, const vector<int> &b) {
	set<int> s(b.begin(), b.end());
	vector<int> res;
	for (auto &&x : a)
		if (s.count(x))
			res.push_back(x);
	return res;
}

void myDFS(const int u, const Graph &D, vector<int> &dp) {
	for (auto &&v : D.adj[u]) {
		myDFS(v, D, dp);
		dp[u] += dp[v];
	}
}

string S;

int dfs(int u, Graph &G, vector<bool> &visited, vector<array<int, 26>> &dp, int &ans) {
	visited[u] = true;
	for (int i = 0; i < 26; ++i)
		dp[u][i] = 0;
	for (auto &&v : G.adj[u]) {
		if (!visited[v]) {
			dfs(v, G, visited, dp, ans);
		}
		for (int i = 0; i < 26; ++i)
			dp[u][i] = max(dp[u][i], dp[v][i]);
	}
	dp[u][S[u] - 'a']++;
	for (int i = 0; i < 26; ++i)
		ans = max(ans, dp[u][i]);
	return ans;
}

int f() {

	int n, m;
	cin >> n >> m;
	Graph G(n);
	cin >> S;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == y) {
			return -1;
		}
		--x, --y;
		G.adj[x].push_back(y);
	}
	auto info = G.dfsInfo(-1);
	if (info.comps.size() != n)
		return -1;
	vector<array<int, 26>> dp(n);
	vector<bool> visited(n);
	int ans = 0;
	for(int i = 0; i < n; ++i)
		if (!visited[i]) {
			dfs(i, G, visited, dp, ans);
		}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << f();
	return 0;
}