#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
//int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 100010;
int n, x[NMAX], y[NMAX];
pii q[NMAX];

int const inf = (int) 1e8;

int get(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2) - 1;
}

int calc(int xx, int yy)
{
	int res = inf;
	forn(i, n)
		res = min(res, get(xx, yy, x[i], y[i]));
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
		scanf("%d%d", &q[i].fs, &q[i].sc);

	sort(q, q + n);
	forn(i, n)
		x[i] = q[i].fs, y[i] = q[i].sc;

	int xmax = -inf;
	int ymax = -inf;
	int xmin = inf;
	int ymin = inf;
	forn(i, n)
	{
		xmin = min(xmin, x[i] - 1);
		ymin = min(ymin, y[i] - 1);
		xmax = max(xmax, x[i] + 1);
		ymax = max(ymax, y[i] + 1);
	}

	int ans = 2 * (ymax - ymin) + 2 * (xmax - xmin);
	ans -= calc(xmin, ymin);
	ans -= calc(xmin, ymax);
	ans -= calc(xmax, ymax);
	ans -= calc(xmax, ymin);
	cout << ans << endl;

	return 0;
}