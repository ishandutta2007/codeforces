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
	LCA:
		Solve lowest common ancestor queries in O(log(n))
		with O(n*log(n)) preprocessing time and O(n*log(n))
		memory.
		Additionally, when solving LCA between two nodes,
		also returns the maximum edge cost in the path
		between them.
	
	Usage:
		See LCA.

	Author: Arthur Pratti Dadalto
*/

struct lca_preprocess
{
	int lgn;
	vector<int> h;
	vector<vector<int>> p;
	vector<vector<ll>> c;

	void dfs(int a, const vector<vector<int>> &graph, const vector<vector<ll>> &cost)
	{
		for (int i = 0; i < sz(graph[a]); i++)
			if (graph[a][i] != p[0][a])
			{
				h[graph[a][i]] = h[a] + 1;
				p[0][graph[a][i]] = a;
				c[0][graph[a][i]] = cost[a][i];
				dfs(graph[a][i], graph, cost);
			}
	}

	lca_preprocess(int root, int n, const vector<vector<int>> &graph, const vector<vector<ll>> &cost) : h(n + 1)
	{
		lgn = 31 - __builtin_clz(n + 1);
		p.assign(lgn + 1, vector<int>(n + 1, 0));
		c.assign(lgn + 1, vector<ll>(n + 1, 0));

		p[0][root] = root;
		h[root] = 0;
		dfs(root, graph, cost);

		for (int i = 1; i <= lgn; i++)
			for (int j = 0; j <= n; j++)
			{
				p[i][j] = p[i - 1][p[i - 1][j]];
				c[i][j] = max(c[i - 1][j], c[i - 1][p[i - 1][j]]);
			}
	}

	// Pair of LCA and the maximum edge cost on the a-b path.
	pair<int, ll> lca(int a, int b)
	{
		if (h[a] < h[b])
			swap(a, b);

		ll res = 0;
		for (int i = lgn; i >= 0; i--)
			if (h[p[i][a]] >= h[b])
			{
				res = max(res, c[i][a]);
				a = p[i][a];
			}

		if (a == b)
			return {a, res};

		for (int i = lgn; i >= 0; i--)
			if (p[i][a] != p[i][b])
			{
				res = max(res, c[i][a]);
				a = p[i][a];

				res = max(res, c[i][b]);
				b = p[i][b];
			}

		return {p[0][a], max(c[0][b], max(res, c[0][a]))};
	}
};

struct edge
{
	int u, v;
	ll w;

	bool operator<(edge rhs)
	{
		return w < rhs.w;
	}
};

void solve_queries(int n, vector<edge> e, int q)
{
	vector<vector<int>> graph(n);
	vector<vector<ll>> cost(n);
	for (int i = 0; i < n - 1; i++)
	{
		graph[e[i].u].push_back(e[i].v);
		cost[e[i].u].push_back(e[i].w);

		graph[e[i].v].push_back(e[i].u);
		cost[e[i].v].push_back(e[i].w);
	}

	lca_preprocess lca(0, n - 1, graph, cost);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << lca.lca(a, b).second << endl;
	}
}

struct union_find
{
	vector<int> p, size;
	union_find(int n) : p(n), size(n, 1)
	{
		iota(p.begin(), p.end(), 0);
	}

	int find(int a)
	{
		return (p[a] == a) ? a : (p[a] = find(p[a]));
	}

	void join(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)
			return;
		if (size[a] < size[b])
			swap(a, b);
		p[b] = a;
		size[a] += size[b];
	}
};

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, nq, a;
	ll x;
	cin >> n >> m >> k >> nq;
	vector<edge> e(m);
	vector<vector<int>> graph(n);
	vector<vector<ll>> cost(n);
	for (int i = 0; i < m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].u--;
		e[i].v--;
		graph[e[i].u].push_back(e[i].v);
		cost[e[i].u].push_back(e[i].w);

		graph[e[i].v].push_back(e[i].u);
		cost[e[i].v].push_back(e[i].w);
	}

	vector<ll> d(n, infll);
	vector<int> p(n, -1);
	priority_queue<pair<ll, int>> q;
	for (int i = 0; i < k; i++)
	{
		d[i] = 0;
		p[i] = i;
		q.push({d[i], i});
	}

	while (!q.empty())
	{
		tie(x, a) = q.top();
		q.pop();
		if (x != -d[a])
			continue;

		for (int i = 0; i < sz(graph[a]); i++)
			if (d[a] + cost[a][i] < d[graph[a][i]])
			{
				d[graph[a][i]] = d[a] + cost[a][i];
				p[graph[a][i]] = p[a];
				q.push({-d[graph[a][i]], graph[a][i]});
			}
	}

	vector<edge> mste;
	for (int i = 0; i < m; i++)
	{
		if (p[e[i].u] != p[e[i].v])
			mste.push_back({p[e[i].u], p[e[i].v], d[e[i].u] + d[e[i].v] + e[i].w});
	}

	vector<edge> tree;
	sort(mste.begin(), mste.end());
	union_find uf(k);
	for (int i = 0; i < sz(mste); i++)
		if (uf.find(mste[i].u) != uf.find(mste[i].v))
		{
			tree.push_back(mste[i]);
			uf.join(mste[i].u, mste[i].v);
		}

	solve_queries(k, tree, nq);
}