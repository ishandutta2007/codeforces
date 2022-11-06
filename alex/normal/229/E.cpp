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
const string name = "e";

int const NMAX = 1010;

int n, k, lvl, take[NMAX], maybe[NMAX];
vector <int> w, p[NMAX];
double ans[NMAX][NMAX], c[NMAX][NMAX];//, pp[NMAX][NMAX];

double calc(int y, int x)
{
	if (c[x][y] > 1e20) return 0;
	else return 1 / c[x][y];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	seta(c, 0);
	forn(i, NMAX)
	{
		c[i][0] = 1.;
		forn(j, i)
			c[i][j + 1] = c[i - 1][j] + c[i - 1][j + 1];
	}
	forn(i, k)
	{
		int num;
		scanf("%d", &num);
		forn(j, num)
		{
			int cc;
			scanf("%d", &cc);
			p[i].pb(cc);
			w.pb(cc);
		}
		sort(all(p[i]));
	}
	sort(all(w));
	lvl = w[w.size() - n];
	forn(i, k)
	{
		take[i] = 0, maybe[i] = 0;
		forn(j, p[i].size())
			if (p[i][j] >= lvl)
			{
				if (p[i][j] == lvl) maybe[i] = 1;
				take[i] = p[i].size() - j - maybe[i];
				break;
			}
	}
	int now = 0;
	for (int i = w.size() - n; i < w.size(); ++i)
		if (lvl == w[i]) now++;

	seta(ans, 0);
	//seta(pp, 0);
	ans[0][0] = 1;//pp[0][0] = 1;
	int ii = 0;
	forn(i, k)
	{
		int cnt = 0;
		for (int j = 0; j < k; ++j)
			cnt += maybe[j];
		forn(j, now + 1)
		{
			if (maybe[i])
			{
				ans[i + 1][j] += ans[i][j] * (ii - j + 1) / (ii + 1) * calc(take[i], p[i].size());
				ans[i + 1][j + 1] += ans[i][j] * (j + 1) / (ii + 1) * calc(take[i] + 1, p[i].size());
				//pp[i + 1][j] += pp[i][j] * (cnt - 1) / cnt;
				//pp[i + 1][j + 1] += pp[i][j] / cnt;
			}
			else
			{
				ans[i + 1][j] += ans[i][j] * calc(take[i], p[i].size());
				//pp[i + 1][j] += pp[i][j];
			}
		}
		if (maybe[i]) ii++;
	}
	printf("%.10lf\n", ans[k][now]);// / pp[k][now]);

	return 0;
}