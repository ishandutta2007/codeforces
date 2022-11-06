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

const int NMAX = 100100;

int n, k, h, ans[NMAX];
pair <pii, int> q[NMAX];

int may(double lvl)
{
	int now = 0;
	forn(i, n)
		if (now < k && q[i].fs.sc * lvl > h * (now + 1))
			ans[now++] = q[i].sc;
	return now == k;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k >> h;
	forn(i, n)
	{
		q[i].sc = i + 1;
		scanf("%d", &q[i].fs.fs);
	}
	forn(i, n)
		scanf("%d", &q[i].fs.sc);
	sort(q, q + n);

	double l = 0, r = 1e9 + 1;
	forn(i, 90)
	{
		double  m = (l + r) / 2;
		if (may(m)) r = m;
		else l = m;
	}
	if (!may(r)) return 1;
	forn(i, k)
		printf("%d ", ans[i]);

	return 0;
}