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
const string name = "c";

const int NMAX = 101;
const int MMAX = 30000;

int64 n;
int k, p[NMAX];
int M[MMAX][NMAX][2];

int64 calc(int i, int64 n, int sgn)
{
	if (n < MMAX)
	{
		int tmp = max(0, sgn);
		if (M[n][i][tmp] != inf)
			return M[n][i][tmp];
		if (i == k) return M[n][i][tmp] = (int) n * sgn;
		return M[n][i][tmp] = (int) (calc(i + 1, n, sgn) + calc(i + 1, n / p[i], -sgn));
	}
	else
	{
		if (i == k) return n * sgn;
		return calc(i + 1, n, sgn) + calc(i + 1, n / p[i], -sgn);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen((name + ".in").data(), "r", stdin);
    freopen((name + ".out").data(), "w", stdout);
#endif

	forn(i, MMAX)
		forn(j, NMAX)
			forn(f, 3)
				M[i][j][f] = inf;
    cin >> n >> k;
    forn(i, k)
		cin >> p[i];
    sort(p, p + k);
    reverse(p, p + k);
    cout << calc(0, n, 1) << endl;
	cerr << clock() << endl;

    return 0;
}