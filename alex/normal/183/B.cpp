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
typedef pair <int64, int64> pii;
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

const int NMAX = 1000100;
int x[NMAX], y[NMAX], zn[NMAX], ans[NMAX], n, m, glob;
vector < pair <pii, int64> > now;

int64 myabs(int64 a)
{
	if (a < 0) return -a;
	else return a;
}

int calc_point(pair <pii, int64> now, int tmp)
{
	int64 a = now.fs.fs, b = now.fs.sc, c = now.sc;
	if (a == 0)
	{
		if (c == 0) glob = max(glob, tmp);
		return 0;
	}
	if (myabs(c) % myabs(a) != 0 || -c / a > n || -c / a <= 0) return 0;
	else return (int) (-c / a);
}

int64 gcd(int64 a, int64 b)
{
	if (a > b) swap(a, b);
	if (a == 0) return b;
	else return gcd(b % a, a);
}

void add(int v, int u)
{
	int64 a = y[v] - y[u];
	int64 b = x[u] - x[v];
	int64 c = -a * x[v] - b * y[v];
	int64 d = gcd(myabs(a), gcd(myabs(b), myabs(c)));
	a /= d, b /= d, c /= d;
	if (a < 0 || (a == 0 && b < 0))
		a = -a, b = -b, c = -c;
	now.pb(mp(mp(a, b), c));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, m)
		scanf("%d%d", &x[i], &y[i]);
	forn(i, n + 1)
		ans[i] = 1;

	seta(zn, 0);
	forn(i, m + 1)
		zn[i * (i + 1) / 2] = i + 1;
	forn(i, m)
		forn(j, i)
			add(i, j);
	sort(all(now));
	now.pb(mp(mp(0, 0), 0));
	int last = 0;
	glob = 0;
	forn(i, now.size())
		if (i != 0 && now[i] != now[i - 1])
		{
			ans[calc_point(now[i - 1], zn[last])] = max(ans[calc_point(now[i - 1], zn[last])], zn[last]);
			last = 1;
		}
		else last++;

	int answer = 0;
	forn(i, n)
		answer += max(ans[i + 1], glob);
	cout << answer << endl;

	return 0;
}