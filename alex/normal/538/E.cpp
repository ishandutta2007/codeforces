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
const string name = "e";

const int NMAX = 201010;

int n;
vector<int> g[NMAX];
vector<pii> ans1[NMAX], ans2[NMAX];

pii solve_max(int v, int h) {
	if (g[v].size() == 0)
		return mp(0, 1);

	int sum = 0;
	forn(i, g[v].size()) {
		ans1[v].pb(solve_max(g[v][i], h + 1));
		sum += ans1[v].back().second;
	}
	int best = 0;

	if (h % 2 == 0)
		forn(i, ans1[v].size())
			best = max(best, sum - ans1[v][i].second + ans1[v][i].first);
	else {
		int now = 0;
		forn(i, ans1[v].size())
			now += ans1[v][i].first;
		best = max(best, now);
	}
	return mp(best, sum);
}

pii solve_min(int v, int h) {
	if (g[v].size() == 0)
		return mp(0, 1);

	int sum = 0;
	forn(i, g[v].size()) {
		ans2[v].pb(solve_min(g[v][i], h + 1));
		sum += ans2[v].back().second;
	}
	int best = sum - 1;

	if (h % 2 == 1)
		forn(i, ans2[v].size())
			best = min(best, ans2[v][i].first);
	else {
		int now = 0;
		forn(i, ans2[v].size())
			now += ans2[v][i].first;
		best = min(best, now + (int) ans2[v].size() - 1);
	}
	return mp(best, sum);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
	}

	cout << solve_max(0, 0).first + 1 << " " << solve_min(0, 0).first + 1 << endl;

	return 0;
}