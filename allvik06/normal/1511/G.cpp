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
    vector<int> f;

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
    vector<int> c(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x - 1] ^= 1;
    }
    cin >> q;
    vector<int> ans(q), cur_d;
    vector<vector<pair<int, int>>> all_q(m);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        all_q[r].emplace_back(l, i);
    }
    Fenwick all_d(0), val(0);
    for (int b = 0; b < 20; ++b) {
        int ln = (2 << b);
        cur_d.assign(ln, 0);
        all_d = Fenwick(ln);
        val = Fenwick(m + ln + 1);
        int prev;
        for (int i = 0; i < m; ++i) {
            int pos = i - ln + 1;
            prev = pos;
            int o = pos % ln;
            if (o < 0) o += ln;
            val.add(pos + ln, cur_d[o]);
            cur_d[o] ^= c[i];
            all_d.add(o, c[i]);
            for (auto j: all_q[i]) {
                int x = 0;
                int l = max(-ln + 1, j.first - (1 << b) + 1);
                int r = min(j.first, prev);
                x ^= val.get_seg(l + ln, r + ln);
                int start_o = l % ln;
                int end_o = r % ln;
                if (start_o < 0) start_o += ln;
                if (end_o < 0) end_o += ln;
                if (l <= r) {
                    if (start_o <= end_o) x ^= all_d.get_seg(start_o, end_o);
                    else x ^= all_d.get_seg(start_o, ln - 1) ^ all_d.get_pref(end_o);
                }
                if (x) ans[j.second] = 1;
            }
        }
    }
    for (int i: ans) {
        if (i) cout << "A";
        else cout << "B";
    }
}

void solve2() {
    int n, m, q;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x - 1] ^= 1;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, x = 0;
        cin >> l >> r;
        --l;
        --r;
        for (int j = l; j <= r; ++j) {
            if (c[j]) x ^= (j - l);
        }
        if (x) cout << "A";
        else cout << "B";
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    solve1();
}