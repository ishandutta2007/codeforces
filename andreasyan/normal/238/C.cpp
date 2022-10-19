#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 3003;

int n;
vector<pair<int, bool> > a[N];

int dp0[N];
void dfs0(int x, int p)
{
    dp0[x] = 0;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        dfs0(h, x);
        dp0[x] += dp0[h];
        if (a[x][i].second == false)
            ++dp0[x];
    }
}

int dp[N];
void dfs(int x, int p)
{
    dp[x] = dp0[x];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        dfs(h, x);
        if (a[x][i].second == true)
            dp[x] = min(dp[x], dp0[x] - dp0[h] + 1 + dp[h]);
        else
            dp[x] = min(dp[x], dp0[x] - dp0[h] - 1 + dp[h]);
    }
}

int ans = N;
void dfs1(int x, int p, int dpp, bool kp)
{
    ans = min(ans, dpp + dp[x]);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        if (a[x][i].second == false)
            dfs1(h, x, dpp + dp0[x] - dp0[h] - 1 + !(kp), a[x][i].second);
        else
            dfs1(h, x, dpp + dp0[x] - dp0[h] + !(kp), a[x][i].second);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(m_p(y, true));
        a[y].push_back(m_p(x, false));
    }
    for (int r = 1; r <= n; ++r)
    {
        dfs0(r, r);
        dfs(r, r);
        dfs1(r, r, 0, true);
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}