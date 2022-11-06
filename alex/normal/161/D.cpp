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

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "d";

const int NMAX = 50010;
const int KMAX = 510;

int n, k, used[NMAX], d[NMAX][KMAX];
vector <int> g[NMAX], norm[NMAX];
int64 ans;

void dfs(int v)
{
	used[v] = 1;
	d[v][0] = 1;
	forn(i, g[v].size())
		if (!used[g[v][i]])
		{
			dfs(g[v][i]);
			forn(j, k + 1)
				if (j) d[v][j] += d[g[v][i]][j - 1];
			norm[v].pb(g[v][i]);
		}
	ans += d[v][k] * 2;
	forn(i, norm[v].size())
	{
		int w = norm[v][i];
		for (int j = 1; j < k; ++j)
			ans += (long long) d[w][j - 1] * (d[v][k - j] - d[w][k - j - 1]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen((name + ".in").data(), "r", stdin);
    freopen((name + ".out").data(), "w", stdout);
#endif

	seta(d, 0);
	cin >> n >> k;
	forn(i, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	ans = 0;
	dfs(0);
	cout << ans / 2 << endl;

    return 0;
}