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

const int P = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);    

    int n; cin >> n;

    vector<vi> g(n);
    vector<ll> x(n);

    f0r(i, n) cin >> x[i];

    f0r(i, n-1) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].eb(v); 
        g[v].eb(u);
    }

    ll ans = 0;

    function<void(int, int, vpl)> dfs = [&](int u, int p, vpl path) {
        trav(t, path) {
            t.f = __gcd(t.f, x[u]);
        }
        path.eb(x[u], 1);
        trav(t, path) {
            ans += (t.f%P * t.s%P)%P;
        }
        vpl new_path;
        int i1 = 0;
        int i2 = 0;
        while (i1 != sz(path)) {
            while (i2 != sz(path)-1 && path[i2].f == path[i2+1].f) i2++;
            ll sum = 0;
            f1r(i, i1, i2+1) {
                sum += path[i].s;
            }
            ll val = path[i1].f;
            new_path.eb(val, sum);
            i1 = ++i2;
        }
        path.swap(new_path);
        trav(v, g[u]) {
            if (v == p) continue;
            dfs(v, u, path);
        }
    };

    dfs(0, -1, {});

    cout << ans%P << '\n';

    return 0;
}