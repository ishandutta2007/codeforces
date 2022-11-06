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
const string name = "b";

const int NMAX= 41;

int n, m;
char s[NMAX][NMAX];
int precalc[NMAX][NMAX];
int inpoint[NMAX][NMAX][NMAX][NMAX];
bool good[NMAX][NMAX][NMAX][NMAX];
int ans[NMAX][NMAX][NMAX][NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	int q;
	cin >> n >> m >> q;
	forn(i, n) {
		scanf("%s", s[i]);
	}
	forn(i, n)
		forn(j, m) {
			precalc[i][j] = 0;
			forn(ii, i + 1)
				forn(jj, j + 1)
					precalc[i][j] += (s[ii][jj] == '1');
		}

	seta(good, 0);
	forn(i, n)
		forn(j, m)
			forn(ii, i + 1)
				forn(jj, j + 1)
				{
					int sum = precalc[i][j];
					if (ii > 0) sum -= precalc[ii - 1][j];
					if (jj > 0) sum -= precalc[i][jj - 1];
					if (ii > 0 && jj > 0) sum += precalc[ii - 1][jj - 1];
					if (sum == 0) good[ii][jj][i][j] = 1;
				}

	forn(i, n)
		forn(j, m)
			ford(ii, i + 1)
				ford(jj, j + 1) {
					inpoint[ii][jj][i][j] = (int) good[ii][jj][i][j];
					if (i - 1 >= ii) inpoint[ii][jj][i][j] += inpoint[ii + 1][jj][i][j];
					if (j - 1 >= jj) inpoint[ii][jj][i][j] += inpoint[ii][jj + 1][i][j];
					if (j - 1 >= jj && i - 1 >= ii) inpoint[ii][jj][i][j] -= inpoint[ii + 1][jj + 1][i][j];
				}

	forn(i, n)
		forn(j, m)
			forn(ii, i + 1)
				forn(jj, j + 1)
				{
					int sum = inpoint[ii][jj][i][j];
					if (i - 1 >= ii) sum += ans[ii][jj][i - 1][j];
					if (j - 1 >= jj) sum += ans[ii][jj][i][j - 1];
					if (j - 1 >= jj && i - 1 >= ii) sum -= ans[ii][jj][i - 1][j - 1];
					ans[ii][jj][i][j] = sum;
				}

	forn(i, q) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1--, y1--, x2--, y2--;
//		cerr << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		printf("%d\n", ans[x1][y1][x2][y2]);
	}

	return 0;
}