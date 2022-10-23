#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;
vi G[N];
int h[N], n, a[N];

void dfs(int u, int r)
{
    a[u] = 0;
    for (int v : G[u])
        if (v != r)
        {
            h[v] = h[u] + 1;
            if (h[u] & 1) a[u]++;
            else a[u]--;
            dfs(v, u);
        }
    if (u > 1)
    {
        if (h[u] & 1) a[u]++;
        else a[u]--;
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
        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 1, u, v; i < n; ++i)
        {
            cin >> u >> v;
            G[u].eb(v);
            G[v].eb(u);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}