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
typedef pair <int64, int> pii;
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
int n, q, v[NMAX], c[NMAX];
pii max1, max2;
int64 A, B, d[NMAX];

int64 get(int idx, int C)
{
	int64 res = max(B * v[idx], d[C]);
	res = max(res, d[C] + A * v[idx]);
	int64 ept = max1.fs;
	if (max1.sc == C) ept = max2.fs;
	res = max(res, ept + B * v[idx]);
	return res;
}

void solve()
{
	max1 = max2 = mp(-inf64, -1);
	forn(i, n + 1)
		d[i] = -inf64;
	forn(i, n)
	{
		d[c[i]] = max(d[c[i]], get(i, c[i]));
		if (max1.fs < d[c[i]]) { if (max1.sc != c[i]) max2 = max1; max1 = mp(d[c[i]], c[i]); }
		else if (max1.sc != c[i] && max2.fs < d[c[i]]) max2 = mp(d[c[i]], c[i]);
	}
	cout << max(0LL, max1.fs) << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> q;
	forn(i, n)
		scanf("%d", &v[i]);
	forn(i, n)
		scanf("%d", &c[i]);
	forn(i, q)
	{
		cin >> A >> B;
		solve();
	}

	return 0;
}