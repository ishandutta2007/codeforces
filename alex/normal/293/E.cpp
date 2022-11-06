#pragma comment(linker, "/STACK:600000000")
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

const int NMAX = 101010;

struct mystr {
	int n;
	vector<int> zn;

	void set_size(int sz)
	{
		n = sz + 2;
		vector<int> now;
		swap(now, zn);
		zn.resize(n);
	}

	void update(int x, int c)
	{
		x++;
		while (x < n)
		{
			zn[x] += c;
			x = x | (x + 1);
		}
	}

	int get(int x)
	{
		x++;
		x = min(x, n - 1);
		int res = 0;
		while (x > 0)
		{
			res += zn[x];
			x = (x & (x + 1)) - 1;
		}
		return res;
	}
};

int n, kill[NMAX], used[NMAX], num, W, L;
int sum[NMAX], dist[NMAX], vert[NMAX], prev[NMAX], dep[NMAX], tp[NMAX], max_dep[NMAX];
vector <int> g[NMAX], w[NMAX];
pair<int, pii> q[NMAX];
int64 ans;
mystr str[NMAX];

int rec(int v, int p)
{
	vert[num++] = v;
	sum[v] = 1;
	prev[v] = p;
	forn(i, g[v].size())
		if (!kill[g[v][i]] && g[v][i] != p)
			sum[v] += rec(g[v][i], v);
	return sum[v];
}

int find_med(int v)
{
	pii best = mp(n + 1, -1);
	rec(v, v);
	forn(i, num)
	{
		int now = 0, v = vert[i], tmp = 0;
		forn(j, g[v].size())
			if (!kill[g[v][j]] && prev[v] != g[v][j]) 
			{
				now = max(now, sum[g[v][j]]);
				tmp += sum[g[v][j]];
			}
		now = max(now, num - tmp - 1);
		best = min(best, mp(now, v));
	}
	return best.sc;
}

void dfs(int v, int p, int h, int len, int ept)
{
	if (ept != -1) max_dep[ept] = max(max_dep[ept], h);
	dist[v] = len;
	dep[v] = h;
	tp[v] = ept;
	forn(i, g[v].size())
		if (!kill[g[v][i]] && g[v][i] != p)
		{
			int tmp = ept;
			if (tmp == -1) tmp = g[v][i];
			dfs(g[v][i], v, h + 1, len + w[v][i], tmp);
		}
}

void solve(int v)
{
	num = 0;
	v = find_med(v);
	kill[v] = 1;

	forn(i, num)
		max_dep[vert[i]] = 0;
	dfs(v, v, 0, 0, -1);

	forn(i, num)
	{
		q[i] = mp(dist[vert[i]], mp(dep[vert[i]], tp[vert[i]]));
		max_dep[v] = max(max_dep[v], dep[vert[i]]);
	}
	sort(q, q + num);
	forn(i, num)
		str[vert[i]].set_size(max_dep[vert[i]]);

	int yl = 0;
	ford(i, num)
	{
		while (yl < num && q[i].fs + q[yl].fs <= W)
		{
			str[v].update(q[yl].sc.fs, 1);
			if (q[yl].sc.sc >= 0)
				str[q[yl].sc.sc].update(q[yl].sc.fs, 1);
			yl++;
		}
		ans += str[v].get(L - q[i].sc.fs);
		if (q[i].sc.sc >= 0)
			ans -= str[q[i].sc.sc].get(L - q[i].sc.fs);
	}
	ans--;

	forn(i, g[v].size())
		if (!kill[g[v][i]])
			solve(g[v][i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif


	cin >> n >> L >> W;
	forn(i, n - 1)
	{
		int x, y, z;
		scanf("%d%d", &y, &z);
		x = i + 1, y--;
		g[x].pb(y);
		w[x].pb(z);
		g[y].pb(x);
		w[y].pb(z);
	}
	seta(kill, 0);
	ans = 0;
	solve(0);
	cout << ans / 2 << endl;

	return 0;
}