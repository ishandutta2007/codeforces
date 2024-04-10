#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;
const int M = 1000000007;

int n;
int pp[N];
vector<int> a[N];
int g[N];

int dp[N][2];
int s[N], p[N];
void dfs(int x)
{
    if (g[x] == 1)
        dp[x][1] = 1;
    if (g[x] == 0)
        dp[x][0] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h);
        if (g[x] == 1)
        {
            dp[x][1] = ((dp[x][1] * 1LL * dp[h][1]) % M + (dp[x][1] * 1LL * dp[h][0])) % M;
        }
        if (g[x] == 0)
        {
            dp[x][0] = ((dp[x][0] * 1LL * dp[h][1]) % M + (dp[x][0] * 1LL * dp[h][0])) % M;
        }
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (i == 0)
            p[i] = (dp[h][0] + dp[h][1]) % M;
        else
            p[i] = (p[i - 1] * 1LL * (dp[h][0] + dp[h][1]) % M) % M;
    }
    for (int i = (int)a[x].size() - 1; i >= 0; --i)
    {
        int h = a[x][i];
        if (i == (int)a[x].size() - 1)
            s[i] = (dp[h][0] + dp[h][1]) % M;
        else
            s[i] = (s[i + 1] * 1LL * (dp[h][0] + dp[h][1]) % M) % M;
    }
    if (g[x] == 0)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            int u = 1;
            if (i > 0)
                u = (u * 1LL * p[i - 1]) % M;
            if (i < (int)a[x].size() - 1)
                u = (u * 1LL * s[i + 1]) % M;
            dp[x][1] += (dp[h][1] * 1LL * u) % M;
            dp[x][1] %= M;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &pp[i]);
        a[pp[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        scanf("%d", &g[i]);
    dfs(0);
    printf("%d\n", dp[0][1]);
    return 0;
}