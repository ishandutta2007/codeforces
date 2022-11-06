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
const string name = "d";

const int NMAX = 100100;
int n, m, k, used[NMAX], ans[NMAX], us[NMAX];
vector <int> g[NMAX], x, y;

void dfs(int v, int zn)
{
	if (zn == 0) x.pb(v);
	else y.pb(v);
	used[v] = 1;
	forn(i, g[v].size())
		if (!used[g[v][i]]) dfs(g[v][i], zn ^ 1);
}

void answer(int now)
{
	now++;
	int cnt = 0;
	forn(i, x.size())
		if (ans[x[i]] == 0)
		{
			cnt++;
			ans[x[i]] = now;
			if (cnt == 3) cnt = 0, now++;
		}
	forn(i, y.size())
		if (ans[y[i]] == 0)
		{
			cnt++;
			ans[y[i]] = now;
			if (cnt == 3) cnt = 0, now++;
		}

	cout << "YES" << endl;
	forn(i, n)
		cout << ans[i] << " ";
	cout << endl;
	exit(0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	k = n / 3;
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	seta(used, 0);
	seta(ans, 0);
	forn(i, n)
		if (!used[i]) dfs(i, 0);
	if (x.size() % 3 == 0) answer(0);
	else
	{
		if (x.size() % 3 == 2) swap(x, y);
		forn(i, x.size())
			if ((int) g[x[i]].size() <= (int) y.size() - 2)
			{
				ans[x[i]] = 1;
				int cnt = 0;
				seta(used, 0);
				forn(j, g[x[i]].size())
					used[g[x[i]][j]] = 1;
				forn(j, y.size())
					if (!used[y[j]] && cnt < 2)
						cnt++, ans[y[j]] = 1;
				answer(1);
			}
			seta(us, 0);
		int calc = 0;
		if (y.size() % 3 == 2) swap(x, y);
		forn(i, x.size())
			if ((int) g[x[i]].size() <= (int) y.size() - 2)
			{
				ans[x[i]] = calc + 1;
				int cnt = 0;
				seta(used, 0);
				forn(j, g[x[i]].size())
					used[g[x[i]][j]] = 1;
				forn(j, y.size())
					if (!used[y[j]] && cnt < 2)
						cnt++, ans[y[j]] = calc + 1;
				calc++;
				if (calc == 2) answer(2);
			}		
	}
	cout << "NO" << endl;

	return 0;
}