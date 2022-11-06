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

const string name = "a";

int64 l, r, ans, glob;

int64 calc(int64 n)
{
	return n * (glob - n);
}

void solve(int64 ll, int64 rr)
{
	glob = rr;
	ll = max(l, ll);
	rr = min(r, rr);
	if (ll > rr) return;

	while (ll < rr - 1000)
	{
		int64 m1 = (2 * ll + rr) / 3;
		int64 m2 = (ll + 2 * rr) / 3;
		if (calc(m1) > calc(m2)) rr = m2;
		else ll = m1;
	}
	for (int64 i = ll; i <= rr; ++i)
		ans = max(ans, calc(i));
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> l >> r;
	if (r == 1000000000)
	{
		cout << 1000000000LL * (8999999999) << endl;
		return 0;
	}
	int64 now = 1;
	ans = 0;
	for (int d = 0; d <= 9; d++)
	{
		solve(now, now * 10 - 1);
		now *= 10;
	}
	cout << ans << endl;

	return 0;
}