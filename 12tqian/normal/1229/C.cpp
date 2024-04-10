#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;
typedef vector<ll> vl;

const int N = 1e5 + 5;
const int B = 305;

int n, m, q;

vi g[N]; // stores things pointing at u
int d[N];

ll c2(ll x) {
    return x * (x-1) / 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    f0r(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        d[u]++;
        d[v]++;
        g[u].pb(v);
    }

    cin >> q;

    ll ans = 0;
    f0r(i, n) {
        ans += 1LL * (d[i] - sz(g[i])) * sz(g[i]);
    }

    auto sub = [&](int u) {
        ans -= 1LL * (d[u] - sz(g[u])) * sz(g[u]);
    };
    
    auto add = [&](int u) {
        ans += 1LL * (d[u] - sz(g[u])) * sz(g[u]);
    };

    cout << ans << '\n';

    f0r(i, q) {
        int v; cin >> v;
        v--;

        trav(t, g[v]) {
            sub(t);
            g[t].pb(v);
            add(t);
        }

        sub(v);
        g[v].clear();
        add(v);

        cout << ans  << '\n';
    }



    return 0;
}