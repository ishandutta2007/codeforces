#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

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
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

const int MAXN = 500500; 

vector<int> g[MAXN];
int ldown[MAXN];
int lup[MAXN];

int res0[MAXN];
int res1[MAXN];
int res2[MAXN];
int res[MAXN];

int dfs0(int v, int p = -1) {
    for (int i = 0; i < sz(g[v]); ++i) {
        if (g[v][i] == p) {
            swap(g[v][i], g[v].back());
            g[v].pop_back();
            break;
        }
    }

    ldown[v] = 0;
    for (int u : g[v]) {
        ldown[v] = max(ldown[v], 1 + dfs0(u, v));
    }

    return ldown[v];
}

void dfs1(int v, int x = 0) {
    lup[v] = x;

    int d = sz(g[v]);
    vector<int> pref(d + 1), suff(d + 1);

    for (int i = 0; i < d; ++i) {
        pref[i + 1] = max(pref[i], ldown[g[v][i]] + 1);
    }
    
    for (int i = d - 1; i >= 0; --i) {
        suff[i] = max(suff[i + 1], ldown[g[v][i]] + 1);
    }    

    for (int i = 0; i < d; ++i) {
        dfs1(g[v][i], 1 + max({x, pref[i], suff[i + 1]}));
    }
}

void dfs2(int v) {
    for (int u : g[v]) {
        dfs2(u);
    }

    int d = sz(g[v]);
    
    vector<int> len(d);
    for (int i = 0; i < d; ++i) {
        len[i] = ldown[g[v][i]] + 1;
    }
    if (lup[v] != 0) {
        len.push_back(lup[v]);
        ++d;
    }
    sort(all(len));

    for (int i = 0; i < d; ++i) {
        res0[len[i]] = max(res0[len[i]], d - i);
        if (i == d - 1) {
            continue;
        }
        if (len[i + 1] >= len[i] + 1) {
            res1[len[i]] = max(res1[len[i]], d - i);
        }
        res1[len[i] - 1] = max(res1[len[i] - 1], d - i);
    }

    vector<pii> vct;
    set<pii> setik;

    vector<int> cnt(d);

    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];
        for (int w : g[u]) {
            vct.push_back({ldown[w] + 1, i});
        }
        if (sz(g[u]) > 0) {
            setik.insert({sz(g[u]), i});
        }
        cnt[i] = sz(g[u]);
    }

    if (lup[v] != 0) {
        vct.push_back({lup[v] - 1, d - 1});
        cnt[d - 1] = 1;
        setik.insert({1, d - 1});
    } 

    sort(all(vct));

    for (int i = 0; i < sz(vct); ) {
        int j = i;
        while (j < sz(vct) && vct[i].first == vct[j].first) {
            ++j;
        }

        int val = sz(setik);

        for (int k = i; k < j; ++k) {
            int id = vct[k].second;

            setik.erase({cnt[id], id});
            --cnt[id];
            
            if (cnt[id] > 0) {
                setik.insert({cnt[id], id});
            }
        }

        if (setik.empty()) {
            break;
        }

        auto it = setik.end();
        --it;

        val += it->first - 1;

        res2[vct[i].first + 1] = max(res2[vct[i].first + 1], val);

        i = j;
    }

    for (int u : g[v]) {
        vector<int> c;
        for (int w : g[u]) {
            c.push_back(ldown[w]);
        }
        sort(all(c));

        for (int i = 0; i < sz(c); ++i) {
            int val = len.end() - lower_bound(all(len), c[i] + 1);
            val += sz(c) - i;
            --val;
            res2[c[i] + 1] = max(res2[c[i] + 1], val);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        res[1] = max(res[1], sz(g[i]) + 1);
    }

    dfs0(0);
    dfs1(0);
    dfs2(0);

    for (int i = n - 1; i >= 0; --i) {
        res0[i] = max(res0[i], res0[i + 1]);
        res1[i] = max(res1[i], res1[i + 1]);
        res2[i] = max(res2[i], res2[i + 1]);
    }

    for (int k = 1; 2 * k <= n; ++k) {
        res[2 * k] = max(res0[k], res2[k]);
        res[2 * k + 1] = max(res0[k + 1], res1[k]);
    }

    for (int i = 1; i <= n; ++i) {
        res[i] = max(res[i], 1);
        cout << res[i] << " ";
    }
    cout << endl;
}