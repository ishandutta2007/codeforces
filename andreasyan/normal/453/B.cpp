#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 102, m = 17;

int n;
int a[N];

bool c[N];
int z;
int u[N];
int xx[N], yy[N];

int dp[N][(1 << m)];
int p[N][(1 << m)];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    c[0] = c[1] = true;
    for (int i = 2; i <= 60; ++i)
    {
        if (c[i])
            continue;
        for (int j = i * i; j <= 60; j += i)
            c[j] = true;
    }
    for (int i = 1; i <= 60; ++i)
    {
        if (!c[i])
            u[i] = z++;
    }
    for (int i = 1; i <= 60; ++i)
    {
        for (int j = 1; j <= 60; ++j)
        {
            if (!c[j])
            {
                if ((i % j) == 0)
                    xx[i] += (1 << u[j]);
                else
                    yy[i] += (1 << u[j]);
            }
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int x = 0; x < (1 << m); ++x)
        {
            dp[i][x] = N * N;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 60; ++j)
        {
            for (int x = yy[j]; ; x = ((x - 1) & yy[j]))
            {
                if (dp[i - 1][x] + abs(a[i] - j) < dp[i][(x | xx[j])])
                {
                    dp[i][(x | (xx[j]))] = dp[i - 1][x] + abs(a[i] - j);
                    p[i][(x | (xx[j]))] = j;
                }
                if (x == 0)
                    break;
            }
        }
    }
    int ans = N * N;
    for (int x = 0; x < (1 << m); ++x)
        ans = min(ans, dp[n][x]);
    for (int x = 0; x < (1 << m); ++x)
    {
        if (ans == dp[n][x])
        {
            vector<int> v;
            for (int i = n; i >= 1; --i)
            {
                v.push_back(p[i][x]);
                x = (x ^ xx[p[i][x]]);
            }
            reverse(v.begin(), v.end());
            for (int i = 0; i < n; ++i)
                printf("%d ", v[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}