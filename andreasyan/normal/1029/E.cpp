#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
vector<int> a[N];

int dp[N][3];

void dfs(int x, int p)
{
    if (x == p)
    {
        dp[x][1] = N;
        dp[x][2] = N;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            dfs(h, x);
            dp[x][0] += dp[h][0];
        }
    }
    else if (p == 1)
    {
        dp[x][1] = N;
        dp[x][2] = N;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (h == p)
                continue;
            dfs(h, x);
            dp[x][0] += min(min(dp[h][0], dp[h][2]), dp[h][1]);
        }
    }
    else
    {
        dp[x][1] = 1;
        int minu = N;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (h == p)
                continue;
            dfs(h, x);
            dp[x][1] += min(min(dp[h][0], dp[h][2]), dp[h][1]);
            dp[x][0] += dp[h][2];
            dp[x][2] += min(dp[h][1], dp[h][2]);
            minu = min(minu, dp[h][1] - min(dp[h][1], dp[h][2]));
            dp[x][0] = min(dp[x][0], N);
            dp[x][2] = min(dp[x][2], N);
        }
        dp[x][2] += minu;
        dp[x][0] = min(dp[x][0], N);
        dp[x][2] = min(dp[x][2], N);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    printf("%d\n", dp[1][0]);
    return 0;
}