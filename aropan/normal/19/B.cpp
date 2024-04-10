#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 2022;
const long long INF = (long long)1000000000 * (long long)1000000000;

int n;
long long f[MAXN][MAXN + MAXN];
long long c;
int t;

void mini(long long &a, long long b)
{
    if (a <= b) return;
    a = b;
}

int main()
{
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        for (int j = -n; j <= n; j++)
            f[i][j + MAXN] = INF;

    f[0][0 + MAXN] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> t >> c;
        for (int j = -n; j <= n; j++)
            if (f[i][j + MAXN] < INF)
            {
//                printf("f[%d][%d] =  %lld\n", i, j, f[i][j + MAXN]);
                if (-n < j)
                    mini(f[i + 1][j + MAXN - 1], f[i][j + MAXN]);


                mini(f[i + 1][min(j + t, n) + MAXN], f[i][j + MAXN] + c);
            }
    }

    long long ans = INF;
    for (int i = 0; i <= n; i++)
        mini(ans, f[n][i + MAXN]);

    cout << ans << endl;

    return 0;
}