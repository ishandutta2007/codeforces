#include <bits/stdc++.h>

using namespace std;

template<typename Fun>
struct y_combinator {
    const Fun fun;
 
    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}
 
    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        cin >> w[i];
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.emplace_back(w[i], i);
    }
    sort(v.begin(), v.end());
    vector<vector<int>> nw_a(n);
    vector<int> nw_w(n);
    for (int i = 0; i < n; ++i) {
        nw_a[i] = a[v[i].second];
        nw_w[i] = w[v[i].second];
    }
    a = nw_a;
    w = nw_w;
    struct node {
        int sz, count;
        unordered_map<int, node*> go;
        node(int _sz) {
            sz = _sz;
            count = 0;
        }
    };
    node *root = new node(0);
    auto add = y_combinator([&](auto add, node *nw, vector<int> &v, int pos) -> void {
        for (int i = pos + 1; i < (int) v.size(); ++i) {
            if (!nw->go[v[i]]) {
                nw->go[v[i]] = new node(nw->sz + 1);
            }
            add(nw->go[v[i]], v, i);
        }
        nw->count++;
    });
    auto del = y_combinator([&](auto del, node *nw, vector<int> &v, int pos) -> void {
        for (int i = pos + 1; i < (int) v.size(); ++i) {
            if (!nw->go[v[i]]) {
                nw->go[v[i]] = new node(nw->sz + 1);
            }
            del(nw->go[v[i]], v, i);
        }
        nw->count--;
    });
    auto get = y_combinator([&](auto get, node *nw, vector<int> &v, int pos) -> int {
        int val = 0;
        for (int i = pos + 1; i < (int) v.size(); ++i) {
            if (!nw->go[v[i]]) {
                nw->go[v[i]] = new node(nw->sz + 1);
            }
            val += get(nw->go[v[i]], v, i);
        }
        if (nw->sz == 0) {
            return val;
        }
        if (nw->sz % 2) {
            val += nw->count;
        } else {
            val -= nw->count;
        }
        return val;
    });
    int ans = -1;
    int r = 0;
    int count = 0;
    while (r < n && get(root, a[0], -1) == count) {
        add(root, a[r], -1);
        count++;
        r++;
    }
    for (int i = 0; i < r; ++i) {
        if (get(root, a[i], -1) == count) {
            continue;
        }
        while (get(root, a[i], -1) != count) {
            r--;
            count--;
            del(root, a[r], -1);
        }
        if (ans == -1 || ans > w[i] + w[r]) {
            ans = w[i] + w[r];
        }
    }
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