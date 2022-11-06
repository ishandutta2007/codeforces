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
#define pss pair < short int, short int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "c";

int const NMAX = 100500;

int n, zn[NMAX], root;
int l[NMAX], r[NMAX], znmin[NMAX], znmax[NMAX], lzn[NMAX], rzn[NMAX];
pii q[NMAX];
double ans[NMAX];

void dfs(int v)
{
	znmin[v] = znmax[v] = zn[v];
	if (l[v] == -1 || r[v] == -1)
		return;
	dfs(l[v]);
	dfs(r[v]);
	lzn[v] = znmax[l[v]];
	rzn[v] = znmin[r[v]];
	znmin[v] = min(znmin[v], min(znmin[l[v]], znmin[r[v]]));
	znmax[v] = max(znmax[v], max(znmax[l[v]], znmax[r[v]]));
}

void solve(int v, int64 sum, int num, int ll, int rr)
{
	if (ll > rr) return;
	if (l[v] == -1 || r[v] == -1)
	{
		for (int i = ll; i <= rr; ++i)
			ans[q[i].sc] = (double) sum / num;
		return;
	}
	int pos = lower_bound(q + ll, q + rr + 1, mp(zn[v], 0)) - q;
	solve(l[v], sum + rzn[v], num + 1, ll, pos - 1);
	solve(r[v], sum + lzn[v], num + 1, pos, rr);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	seta(l, 255);
	seta(r, 255);
	forn(i, n)
	{
		int p;
		scanf("%d%d", &p, &zn[i]);
		p--;
		if (p < 0) root = i;
		else
		{
			if (l[p] == -1) l[p] = i;
			else
			{
				r[p] = i;
				if (zn[l[p]] > zn[r[p]])
					swap(l[p], r[p]);
			}
		}
	}

	cin >> n;
	forn(i, n)
	{
		scanf("%d", &q[i].fs);
		q[i].sc = i;
	}
	sort(q, q + n);
	dfs(root);
	solve(root, 0, 0, 0, n - 1);

	forn(i, n)
		printf("%.10lf\n", ans[i]);

	return 0;
}