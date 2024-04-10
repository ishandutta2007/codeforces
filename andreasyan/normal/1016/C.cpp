#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;

int n, m;
long long a[3][N];

long long s[N];

long long u[3][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
            scanf("%lld", &a[i][j]);
    }
    long long ans = 0;
    for (int j = n; j >= 1; --j)
    {
        s[j] = s[j + 1];
        s[j] += a[1][j];
        s[j] += a[2][j];
    }
    for (int j = n; j >= 1; --j)
    {
        u[1][j] = u[1][j + 1] + a[2][j] * ((n - j + 1) * 2 - 1) + s[j + 1];
        u[2][j] = u[2][j + 1] + a[1][j] * ((n - j + 1) * 2 - 1) + s[j + 1];
    }
    long long yans = 0;
    long long t = 0;
    for (int j = 1; j <= n; ++j)
    {
        if (j % 2 == 1)
        {
            ans = max(ans, yans + u[1][j] + t * s[j]);
            for (int i = 1; i <= 2; ++i)
            {
                yans += t * a[i][j];
                ++t;
            }
        }
        else
        {
            ans = max(ans, yans + u[2][j] + t * s[j]);
            for (int i = 2; i >= 1; --i)
            {
                yans += t * a[i][j];
                ++t;
            }
        }
    }
    ans = max(ans, yans);
    printf("%lld\n", ans);
    return 0;
}