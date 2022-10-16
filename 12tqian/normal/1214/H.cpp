#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef __int128_t i128;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    auto fail = [&]() {
        cout << "No" << '\n';
        exit(0);
    };

    int n, k; cin >> n >> k;
    vector<vi> g(n);
    vi dep(n);
    vi up(n);
    vi down(n);
    vi par(n);

    f0r(i, n-1) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    if (k == 2) {
        vi ans(n);
        auto dfs = [&](auto& self, int u, int p) -> void { 
            each(v, g[u]) {
                if (v == p) continue;
                ans[v] = ans[u] ^ 1;
                self(self, v, u);
            }
        };
        dfs(dfs, 0, -1);
        cout << "Yes" << '\n';
        f0r(i, n) cout << ans[i]+1 << '\n';
        return 0;
    }

    auto dfs_precompute = [&](auto& self, int u, int p) -> void {
        par[u] = p;
        each(v, g[u]) {
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
        each(v, g[u]) {
            if (v == p) continue;
            ckmax(down[u], down[v] + 1);
        }
    };
    
    dfs_precompute(dfs_precompute, 0, -1);

    auto dfs_up = [&](auto& self, int u, int p, int top) -> void {
        up[u] = top;
        pi best = {0, 0};
        each(v, g[u]) {
            if (v == p) continue;
            ckmax(best.s, down[v] + 1);
            if (best.f < best.s) swap(best.f, best.s);
        }
        each(v, g[u]) {
            if (v == p) continue;
            int val = down[v] + 1;
            int nxt = top + 1;
            if (val == best.f) ckmax(nxt, best.s + 1);
            else ckmax(nxt, best.f + 1);
            self(self, v, u, nxt);
        }
    };

    dfs_up(dfs_up, 0, -1, 0);

    f0r(u, n) {
        vi go;
        if (par[u] != -1) {
            go.pb(up[u]);
        }
        each(v, g[u]) {
            if (v == par[u]) continue;
            go.pb(down[v] + 1);
        }
        sort(all(go));
        reverse(all(go));
        if (sz(go) >= 3) {
            int x = go[0];
            int y = go[1];
            int z = go[2];
            if (x + y >= k - 1 && y + z >= k - 1 && z + x >= k - 1) fail();
        }
    }

    auto get_far = [&](int x) -> int {
        vi dep(n);
        auto dfs = [&](auto& self, int u, int p) -> void {
            each(v, g[u]) {
                if (v == p) continue;
                dep[v] = dep[u] + 1;
                self(self, v, u);
            }
        };
        dfs(dfs, x, -1);
        pi best = {0, 0};
        f0r(i, n) ckmax(best, {dep[i], i});
        return best.s;
    };

    auto get_path = [&](int u, int v) -> vi {
        vi path;
        vi res;
        auto dfs = [&](auto& self, int u, int p) -> void {
            path.pb(u);
            if (u == v) res = path;
            each(v, g[u]) {
                if (v == p) continue;
                self(self, v, u); 
            }
            path.pop_back();
        };
        dfs(dfs, u, -1);
        return res;
    };

    vi ans(n);

    int x = get_far(0);
    int y = get_far(x);

    vi diam = get_path(x, y);

    vi vis(n);
    each(x, diam) vis[x] = 1;

    f0r(i, sz(diam)) ans[diam[i]] = i % k;
    f0r(i, sz(diam)) {
        int d = diam[i];
        auto dfs = [&](auto& self, int u, int p, int h) -> void {
            each(v, g[u]) {
                if (vis[v]) continue;
                if (v == p) continue;
                if (i < sz(diam) / 2) {
                    ans[v] = ((i - h - 1) % k + k) % k;
                } else {
                    ans[v] = (i + h + 1) % k;
                }
                self(self, v, u, h + 1);
            }
        };
        dfs(dfs, d, -1, 0);
    }

    cout << "Yes" << '\n';

    f0r(i, n) cout << ans[i]+1 << " ";
    cout << '\n';

    return 0;
}