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
const string name = "c";

const int NMAX = 888888;

int ans, n, g[NMAX], cnt[NMAX], l, r, t[2100100];
int64 ept[NMAX];

void update(int v, int l, int r, int p, int c)
{
	if (l > p || r < p) return;
	if (l == r)
	{
		t[v] = c;
		return;
	}
	update(2 * v, l, (l + r) >> 1, p, c);
	update(2 * v + 1, (l + r + 2) >> 1, r, p, c);
	t[v] = t[2 * v] + t[2 * v + 1];
}

int get(int v, int l, int r)
{
	if (l == r) return l;
	if (t[2 * v] < ((l + r) >> 1) - l + 1) return get(2 * v, l, (l + r) >> 1);
	return get(2 * v + 1, (l + r + 2) >> 1, r);
}

int calc(int64 zn)
{
	int ll = (int) (sqrt(sqrt(zn + 0.0)) - 0.000001) + 1;
	int rr = (int) (sqrt(zn + 0.0) + 0.000001);
//	cerr << ll << " " << rr << endl;
	while (l < ll) { cnt[g[l]]--; if (cnt[g[l]] == 0) update(1, 0, NMAX - 1, g[l], 0); l++; }
	while (r < rr) { r++; cnt[g[r]]++; if (cnt[g[r]] == 1) update(1, 0, NMAX - 1, g[r], 1); }
	return get(1, 0, NMAX - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	for (int i = 1; i <= 3; ++i)
		g[i] = 0;
	seta(t, 0);
	seta(cnt, 0);
	l = 2, r = 1;
	for (int i = 4; i < NMAX; ++i)
		g[i] = calc(i);

	cerr << clock() << endl;

	cin >> n;
	forn(i, n)
		scanf("%I64d", &ept[i]);
	sort(ept, ept + n);
	seta(t, 0);
	seta(cnt, 0);
	ans = 0, l = 2, r = 1;
	forn(i, n)
		ans ^= calc(ept[i]);
	if (ans) cout << "Furlo" << endl;
	else cout << "Rublo" << endl;

	return 0;
}