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

const int NMAX = 5010;

int answer, n, h[NMAX], d[NMAX][NMAX], sum, yl;

void update(int l, int r)
{
	sum -= 2 * h[r];
	while (yl < n && sum < 0)
	{
		yl++;
		sum += h[yl];
	}
	if (yl == n) return;
	d[r + 1][yl] = min(d[r + 1][yl], d[l][r] + (yl - r - 1));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
		scanf("%d", &h[i]);

	forn(l, n)
		forn(r, n)
			d[l][r] = n;
	answer = n;
	d[0][0] = 0;
	forn(l, n)
	{
		sum = h[l], yl = l;
		update(l, l);
		int now = d[l][l];
		for (int r = l + 1; r < n; ++r)
		{
			d[l][r] = min(now + 1, d[l][r]);
			now = d[l][r];
			update(l, r);
		}
		answer = min(answer, d[l][n - 1]);
	}
	cout << answer << endl;

	return 0;
}