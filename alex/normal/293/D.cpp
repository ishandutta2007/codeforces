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

const int NMAX = 101010;
const int XMAX = 2001010;

int n, x[NMAX], y[NMAX];
int l[XMAX], r[XMAX], zn[XMAX];

void update(int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
	{
		l[x1] = min(l[x1], min(y1, y2));
		r[x1] = max(r[x1], max(y1, y2));
		return;
	}

	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	for (int i = x1; i <= x2; ++i)
	{
		int now;
		now = y1 + (double)(i - x1) * (y2 - y1) / (x2 - x1) - 1e-7 + 1;
		l[i] = min(l[i], now);
		now = y1 + (double)(i - x1) * (y2 - y1) / (x2 - x1) + 1e-7;
		r[i] = max(r[i], now);
	}
}

double solve()
{
	x[n] = x[0], y[n] = y[0];
	forn(i, XMAX)
		l[i] = inf, r[i] = -inf;

	forn(i, n)
		update(x[i], y[i], x[i + 1], y[i + 1]);
	forn(i, XMAX)
		zn[i] = max(0, r[i] - l[i] + 1);

	double ans = 0, now = 0, cnt = 0, dist = 0;
	forn(i, XMAX)
	{
		ans += zn[i] * now;
		cnt += zn[i];
		now += 2 * dist + cnt;
		dist += cnt;
	}
	return ans / (cnt * (cnt - 1) / 2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
		scanf("%d%d", &x[i], &y[i]);

	int xmin = 0, ymin = 0;
	forn(i, n)
	{
		xmin = min(xmin, x[i]);
		ymin = min(ymin, y[i]);
	}
	forn(i, n)
	{
		x[i] -= xmin;
		y[i] -= ymin;
	}

	double ans = solve();
	forn(i, n)
		swap(x[i], y[i]);
	ans += solve();
	printf("%.10lf\n",  ans / 2);

	return 0;
}