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
const int N = 1e6 + 10;
const ll mod = 1e9 + 7;
int a[3][N], n, p[N], vis[N];

void dfs(int u)
{
    vis[u] = 1;
    if (!vis[p[u]]) dfs(p[u]);
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
        int n;
        cin >> n;
        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= n; ++j) cin >> a[i][j];
        for (int i = 1; i <= n; ++i) p[a[1][i]] = a[2][i];
        int res = 1;
        for (int i = 1; i <= n; ++i) vis[i] = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) dfs(i), res = (res + res) % mod;
        cout << res << "\n";
    }
    return 0;
}