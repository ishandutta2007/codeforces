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
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (1 << 30) - 1;
int64 const inf64 = (1LL << 62) - 1;
const string name = "c";

const int NMAX = 52;
int n, m, k, num[NMAX];
int64 l[NMAX], d[NMAX], c[NMAX];
vector <int64> ans[NMAX][NMAX];
vector <pii> prev[NMAX][NMAX];

void way(int x, int y, int z)
{
	if (y == 0) return;
	way(prev[x][y][z].fs, y - 1, prev[x][y][z].sc);
	cout << num[x] + 1 << " " << z + l[x] << " " << endl;
}

pair <pair <int64, int64>, pair <int64, int64> > q[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> k;
	forn(i, m)
	{
		q[i].fs.sc = i;
		cin >> q[i].sc.fs >> q[i].sc.sc >> q[i].fs.fs;
	}
	sort(q, q + m);

	forn(i, m)
	{
		l[i] = q[i].sc.fs;
		d[i] = q[i].sc.sc;
		c[i] = q[i].fs.fs;
		num[i] = (int) q[i].fs.sc;
		d[i] -= l[i];
		forn(j, n + 1)
		{
			ans[i][j].resize((int) d[i] + 1);
			prev[i][j].resize((int) d[i] + 1);
			forn(f, ans[i][j].size())
				if (j == 1) ans[i][j][f] = l[i] + f;
				else ans[i][j][f] = -1;
		}
	}

	forn(i, m - 1)
		forn(j, n)
			forn(f, ans[i][j].size())
			if (ans[i][j][f] >= 0)
	{
				int64 now;
				int64 zn;
				zn = ans[i][j][f] + (l[i] + f) + k;
				now = (l[i] + f) + k;
				for (int t = i + 1; t < m; ++t)
					if (c[t] > c[i])
				{
					int64 ff = now - l[t];
					int w = (int) ff;
					if (ff >= 0 && ff <= d[t] && ans[t][j + 1][w] < zn)
					{
						ans[t][j + 1][w] = zn;
						prev[t][j + 1][w] = mp(i, f);
					}
				}

				zn = ans[i][j][f] + (l[i] + f) * k;
				now = (l[i] + f) * k;
				for (int t = i + 1; t < m; ++t)
					if (c[t] > c[i])
				{
					int64 ff = now - l[t];
					int w = (int) ff;
					if (ff >= 0 && ff <= d[t] && ans[t][j + 1][w] < zn)
					{
						ans[t][j + 1][w] = zn;
						prev[t][j + 1][w] = mp(i, f);
					}
				}
	}

	int64 best = -1;
	int x = -1, y = -1, z = -1;
	forn(i, m)
		forn(j, ans[i][n].size())
			if (ans[i][n][j] > best)
			{
				best = ans[i][n][j];
				x = i, y = n, z = j;
			}
	if (best == -1) cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		way(x, y, z);
	}

	return 0;
}