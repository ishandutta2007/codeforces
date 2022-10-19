#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) flag? "YES\n": "NO\n"
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 100000;
const int logN = 18;
int n, m;

struct Edge
{
	int u, v;
	bool isBridge = false;
}Es[N];
struct Graph1
{
	int n;
	vector<pair<int, Edge*> > A[N];
}G;
struct Graph2
{
	int n;
	vector<int> A[N];
}T;

bool vis[N] = {};
int disc[N];
int low[N];
int time = 0;
void findBridge(int u,int p)
{
	vis[u] = true;
	disc[u] = time++;
	low[u] = disc[u];
	for (auto e : G.A[u])
	{
		int v = e.first;
		if (!vis[v])
		{
			findBridge(v, u);
			low[u] = min(low[v], low[u]);
			if (low[v] > disc[u])
				e.second->isBridge = true;
		}
		else if (v != p)
			low[u] = min(disc[v], low[u]);
	}
}

int dsu[N];
int find(int i)
{
	if (dsu[i] == -1)
		return i;
	dsu[i] = find(dsu[i]);
	return dsu[i];
}
void Union(int u, int v)
{
	int a = find(u);
	int b = find(v);
	if (a != b)
		dsu[b] = a;
}
void makeTree()
{
	for (auto e : Es)
	{
		if (!e.isBridge)
			Union(e.u, e.v);
	}
	int cnt = 1;
	for (auto e : Es)
	{
		if (e.isBridge)
		{
			int a = find(e.u);
			int b = find(e.v);
			T.A[a].push_back(b);
			T.A[b].push_back(a);
			cnt++;
		}
	}
	T.n = cnt;
}

int lca[N][logN];
int h[N];
void preLCA(int u, int p,int d)
{
	h[u] = d;
	lca[u][0] = p;
	Loop(i, 1, logN)
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	for (auto v : T.A[u])
		if (v != p)
			preLCA(v, u, d + 1);
}
int LCA(int u, int v)
{
	if (h[u] > h[v])
		swap(u, v);
	int del = h[v] - h[u];
	for (int i = 0; del > 0; i++)
	{
		if (del & 1)
			v = lca[v][i];
		del >>= 1;
	}
	if (u == v)
		return u;
	LoopR(i, 0, logN)
	{
		if (lca[u][i] != lca[v][i])
		{
			u = lca[u][i];
			v = lca[v][i];
		}
	}
	return lca[u][0];
}

int main()
{
	cin >> n >> m; G.n = n;
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		Es[i].u = u; Es[i].v = v;
		G.A[u].push_back({ v,&Es[i] });
		G.A[v].push_back({ u,&Es[i] });
	}
	findBridge(0, -1);
	memset(dsu, -1, N * 4);
	makeTree();
	Loop(i,0,n)
		if (T.A[i].size() > 0)
		{
			preLCA(i, i, 0);
			break;
		}
	preLCA(0, 0, 0);
	int t;
	cin >> t;
	while (t--)
	{
		int u, v;
		cin >> u >> v;
		u = find(u - 1); v = find(v - 1);
		int a = LCA(u, v);
		cout << h[u] + h[v] - 2 * h[a] << '\n';
	}
}