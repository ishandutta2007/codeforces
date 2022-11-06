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
#include <deque>

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
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int NMAX = 100010;

int num, n, m, k, tree[3 * NMAX];
pair <pii, pii> q[NMAX];
pair <int, pii> p[NMAX];
int ans[NMAX], x[NMAX], a[NMAX], r[NMAX], zn[NMAX];
pii tmp[NMAX];

int find_sum(int v, int l, int r, int ll, int rr)
{
	if (x[l] > rr || x[r] < ll) return 0;
	if (x[l] >= ll && x[r] <= rr) return tree[v];
	return find_sum(2 * v, l, (l + r) >> 1, ll, rr) + find_sum(2 * v + 1, (l + r + 2) >> 1, r, ll, rr);
}

void update_sum(int v, int l, int r, int p, int zn)
{
	if (x[l] > p || x[r] < p) return;
	if (x[l] == x[r])
	{
		tree[v] += zn;
		return;
	}
	update_sum(2 * v, l, (l + r) >> 1, p, zn);
	update_sum(2 * v + 1, (l + r + 2) >> 1, r, p, zn);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int find(int v, int l, int r, int ll, int rr)
{
	if (x[l] > rr || x[r] < ll) return -1;
	if (x[l] >= ll && x[r] <= rr) return tree[v];
	return max(find(2 * v, l, (l + r) >> 1, ll, rr), find(2 * v + 1, (l + r + 2) >> 1, r, ll, rr));
}

void update(int v, int l, int r, int p, int zn)
{
	if (x[l] > p || x[r] < p) return;
	if (x[l] == x[r])
	{
		tree[v] = max(tree[v], zn);
		return;
	}
	update(2 * v, l, (l + r) >> 1, p, zn);
	update(2 * v + 1, (l + r + 2) >> 1, r, p, zn);
	tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

void precalc()
{
	forn(i, n)
		tmp[i] = mp(r[i], i);
	sort(tmp, tmp + n);
	seta(tree, 0);
	int i = 0;
	while (i < n)
	{
		int j = i;
		while (j < n && tmp[i].fs == tmp[j].fs)
		{
			update_sum(1, 0, num - 1, a[tmp[j].sc], 1);
			j++;
		}
		j = i;
		while (j < n && tmp[i].fs == tmp[j].fs)
		{
			zn[tmp[j].sc] = find_sum(1, 0, num - 1, a[tmp[j].sc] - k, a[tmp[j].sc] + k);
			j++;
		}
		i = j;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	forn(i, n)
		scanf("%d", &r[i]);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		x[i] = a[i];
	sort(x, x + n);
	num = unique(x, x + n) - x;
	precalc();
	forn(i, n)
		p[i] = mp(r[i], mp(a[i], zn[i]));
	sort(p, p + n);
	reverse(p, p + n);

	cin >> m;
	forn(i, m)
	{
		scanf("%d%d", &q[i].sc.fs, &q[i].sc.sc);
		q[i].sc.fs--, q[i].sc.sc--;
		if (a[q[i].sc.fs] > a[q[i].sc.sc])
			swap(q[i].sc.fs, q[i].sc.sc);
		q[i].fs = mp(max(r[q[i].sc.fs], r[q[i].sc.sc]), i);
	}
	sort(q, q + m);
	reverse(q, q + m);

	seta(tree, 255);
	int y1 = 0, y2 = 0;
	while (y2 < m)
	{
		if (y1 == n || q[y2].fs.fs > p[y1].fs)
		{
			ans[q[y2].fs.sc] = find(1, 0, num - 1, a[q[y2].sc.sc] - k, a[q[y2].sc.fs] + k);
			y2++;
		}
		else
		{
			update(1, 0, num - 1, p[y1].sc.fs, p[y1].sc.sc);
			y1++;
		}
	}
	forn(i, m)
		printf("%d\n", ans[i]);

	return 0;
}