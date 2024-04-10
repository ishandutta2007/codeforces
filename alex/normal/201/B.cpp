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
const string name = "b";

const int NMAX = 1010;

int n, m, zn[NMAX][NMAX];
int64 raw[NMAX], col[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	seta(raw, 0);
	seta(col, 0);
	forn(i, n)
		forn(j, m)
		{
			scanf("%d", &zn[i][j]);
			raw[i] += zn[i][j];
			col[j] += zn[i][j];
		}

	int x, y;
	int64 xans = inf64, yans = inf64;
	forn(i, n + 1)
	{
		int64 now = 0;
		forn(j, n)
			now += raw[j] * (4 * i - 4 * j - 2) * (4 * i - 4 * j - 2);
		if (xans > now)
			xans = now, x = i;
	}
	forn(i, m + 1)
	{
		int64 now = 0;
		forn(j, m)
			now += col[j] * (4 * i - 4 * j - 2) * (4 * i - 4 * j - 2);
		if (yans > now)
			yans = now, y = i;
	}
	cout << xans + yans << endl << x << " " << y << endl;

	return 0;
}