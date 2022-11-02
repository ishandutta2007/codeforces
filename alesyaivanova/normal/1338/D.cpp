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
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
vector<int> g[maxn];
int dp[maxn][2];
int ans;
int n;

void dfs(int v, int pr)
{
    int ma1 = 0, ma2 = 0;
    for (int to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
            int x = max(dp[to][0], dp[to][1]);
            if (x > ma1)
            {
                ma2 = ma1;
                ma1 = x;
            }
            else if (x > ma2)
                ma2 = x;
        }
    }
    int sz = (int)g[v].size();
    if (pr != -1)
        sz--;
    ans = max(ans, ma1 + ma2 + max(0ll, sz - 2) + (pr != -1 ? 1 : 0));

    dp[v][0] = ma1 + max(0ll, sz - 1);

    ma1 = 0, ma2 = 0;
    for (int to : g[v])
    {
        if (to != pr)
        {
            int x = dp[to][0];
            if (x > ma1)
            {
                ma2 = ma1;
                ma1 = x;
            }
            else if (x > ma2)
                ma2 = x;
        }
    }

    ans = max(ans, ma1 + ma2 + 1);

    dp[v][1] = ma1 + 1;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    cout << ans;
}