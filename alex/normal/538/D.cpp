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
const string name = "d";

const int NMAX = 105;

int n, used[NMAX][NMAX];
char s[NMAX][NMAX], ans[NMAX][NMAX];

int good(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n) {
		scanf("%s", s[i]);
	}
	forn(i, 2 * n - 1)
		ans[i][2 * n] = '\0';

	seta(used, 0);
	for (int dx = -(n - 1); dx <= (n - 1); ++dx)
		for (int dy = -(n - 1); dy <= (n - 1); ++dy) {
			int ok = 1, ept = 0;
			forn(x, n)
				forn(y, n)
					if (s[x][y] == 'o') {
						if (good(x + dx, y + dy) && s[x + dx][y + dy] == '.')
							ok = 0;
						if (good(x + dx, y + dy) && s[x + dx][y + dy] == 'x')
							ept = 1;
					}
			if (ok && ept) {
				ans[n - 1 + dx][n - 1 + dy] = 'x';
				forn(x, n)
					forn(y, n)
						if (s[x][y] == 'o') {
							if (good(x + dx, y + dy))
								used[x + dx][y + dy] = 1;
						}
			}
			else
				ans[n - 1 + dx][n - 1 + dy] = '.';
		}
	ans[n - 1][n - 1] = 'o';

	forn(i, n)
		forn(j, n)
			if (s[i][j] == 'x' && !used[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
	cout << "YES" << endl;
	forn(i, 2 * n - 1)
		cout << ans[i] << endl;

	return 0;
}