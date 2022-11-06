#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "e";

int const NMAX = 101000;

int k, n, m, cnt, used[NMAX], c[NMAX], vnum[NMAX], ans[NMAX], st[NMAX];
vector <int> g[NMAX], ginv[NMAX], cand[NMAX], num[NMAX];
vector <int> G[NMAX], CAND[NMAX], NUM[NMAX], zn, now;

void tp(int v)
{
	used[v] = 1;
	forn(i, g[v].size())
		if (!used[g[v][i]]) tp(g[v][i]);
	vnum[cnt++] = v;
}

void dfs(int v)
{
	used[v] = 1;
	c[v] = k;
	forn(i, ginv[v].size())
		if (!used[ginv[v][i]]) dfs(ginv[v][i]);
}

void add(int v)
{
	used[v] = 1;
	zn.pb(v);
	forn(i, G[v].size())
		if (!used[G[v][i]])
			add(G[v][i]);
}

int main()
{
/*#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif*/
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	forn(i, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		if (z) { cand[x].pb(y); num[x].pb(i); }
		else { g[x].pb(y); ginv[y].pb(x); }
	}
	cnt = 0;
	seta(used, 0);
	forn(i, n)
		if (!used[i]) tp(i);
	seta(used, 0);
	ford(i, n)
		if (!used[vnum[i]]) 
		{
			dfs(vnum[i]);
			k++;
		}
	seta(st, 0);
	forn(i, n)
		forn(j, g[i].size())
			if (c[i] != c[g[i][j]])
			{
				G[c[i]].pb(c[g[i][j]]);
				st[c[g[i][j]]]++;
			}
	forn(i, n)
		forn(j, cand[i].size())
			if (st[c[cand[i][j]]] == 0)
			{
				CAND[c[i]].pb(c[cand[i][j]]);
				NUM[c[i]].pb(num[i][j]);
			}

	seta(used, 0);
	seta(ans, 0);
	zn.clear();
	add(c[0]);
	int ept = 0;
	while ((int) zn.size() > 0)
	{
		now = zn;
		zn.clear();
		forn(i, now.size())
			forn(j, CAND[now[i]].size())
				if (!used[CAND[now[i]][j]])
				{
					ept++;
					ans[NUM[now[i]][j]] = 1;
					add(CAND[now[i]][j]);
				}
	}
	
	forn(i, k)
		if (!used[i])
		{
			cout << -1 << endl;
			return 0;
		}
	cout << ept << endl;
	forn(i, m)
		if (ans[i]) printf("%d ", i + 1);

	return 0;
}