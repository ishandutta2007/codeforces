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

const int NMAX = 100100;
int n, m, t[NMAX], x[NMAX], ans[NMAX];
pii zn[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, n)
		scanf("%d%d", &t[i], &x[i]);
	int now = 0;
	forn(i, (n + m - 1) / m)
	{
		int l = i * m;
		int r = min((i + 1) * m, n);
		int num = 0;
		for (int j = l; j < r; ++j)
		{
			now = max(now, t[j]);
			zn[num++] = mp(x[j], j);
		}
		sort(zn, zn + num);
		int cnt = 1;
		now += zn[0].fs;
		ans[zn[0].sc] = now;
		for (int i = 1; i < num; ++i)
			if (zn[i].fs == zn[i - 1].fs)
			{
				ans[zn[i].sc] = ans[zn[i - 1].sc];
				cnt++;
			}
			else
			{
				now += zn[i].fs - zn[i - 1].fs + 1 + cnt / 2;
				ans[zn[i].sc] = now;
				cnt = 1;
			}
		now += zn[num - 1].fs + 1 + cnt / 2;
	}
	forn(i, n)
		printf("%d ", ans[i]);

	return 0;
}