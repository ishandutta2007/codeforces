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
const string name = "c";

const int NMAX = 510;
int n, m, num, x[7], y[7], best, sz;
int sum[NMAX][NMAX], a[NMAX][NMAX], pre[NMAX][NMAX];

inline int get(int x1, int y1, int x2, int y2)
{
	return pre[x2][y2] + pre[x1 - 1][y1 - 1] - pre[x1 - 1][y2] - pre[x2][y1 - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	ford(i, n)
		forn(j, m)
			scanf("%d", &a[i][j]);
	seta(pre, 0);
	forn(i, n + 1)
		forn(j, m + 1)
			if (i > 0 && j > 0) pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i - 1][j - 1];

	num = 7;
	best = -1000000000;
	x[0] = 0, y[0] = 0;
	x[1] = 1, y[1] = 0;
	x[2] = 2, y[2] = 0;
	x[3] = 2, y[3] = 1;
	x[4] = 2, y[4] = 2;
	x[5] = 1, y[5] = 2;
	x[6] = 0, y[6] = 2;
	forn(i, num)
		swap(x[i], y[i]);
	sz = 3;
	forn(i, n - sz + 1)
		forn(j, m - sz + 1)
		{
			sum[i][j] = 0;
			forn(f, num)
				sum[i][j] += a[i + x[f]][j + y[f]];
			best = max(best, sum[i][j]);
			//cout << sum[i][j] << endl;
		}
	while (sz + 2 <= min(n, m))
	{
		sz += 2;
		forn(i, n - sz + 1)
			forn(j, m - sz + 1)
			{
				best = max(best, sum[i][j] = get(i + 1, j + 1, i + sz, j + sz) - sum[i + 1][j + 1] - a[i + sz - 2][j]);
			//	cout << sum[i][j] << endl;
			}
	}
	cout << best << endl;

	return 0;
}