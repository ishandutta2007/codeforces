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
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9 + 1;
int64 const inf64 = (int64) 4e18 + 1;
const string name = "b";

int l1, l2, r1, r2, k;
int64 ans;
vector <int> now;

void rec(int zn, int n)
{
	if (zn > 0) now.pb(n);
	if (zn == 9) return;
	rec(zn + 1, n * 10 + 4);
	rec(zn + 1, n * 10 + 7);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> l1 >> r1 >> l2 >> r2 >> k;
	ans = 0;
	now.clear();
	rec(0, 0);
	now.pb(0);
	now.pb(inf);
	sort(all(now));
	for (int i = 1; i < I now.size() - k; ++i)
	{
		int L1 = max(now[i - 1] + 1, l1);
		int R1 = min(now[i], r1);
		int L2 = max(now[i + k - 1], l2);
		int R2 = min(now[i + k] - 1, r2);
		if (L1 <= R1 && L2 <= R2)
			ans += (int64) (R1 - L1 + 1) * (int64) (R2 - L2 + 1);
	}
	for (int i = 1; i < I now.size() - k; ++i)
	{
		int L1 = max(now[i - 1] + 1, l2);
		int R1 = min(now[i], r2);
		int L2 = max(now[i + k - 1], l1);
		int R2 = min(now[i + k] - 1, r1);
		if (L1 <= R1 && L2 <= R2)
			ans += (int64) (R1 - L1 + 1) * (int64) (R2 - L2 + 1);
	}
	forn(i, I now.size())
		if (k == 1 && l1 <= now[i] && now[i] <= r1 && l2 <= now[i] && now[i] <= r2) ans--;
	printf("%.10lf\n", (double) ans / (double) (r2 - l2 + 1) / (double) (r1 - l1 + 1));

	return 0;
}