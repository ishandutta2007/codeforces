#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 200000;
const int logN = 19;
int n, m;
struct Edge
{
	int u, v;
	ll w;
	int tag;
}E[N];
ll W = 0;
vector<pair<int, ll> > A[N];
int lca[N][logN];
ll lcamax[N][logN];
int d[N];

void dfs(int u, int p, ll pW, int h)
{
	d[u] = h;
	lca[u][0] = p;
	Loop(i, 1, logN)
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	lcamax[u][0] = pW;
	Loop(i, 1, logN)
		lcamax[u][i] = max(lcamax[u][i - 1], lcamax[lca[u][i - 1]][i - 1]);
	for (auto v : A[u])
	{
		if (v.first != p)
			dfs(v.first, u, v.second, h + 1);
	}
}

int LCA(int u, int v)
{
	int a = u, b = v;
	if (d[a] > d[b])
		swap(a, b);
	int dif = d[b] - d[a];
	for (int i = 0; dif > 0; i++)
	{
		if (dif & 1)
			b = lca[b][i];
		dif >>= 1;
	}
	if (a == b)
		return a;
	LoopR(i, 0, logN)
	{
		if (lca[a][i] != lca[b][i])
		{
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}

ll getMax(int u, int up)
{
	int a = u;
	int dif = up;
	ll ans = 0;
	for (int i = 0; dif > 0; i++)
	{
		if (dif & 1)
		{
			ans = max(ans, lcamax[a][i]);
			a = lca[a][i];
		}
		dif >>= 1;
	}
	return ans;
}

int dsu[N];
int find(int u)
{
	if (dsu[u] == u)
		return u;
	dsu[u] = find(dsu[u]);
	return dsu[u];
}
void DSU(Edge e)
{
	int u = find(e.u);
	int v = find(e.v);
	if (u != v)
	{
		W += e.w;
		dsu[v] = u;
		A[e.u].push_back({ e.v,e.w });
		A[e.v].push_back({ e.u,e.w });
	}
}

int main()
{
	cin >> n >> m;
	Loop(i, 0, m)
	{
		cin >> E[i].u >> E[i].v >> E[i].w;
		E[i].u--; E[i].v--;
		E[i].tag = i;
	}
	sort(E, E + m, [&](Edge a, Edge b)
		{
			return a.w < b.w;
		});
	Loop(i, 0, n)
		dsu[i] = i;
	Loop(i, 0, m)
		DSU(E[i]);
	dfs(0, 0, 0, 0);
	sort(E, E + m, [&](Edge a, Edge b)
		{
			return a.tag < b.tag;
		});
	Loop(i, 0, m)
	{
		if (E[i].u == lca[E[i].v][0] || E[i].v == lca[E[i].u][0])
			cout << W << ' ';
		else
		{
			int l = LCA(E[i].u, E[i].v);
			ll ans = max(getMax(E[i].u, d[E[i].u] - d[l]),
				getMax(E[i].v, d[E[i].v] - d[l]));
			cout << W - ans + E[i].w << ' ';
		}
	}
}