#pragma comment(linker, "/STACK:600000000")
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
const string name = "a";

const int NMAX = 101010;

int n, minyl, maxyl, yy[NMAX], used[NMAX];
double x[NMAX], y[NMAX], zn[NMAX];
pair<double, double> q[NMAX];
pair<double, int> qq[NMAX];

int may(double r)
{
	seta(used, 0);
	double _max = -1e10, _min = 1e10;
	int yl = 0;
	minyl = 0, maxyl = n - 1;
	forn(i, n)
	{
		while (yl < n && x[yl] - x[i] <= 2 * r)
		{
			used[yy[yl]] = 1;
			while (maxyl >= 0 && used[maxyl]) maxyl--;
			while (minyl < n && used[minyl]) minyl++;
			yl++;
		}
		double tmp_max = _max;
		if (maxyl >= 0) tmp_max = max(tmp_max, zn[maxyl]);
		double tmp_min = _min;
		if (minyl < n) tmp_min = min(tmp_min, zn[minyl]);
		if (tmp_max - tmp_min <= 2 * r)
			return 1;
		_max = max(_max, y[i]);
		_min = min(_min, y[i]);
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
	{
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		q[i] = mp(xx + yy, xx - yy);
//		cerr << q[i].fs << " " << q[i].sc << endl;
	}
	sort(q, q + n);
	forn(i, n)
	{
		x[i] = q[i].fs, y[i] = q[i].sc;
		qq[i] = mp(y[i], i);
	}
	sort(qq, qq + n);
	forn(i, n)
		zn[i] = qq[i].fs, yy[qq[i].sc] = i;
	double l = 0, r = 1e10;
	may(0);
	forn(i, 55)
	{
		double m = (l + r) / 2;
		if (may(m)) r = m;
		else l = m;
	}
	printf("%.10lf\n", l);

	return 0;
}