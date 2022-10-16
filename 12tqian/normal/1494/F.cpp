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

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct DSU {
    std::vector<int> e;

    void init(int n) {
        e = std::vector<int>(n, -1);
    }

    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }

    bool same_set(int a, int b) {
        return get(a) == get(b);
    }

    int size(int x) {
        return -e[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) std::swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

template <bool directed> struct Euler {
    int n;
    std::vector<std::vector<std::pair<int, int>>> adj;
    std::vector<std::vector<std::pair<int, int>>::iterator> its;
    std::vector<bool> used;

    void init(int _n) {
        n = _n;
        adj.resize(n);
    }

    void ae(int u, int v) {
        int m = (int)used.size();
        used.push_back(false);
        adj[u].emplace_back(v, m);
        if (!directed) {
            adj[v].emplace_back(u, m);
        }
    }

    // We assume the graph is connected
    std::vector<std::pair<int, int>> euler_path() {
        int cnt = 0;
        for (int i = 0; i < n; i++) 
            cnt += (int)adj[i].size() % 2;
        if (cnt == 2) {
            for (int i = 0; i < n; i++) 
                if ((int)adj[i].size() % 2) 
                    return get_path(i);
        } else if (cnt == 0) {
            return get_path(0);
        }
        return {};
    }
    
    std::vector<std::pair<int, int>> get_path(int src = 0) {
        its.resize(n);
        std::vector<std::pair<int, int>> ans, s{{src, -1}};
        for (int i = 0; i < n; i++) {
            its[i] = adj[i].begin();
        }
        int lst = -1;
        while ((int)s.size()) {
            int x = s.back().first;
            auto& it = its[x];
            auto en = adj[x].end();
            while (it != en && used[it->second]) {
                ++it;
            }
            if (it == en) {
                if (lst != -1 && lst != x) {
                    return {};
                }
                ans.push_back(s.back());
                s.pop_back();
                if ((int)s.size()) {
                    lst = s.back().first;
                }
            } else {
                s.push_back(*it);
                used[it->second] = 1;
            }
        }
        if ((int)ans.size() != (int)used.size() + 1) {
            return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vi> g(n);
    vpi ed;
    f0r(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
        ed.eb(u, v);
    }
    int odd = 0;
    f0r(i, n) odd += (sz(g[i]) % 2 == 1);
    DSU D; 
    auto finish = [&](int c, vi bad) {
        vi mark(n);
        each(x, bad) mark[x] = 1;
        vector<vi> ng(n);
        Euler<false> E; E.init(n);
        f0r(i, n) {
            each(j, g[i]) {
                if (i == c && mark[j]) continue;
                if (mark[i] && j == c) continue;
                if (i < j) E.ae(i, j);
            }
        }
        auto path = E.get_path(c);
        vi res;
        each(x, bad) {
            res.pb(c);
            res.pb(x);
        }
        res.pb(-1);
        each(e, path) {
            res.pb(e.f);
        }
        reverse(all(res));
        cout << sz(res) << '\n';
        each(x, res) {
            if (x < 0) cout << x << " ";
            else cout << x + 1 << " ";
        }
        cout << '\n';
        exit(0);
    };
    auto check = [&](int c) {
        D.init(n);
        each(e, ed) {
            if (e.f == c || e.s == c) continue;
            D.unite(e.f, e.s);
        }
        vector<vi> lead(n);
        each(v, g[c]) {
            lead[D.get(v)].pb(v);
        }
        { // center is even
            vi bad;
            bool ok = true;
            f0r(i, n) {
                if (sz(lead[i]) == 0) continue;
                int cnt = 0;
                each(j, lead[i]) {
                    if (sz(g[j]) % 2 == 1) {
                        cnt++;  
                        bad.pb(j);
                    }
                }
                if (cnt == sz(lead[i]) && D.size(i) > 1) {
                    ok = false;
                    break;
                }
            }
            int num_odd = odd;
            if (sz(bad) % 2 == 1) {
                if (sz(g[c]) % 2 == 1) num_odd--;
                else num_odd++;
            }
            num_odd -= sz(bad);
            if (ok && num_odd == 0) { // delete everything in bad
                finish(c, bad);
            }
        }
        { // center is odd
            vi bad;
            vi all_done(n);
            int num = 0;
            f0r(i, n) {
                if (sz(lead[i]) == 0) continue;
                int cnt = 0;
                each(j, lead[i]) {
                    
                    if (sz(g[j]) % 2 == 1) {
                        cnt++;
                        bad.pb(j);
                    }
                }
                if (cnt == sz(lead[i]) && D.size(i) > 1) {
                    all_done[i] = 1;
                    num++;
                }
            }
            int num_odd = odd;
            if (sz(bad) % 2 == 1) {
                if (sz(g[c]) % 2 == 1) num_odd--;
                else num_odd++;
            }
            num_odd -= sz(bad);
            if (num <= 1 && num_odd == 0) { // check if one of bad can be not used
                each(x, bad) {
                    if (num) {
                        if (all_done[D.get(x)]) { // delete everything in bad except for this
                            vi nbad;
                            each(y, bad) {
                                if (y == x) continue;
                                nbad.pb(y);
                            }
                            finish(c, nbad);
                        }
                    } else { // delete everything in bad except for this
                        finish(c, bad);
                    }
                }
            } else if (num_odd == 2 && num == 0) {
                if (sz(bad) % 2 != sz(g[c]) % 2) {
                    finish(c, bad);
                }
            }
        }
    };
    Euler<false> E; E.init(n);
    f0r(i, n) { 
        each(j, g[i]) {
            if (j < i) E.ae(i, j);
        }
    }
    auto res = E.euler_path();
    if (sz(res)) {
        cout << sz(res) << '\n';
        each(e, res) cout << e.f + 1 << " ";
        cout << '\n';
        exit(0);
    }
    f0r(i, n) check(i);
    cout << 0 << '\n';
    return 0;
}