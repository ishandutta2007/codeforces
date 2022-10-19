#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 33;

int n;
int a[N];

int z;
int t[N * M][2];

int dp[N * M];

void dfs(int pos, int d)
{
    if (t[pos][0])
        dfs(t[pos][0], d - 1);
    if (t[pos][1])
        dfs(t[pos][1], d - 1);
    if (!t[pos][0] && !t[pos][1])
        dp[pos] = 0;
    else if (t[pos][0] && !t[pos][1])
        dp[pos] = dp[t[pos][0]];
    else if (!t[pos][0] && t[pos][1])
        dp[pos] = dp[t[pos][1]];
    else
        dp[pos] = min(dp[t[pos][0]], dp[t[pos][1]]) + (1 << (d - 1));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        int pos = 0;
        for (int i = 29; i >= 0; --i)
        {
            int u;
            if ((x & (1 << i)))
                u = 1;
            else
                u = 0;
            if (!t[pos][u])
                t[pos][u] = ++z;
            pos = t[pos][u];
        }
    }
    dfs(0, 30);
    printf("%d\n", dp[0]);
    return 0;
}