#pragma comment(linker, "/STACK:600000000")
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
const string name = "d";

const int NMAX = 510;
const int MMAX = 10010;

int n, m, q, x[MMAX], y[MMAX], used[NMAX], l[NMAX];
int L[MMAX][NMAX], R[MMAX][NMAX];
vector <int> g[NMAX];

void dfs(int v)
{
	used[v] = 1;
	forn(i, g[v].size())
		if (!used[g[v][i]]) dfs(g[v][i]);
}

int leader(int x)
{
	if (l[x] == x) return x;
	else return l[x] = leader(l[x]);
}

void unite(int x, int y)
{
	if ((x + y) & 1) l[leader(x)] = leader(y);
	else l[leader(y)] = leader(x);
}

void add(int x, int y)
{
	g[x].pb(y);
	g[y].pb(x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, m)
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i]--, y[i]--;
	}
	forn(i, n)
		l[i] = i;
	forn(i, m)
	{
		unite(x[i], y[i]);
		forn(j, n)
			L[i][j] = leader(j);
	}
	forn(i, n)
		l[i] = i;
	ford(i, m)
	{
		unite(x[i], y[i]);
		forn(j, n)
			R[i][j] = leader(j);
	}

	cin >> q;
	forn(i, q)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		forn(i, n)
			g[i].clear();
		if (l > 0)
		{
			forn(i, n)
				add(i, L[l - 1][i]);
		}
		if (r < m - 1)
		{
			forn(i, n)
				add(i, R[r + 1][i]);
		}
		seta(used, 0);
		int ans = 0;
		forn(j, n)
			if (!used[j]) { ans++; dfs(j); }
		printf("%d\n", ans);
	}

	return 0;
}