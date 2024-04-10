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
const string name = "a";

int n, m, ans;
char s[110][10100];
vector <int> now[110];

int get(int x, int y)
{
	if (x > y) swap(x, y);
	return min(y - x, x + m - y);
}

int calc(int st)
{
	int res = 0;
	forn(i, n)
	{
		if (now[i].size() == 0) return inf;
		int idx = lower_bound(all(now[i]), st) - now[i].begin();
		int zn = inf;
		for (int j = -1; j <= 1; ++j)
			zn = min(zn, get(now[i][(now[i].size() + idx + j) % now[i].size()], st));
		res += zn;
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, n)
	{
			scanf("%s", s[i]);
			forn(j, m)
				if (s[i][j] == '1') now[i].pb(j);
	}

	ans = inf;
	forn(i, m)
		ans = min(ans, calc(i));
	if (ans < inf) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}