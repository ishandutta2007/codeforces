#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int const NMAX = 1010;
int n, m, k;
int x[NMAX], y[NMAX], xx[NMAX], yy[NMAX], r[NMAX];
int g[NMAX][NMAX];

int main()
{
//      freopen("input.txt", "r", stdin);
//      freopen("output.txt", "w", stdout);

        cin >> n >> m >> k;
        forn(i, n)
                scanf("%d%d", &x[i], &y[i]);
        forn(i, m)
                scanf("%d%d%d", &r[i], &xx[i], &yy[i]);

        seta(g, 0);
        forn(i, n)
                forn(j, m)
                        if ((long long) (x[i] - xx[j]) * (x[i] - xx[j]) + (long long) (y[i] - yy[j]) * (y[i] - yy[j]) <= (long long) r[j] * r[j])
                                g[i][j] = 1;

        forn(i, k)
        {
                int ans = 0, x, y;
                scanf("%d%d", &x, &y);
		int now = 0;
                forn(f, m * 16)
		{
			if (now == m) now = 0;
                        ans += (g[x - 1][now] ^ g[y - 1][now]);
			now++;
		}
                printf("%d\n", ans / 16);
        }

        return 0;
}