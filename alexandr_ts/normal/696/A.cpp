#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;

ll len(ll x) {
    ll ans = 0;
    while (x) {
        x >>= 1ll;
        ans++;
    }
    return ans;
}

ll LCA(ll v, ll u) {
    if (v == u)
        return v;
    if (v > u)
        return LCA(v / 2ll, u);
    return LCA(u / 2ll, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    map <ll, ll> up;
    int q;
    cin >> q;
    fr(i1, q) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            ll v, u, w;
            cin >> v >> u >> w;
            ll lca = LCA(v, u);
            while (v != lca) {
                up[v] += w;
                v /= 2;
            }
            while (u != lca) {
                up[u] += w;
                u /= 2;
            }
        }
        else {
            ll v, u;
            cin >> v >> u;
            ll ans = 0;
            ll lca = LCA(v, u);
            while (v != lca) {
                if (up.count(v))
                    ans += up[v];
                v /= 2;
            }
            while (u != lca) {
                if (up.count(u))
                    ans += up[u];
                u /= 2;
            }
            cout << ans << endl;
        }
    }
}