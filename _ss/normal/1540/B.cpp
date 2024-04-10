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
const int N = 1e3 + 10;
const ll mod = 1e9 + 7;
ll dp[N][N], inv[N];

void build(int h)
{
    inv[1]=1;
    for (int i=2;i<=h;i++) inv[i]=mod-mod/i*inv[mod%i]%mod;
}

vi G[N], vt[N];
int h[N];
ll res = 0;

void dfs(int u, int r)
{
    vt[u].eb(u);
    for (int v : G[u])
        if (v != r)
        {
            h[v] = h[u] + 1;
            dfs(v, u);
            for (int i : vt[u])
                for (int j : vt[v])
                    if (i > j) res = (res + dp[h[i] + h[j] - 2 * h[u] + 1][h[j] - h[u] + 1]) % mod;
                    else res = (res + dp[h[i] + h[j] - 2 * h[u] + 1][h[i] - h[u] + 1]) % mod;
            for (int j : vt[v]) vt[u].eb(j);
        }
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    build(n);
    dp[2][2] = 1;
    for (int len = 3; len <= n; ++len)
    {
        dp[len][len] = 1;
        for (int pos = 2; pos < len; ++pos)
            dp[len][pos] = (dp[len - 1][pos - 1] + dp[len - 1][pos]) * inv[2] % mod;
    }
    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        G[u].eb(v);
        G[v].eb(u);
    }
    for (int root = 1; root <= n; ++root)
    {
        for (int i = 1; i <= n; ++i) h[i] = 0, vt[i].clear();
        dfs(root, 0);
    }
    res = res * inv[n] % mod;
    cout << res;
    return 0;
}