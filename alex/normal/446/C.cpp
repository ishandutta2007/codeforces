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
const string name = "c";

const int NMAX = 301000;
const int P = 1000000009;

int n, m, val[NMAX];
int64 t[4 * NMAX], x[4 * NMAX], y[4 * NMAX], f[NMAX];

int64 calc_nth(int64 x, int64 y, int n) {
	if (n == 1) return x;
	return (f[n - 2] * x + f[n - 1] % P * y) % P;
}

int64 calc_sum(int64 x, int64 y, int n) {
	return (f[n] * x + (f[n + 1] - 1 + P) % P * y) % P;
}

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = val[l];
		return;
	}
	build(2 * v, l, (l + r) >> 1);
	build(2 * v + 1, (2 + l + r) >> 1, r);
	t[v] = (t[2 * v] + t[2 * v + 1]) % P;
}

void push(int v, int l, int r) {
	x[2 * v] = (x[2 * v] + x[v]) % P;
	y[2 * v] = (y[2 * v] + y[v]) % P;
	x[2 * v + 1] = (x[2 * v + 1] + calc_nth(x[v], y[v], ((l + r) >> 1) - l + 2)) % P;
	y[2 * v + 1] = (y[2 * v + 1] + calc_nth(x[v], y[v], ((l + r) >> 1) - l + 3)) % P;
	x[v] = 0;
	y[v] = 0;
}

int64 weight(int v, int l, int r) {
	return (t[v] + calc_sum(x[v], y[v], r - l + 1)) % P;
}

void update(int v, int l, int r, int ll, int rr, int64 a, int64 b) {
	if (l > rr || r < ll) return;
	if (ll <= l && r <= rr) {
		x[v] = (x[v] + calc_nth(a, b, 1 + l - ll)) % P;
		y[v] = (y[v] + calc_nth(a, b, 2 + l - ll)) % P;
		return;
	}
	push(v, l, r);
	update(2 * v, l, (l + r) >> 1, ll, rr, a, b);
	update(2 * v + 1, (2 + l + r) >> 1, r, ll, rr, a, b);
	t[v] = (weight(2 * v, l, (l + r) >> 1) + weight(2 * v + 1, (2 + l + r) >> 1, r)) % P;
}

int64 get(int v, int l, int r, int ll, int rr) {
	if (l > rr || r < ll) return 0;
	if (ll <= l && r <= rr)
		return weight(v, l, r);
	push(v, l, r);
	t[v] = (weight(2 * v, l, (l + r) >> 1) + weight(2 * v + 1, (2 + l + r) >> 1, r)) % P;
	int64 a = get(2 * v, l, (l + r) >> 1, ll, rr);
	int64 b = get(2 * v + 1, (2 + l + r) >> 1, r, ll, rr);
	return (a + b) % P;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	seta(x, 0);
	seta(y, 0);
	f[0] = 0, f[1] = 1, f[2] = 1;
	forn(i, NMAX)
		if (i > 2) f[i] = (f[i - 2] + f[i - 1]) % P;

	cin >> n >> m;
	forn(i, n)
		scanf("%d", &val[i]);
	build(1, 0, n - 1);

	forn(i, m) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		l--, r--;
		if (op == 1) update(1, 0, n - 1, l, r, 1, 1);
		if (op == 2) printf("%d\n", (int) get(1, 0, n - 1, l, r));
	}

	return 0;
}