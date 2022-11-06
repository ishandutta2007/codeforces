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
#define y1 qqqqq
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
const double eps = 1e-5;

int n;
double d, l, v1, v2, x[3 * NMAX], ans[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> l >> v1 >> v2;
	forn(i, n)
		scanf("%lf", &x[i]);
	forn(i, n)
	{
		x[i + n] = x[i] + 2 * l;
		x[i + 2 * n] = x[i] + 4 * l;
	}
	d = l * v2 / (v1 + v2);

	double last = x[0];
	int y1 = 0, y2 = 0;
	forn(i, 2 * n)
		if (x[i] > last + d - eps)
		{
			y2 = i;
			break;
		}
	seta(ans, 0);
	while (y1 < n)
	{
		double d1 = x[y1 + 1] - last, d2 = x[y2] - last - d;
		ans[y2 - y1 - 1] += (min(d1, d2)) / (2 * l);
		if (d1 < d2) last += d1, y1++;
		else last += d2, y2++;
	}
	forn(i, n + 1)
		printf("%.10lf\n", ans[i]);

	return 0;
}