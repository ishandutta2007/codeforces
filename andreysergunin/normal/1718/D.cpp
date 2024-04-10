#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  
 
    int tests = 1;
    cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        k += b[i] == 0;
    }

    vector<int> rest(k - 1);
    for (int i = 0; i < k - 1; ++i) {
        cin >> rest[i];
    }

    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    int m = 0;
    vector<int> st;
    vector<int> lf(n), rg(n);
    for (int i = 0; i < n; ++i) {
        while (m > 0 && a[st[m - 1]] < a[i]) {
            st.pop_back();
            --m;
        }
        lf[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
        ++m;
    }

    m = 0;
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (m > 0 && a[st[m - 1]] < a[i]) {
            st.pop_back();
            --m;
        }
        rg[i] = st.empty() ? n : st.back();
        st.push_back(i);
        ++m;
    }

    int root = max_element(all(a)) - a.begin();

    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        if (lf[i] == -1 && rg[i] == n) {
            assert(i == root);
            continue;
        } else if (lf[i] == -1) {
            g[rg[i]].push_back(i);
        }  else if (rg[i] == n) {
            g[lf[i]].push_back(i);
        } else if (a[lf[i]] < a[rg[i]]) {
            g[lf[i]].push_back(i);
        } else {
            g[rg[i]].push_back(i);
        }
    }


    bool ok = true;
    vector<int> lower(n), upper(n);
    function<int(int, int)> dfs = [&](int v, int up) {
        if (!b[v]) {
            upper[v] = up;
        }
        if (b[v] && up < b[v]) {
            ok = false;
        }
        int x = b[v];
        for (int u : g[v]) {
            x = max(x, dfs(u, b[v] ? min(up, b[v]) : up));
        }
        if (!b[v]) {
            lower[v] = x;
        }
        return x;
    };
    dfs(root, int(1e9));

    sort(all(rest));

    vector<pii> seg(n);
    vector<array<int, 3>> segs; 
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            continue;
        }
        int l = lower_bound(all(rest), lower[i]) - rest.begin();
        int r = upper_bound(all(rest), upper[i]) - rest.begin();
        segs.push_back({l, r, i});
        seg[i] = {l, r};
    }

    sort(all(segs));

    set<pii> setik;
    vector<int> par(k - 1, -1), rev(n, -1);
    for (int i = 0, j = 0; i < sz(rest); ++i) {
        while (j < sz(segs) && segs[j][0] == i) {
            setik.insert({segs[j][1], segs[j][2]});
            ++j;
        }
        while (!setik.empty()) {
            auto it = setik.begin();
            if (it->first == i) {
                setik.erase(it);
            } else {
                break;
            }
        }

        if (setik.empty()) {
            ok = false;
            break;
        }
        auto it = setik.begin();
        int id = it->second;
        setik.erase(it);
        par[i] = id;
        rev[id] = i;
    }

    if (!ok) {
        for (int i = 0; i < q; ++i) {
            cout << "NO\n";
        }
        return;
    }


    vector<int> cands;

    set<int> alive;
    for (int i = 0; i < k - 1; ++i) {
        alive.insert(i);
    }

    queue<int> que;

    for (int i = 0; i < n; ++i) {
        if (!b[i] && rev[i] == -1) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int id = que.front();
        que.pop();
        cands.push_back(id);
        auto [l, r] = seg[id];

        while (true) {
            auto it = alive.lower_bound(l);
            if (it == alive.end() || *it >= r) {
                break;
            }
            que.push(par[*it]);
            alive.erase(it);
        }
    }

    vector<pii> to_unite;
    for (int j : cands) {
        to_unite.emplace_back(lower[j], upper[j]);
    }
    sort(all(to_unite));

    vector<pii> final_segs;
    if (sz(to_unite) > 0) {
        int lf = to_unite[0].first, rg = to_unite[0].first;
        for (auto [l, r] : to_unite) {
            if (rg < l) {
                final_segs.emplace_back(lf, rg);
                lf = l;
                rg = r;
            } else {
                rg = max(r, rg);
            }
        }
        final_segs.emplace_back(lf, rg);
    }


    for (int i = 0; i < sz(queries); ++i) {
        int pos = lower_bound(all(final_segs), pii{queries[i], int(1.1e9)}) - final_segs.begin() - 1;
        cout << (pos >= 0 && final_segs[pos].first <= queries[i] && queries[i] <= final_segs[pos].second ? "YES\n" : "NO\n");
    }
}