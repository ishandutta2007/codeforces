// https://codeforces.com/contest/342/problem/E

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

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())

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
	Centroid Decomposition:
		Solve tree problems by divide and conquer splitting the tree repeatedly on centroid.
		Centroid is the vertex with smallest <largerst subtree>.
		O(n log n if process is O(sz))

	Usage:
		Call put_edge to initialize the tree edges.
		Then call decomp(i, n) for any vertex i in the tree, with n being the number of vertices.
		Function process will be called for a centroid <a> with subtree total size sz.
			In process you can use:
			graph[a][i] - graph adjacency list
			block[a] - true if you should ignore the vertex.
			sub_size[a][i] - subtree size for edge a -> graph[a][i] (considering only non-blocked parts).
		
		if process can be O(sz + h * log) where h is subtree height it is a lot better constant than
		O(sz * log)

	PRINT APPLICATION WITH THIS.

	Author: Arthur Pratti Dadalto
*/

#define MAXN 112345

void process(int a, int sz);

vector<int> graph[MAXN];
vector<int> sub_size[MAXN];
bool block[MAXN];

int dfs_centroid(int a, int p, int sz, int &centroid, int &val)
{
	int sum = 0, mx = 0, pidx = -1;
	for (int i = 0; i < sz(graph[a]); i++)
		if (graph[a][i] != p && !block[graph[a][i]])
		{
			int x = dfs_centroid(graph[a][i], a, sz, centroid, val);

			sub_size[a][i] = x;
			mx = max(x, mx);
			sum += x;
		}
		else if (graph[a][i] == p && !block[graph[a][i]])
			pidx = i;

	if (pidx != -1)
	{
		sub_size[a][pidx] = sz - sum - 1;
		mx = max(mx, sub_size[a][pidx]);
	}

	if (mx < val)
		val = mx, centroid = a;

	return sum + 1;
}

void decomp(int a, int sz)
{
	int val = inf;
	dfs_centroid(a, a, sz, a, val);

	process(a, sz);

	block[a] = true;
	for (int i = 0; i < sz(graph[a]); i++)
		if (!block[graph[a][i]])
			decomp(graph[a][i], sub_size[a][i]);
}

void put_edge(int a, int b)
{
	graph[a].push_back(b);
	sub_size[a].push_back(0);
	graph[b].push_back(a);
	sub_size[b].push_back(0);
}

/*
	LCA:
		Solve lowest common ancestor queries in O(log(n))
		with O(n*log(n)) preprocessing time and O(n*log(n))
		memory.
	
	Usage:
		Initialize struct with tree root, number of vertices
		and graph. Has been tested with label in [1, n], but should
		work for labels in [0, n].

	Author: Arthur Pratti Dadalto
*/

struct lca_preprocess
{
	int lgn;
	vector<int> h;
	vector<vector<int>> p;
	vector<int> *graph;

	void dfs(int a)
	{
		for (int i = 0; i < sz(graph[a]); i++)
			if (graph[a][i] != p[0][a])
			{
				h[graph[a][i]] = h[a] + 1;
				p[0][graph[a][i]] = a;
				dfs(graph[a][i]);
			}
	}

	lca_preprocess(int root, int n, vector<int> graph[]) : h(n + 1), graph(graph)
	{
		lgn = 31 - __builtin_clz(n + 1);
		p.assign(lgn + 1, vector<int>(n + 1, 0));

		p[0][root] = root;
		h[root] = 0;
		dfs(root);

		for (int i = 1; i <= lgn; i++)
			for (int j = 0; j <= n; j++)
				p[i][j] = p[i - 1][p[i - 1][j]];
	}

	int lca(int a, int b)
	{
		if (h[a] < h[b])
			swap(a, b);
		for (int i = lgn; i >= 0; i--)
			if (h[p[i][a]] >= h[b])
				a = p[i][a];

		if (a == b)
			return a;

		for (int i = lgn; i >= 0; i--)
			if (p[i][a] != p[i][b])
			{
				a = p[i][a];
				b = p[i][b];
			}

		return p[0][a];
	}

	int dist(int a, int b)
	{
		return h[a] + h[b] - 2 * h[lca(a, b)];
	}
};

/*
	BIT: element update, range sum query and sum lower_bound in O(log(N)).
	Represents an array of elements in range [1, N].
*/

template <class T>
struct bit
{
	int n, LOGN;
	vector<T> val;
	bit(int _n = 0) : n(_n), LOGN(log2(n + 1)), val(_n + 1, 0) {}

	// val[pos] += x
	void update(int pos, T x)
	{
		for (int i = pos; i <= n; i += -i & i)
			val[i] += x;
	}

	// sum of range [1, pos]
	T query(int pos)
	{
		T retv = 0;
		for (int i = pos; i > 0; i -= -i & i)
			retv += val[i];
		return retv;
	}

	// min pos such that sum of [1, pos] >= sum, or n + 1 if none exists.
	int lower_bound(T x)
	{
		T sum = 0;
		int pos = 0;

		for (int i = LOGN; i >= 0; i--)
			if (pos + (1 << i) <= n && sum + val[pos + (1 << i)] < x)
				sum += val[pos += (1 << i)];

		return pos + 1; // pos will have position of largest value less than x.
	}
};

int par[MAXN];
bit<int> ans[MAXN];

void dfs(int a, int p, int c, int l, int &mh)
{
	mh = max(mh, l);
	par[a] = c;

	for (int i = 0; i < sz(graph[a]); i++)
		if (graph[a][i] != p && !block[graph[a][i]])
			dfs(graph[a][i], a, c, l + 1, mh);
}

void process(int a, int sz)
{
	int mh = 1;
	for (int i = 0; i < sz(graph[a]); i++)
		if (!block[graph[a][i]])
			dfs(graph[a][i], a, a, 1, mh);

	ans[a] = bit<int>(mh + 1);
}

int cnt_ans[MAXN];
bool color[MAXN];

void toggle(int a, lca_preprocess &lca)
{
	color[a] = !color[a];
	for (int v = a; v != 0; v = par[v])
		if (color[a])
		{	
			cnt_ans[v]++;
			ans[v].update(lca.dist(a, v) + 1, 1);
		}
		else
		{	
			cnt_ans[v]--;
			ans[v].update(lca.dist(a, v) + 1, -1);
		}
}

int get_ans(int a, lca_preprocess &lca)
{
	int retv = inf;
	for (int v = a; v != 0; v = par[v])
		if (cnt_ans[v])
			retv = min(retv, ans[v].lower_bound(1) - 1 + lca.dist(a, v));

	return retv;
}

int main(void)
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i + 1 < n; i++)
	{
		scanf("%d %d", &a, &b);
		put_edge(a, b);
	}

	decomp(1, n);

	lca_preprocess lca(1, n, graph);

	toggle(1, lca);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		if (a == 1)
			toggle(b, lca);
		else
		{
			int x = get_ans(b, lca);
			printf("%d\n", (x == inf ? -1 : x));
		}
	}
}