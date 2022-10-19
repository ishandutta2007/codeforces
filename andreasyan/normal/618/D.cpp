#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;
const long long INF = 200005000000009;

int n, xx, yy;
vector<int> a[N];

long long dp[N][2];

void dfs(int x, int p)
{
    dp[x][0] = dp[x][1] = INF;
    long long s = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        s += min(dp[h][0], dp[h][1]);
        s += yy;
    }
    dp[x][1] = s;
    long long min1 = INF, min2 = INF;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        long long u = -min(dp[h][0], dp[h][1]) - yy + dp[h][1] + xx;
        if (u <= min1)
        {
            min2 = min1;
            min1 = u;
        }
        else if (u <= min2)
            min2 = u;
    }
    dp[x][1] = min(dp[x][1], s + min1);
    dp[x][0] = min(dp[x][0], s + min1 + min2);
}

int main()
{
    scanf("%d%d%d", &n, &xx, &yy);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (yy <= xx)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (a[i].size() == n - 1)
            {
                printf("%lld\n", yy * 1LL * (n - 2) + xx);
                return 0;
            }
        }
        printf("%lld\n", yy * 1LL * (n - 1));
        return 0;
    }
    dfs(1, 1);
    printf("%lld\n", min(dp[1][0], dp[1][1]));
    return 0;
}