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
typedef vector<ll> vl;

const int N = 5e5 + 5;

int n, m, removed;

set<int> adj[N];
set<int> rem;
vector<int> star[N];
vector<int> down[N];
int p[N], q[N], bad[N], vis[N], cen[N], dg[N], par[N], used[N];

void reset_input() {
    cin >> n >> m;
    removed = 0;
    f0r(i, n) 
    adj[i].clear(), star[i].clear(), down[i].clear();
    f0r(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    f0r(i, n) {
        cen[i] = vis[i] = bad[i] 
            = p[i] = q[i] = dg[i] = par[i] = used[i] = 0;
        rem.insert(i);
    }
}

void destroy_vertex(int u) {
    p[u] = q[u] = n-1-removed;
    bad[u] = 1;
    rem.erase(u);
    trav(v, adj[u]) {
        adj[v].erase(u);
    }
    adj[u].clear();
    removed++;
}

void solve_case() {
    reset_input();
    vi dead;
    f0r(i, n) {
        if (sz(adj[i]) == n-1) {
            dead.eb(i);
        }
    }
    trav(t, dead) destroy_vertex(t);
    int cur = 0;
    f0r(i, n) {
        if (vis[i] || bad[i]) continue;
        vi comp;
        set<pi> use;
        function<void(int, int, int)> dfs = [&](int u, int a, int center) {
            par[u] = a;
            vis[u] = 1;
            
            comp.eb(u);

            if (rem.count(u)) rem.erase(u);
            vi go;
            trav(v, rem) {
                if (adj[u].count(v)) continue;
                go.eb(v);
            }   
            trav(v, go) {
                rem.erase(v);
            }
            trav(v, go) {
                dfs(v, u, center ^ 1);
            }
            down[u] = go;
            if (a != -1) down[u].eb(a);
            dg[u] = sz(down[u]);
            // cout << u << " " << a << endl;
            use.emplace(dg[u], u);
        };
        // cout << "--------------" << endl;

        dfs(i, -1, 0);
        while (sz(use)) {
            auto x = *use.begin();

            int u = x.s;
            int d = x.f;

            int center = par[u];


            if (center == -1) {
                use.erase({dg[u], u});
                continue;
            }
            
            if (used[center]) {
                use.erase({dg[u], u});
                continue;
            }
            used[center] = 1;
            // cout << u << " CHOSEN " << d << " " << center << endl;

            if (par[center] != -1 && dg[par[center]] == 1) {
                star[center].eb(par[center]);
            }

            trav(t, down[center]) {
                if (t == par[center]) continue;
                if (dg[t] != 1) continue;
                star[center].pb(t);
            }
            auto destroy = [&](int v) {
                trav(t, down[v]) {
                    if (use.count({dg[t], t}) == 0) continue;
                    use.erase({dg[t], t});
                    dg[t]--;
                    if (dg[t] == 0) {
                        continue;
                    }
                    use.emplace(dg[t], t);
                }
                // cout << v << " REM " << dg[v] << endl;
                // assert(use.count({dg[v], v}));
                if (use.count({dg[v], v})) use.erase({dg[v], v});
                dg[v] = 0;
            };
            destroy(center);
        }

        trav(center, comp) {
            if (star[center].empty()) continue;
            int lo = cur;
            int hi = cur + sz(star[center]);
            p[center] = lo;
            q[center] = hi;
            f1r(i, lo+1, hi+1) {
                int v = star[center][i-(lo+1)];
                p[v] = i;
                q[v] = i-1;
            } 
            cur += sz(star[center]) + 1;
        }
    }
    f0r(i, n) {
        cout << p[i]+1 << " ";
    }
    cout << '\n';
    f0r(i, n) {
        cout << q[i]+1 << " ";
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    f1r(tc, 1, tt+1) solve_case();
    return 0;
}