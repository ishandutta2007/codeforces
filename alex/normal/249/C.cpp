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
const string name = "c";

const int NMAX = 111111;
const int ZNMAX = 105;

int n, q, zn[NMAX];
double ept[7], p[NMAX][ZNMAX], ans, old[ZNMAX], c[5 * NMAX][7];

double calc(int x, int y, int xx, int yy)
{
	if (x < xx || y < yy) return 0;
	else return c[x][xx] * c[y][yy];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	forn(i, 5 * NMAX)
	{
		c[i][0] = 1;
		forn(j, 6)
			if (j) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}

	cin >> n;
	forn(i, n)
		cin >> zn[i];

	seta(p, 0);
	forn(i, n)
		p[i][zn[i]] = 1;
	cin >> q;
	ans = 0;
	forn(i, n)
		ans += p[i][0];
	forn(i, q)
	{
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		u--, v--;
		ans -= p[u][0];

		forn(j, ZNMAX)
			old[j] = p[u][j];
		seta(p[u], 0);
		forn(j, ZNMAX)
		{
			double sum = 0;
			forn(f, k + 1)
				sum += (ept[f] = calc(j, zn[u] - j, f, k - f));
			forn(f, k + 1)
				if (j >= f && sum > 1e-10) 
					p[u][j - f] += old[j] * ept[f] / sum;
		}
			
		zn[u] -= k, zn[v] += k;
		ans += p[u][0];
		printf("%.12lf\n", ans);
	}

	return 0;
}