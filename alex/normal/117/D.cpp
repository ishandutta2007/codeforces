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

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "d";

int64 P, n, ans, A, B, L, R;
int m;

inline int64 calc(int64 zn, int64 p, int64 lvl)
{
	int64 max = (lvl - zn) / p * p + zn;
	if (max + p <= lvl) max += p;
	if (max > lvl) max -= p;
	int64 X = 1 + (max - zn) / p;
	int64 Y = max + zn;
	if ((X & 1) == 0) X >>= 1;
	else Y >>= 1;
	int64 res = ((X % P) * (Y % P)) % P;
	return res;
}

void sum(int64 l, int64 r, int64 zn, int64 p)
{
	if (L > r || l > R) return;
	if (L <= l && r <= R)
	{
		if (zn == p) zn = 0;
		ans += calc(zn, p, B) - calc(zn, p, A);
		if (ans < 0) ans += P;
		if (ans >= P) ans -= P;
		return;
	}
	sum(l, (l + r) >> 1, zn, 2 * p);
	sum((l + r + 2) >> 1, r, zn + p, 2 * p);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> P;
	forn(i, m)
	{
		cin >> L >> R >> A >> B;
		if (A > n)
			printf("0\n");
		else
		{
			B = min(n, B);
			A--;
			ans = 0;
			sum(1, n, 1, 1);
			printf("%d\n", ans);
		}
	}
	cerr << clock() << endl;

	return 0;
}