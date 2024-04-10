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
#include <deque>

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

const int NMAX = 1001000;
int n, m, now, ans;
int a[NMAX], b[NMAX], zn[NMAX], ind[NMAX];

int nxt(int now)
{
	now++;
	if (now == n) now = 0;
	return now;
}

int nxt2(int now)
{
	now++;
	if (now == m) now = 0;
	return now;
}

int prin(int x, int l, int r)
{
	if (l <= r)
		return (x >= l && x <= r);
	else
		return (x >= l || x <= r);
}

void calc(int x)
{
	if (ind[x] == -1)
	{
		now++;
		return;
	}
	int r = ind[x], l = nxt2(ind[now]);
	while (nxt(now) != x)
	{
		int tmp = nxt(now);
		if (ind[tmp] == -1 || !prin(ind[tmp], l, r)) break;
		now = nxt(now);
		l = nxt2(ind[now]);
	}
	ans = max(ans, (n + now - x) % n + 1);
	if (now == x) now++;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, n)
		scanf("%d", &a[i]);
	seta(zn, 255);
	forn(i, m)
	{
		scanf("%d", &b[i]);
		zn[b[i]] = i;
	}
	forn(i, n)
		ind[i] = zn[a[i]];

	ans = 0;
	now = 0;
	forn(i, n)
		calc(i);
	cout << ans << endl;

	return 0;
}