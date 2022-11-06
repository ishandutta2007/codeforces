#pragma comment(linker, "/STACK:600000000")
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
int const inf = (int) 2e9 + 1;
int64 const inf64 = (int64) 4e18;
const string name = "b";

const int NMAX = 2014;

int n, k, a[NMAX];
int d[NMAX][NMAX];

int may(int64 lvl) {
	forn(i, n + 1)
		forn(j, i + 1)
			d[i][j] = k + 1;
	d[0][0] = 0;
	forn(i, n)
		forn(j, i + 1)
			if (d[i][j] <= k) {
				d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j] + 1);
				if (i == j || abs(a[i] - a[i - j - 1]) <= lvl * (j + 1))
					d[i + 1][0] = min(d[i + 1][0], d[i][j]);
			}
	forn(i, n + 1)
		if (d[n][i] <= k) return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	forn(i, n)
		scanf("%d", &a[i]);
	int64 l = 0, r = inf;
	while (r - l > 0) {
		int64 m = ((l + r) / 2);
		if (may(m))
			r = m;
		else
			l = m + 1;
	}
	cout << l << endl;

	return 0;
}