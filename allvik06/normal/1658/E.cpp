#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct Fenwick {
    int n;
    vector <int> f;

    inline Fenwick(int n) : n(n) {
        f.resize(n + 1);
    }

    inline void add(int i, int x) {
        for (++i; i <= n; i += (i & (-i))) f[i] ^= x;
    }

    inline int get_pref(int i) {
        int x = 0;
        for (++i; i > 0; i -= (i & (-i))) x ^= f[i];
        return x;
    }

    inline int get_seg(int l, int r) {
        if (l > r) return 0;
        return get_pref(r) ^ get_pref(l - 1);
    }
};

void solve1() {
    int n, m, q;
    cin >> n >> m;
    vector <int> c(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x - 1] ^= 1;
    }
    cin >> q;
    vector <int> ans(q), cur_d;
    vector <vector <pair <int, int>>> all_q(m);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r; --l; --r;
        all_q[r].emplace_back(l, i);
    }
    Fenwick all_d(0), val(0);
    for (int b = 0; b < 20; ++b) {
        int ln = (2 << b);
        cur_d.assign(ln, 0);
        all_d = Fenwick(ln);
        val = Fenwick(m);
        int prev = -1;
        for (int i = 0; i < m; ++i) {
            int pos = i - ln + 1;
            if (pos >= 0) {
                prev = pos;
                int o = pos % ln;
                val.add(pos, cur_d[o]);
                cur_d[o] ^= c[i];
                all_d.add(o, c[i]);
            }
            for (auto j : all_q[i]) {
                int x = 0;
                int l = max(0, j.first - (1 << b) + 1);
                int r = min(j.first, prev);
                x ^= val.get_seg(l, r);
                int start_o = l % ln;
                int end_o = r % ln;
                if (l <= r) {
                    if (start_o <= end_o) x ^= all_d.get_seg(start_o, end_o);
                    else x ^= all_d.get_seg(start_o, ln - 1) ^ all_d.get_pref(end_o);
                }
                if (x) ans[j.second] = 1;
            }
        }
    }
    for (int i : ans) {
        if (i) cout << "A";
        else cout << "B";
    }
}

void solve2() {
    int n, m, q;
    cin >> n >> m;
    vector <int> c(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x - 1] ^= 1;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, x = 0;
        cin >> l >> r; --l; --r;
        for (int j = l; j <= r; ++j) {
            if (c[j]) x ^= (j - l);
        }
        if (x) cout << "A";
        else cout << "B";
    }
}

inline int dist(pair <int, int> x, pair <int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}
signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, k;
    cin >> n >> k;
    vector <pair <int, int>> all(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            all[x - 1] = make_pair(i, j);
        }
    }
    int ans[n][n];
    pair <int, int> cur1 = all[n * n - 1];
    auto cur2 = cur1;
    auto cur3 = cur1;
    auto cur4 = cur1;
    for (int i = n * n - 1; i >= 0; --i) {
        auto x = all[i];
        if (dist(x, cur1) > k || dist(x, cur2) > k || dist(x, cur3) > k || dist(x, cur4) > k) {
            ans[x.first][x.second] = 1;
        } else {
            ans[x.first][x.second] = 0;
            if (x.first + x.second > cur1.first + cur1.second) cur1 = x;
            if (-x.first + x.second > -cur2.first + cur2.second) cur2 = x;
            if (x.first - x.second > cur3.first - cur3.second) cur3 = x;
            if (-x.first - x.second > -cur4.first - cur4.second) cur4 = x;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!ans[i][j]) cout << "M";
            else cout << "G";
        }
        cout << "\n";
    }
}