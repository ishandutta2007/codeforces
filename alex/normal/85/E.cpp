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
#define pss pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "c";

int const NMAX = 5010;

int n, x[NMAX], y[NMAX], l[NMAX], h[NMAX], used[NMAX], fg;
vector <int> g[NMAX];
vector <pss> dl[NMAX * 2];
set <int> S;

void dfs(int v, int hh)
{
	h[v] = hh;
	used[v] = 1;
	forn(i, g[v].size())
		if (!used[g[v][i]]) dfs(g[v][i], hh + 1);
}

void add(int P, int V)
{
	g[P].pb(V);
	g[V].pb(P);
	seta(used, 0);
	dfs(P, 0);
}

int leader(int v)
{
	if (l[v] == v) return v;
	else return l[v] = leader(l[v]);
}

inline void unite(int v1, int v2)
{
	l[leader(v1)] = leader(v2);
	if (fg) add(v2, v1);
}

void solve(int ans)
{
	fg = 0;
	forn(i, n)
		leader(i);
	cout << ans << endl;
	forn(i, n)
		l[i] = i, h[i] = 0;
	int v1, v2;
	for (int i = 2 * NMAX - 1; i > ans; --i)
	{
		forn(j, dl[i].size())
		{
			v1 = dl[i][j].fs, v2 = dl[i][j].sc;
			unite(v1, v2);
		}
	}

	S.clear();
	forn(i, n)
		S.insert(leader(i));
	int st = S.size();
	int ans = 1;
	forn(i, st)
		ans = (ans * 2) % 1000000007;
	cout << ans << endl;
	exit(0);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	fg = 1;
	cin >> n;
	forn(i, n)
		scanf("%d%d", &x[i], &y[i]);
	forn(i, 2 * NMAX)
		dl[i].clear();
	forn(i, n)
		forn(j, i)
			dl[abs(x[i] - x[j]) + abs(y[i] - y[j])].pb(mp(j, i));

	forn(i, n)
		l[i] = i, h[i] = 0;
	int v1, v2;
	for (int i = 2 * NMAX - 1; i >= 0; --i)
	{
		forn(j, dl[i].size())
		{
			v1 = dl[i][j].fs, v2 = dl[i][j].sc;
			if (leader(v1) == leader(v2)) {
				if ((h[v1] & 1) == (h[v2] & 1)) solve(i);
			} else {
				unite(v1, v2);
			}
		}
	}
	solve(0);

	return 0;
}