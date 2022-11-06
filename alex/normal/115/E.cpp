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
#define pii pair < int64, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "e";

const int NMAX = 200010;

struct rec{
	int l, r;
	int64 p;
	rec() {}
	rec(int L, int R, int64 P): l(L), r(R), p(P) {}
};

int64 ex[600000], t[600000], ans[600000];
int n, m;
int64 p[NMAX];
vector <rec> g[NMAX];

void push(int v)
{
	ex[2 * v] += ex[v];
	t[2 * v] += ex[v];
	ex[2 * v + 1] += ex[v];
	t[2 * v + 1] += ex[v];
	ex[v] = 0;
}

void update(int v, int l, int r, const rec &zn)
{
	if (r < zn.l || l > zn.r) return;
	if (l >= zn.l && r <= zn.r)
	{
		ex[v] += zn.p;
		t[v] += zn.p;
		return;
	}
	push(v);
	update(2 * v, l, (l + r) >> 1, zn);
	update(2 * v + 1, (l + r + 2) >> 1, r, zn);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m;
	forn(i, n)
		scanf("%d", &p[i]);
	rec zn;
	seta(t, 0);
	forn(i, m)
	{
		scanf("%d%d%I64d", &zn.l, &zn.r, &zn.p);
		zn.l--, zn.r--;
		g[zn.r].pb(zn);
	}

	forn(i, n)
	{
		int64 last = 0;
		if (i) last = ans[i - 1];
		update(1, 0, n - 1, rec(i, i, last));
		update(1, 0, n - 1, rec(0, i, -p[i]));
		forn(j, g[i].size())
			update(1, 0, n - 1, rec(0, g[i][j].l, g[i][j].p));
		ans[i] = max(last, t[1]);
	}
	cout << ans[n - 1] << endl;

	return 0;
}