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
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "c";

int const NMAX = 15;
int n, m, now[6], ans, lvl;
int x[NMAX], y[NMAX], l[NMAX], r[NMAX], p[NMAX];
int g[6][6];

void rec(int x, int y, int sum)
{
//	if (now[x] < 0) return;
	if (x == n - 1)
	{
		forn(i, n - 1)
			if (now[i] != 0) return;
		ans = max(ans, sum);
		return;
	}
	if (y == n)
	{
		if (now[x] == 0)
			rec(x + 1, x + 2, sum);
		return;
	}

	int tmp, num = g[x][y];
	for (int i = l[num]; i <= r[num]; ++i)
	{
		now[x] -= i;
		now[y] += i;
		tmp = i * i;
		if (i > 0) tmp += p[num];
		rec(x, y + 1, sum + tmp);
		now[x] += i;
		now[y] -= i;
	}
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	m = n * (n - 1) / 2;
	forn(i, m)
	{
		cin >> x[i] >> y[i] >> l[i] >> r[i] >> p[i];
		x[i]--, y[i]--;
		g[x[i]][y[i]] = i;
	}

	seta(now, 0);
	for (lvl = 0; lvl <= 25; lvl++)
	{
		ans = -1;
		now[0] = lvl;
		rec(0, 1, 0);
		if (ans >= 0)
		{
			cout << lvl << " " << ans << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << endl;

	return 0;
}