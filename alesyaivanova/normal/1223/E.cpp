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

const int MAXN = 5e5 + 9;
vector<pii> g[MAXN];
int n, k;
int dp[MAXN][2];

void dfs(int v, int pr)
{
    int ans = 0;
    vector<int> cur;
    for (pii to : g[v])
    {
        if (to.ff == pr)
            continue;
        dfs(to.ff, v);
        ans += dp[to.ff][0];
        if (dp[to.ff][1] + to.ss - dp[to.ff][0] > 0)
            cur.pb(dp[to.ff][1] + to.ss - dp[to.ff][0]);
    }
    sort(cur.rbegin(), cur.rend());
    int sz = cur.size();
    for (int i = 0; i < min(sz, k - 1); i++)
        ans += cur[i];
    dp[v][1] = ans;
    if (sz >= k)
        dp[v][0] = ans + cur[k - 1];
    else
        dp[v][0] = ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        cin >> n >> k;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            g[a].pb(b, c);
            g[b].pb(a, c);
        }
        dfs(0, -1);
        cout << dp[0][0] << "\n";
        for (int i = 0; i < n; i++)
        {
            //cout << i + 1 << " " << dp[i][0] << " " << dp[i][1] << "\n";
            g[i].resize(0);
            g[i].shrink_to_fit();
        }
    }
}