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

const int N = 2e5 + 5;

int fib[N];
int id[N];
vi f;

void fail() {
    cout << "NO" << '\n';
    exit(0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    f0r(i, N) id[i] = -1;
    f.pb(1); f.pb(2);
    while (true) {
        int x = f.back();
        int y = f[sz(f) - 2];
        if (x + y >= N) break;
        f.pb(x + y);
    }
    f0r(i, sz(f)) id[f[i]] = i;
    each(x, f) fib[x] = 1;

    int n; cin >> n;
    vector<set<int>> g(n);
    f0r(i, n - 1) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    vi sub(n);
    vi par(n);
    function<void(int)> solve = [&](int x) {
        int sz = 0;
        vi vert;
        function<void(int, int)> dfs = [&](int u, int p) {
            par[u] = p;
            sub[u] = 1;
            sz++;
            vert.pb(u);
            each(v, g[u]) {
                if (v == p) continue;
                dfs(v, u); 
                sub[u] += sub[v];
            }
        };
        dfs(x, -1);
        if (!fib[sz]) fail();
        if (sz <= 3) return;
        int ii = id[sz];
        int p = f[ii - 1];
        int q = f[ii - 2];
        bool good = false;
        each(i, vert) {
            if (sub[i] == p || sub[i] == q) {
                g[i].erase(par[i]);
                g[par[i]].erase(i);
                int j = par[i];
                solve(i);
                solve(j);
                good = true;
                break;
            }
        }
        if (!good) fail();
    };
    solve(0);
    cout << "YES" << '\n';
    return 0;
}