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

const int N = 2e5 + 10;
const ll mod = 998244353;

struct edge {int v, x, y;};
vector<edge> G[N];
int n;
map<int, int> up, down, mx;
ll val[N], inv[N];
vector<pii> factor[N];

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}

void dfs(int u, int r)
{
    for (edge e : G[u])
        if (e.v != r)
        {
            int v = e.v;
            int x = e.x;
            int y = e.y;
            val[v] = val[u] * x % mod * inv[y] % mod;
            int g = __gcd(x, y);
            x /= g;
            y /= g;
            for (pii pa : factor[x])
            {
                int mn = min(pa.se, down[pa.fi]);
                down[pa.fi] -= mn;
                pa.se -= mn;
                up[pa.fi] += pa.se;
            }
            for (pii pa : factor[y])
            {
                int mn = min(pa.se, up[pa.fi]);
                up[pa.fi] -= mn;
                pa.se -= mn;
                down[pa.fi] += pa.se;
                mx[pa.fi] = max(mx[pa.fi], down[pa.fi]);
            }
            dfs(v, u);
            swap(x, y);
            for (pii pa : factor[x])
            {
                int mn = min(pa.se, down[pa.fi]);
                down[pa.fi] -= mn;
                pa.se -= mn;
                up[pa.fi] += pa.se;
            }
            for (pii pa : factor[y])
            {
                int mn = min(pa.se, up[pa.fi]);
                up[pa.fi] -= mn;
                pa.se -= mn;
                down[pa.fi] += pa.se;
                mx[pa.fi] = max(mx[pa.fi], down[pa.fi]);
            }
        }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1, u, v, x, y; i < n; ++i)
    {
        cin >> u >> v >> x >> y;
        G[v].pb({u, x, y});
        G[u].pb({v, y, x});
    }
    up.clear();
    down.clear();
    mx.clear();
    val[1] = 1;
    dfs(1, 0);
    ll res = 0;
    for (int i = 1; i <= n; ++i) res += val[i];
    res %= mod;
    for (pii pa : mx) res = res * modpow(pa.fi, pa.se) % mod;
    cout << res << "\n";
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    inv[1] = 1;
    for (int i = 2; i <= 2e5; ++i)
    {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
        if (factor[i].empty())
        {
            for (int j = i; j <= 2e5; j += i)
            {
                int cnt = 0, x = j;
                while (x % i == 0) x /= i, cnt++;
                factor[j].eb(i, cnt);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}