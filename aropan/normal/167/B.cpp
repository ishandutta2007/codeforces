#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

const int MAXN = 203;
const long double EPS = 1e-9;

long double f[MAXN][MAXN][MAXN + MAXN];
int n, l, k;
long double p[MAXN];
int a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i] /= 100;
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];

    f[0][0][MAXN + k] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < MAXN + MAXN; k++)
            {
//                if (f[i][j][k] < EPS) continue;
                if (a[i] < 0)
                    f[i + 1][j + 1][k - 1] += f[i][j][k] * p[i];
                else
                    f[i + 1][j + 1][min(k + a[i], MAXN + MAXN - 1)] += f[i][j][k] * p[i];
                f[i + 1][j][k] += f[i][j][k] * (1 - p[i]);
            }
    long double ans = 0;
    for (int i = l; i <= n; i++)
        for (int j = MAXN; j < MAXN + MAXN; j++)
            ans += f[n][i][j];
    printf("%.10lf\n", (double)ans);
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}