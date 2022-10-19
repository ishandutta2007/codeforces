#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to, fl, c, ind;

    edge(int _to, int _c, int _ind) {
        to = _to, fl = 0, c = _c, ind = _ind;
    }
};

const int maxn = 205;

vector<edge> g[maxn];

int used[maxn];

int s, t;

void add_edge(int u, int v, int c) {
    g[u].emplace_back(v, c, g[v].size());
    g[v].emplace_back(u, 0, (int)g[u].size() - 1);
}

int dfs(int v, int fl) {
    if (v == t) {
        return fl;
    }
    used[v] = 1;
    for (auto &e : g[v]) {
        if (e.fl < e.c && !used[e.to]) {
            int val = dfs(e.to, min(fl, e.c - e.fl));
            if (val != 0) {
                e.fl += val;
                g[e.to][e.ind].fl -= val;
                return val;
            }
        }
    }
    return 0;
}

const int maxval = 3e4 + 5;

bool prime[maxval];

void solve() {
    for (int i = 2; i < maxval; ++i) {
        prime[i] = true;
    }
    for (int i = 2; i < maxval; ++i) {
        if (prime[i]) {
            for (int j = i * 2; j < maxval; j += i) {
                prime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    s = n, t = n + 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            add_edge(s, i, 2);
            cnt++;
        } else {
            add_edge(i, t, 2);
        }
        for (int j = 0; j < n; ++j) {
            if (prime[a[i] + a[j]] && a[i] % 2 == 0) {
                add_edge(i, j, 1);
            }
        }
    }
    if (cnt * 2 != n) {
        cout << "Impossible\n";
        return;
    }
    int fl = 0;
    while (true) {
        for (int i = 0; i < n; ++i) {
            used[i] = 0;
        }
        int add = dfs(s, 1);
        fl += add;
        if (add == 0) {
            break;
        }
    }
    for (auto e : g[s]) {
        if (e.fl != 2) {
            cout << "Impossible\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        used[i] = 0;
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ans.push_back({});
            int v = i;
            while (v != -1) {
                ans.back().push_back(v);
                used[v] = 1;
                int u = -1;
                for (auto e : g[v]) {
                    if (!used[e.to] && abs(e.fl) == 1) {
                        u = e.to;
                    }
                }
                v = u;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto table : ans) {
        cout << table.size() << ' ';
        for (auto ind : table) {
            cout << ind + 1 << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}