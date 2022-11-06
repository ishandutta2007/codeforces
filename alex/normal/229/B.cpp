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
int const inf = (int) 1.1e9;
int64 const inf64 = (int64) 4e18;
const string name = "b";

const int NMAX = 200010;

int n, m, d[NMAX];
vector <int> g[NMAX], w[NMAX], t[NMAX];
set <pii> S;

void update(int x, int y)
{
	S.erase(mp(d[x], x));
	d[x] = y;
	S.insert(mp(d[x], x));
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
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
		w[x].pb(z);
		w[y].pb(z);
	}
	forn(i, n)
	{
		int num;
		scanf("%d", &num);
		forn(j, num)
		{
			int tt;
			scanf("%d", &tt);
			t[i].pb(tt);
		}
	}

	forn(i, n)
	{
		d[i] = inf;
		S.insert(mp(d[i], i));
	}
	update(0, 0);
	while (S.size() > 0)
	{
		int v = S.begin()->sc;
		S.erase(S.begin());
		if (d[v] == inf) break;
		if (v == n - 1)
		{
			cout << d[v] << endl;
			return 0;
		}
		forn(i, t[v].size())
			if (d[v] == t[v][i]) d[v]++;
		forn(i, g[v].size())
			if (d[g[v][i]] > d[v] + w[v][i])
				update(g[v][i], d[v] + w[v][i]);
	}
	cout << -1 << endl;

	return 0;
}