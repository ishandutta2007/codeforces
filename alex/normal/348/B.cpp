#pragma comment(linker, "/STACK:600000000")
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
const string name = "b";

const int NMAX = 100110;
const int64 WMAX = (int64) 1e13 + 1;

int n, zn[NMAX], used[NMAX];
int64 ept[NMAX];
vector<int> g[NMAX];

int64 gcd(int64 a, int64 b) {
	if (a == 0 || b == 0) return a + b;
	return gcd(b % a, a);
}

int64 dfs(int v) {
	used[v] = 1;
	int num = g[v].size();
	if (v != 0) num--;
	int64 res = 1;
	forn(i, g[v].size())
		if (!used[g[v][i]]) {
			int64 now = dfs(g[v][i]);
			if (now >= WMAX)
				return WMAX;
			int64 d = gcd(now, res);
			now /= d;
			if (n * WMAX / now < res || now * res >= WMAX)
				return WMAX;
			res *= now;
		}
	if (res * num >= WMAX) return WMAX;
	if (num > 0) res *= num;
	return res;
}

void paint(int v, int64 lvl) {
	used[v] = 1;
	int num = g[v].size();
	if (v != 0) num--;
	if (num == 0) ept[v] = lvl;
	forn(i, g[v].size()) {
		if (!used[g[v][i]]) {
			paint(g[v][i], lvl / num);
		}
	}
}

int may(int val) {
	forn(i, n) 
		if (ept[i] * val > zn[i]) return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	int64 sum = 0;
	forn(i, n) {
		scanf("%d", &zn[i]);
		sum += zn[i];
	}
	forn(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	seta(used, 0);
	int64 lvl = dfs(0);
	int bad = 0;
	seta(used, 0);
	paint(0, lvl);
	forn(i, n)
		if (ept[i] >= 1e9) bad = 1;
	if (lvl >= WMAX || bad) {
		cout << sum << endl;
		return 0;
	}

	int l = 0, r = (int) 1e9;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (may(m)) l = m;
		else r = m - 1;
	}
	cout << sum - lvl * l << endl;

	return 0;
}