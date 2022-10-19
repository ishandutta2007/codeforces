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
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 100000;
const int logN = 18;

struct query
{
	int t;
	int a, b;
}q[N];

int n, m;
vector<int> A[N];
int lca[N][logN];
int d[N];
bool havBoss[N] = {};
pair<int, int> Doc[N];
pair<int, int> dsupar[N];

pair<int, int> Find(int x)
{
	if (dsupar[x].first == x)
		return dsupar[x];
	auto par = Find(dsupar[x].first);
	par.second += dsupar[x].second;
	dsupar[x] = par;
	return par;
}

void dsu(int u, int v)
{
	dsupar[v] = { u, 1 };
}

void dfs(int u, int p,int h)
{
	lca[u][0] = p;
	d[u] = h;
	Loop(i, 1, logN)
	{
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	}
	for (auto v : A[u])
		dfs(v, u, h + 1);
}

int getAnc(int u, int h)
{
	int dif = h;
	int v = u;
	for (int i = 0; dif > 0; i++)
	{
		if (dif & 1)
			v = lca[v][i];
		dif >>= 1;
	}
	return v;
}

int main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, m)
	{
		int t;
		cin >> t;
		q[i].t = t;
		switch (t)
		{
		case 1: cin >> q[i].a >> q[i].b; q[i].a--; q[i].b--;
			A[q[i].b].push_back(q[i].a);
			havBoss[q[i].a] = true; break;
		case 2: cin >> q[i].a; q[i].a--; break;
		case 3: cin >> q[i].a >> q[i].b; q[i].a--; q[i].b--; break;
		}
	}
	Loop(i, 0, n)
	{
		if (!havBoss[i])
			dfs(i, i, 0);
		dsupar[i] = { i, 0 };
	}
	int docSize = 0;
	Loop(i, 0, m)
	{
		switch (q[i].t)
		{
		case 1: dsu(q[i].b, q[i].a); break;
		case 2: Doc[docSize++] = { q[i].a, Find(q[i].a).second }; break;
		case 3: int dif = d[Doc[q[i].b].first] - d[q[i].a];
			  if (dif > Doc[q[i].b].second || dif < 0) cout << "NO\n";
			  else
			  {
				if(getAnc(Doc[q[i].b].first, dif) == q[i].a)
					cout << "YES\n";
				else
					cout << "NO\n";
			  } break;
		}
	}
}