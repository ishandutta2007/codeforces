#pragma comment(linker, "/STACK:100000000")
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
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "c";

const int NMAX = 4000010;
int n, m, num, ans;
int x[NMAX], y[NMAX], used[NMAX];

int calc(int x, int y)
{
	if (y == 0) return x;
	if (y == m - 1) return n + x;
	if (x == 0) return 2 * n + y - 1;
	if (x == n - 1) return 2 * n + m - 2 + y - 1;
	return -1;
}

inline bool good(int x, int y)
{
	return (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1);
}

void get(int x, int y, int dx, int dy, int &xx, int &yy)
{
	int d;
	if (x != 0)
	{
		d = -x * dx;
		xx = x + dx * d, yy = y + dy * d;
		if (good(xx, yy)) return;
	}
	if (x != n - 1)
	{
		d = (n - x - 1) * dx;
		xx = x + dx * d, yy = y + dy * d;
		if (good(xx, yy)) return;
	}
	if (y != 0)
	{
		d = -y * dy;
		xx = x + dx * d, yy = y + dy * d;
		if (good(xx, yy)) return;
	}
	if (y != m - 1)
	{
		d = (m - y - 1) * dy;
		xx = x + dx * d, yy = y + dy * d;
		if (good(xx, yy))
			return;
	}
	xx = yy = -1;
}

void dfs(int v)
{
	used[v] = true;
	int xx = x[v], yy = y[v], dx, dy;
	get(xx, yy, 1, 1, dx, dy);
	int now = calc(dx, dy);
	assert(now == -1 || (x[now] == dx && y[now] == dy));
	if (now >= 0 && !used[now]) dfs(now);

	get(xx, yy, 1, -1, dx, dy);
	now = calc(dx, dy);
	assert(now == -1 || (x[now] == dx && y[now] == dy));
	if (now >= 0 && !used[now]) dfs(now);
}

void add(int xx, int yy)
{
	x[num] = xx;
	y[num] = yy;
	num++;
}

int main()
{
//	freopen((name + ".in").data(), "r", stdin);
//	freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m;
	forn(i, n)
		add(i, 0);
	forn(i, n)
		add(i, m - 1);
	forn(i, m)
		if (i != 0 && i != m - 1)
			add(0, i);
	forn(i, m)
		if (i != 0 && i != m - 1)
			add(n - 1, i);

	seta(used, 0);
	forn(i, num)
		if (!used[i])
		{
			ans++;
			dfs(i);
		}

	cout << ans << endl;

	return 0;
}