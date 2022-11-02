#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ss second
#define ff first
#define pii pair<int, int>
#define pb emplace_back

const int MAXN = 200009;
vector<pii> g[MAXN];
int n;
int dp[MAXN][4];
int ans;

void dfs(int v, int pr)
{
    for (auto to : g[v])
    {
        if (to.ff == pr)
            continue;
        dfs(to.ff, v);
        int cur[4] = {};
        if (to.ss == 0)
        {
            cur[0] = dp[to.ff][0] + 1;
            cur[1] = dp[to.ff][1] + dp[to.ff][3];
        }
        else
        {
            cur[3] = dp[to.ff][3] + 1;
            cur[2] = dp[to.ff][2] + dp[to.ff][0];
        }
        ans -= cur[0] * (cur[1] + cur[3]) + cur[2] * cur[3] + cur[0] * cur[0] + cur[3] * cur[3];
        for (int j = 0; j < 4; j++)
            dp[v][j] += cur[j];
    }
    ans += dp[v][0] * (dp[v][1] + dp[v][3]) + dp[v][2] * dp[v][3] + dp[v][1] + dp[v][2] +  2 * (dp[v][0] + dp[v][3]) + dp[v][0] * dp[v][0] + dp[v][3] * dp[v][3];
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].pb(b, c);
        g[b].pb(a, c);
    }
    dfs(0, -1);
    cout << ans;
}