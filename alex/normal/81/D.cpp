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
#define ford(i, n) for (int i = (int) (n) - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "d";

const int MMAX = 50;
const int NMAX = 1010;

int N, n, m, x[MMAX];
int ans[NMAX];
pii q[NMAX];

void solve1(int n, int c)
{
	n /= 2;
	forn(i, m)
		q[i] = mp(-x[i], i);
	sort(q, q + m);
	forn(i, m)
		q[i].fs = -q[i].fs;

	int yl = 0;
	forn(i, n)
		if (q[yl].fs > 0 && (i != 0 || q[yl].sc != c))
		{
			ans[2 * i] = q[yl].sc;
			q[yl].fs--;
		}
		else
		{
			yl++;
			i--;
			if (yl > m) return;
		}

	forn(i, n)
		if (q[yl].fs > 0 && ans[2 * i] != q[yl].sc && ans[2 * i + 2] != q[yl].sc)
		{
			ans[2 * i + 1] = q[yl].sc;
			q[yl].fs--;
		}
		else
		{
			yl++;
			i--;
			if (yl == m) return;
		}

	forn(i, N)
		cout << ans[i] + 1 << " ";
	exit(0);
}

void solve2(int n, int c)
{
	n /= 2;
	forn(i, m)
		q[i] = mp(-x[i], i);
	sort(q, q + m);
	forn(i, m)
		q[i].fs = -q[i].fs;

	int yl = 0;
	ford(i, n)
		if (q[yl].fs > 0 && (i != 0 || q[yl].sc != c))
		{
			ans[2 * i] = q[yl].sc;
			q[yl].fs--;
		}
		else
		{
			yl++;
			i++;
			if (yl > m) return;
		}

	ford(i, n)
		if (q[yl].fs > 0 && ans[2 * i] != q[yl].sc && ans[2 * i + 2] != q[yl].sc)
		{
			ans[2 * i + 1] = q[yl].sc;
			q[yl].fs--;
		}
		else
		{
			yl++;
			i++;
			if (yl == m) return;
		}

	forn(i, N)
		cout << ans[i] + 1 << " ";
	exit(0);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m;
	N = n;
	forn(i, n)
		cin >> x[i];

	if (n & 1)
	{
		forn(i, m)
		{
			ans[n - 1] = i;
			x[i]--;
			solve1(n - 1, i);
			solve2(n - 1, i);
			x[i]++;
		}
	}
	else
	{
		ans[n] = -1;
		solve1(n, -1);
		solve2(n, -1);
	}
	cout << -1 << endl;

	return 0;
}