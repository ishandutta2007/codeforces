#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;

bool used[maxn * 2];

int val[maxn * 2], cmp[maxn * 2];

vector<int> ord;

vector<int> g[maxn * 2], _g[maxn * 2], g_st[maxn];

int tin[maxn], tout[maxn], pr[maxn];

int t = 0;

void dfs_st(int v) {
    tin[v] = ++t;
    for (auto u : g_st[v]) {
        if (u != pr[v]) {
            pr[u] = v;
            dfs_st(u);
        }
    }
    tout[v] = ++t;
}

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
    ord.push_back(v);
}

void col(int v, int c) {
    cmp[v] = c;
    for (auto u : _g[v]) {
        if (!cmp[u]) {
            col(u, c);
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g_st[u].push_back(v);
        g_st[v].push_back(u);
    }
    for (int i = 0; i < n * 2; ++i) {
        val[i] = -1;
    }
    dfs_st(0);
    while (q--) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        x--, y--;
        vector<int> v_st, v_f;
        int v = x;
        while (!(tin[v] <= tin[y] && tout[y] <= tout[v])) {
            v_st.push_back(v);
            v = pr[v];
        }
        v_st.push_back(v);
        v = y;
        while (!(tin[v] <= tin[x] && tout[x] <= tout[v])) {
            v_f.push_back(v);
            v = pr[v];
        }
        reverse(v_f.begin(), v_f.end());
        for (auto val : v_f) {
            v_st.push_back(val);
        }
        int fixed = -1, pos = -1;
        for (int i = 0; i < (int)v_st.size(); ++i) {
            if (val[v_st[i]] == -1) {
                val[v_st[i]] = s[i] - 'a';
                if (s.rbegin()[i] != s[i]) {
                    val[v_st[i] + n] = s.rbegin()[i] - 'a';
                } else {
                    g[v_st[i] + n].push_back(v_st[i]);
                }
            }
        }
        for (int i = 0; i < (int)v_st.size(); ++i) {
            if (s[i] != s.rbegin()[i]) {
                pos = i;
            }
            if (val[v_st[i]] != -1) {
                if (val[v_st[i]] != s[i] - 'a' && val[v_st[i] + n] != s[i] - 'a') {
                    fixed = 1;
                    break;
                } else if (val[v_st[i]] != s.rbegin()[i] - 'a' && val[v_st[i] + n] != s.rbegin()[i] - 'a') {
                    fixed = 0;
                    break;
                }
            }
        }
        if (fixed == -1 && pos == -1) {
            fixed = 0;
        }
        if (fixed == 1) {
            reverse(s.begin(), s.end());
        }
        if (fixed != -1) {
            for (int i = 0; i < (int)v_st.size(); ++i) {
                if (val[v_st[i]] != s[i] - 'a' && val[v_st[i] + n] != s[i] - 'a') {
                    cout << "NO\n";
                    return;
                } else if (val[v_st[i]] != s[i] - 'a') {
                    g[v_st[i]].push_back(v_st[i] + n);
                } else {
                    g[v_st[i] + n].push_back(v_st[i]);
                }
            }
        } else {
            int pos0 = (val[v_st[pos]] == s[pos] - 'a' ? 0 : 1);
            for (int i = 0; i < (int)v_st.size(); ++i) {
                if (s[i] != s.rbegin()[i] && i != pos) {
                    int pos0_nw = (val[v_st[i]] == s[i] - 'a' ? 0 : 1);
                    g[v_st[pos] + pos0 * n].push_back(v_st[i] + pos0_nw * n);
                    g[v_st[i] + pos0_nw * n].push_back(v_st[pos] + pos0 * n);
                    g[v_st[pos] + (1 - pos0) * n].push_back(v_st[i] + (1 - pos0_nw) * n);
                    g[v_st[i] + (1 - pos0_nw) * n].push_back(v_st[pos] + (1 - pos0) * n);
                } else if (s[i] == s.rbegin()[i]) {
                    if (val[v_st[i]] != s[i] - 'a') {
                        g[v_st[i]].push_back(v_st[i] + n);
                    } else {
                        g[v_st[i] + n].push_back(v_st[i]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n * 2; ++i) {
        for (auto j : g[i]) {
            _g[j].push_back(i);
        }
    }
    for (int i = 0; i < n * 2; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(ord.begin(), ord.end());
    int cnt = 0;
    for (auto v : ord) {
        if (cmp[v] == 0) {
            cnt++;
            col(v, cnt);
        }
    }
    string ans(n, 'a');
    for (int i = 0; i < n; ++i) {
        if (cmp[i] == cmp[i + n]) {
            cout << "NO\n";
            return;
        }
        if (cmp[i] > cmp[i + n]) {
            if (val[i] == -1) {
                ans[i] = 'a';
            } else {
                ans[i] = 'a' + val[i];
            }
        } else {
            if (val[i + n] == -1) {
                ans[i] = 'a';
            } else {
                ans[i] = 'a' + val[i + n];
            }
        }
    }
    cout << "YES\n";
    cout << ans << '\n';
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