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
const string name = "a";

int n, m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, n)
	{
		int ans, x, y, t, now;
		scanf("%d%d%d", &x, &y, &t);
		x--, y--;
		if (x == y) ans = t;
		else
		{
			if (x < y)
			{
				now = t / (2 * m - 2) * (2 * m - 2) + x - (2 * m - 2);
				while (now < t) now += (2 * m - 2);
			}
			else
			{
				now = t / (2 * m - 2) * (2 * m - 2) - m + 1 + (m - x - 1) - (2 * m - 2);
				while (now < t) now += (2 * m - 2);
			}
			ans = now + abs(y - x);
		}
		printf("%d\n", ans);
	}

	return 0;
}