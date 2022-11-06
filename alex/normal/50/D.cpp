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
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < long long, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 200;
int n, k;
double e, xx, yy, x[NMAX], y[NMAX];
double d[NMAX][NMAX];

double calc(int num, double r)
{
	double d = (xx - x[num]) * (xx - x[num]) + (yy - y[num]) * (yy - y[num]);
	r *= r;
	if (d < r) return 1;
	else return exp(1 - d / r);
}

bool may(double r)
{

	seta(d, 0);
	d[0][0] = 1;
	forn(i, n)
	{
		double prob = calc(i, r);
		forn(j, n)
		{
			d[i + 1][j + 1] += d[i][j] * prob;
			d[i + 1][j] += d[i][j] * (1 - prob);
		}
	}
	double now = 0;
	for (int i = k; i <= n; i++)
		now += d[n][i];
	if (now < e) return false;
	else return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> k >> e;
	e /= 1000.;
	e = 1 - e;
	int cnt = 0;
	cin >> xx >> yy;
	forn(i, n)
	{
		cin >> x[i] >> y[i];
		if (fabs(x[i] - xx) + fabs(y[i] - yy) < 1e-7)
			cnt++;
	}
	if (cnt >= k)
	{
		printf("%.10lf\n", 0);
		return 0;
	}

	double l = 0, r = 1e7;
	while (fabs(r - l) > 1e-8)
	{
		double m = (l + r) / 2;
		if (may(m)) r = m;
		else l = m;
	}
	printf("%.10lf\n", (l + r) / 2);

	return 0;
}