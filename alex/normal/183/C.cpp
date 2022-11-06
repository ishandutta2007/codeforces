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
#include <deque>

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
const string name = "c";

const int NMAX = 100100;

int n, m, now, calc, c[NMAX], used[NMAX];
vector <int> g[NMAX], ginv[NMAX];

int next(int zn)
{
	if (now == -1) return zn + 1;
	else return (zn + 1) % now;
}

int prev(int zn)
{
	if (now == -1) return zn - 1;
	else return (zn + now - 1) % now;
}

int find_calc(int x, int y)
{
	int lvl = calc;
	if (lvl == -1) lvl = n;
	for (int i = lvl; i >= 1; i--)
		if ((x % i + i) % i == (y % i + i) % i && (calc == -1 || calc % i == 0))
			return i;
	exit(1);
}

void dfs(int v, int zn)
{
	used[v] = 1;
	c[v] = zn;
	forn(i, g[v].size())
		if (!used[g[v][i]]) dfs(g[v][i], next(zn));
		else if (c[g[v][i]] != next(zn)) calc = find_calc(zn, prev(c[g[v][i]]));
	forn(i, ginv[v].size())
		if (!used[ginv[v][i]]) dfs(ginv[v][i], prev(zn));
		else if (c[ginv[v][i]] != prev(zn)) calc = find_calc(zn, next(c[ginv[v][i]]));
}

void paint()
{
	seta(used, 0);
	calc = now;
	forn(i, n)
		if (!used[i]) dfs(i, 0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	/*cout << 200000 << endl;
	forn(i, 199998)
		printf("UL\n");
	cout << "UR" << endl;
	cout << "ULDR" << endl;
	return 0;*/

	cin >> n >> m;
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
		ginv[y].pb(x);
	}
	now = -1;
	//while (1)
	{
		paint();
	//	if (calc == now) break;
		now = calc;
	}
	if (now == -1) cout << n << endl;
	else cout << now << endl;

	return 0;
}