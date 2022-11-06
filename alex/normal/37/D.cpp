#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

double const pi = 3.1415926535897932384626433832795;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < double, double >
#define mp make_pair
#define fs first
#define sc second

long long const P = 1000000007;
int const NMAX = 1002;
int const MMAX = 102;

int n, m, x[MMAX], y[MMAX];
long long d[MMAX][NMAX], c[NMAX][NMAX];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> m;
	n = 0;
	forn(i, m)
	{
		cin >> x[i];
		n += x[i];
	}
	forn(j, m)
		cin >> y[j];

	seta(c, 0);
	forn(i, n + 1)
	{
		c[i][0] = 1;
		forn(j, i)
			c[i][j + 1] = (c[i - 1][j] + c[i - 1][j + 1]) % P;
	}

	seta(d, 0);
	d[0][0] = 1;
	forn(i, m)
		forn(j, n + 1)
			if (d[i][j] > 0)
			{
				int all = -j;
				forn(f, i + 1)
					all += x[f];
				forn(w, y[i] + 1)
				{
					if (w > all) break;
					d[i + 1][j + w] = (d[i + 1][j + w] + c[all][w] * d[i][j]) % P;
				}
			}

	long long ans = d[m][n];
	forn(i, m)
	{
		ans = (ans * c[n][x[i]]) % P;
		n -= x[i];
	}
	cout << ans << endl;

	return 0;
}