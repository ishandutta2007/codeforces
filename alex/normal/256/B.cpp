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

#include <string.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define seta(a, b) memset(a, b, sizeof(a))


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

int64 n, x, y, k;

int64 calc(int64 x, int64 y, int64 t)
{
	if (t <= 1) return 0;
	t--;
	if (x > y) swap(x, y);
	if (t <= x) return t * (t + 1) / 2;
	if (t >= x + y - 1) return x * y;
	if (t >= y) return x * y - (x + y - 1 - t) * (x + y - 1 - t + 1) / 2;
	return x * (x + 1) / 2 + x * (t - x);
}

int may(int64 t)
{
	int64 now = 1 + min(t, x - 1) + min(t, y - 1) + min(t, n - x) + min(t, n - y);
	now += calc(x - 1, y - 1, t);
	now += calc(n - x, y - 1, t);
	now += calc(n - x, n - y, t);
	now += calc(x - 1, n - y, t);
	return now >= k;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> x >> y >> k;
	int64 l = 0, r = 2 * n;
	while (l < r)
	{
		int64 m = (l + r) >> 1;
		if (may(m)) r = m;
		else l = m + 1;
	}
	cout << l << endl;

	return 0;
}