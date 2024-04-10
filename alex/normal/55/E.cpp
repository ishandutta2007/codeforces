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

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

double const pi = 3.1415926535897;
int const NMAX = 100010;
int k, n, m, x[NMAX], y[NMAX];
int64 xx, yy, ans;

bool good(int a, int b)
{
	double x1 = xx - x[a];
	double y1 = yy - y[a];
	double x2 = x[b] - x[a];
	double y2 = y[b] - y[a];

	double ang = atan2(y2, x2) - atan2(y1, x1);
	if (ang < 0) ang += 2 * pi;

	if (ang < pi) return true;
	else return false;
}

bool check()
{
	x[n] = x[0], y[n] = y[0];
	forn(i, n)
		if (!good(i, i + 1)) return false;
	return true;
}

void solve()
{
	ans = (int64) n * (n - 1) * (n - 2) / 6;
	cin >> xx >> yy;
	if (!check())
	{
		cout << 0 << endl;
		return;
	}

	int p = 1;
	forn(i, n)
	{
		while (good(i, p + 1))
		{
			p++;
			if (p == n) p = 0;
		}
		int64 now = (i + n - p - 2) % n;
		ans -= now * (now + 1) / 2;
	}

	cout << ans << endl;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
		scanf("%d%d", &x[i], &y[i]);
	cin >> k;
	forn(i, k)
		solve();

	return 0;
}