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
const string name = "d";

struct Tans {
	int64 s, a, b, c;
	Tans(): s((int64) 6e18 + 1), a(0), b(0), c(0) {}
};

map <int64, Tans> M;
Tans best;
int n, num;
int64 V, a[30], b[30], lvl1, lvl2, may[11000];

void rec2(int now, int64 C, int64 B, int64 A)
{
	if (now == n)
	{
		if (2 * (A * B + A * C + B * C) < best.s)
		{
			best.s = 2 * (A * B + A * C + B * C);
			best.a = A;
			best.b = B;
			best.c = C;
		}
		return;
	}
	forn(i, b[now])
		C *= a[now];
	forn(i, b[now] + 1)
		if (B <= lvl2)
		{
			rec2(now + 1, C, B, A);
			B *= a[now];
			C /= a[now];
		}
		else break;
}

void rec1(int now, int64 A)
{
	if (now == n)
	{
		int64 X = (int64) (sqrt(0. + V / A) + 1e-3);
		int64 S = 2 * (2 * A * X + X * X);
		if (S < best.s)
		{
			lvl2 = X;
			rec2(0, 1, 1, A);
		}
		return;
	}
	forn(i, b[now])
		A *= a[now];
	ford(i, b[now] + 1)
	{
		b[now] -= i;
		if (A <= lvl1) rec1(now + 1, A);
		A /= a[now];
		b[now] += i;
	}
}

void solve()
{
	V = 1;
	cin >> n;
	forn(i, n)
	{
		cin >> a[i] >> b[i];
		forn(j, b[i])
			V *= a[i];
	}
	if (!M.count(V))
	{
		lvl1 = (int64) (pow((double) V, 1. / 3.) + 1e-3);
		Tans tmp;
		best = tmp;
		rec1(0, 1);
		M[V] = best;
	}
	cout << M[V].s << " " << M[V].a << " " << M[V].b << " " << M[V].c << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	int tst;
	cin >> tst;
	forn(i, tst)
	{
		solve();
		cerr << clock() << endl;
	}

	return 0;
}