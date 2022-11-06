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

const int P = 777777777;
const int NMAX = 262144;

int n, m, p, zn, w[4][4], start[NMAX];
int t[NMAX][4][4];

void recalc(int v)
{
	seta(t[v], 0);
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			if (w[i][j])
			{
				for (int ii = 1; ii <= 3; ++ii)
					for (int jj = 1; jj <= 3; ++jj)
					{
						t[v][ii][jj] += ((long long) t[2 * v][ii][i] * t[2 * v + 1][j][jj]) % P;
						if (t[v][ii][jj] >= P) t[v][ii][jj] -= P;
					}
			}
}

void build(int v, int l, int r)
{
	if (l == r)
	{
		t[v][1][1] = t[v][2][2] = t[v][3][3] = 1;
		return;
	}
	build(2 * v, l, (l + r) >> 1);
	build(2 * v + 1, (l + r + 2) >> 1, r);
	recalc(v);
}

void update(int v, int l, int r)
{
	if (l > p || r < p) return;
	if (l == r)
	{
		seta(t[v], 0);
		if (start[l] == 0) t[v][1][1] = t[v][2][2] = t[v][3][3] = 1;
		else t[v][start[l]][start[l]] = 1;
		return;
	}
	update(2 * v, l, (l + r) >> 1);
	update(2 * v + 1, (l + r + 2) >> 1, r);
	recalc(v);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	seta(start, 0);

	seta(w, 0);
	forn(i, 3)
		forn(j, 3)
			cin >> w[i + 1][j + 1];
	build(1, 0, n - 1);
	forn(i, m)
	{
		scanf("%d%d", &p, &zn);
		p--;
		start[p] = zn;
		update(1, 0, n - 1);
		int64 ans = 0;
		forn(ii, 4)
			forn(jj, 4)
				ans += t[1][ii][jj];
		printf("%d\n", ans % P);
	}

	return 0;
}