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
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "d";

int const NMAX = 260;
int const P = 1000000007;

int n, m, ans[NMAX], d[NMAX];
bool v[NMAX][NMAX], h[NMAX][NMAX];
char s[4 * NMAX][4 * NMAX];

void get(int x, int y)
{
	int cnt = 0;
	forn(i, 3)
		forn(j, 3)
			if (s[i + 4 * x + 1][j + 4 * y + 1] != '.') cnt++;
	if (cnt == 0 || cnt == 1 || cnt == 4 || cnt == 5) return;
	if (cnt == 2)
	{
		if (s[4 * x + 1][4 * y + 1] != '.') 
			v[x][y] = 0;
		else
			h[x][y] = 0;
		return;
	}
	if (cnt == 3)
	{
		if (s[4 * x + 1][4 * y + 1] != '.') 
			v[x][y] = 0;
		else
			h[x][y] = 0;
		return;
	}
	if (cnt == 6)
	{
		if (s[4 * x + 1][4 * y + 2] != '.') 
			v[x][y] = 0;
		else
			h[x][y] = 0;
		return;
	}
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m;
	forn(i, 4 * n + 1)
		scanf("%s", s[i]);

	seta(h, 1);
	seta(v, 1);
	forn(i, n)
		forn(j, m)
			get(i, j);

	seta(ans, 0);
	ans[0] = 1;
	forn(i, m + 1)
	{
		if (i > 1 && !(n & 1))
		{
			int ok = 1;
			forn(j, n)
				if (!v[j][i - 2] || !v[j][i - 1]) ok = 0;
			if (ok) 
				ans[i] = (P + ans[i] - ans[i - 2]) % P;
		}

		if (i < m && !(n & 1))
		{
			int ok = 1;
			forn(j, n)
				if (!v[j][i]) ok = 0;
			if (ok)
			{
				ans[i + 1] += ans[i];
				if (ans[i + 1] >= P)
					ans[i + 1] -= P;
			}
		}
				
		if (i < m - 1)
		{
			seta(d, 0);
			d[0] = 1;
			forn(j, n)
			{
				if (h[j][i] && h[j][i + 1])
				{
					d[j + 1] += d[j];
					if (d[j + 1] >= P)
						d[j + 1] -= P;
				}
				if (j < n - 1 && v[j][i] && v[j + 1][i] && v[j][i + 1] && v[j + 1][i + 1])
				{
					d[j + 2] += d[j];
					if (d[j + 2] >= P)
						d[j + 2] -= P;
				}
			}

			int sum = d[n];
			ans[i + 2] += ((long long) sum * ans[i]) % P;
			if (ans[i + 2] >= P)
				ans[i + 2] -= P;
		}
	}
	cout << ans[m] << endl;

	return 0;
}