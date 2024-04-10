#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005, M = 998244353;

int n;
vector<int> a[N];

int dp[N][3];

void dfs(int x, int p)
{
    dp[x][0] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        int u = (dp[h][0] * 2) % M;
        u = (u + (dp[h][1] * 2) % M) % M;
        u = (u + dp[h][2]) % M;
        dp[x][0] = (dp[x][0] * 1LL * u) % M;
    }
    dp[x][2] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        int u = (dp[h][0]);
        u = (u + dp[h][1]) % M;
        dp[x][2] = (dp[x][2] * 1LL * u) % M;
    }
    dp[x][1] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        int u = (dp[h][0] * 2) % M;
        u = (u + dp[h][1]) % M;
        dp[x][1] = (dp[x][1] * 1LL * u) % M;
    }
    dp[x][1] = (dp[x][1] - dp[x][2] + M) % M;
}

void solv()
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
    int ans = (dp[1][1] + dp[1][0]) % M;
    ans = (ans - 1 + M) % M;
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}