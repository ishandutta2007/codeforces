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

const int NMAX = 205;

int n, k, l, zn[NMAX];
double d1[NMAX][NMAX][NMAX], d2[NMAX][NMAX][NMAX], p[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> l >> k;
	forn(i, n)
	{
		int pp;
		scanf("%d", &pp);
		p[i] = pp / 100.;
	}
	forn(i, n)
		cin >> zn[i];

	seta(d1, 0);
	d1[0][min(k, n)][0] = 1;
	forn(i, n)
	{
		forn(j, n + 1)
			forn(f, n + 1)
			{
				if (zn[i] == -1)
					d1[i + 1][j][f] += d1[i][j][f];
				else
				{
					d1[i + 1][min(n, j + zn[i])][f + 1] += d1[i][j][f] * p[i];
					d1[i + 1][j][f] += d1[i][j][f] * (1 - p[i]);
				}
			}
	}
	seta(d2, 0);
	d2[0][0][0] = 1;
	forn(i, n)
		forn(j, n + 1)
			forn(f, n + 1)
			{
				if (zn[i] != -1)
					d2[i + 1][j][f] += d2[i][j][f];
				else
				{
					d2[i + 1][j][f + 1] += d2[i][j][f] * p[i];
					d2[i + 1][j][f] += d2[i][j][f] * (1 - p[i]);
				}
			}
	double ans = 0;
	forn(i1, n + 1)
		forn(j1, n + 1)
			forn(j2, n + 1)
				if (i1 >= j2 && j1 + j2 >= l)
				{
			//		if (d1[n][i1][j1] > 0.1) cerr << d2[n][0][j2] << endl;
					ans += d1[n][i1][j1] * d2[n][0][j2];
				}
	printf("%.10lf\n", ans);

	cerr << clock() << endl;

	return 0;
}