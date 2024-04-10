#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
vi G[N];
int val[N][2], n;
ll dp[N][2];

void dfs(int u, int r)
{
    dp[u][0] = dp[u][1] = 0;
    for (int v : G[u])
        if (v != r)
        {
            dfs(v, u);
            for (int i = 0; i <= 1; ++i)
            {
                ll mx = 0;
                for (int j = 0; j <= 1; ++j)
                    mx = max(mx, dp[v][j] + abs(val[u][i] - val[v][j]));
                dp[u][i] += mx;
            }
        }
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> val[i][0] >> val[i][1], G[i].clear();
        for (int i = 1, u, v; i < n; ++i)
        {
            cin >> u >> v;
            G[u].eb(v);
            G[v].eb(u);
        }
        dfs(1, 0);
        cout << max(dp[1][0], dp[1][1]) << "\n";
    }
    return 0;
}