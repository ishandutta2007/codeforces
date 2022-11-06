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
typedef pair <int64, int> pii;
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
const string name = "c";

const int NMAX = 200202;

int used[NMAX], n, m, ans[NMAX], need[NMAX];
vector <int> g[NMAX], num[NMAX], tp[NMAX], w[NMAX];
set <pii> S;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, m)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		g[x].pb(y);
		w[x].pb(z);
		num[x].pb(i);
		tp[x].pb(0);
		g[y].pb(x);
		w[y].pb(z);
		num[y].pb(i);
		tp[y].pb(1);
	}
	forn(i, n)
	{
		need[i] = 0;
		forn(j, g[i].size())
			need[i] += w[i][j];
		if (i != n - 1) need[i] = need[i] / 2;
		if (i > 0) S.insert(mp(need[i], i));
	}
	S.insert(mp(0, 0));

	seta(used, 0);
	while (S.size() > 0)
	{
		int v = S.begin()->sc;
		S.erase(S.begin());
		forn(i, g[v].size())
			if (!used[num[v][i]])
		{
			used[num[v][i]] = 1;
			ans[num[v][i]] = tp[v][i];
			S.erase(mp(need[g[v][i]], g[v][i]));
			need[g[v][i]] -= w[v][i];
			S.insert(mp(need[g[v][i]], g[v][i]));
		}
	}

	forn(i, m)
		printf("%d\n", ans[i]);

	return 0;
}