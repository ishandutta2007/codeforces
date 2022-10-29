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

struct apb
{
	vector<int> *graph;
	vector<bool> art;
	vector<int> num, low;
	vector<pii> bridges;
	
	int id;
	
	apb(int a, int n, vector<int> graph[]) : graph(graph), art(n+1, false), num(n+1), low(n+1)
	{
		id = 1;
		dfs(a, a);
	}
	
	void dfs(int a, int p)
	{
		low[a] = num[a] = id++;
		int comp = 0;
		
		for (int i =0; i < graph[a].size(); i++)
		{
			if (num[graph[a][i]] == 0)
			{
				comp++;
				dfs(graph[a][i], a);
				low[a] = min(low[a], low[graph[a][i]]);
				if (a != 1 && low[graph[a][i]] >= num[a])
					art[a] = true;
				if (low[graph[a][i]] > num[a])
					bridges.push_back({a, i});
				
			}
			else if (graph[a][i] != p && num[graph[a][i]] < low[a])
				low[a] = num[graph[a][i]];
				
		}
		
		if (a == p && comp > 1)
			art[a] = true;
	}
};
 
#define MAXN 212345
 
vector<int> block[MAXN];
vector<int> graph[MAXN];
int w[MAXN];
int comp[MAXN];
int id = 0;
 
void dfs(int a)
{
	for (int i =0; i < graph[a].size(); i++)
	{
		if (comp[graph[a][i]] == 0)
		{
			if (block[a][i])
				comp[graph[a][i]] = ++id;
			else
				comp[graph[a][i]] = comp[a];
 
			dfs(graph[a][i]);
		}
	}	
}
 
struct edge { int u, v, w; };
 
vector<int>  tree[MAXN];
ll tw[MAXN];
ll tsize[MAXN];
ll total_back = 0;

pair<bool, ll> dfs2(int a, int p)
{
	bool back = false;
	ll deep = 0;
	if (tsize[a] > 1)
		back = true;
	
	for (int i = 0; i < tree[a].size(); i++)
		if (tree[a][i] != p)
		{
			auto res = dfs2(tree[a][i], a);
			if (res.first)
				back = true;

			deep = max(deep, res.second);
		}

	if (back)
	{
		total_back += tw[a];
		return {true, deep};
	}
	else
	{
		deep += tw[a];
		return {false, deep};
	}
}

int main(void)
{
	int n, m, a, b, c, start;
	scanf("%d %d", &n, &m);
		
	id = 0;
	memset(comp, 0, sizeof(comp));
	memset(tw, 0, sizeof(tw));
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);

	vector<edge> e;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		block[a].push_back(0);
		graph[b].push_back(a);
		block[b].push_back(0);
		
		e.push_back({a, b, 0});
	}

	scanf("%d", &start);

	apb br(start, n, graph);
	for (auto p : br.bridges)
	{
		block[p.first][p.second] = true;
	}
	
	comp[start] = ++id;
	dfs(start);
	
	for (int i = 0; i < e.size(); i++)
		if (comp[e[i].u] != comp[e[i].v])
		{
			tree[comp[e[i].u]].push_back(comp[e[i].v]);

			tree[comp[e[i].v]].push_back(comp[e[i].u]);
		}
	
	for (int i = 1; i <= n; i++)
	{
		tw[comp[i]] += w[i];
		tsize[comp[i]]++;
	}

	// for (int i = 1; i <= id; i++)
	// 	debug(tw[i], tsize[i]);

	auto ans = dfs2(comp[start], comp[start]);
	
	cout << total_back + ans.second << endl;
}