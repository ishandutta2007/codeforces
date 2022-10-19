#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <chrono>
#include <random>

using namespace std;
#define int long long

struct Node {
    int sum = 0, pref = 0, suf = 0, ans = 0;
};

inline void merge(const Node& a, const Node& b, Node& ans) {
    ans.sum = a.sum + b.sum;
    ans.pref = max(a.pref, a.sum + b.pref);
    ans.suf = max(b.suf, b.sum + a.suf);
    ans.ans = max({a.ans, b.ans, a.suf + b.pref});
}

struct SegTree {
    int n;
    vector <Node> t;

    SegTree(int n, const vector <int>& a) : n(n) {
        t.resize(2 << n);
        for (int i = (2 << n) - 1; i > 0; --i) {
            if (i >= (1 << n)) {
                int x = a[i - (1 << n)];
                t[i].sum = x;
                if (x > 0) t[i].pref = t[i].suf = t[i].ans = x;
            } else {
                merge(t[2 * i], t[2 * i + 1], t[i]);
            }
        }
    }

    inline void relax_vertex(int v) {
        while (v >= 1) {
            merge(t[2 * v], t[2 * v + 1], t[v]);
            v >>= 1;
        }
    }

    inline void relax_lvl(int k) {
        for (int i = (1 << k); i < (2 << k); i += 2) {
            swap(t[i], t[i + 1]);
            relax_vertex(i >> 1);
        }
    }
};

int n;
vector <int> ans;

void find_ans(int lvl, int mask, SegTree& t) {
    if (lvl == n) {
        ans[mask] = t.t[1].ans;
        return;
    }
    find_ans(lvl + 1, mask, t);
    t.relax_lvl(n - lvl);
    find_ans(lvl + 1, mask | (1 << lvl), t);
    t.relax_lvl(n - lvl);
}

inline void solve() {
    cin >> n;
    vector <int> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) cin >> a[i];
    SegTree t(n, a);
    ans.resize(1 << n);
    find_ans(0, 0, t);
    int q, mask = 0;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        mask ^= (1 << x);
        cout << ans[mask] << "\n";
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*

 */