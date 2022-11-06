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
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (1 << 30) - 1;
int64 const inf64 = (1LL << 62) - 1;
const string name = "c";

const int NMAX = 1010;
const int64 P = 1000000007;

int n, m, k;
int64 d[NMAX][NMAX], sum[NMAX][NMAX];

void pre(int k)
{
	if (k == 0)
		return;
	sum[k - 1][0] = 0;
	forn(i, NMAX)
		if (i) sum[k - 1][i] = (sum[k - 1][i - 1] + d[k - 1][i]) % P;
}

void solve(int k)
{
	if (k == 0)
	{
		forn(i, NMAX)
			if (i) d[k][i] = 1;
			else d[k][i] = 0;
		return;
	}
	d[k][0] = 0;
	forn(i, NMAX)
		if (i >= 3)
			if (i > 1) d[k][i] = (d[k][i - 1] + sum[k - 1][i - 2]) % P;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> k;
	forn(i, k + 1)
	{
		pre(i);
		solve(i);
	}
	cout << (d[k][n] * d[k][m]) % P << endl;

	return 0;
}