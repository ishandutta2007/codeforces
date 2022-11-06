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
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int64, int64 >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "d";

const int NMAX = 100010;

int n, used[NMAX];
int64 ans[NMAX], num[NMAX], sum[NMAX];
vector <int> g[NMAX], w[NMAX];
vector <pair<double, int> > q;

int64 solve(const vector <pii> &now)
{
	q.clear();
	forn(i, now.size())
		q.pb(mp((double) now[i].sc / now[i].fs, i));
	sort(all(q));
	int64 lvl = 0, res = 0;
	forn(i, q.size())
	{
		res += lvl * now[q[i].sc].fs;
		lvl += now[q[i].sc].sc;
	}
	return res;
}

void dfs(int v)
{
	used[v] = 1;
	ans[v] = 0;
	num[v] = 1;
	sum[v] = 0;
	vector <pii> zn;
	forn(i, g[v].size())
		if (!used[g[v][i]])
		{
			dfs(g[v][i]);
			ans[v] += ans[g[v][i]] + num[g[v][i]] * w[v][i];
			num[v] += num[g[v][i]];
			sum[v] += sum[g[v][i]] + w[v][i] * 2;
			zn.pb(mp(num[g[v][i]], sum[g[v][i]] + w[v][i] * 2));
		}
	ans[v] += solve(zn);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	forn(i, n - 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		g[x].pb(y);
		w[x].pb(z);
		g[y].pb(x);
		w[y].pb(z);
	}

	seta(used, 0);
	dfs(0);
	printf("%.10lf\n", (long double) ans[0] / (long double) (n - 1));

	return 0;
}