#include <bits/stdc++.h>

using namespace std;

const int R = 1 << 19, inf = 1e9 + 7;

pair<int, int> mx[R * 2];

void change(int pos, pair<int, int> val) {
    pos += R;
    mx[pos] = val;
    for (pos /= 2; pos > 0; pos /= 2) {
        mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
    }
}

pair<int, int> get(int l, int r) {
    l += R;
    r += R;
    pair<int, int> ans = {0, 0};
    while (l < r) {
        if (l & 1) {
            ans = max(ans, mx[l++]);
        }
        if (r & 1) {
            ans = max(ans, mx[--r]);
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

const int maxn = 3e5 + 5;

vector<int> g[maxn];

int build(int l, int r) {
    int m = get(l, r).second;
    if (l < m) {
        g[m].push_back(build(l, m));
    }
    if (m + 1 < r) {
        g[m].push_back(build(m + 1, r));
    }
    return m;
}

int val[maxn], val2[maxn], sz[maxn];

void dfs(int v) {
    sz[v] = 1;
    for (auto u : g[v]) {
        val2[u] = min(val2[u], val2[v]);
        dfs(u);
        val[v] = max(val[v], val[u]);
        sz[v] += sz[u];
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        change(i, {p[i], i});
        g[i].clear();
    }
    int root = build(0, n);
    vector<int> a(n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        val[i] = a[i];
        if (val[i] == 0) {
            k++;
            val2[i] = inf;
        } else {
            val2[i] = val[i];
        }
    }
    dfs(root);
    vector<int> s(k - 1);
    for (int i = 0; i < k - 1; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    vector<int> d(q);
    for (int i = 0; i < q; ++i) {
        cin >> d[i];
    }
    vector<pair<pair<int, int>, int>> kek;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            kek.push_back({{val[i], val2[i]}, i});
        } else if (val[i] > val2[i]) {
            for (int i = 0; i < q; ++i) {
                cout << "NO\n";
            }
            return;
        }
    }
    sort(kek.begin(), kek.end());
    set<pair<int, int>> nw;
    vector<int> val_p(n);
    int pos = 0;
    map<int, int> pr;
    for (auto val : s) {
        while (pos < kek.size() && kek[pos].first.first <= val) {
            nw.insert({kek[pos].first.second, kek[pos].second});
            pos++;
        }
        auto it = nw.lower_bound({val, 0});
        if (it == nw.end()) {
            for (int i = 0; i < q; ++i) {
                cout << "NO\n";
            }
            return;
        }
        pr[val] = it->second;
        val_p[it->second] = val;
        nw.erase(it);
    }
    int l_ans = 0, r_ans = inf;
    set<int> s_nw;
    for (auto val : s) {
        s_nw.insert(val);
    }
    queue<int> qq;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && val_p[i] == 0) {
            l_ans = val[i];
            r_ans = val2[i];
            while (true) {
                auto it = s_nw.lower_bound(val[i]);
                if (it != s_nw.end() && *it <= val2[i]) {
                    qq.push(*it);
                    s_nw.erase(it);
                } else {
                    break;
                }
            }
        }
    }
    while (!qq.empty()) {
        auto v = qq.front();
        qq.pop();
        l_ans = min(l_ans, val[pr[v]]);
        r_ans = max(r_ans, val2[pr[v]]);
        while (true) {
            auto it = s_nw.lower_bound(val[pr[v]]);
            if (it != s_nw.end() && *it <= val2[pr[v]]) {
                qq.push(*it);
                s_nw.erase(it);
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        if (l_ans <= d[i] && d[i] <= r_ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}