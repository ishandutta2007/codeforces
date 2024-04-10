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
#include <cassert>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "b";

int const NMAX = 8;
int n, k, A, w[NMAX], p[NMAX];
double best, prob[NMAX];

double calc()
{
	forn(i, n)
		prob[i] = p[i] / 100.;

	double res = 0;
	forn(i, 1 << n)
	{
		double tmp = 1, B = 0;
		int cnt = 0;
		forn(j, n)
			if (i & (1 << j))
				cnt++, tmp *= prob[j];
			else
				B += w[j], tmp *= (1 - prob[j]);
		if (cnt * 2 > n) res += tmp;
		else res += tmp * A / (A + B);
	}
	return res;
}

void rec(int now, int may)
{
	if (now == n)
	{
		best = max(best, calc());
		return;
	}
	rec(now + 1, may);
	if (may > 0 && p[now] < 100)
	{
		p[now] += 10;
		rec(now, may - 1);
		p[now] -= 10;
	}
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> k >> A;
	forn(i, n)
		cin >> w[i] >> p[i];

	best = 0;
	rec(0, k);
	printf("%.10lf\n", best);

	//cerr << clock() << endl;

	return 0;
}