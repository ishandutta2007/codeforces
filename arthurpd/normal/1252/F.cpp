// https://codeforces.com/contest/343/problem/E

#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }

template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}

#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

// int main()
// {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// }

/*
	Dinic:
		Max-flow O(V^2E)
		Bipartite Matching O(sqrt(V)E)

	Constraints:
		Vertices are labeled from 0 to n (inclusive).
		Edge capacities must fit int (flow returned is long long).

	Usage:
		Set MAXV if necessary.
		Call init passing n, the source and the sink.
		Add edges to the graph by calling put_edge(_undirected).
		Call max_flow to get the total flow. Then, individual edge flows can be retrieved in the graph.
		Note that flow will be negative in return edges.
*/

namespace dinic
{
struct edge
{
	int dest, cap, re, flow;
};

const int inf = 0x3f3f3f3f;
const int MAXV = 312345;

int n, s, t, d[MAXV], q[MAXV], next[MAXV];
vector<vector<edge>> graph;

void init(int _n, int _s, int _t)
{
	n = _n, s = _s, t = _t;
	graph = vector<vector<edge>>(n + 1);
}

void put_edge(int u, int v, int cap)
{
	graph[u].push_back({v, cap, (int)graph[v].size(), 0});
	graph[v].push_back({u, 0, (int)graph[u].size() - 1, 0});
}

void put_edge_undirected(int u, int v, int cap)
{
	graph[u].push_back({v, cap, (int)graph[v].size(), 0});
	graph[v].push_back({u, cap, (int)graph[u].size() - 1, 0});
}

bool bfs()
{
	int qb = 0, qe = 0;
	q[qe++] = s;
	memset(d, 0x3f, sizeof(int) * (n + 1));
	d[s] = 0;
	while (qb < qe)
	{
		int a = q[qb++];
		if (a == t)
			return true;
		for (int i = 0; i < (int)graph[a].size(); i++)
		{
			edge &e = graph[a][i];
			if (e.cap - e.flow > 0 && d[e.dest] == inf)
				d[q[qe++] = e.dest] = d[a] + 1;
		}
	}

	return false;
}

int dfs(int a, int flow)
{
	if (a == t)
		return flow;
	for (int &i = next[a]; i < (int)graph[a].size(); i++)
	{
		edge &e = graph[a][i];
		if (d[a] + 1 == d[e.dest] && e.cap - e.flow > 0)
		{
			int x = dfs(e.dest, min(flow, e.cap - e.flow));
			if (x == 0)
				continue;
			e.flow += x;
			graph[e.dest][e.re].flow -= x;
			return x;
		}
	}

	d[a] = inf;
	return 0;
}

long long max_flow()
{
	long long total_flow = 0;
	while (bfs())
	{
		memset(next, 0, sizeof(int) * (n + 1));
		while (int path_flow = dfs(s, inf))
			total_flow += path_flow;
	}

	return total_flow;
}
} // namespace dinic

/*
	Gomory-Hu Tree construction O(V * flow_time) (so O(V^3E), but not really):
		The GomoryHu tree of an undirected graph with capacities is a weighted
		tree that represents the minimum s-t cuts for all s-t pairs in the graph.

		The minimum cut cost between vertices s and t is the minimum cost of 
		an edge on the path from s to t in the Gomory-Hu tree.

	Constraints:
		Vertices are labeled from 0 to n-1 (inclusive).
		Undirected graph.

	Usage:
		Check Dinic usage.
		Create struct and call add edge for each edge in the graph.
		Then, just call solve passing the number of vertices.

		The vector returned will have size n and for each i > 0,
		retv[i] is a pair (cost, parent) representing an edge 
		(i, parent) in the Gomory-Hu tree.
		retv[0] means nothing.
*/

struct gomory_hu
{
	struct edg
	{
		int u, v, cap;
	};

	vector<edg> edgs;

	void add_edge(int u, int v, int cap)
	{
		edgs.push_back({u, v, cap});
	}

	vector<int> vis;

	void dfs(int a)
	{
		if (vis[a])
			return;
		vis[a] = 1;
		for (auto &e : dinic::graph[a])
			if (e.cap - e.flow > 0)
				dfs(e.dest);
	}

	vector<pair<ll, int>> solve(int n) 
	{					   
		vector<pair<ll, int>> retv(n); // if i > 0, stores pair(cost, parent).
		for (int i = 1; i < n; i++)
		{
			dinic::init(n, i, retv[i].second);

			for (auto &e : edgs)
				dinic::put_edge_undirected(e.u, e.v, e.cap);

			retv[i].first = dinic::max_flow();
			
			vis.assign(n, 0);
			dfs(i);

			for (int j = i + 1; j < n; j++)
				if (retv[j].second == retv[i].second && vis[j])
					retv[j].second = i;
		}

		return retv;
	}
};

int ans;
vector<int> ord;
vector<set<pii>> graph;

tuple<int,int,int> dfs(int a, int p)
{
	tuple<int,int,int> retv = {inf, 0, 0};
	for (auto &e : graph[a])
		if (e.first != p)
		{
			retv = min(retv, dfs(e.first, a));
			retv = min(retv, {e.second, e.first, a});
		}

	return retv;
}

void solve(int a)
{
	int u, v, w;
	tie(w, u, v) = dfs(a, a);
	if (w == inf)
		ord.push_back(a);
	else
	{
		graph[u].erase({v, w});
		graph[v].erase({u, w});
		solve(u);
		solve(v);
		ans += w;
	}
}

int main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	graph.assign(n, set<pii>());

	gomory_hu gh;
	for (int i = 0; i < m; i++)	
	{
		cin >> a >> b >> c;
		gh.add_edge(a - 1, b - 1, c);
	}

	auto tree_edges = gh.solve(n);

	for (int i = 1; i < n; i++)
	{
		graph[tree_edges[i].second].insert({i, (int)tree_edges[i].first});
		graph[i].insert({tree_edges[i].second, (int)tree_edges[i].first});
	}

	solve(0);

	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << ord[i] + 1 << " ";
	cout << endl;
}