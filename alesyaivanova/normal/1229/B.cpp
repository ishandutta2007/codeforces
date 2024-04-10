#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

const int MAXN = 100009;
vector<int> g[MAXN];
vector<pii> dp[MAXN];
int n;
int ans;
int x[MAXN];
int mod = 1e9 + 7;

void dfs(int v, int pr)
{
    if (pr != -1)
    {
        dp[v] = dp[pr];
        for (int i = 0; i < (int)dp[v].size(); i++)
            dp[v][i].ff = __gcd(dp[v][i].ff, x[v]);
        vector<pii> kek;
        for (int i = 0; i < (int)dp[v].size(); i++)
        {
            if (i > 0 && dp[v][i].ff == dp[v][i - 1].ff)
                kek.back().ss += dp[v][i].ss;
            else
                kek.pb(dp[v][i]);
        }
        dp[v].swap(kek);
    }
    if (!dp[v].empty() && dp[v].back().ff == x[v])
        dp[v].back().ss++;
    else
        dp[v].pb(x[v], 1);
    for (pii e : dp[v])
        ans = (ans + (e.ff % mod) * e.ss) % mod;
    for (int to : g[v])
    {
        if (to != pr)
            dfs(to, v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    cout << ans;
}