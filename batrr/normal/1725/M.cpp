#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

const ll mx = 1000000000;

#define X first
#define Y second

void solve() {
    ll n, m;
    cin >> n >> m;
    ll N = 2*n;
    vector<vector<pair<ll,ll>>> g(N);
    for (ll i=0;i<m;i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({v,c});
        g[v+n].push_back({u+n,c});
    }
    for (ll i=0;i<n;i++) g[i].push_back({i+n,0});
    vector<ll> D(N,mx*mx);
    set<pair<ll,ll>> kek;
    D[0] = 0;
    for (ll i=0;i<N;i++) kek.insert({D[i],i});
    while (kek.size()>0)
    {
        ll u = kek.begin()->Y;
        kek.erase({D[u],u});
        for (ll i=0;i<g[u].size();i++)
        {
            ll v = g[u][i].X;
            ll S = D[u]+g[u][i].Y;
            if (S<D[v])
            {
                kek.erase({D[v],v});
                D[v] = S;
                kek.insert({D[v],v});
            }
        }
    }
    for (ll i=1;i<n;i++)
    {
        if (D[n+i]<mx*mx) cout << D[n+i] << " ";
        else cout << -1 << " ";
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}