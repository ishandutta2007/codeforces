#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;
#define int long long
const int INF = 1e15;

struct SegTree {
    int len;
    vector<int> p;
    vector<pair<int, int>> t;

    SegTree(int n) {
        len = 1 << (int) ceil(log2(n));
        t.resize(2 * len);
        p.resize(2 * len);
    }

    inline pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return {a.first, a.second + b.second};
        return max(a, b);
    }

    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = make_pair(0, 1);
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    inline void push(int v) {
        p[2 * v] += p[v];
        p[2 * v + 1] += p[v];
        t[2 * v].first += p[v];
        t[2 * v + 1].first += p[v];
        p[v] = 0;
    }

    void update(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (A <= l && r <= B) {
            t[v].first += x;
            p[v] += x;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(2 * v, l, m, A, B, x);
        update(2 * v + 1, m + 1, r, A, B, x);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    inline void upd(int l, int r, int x) {
        update(1, 0, len - 1, l, r, x);
    }

    int get(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return INF;
        if (A <= l && r <= B) {
            if (t[v].first <= 0) return INF;
            if (l == r) return l;
        }
        push(v);
        int m = (l + r) / 2;
        int left = get(2 * v, l, m, A, B);
        if (left != INF) return left;
        return get(2 * v + 1, m + 1, r, A, B);
    }

    inline int get_flex(int l, int r) {
        return get(1, 0, len - 1, l, r);
    }

    inline pair<int, int> get_super(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return {-1, 0};
        if (A <= l && r <= B) return t[v];
        push(v);
        int m = (l + r) / 2;
        return merge(get_super(2 * v, l, m, A, B), get_super(2 * v + 1, m + 1, r, A, B));
    }

    inline int get_super_flex(int l, int r) {
        pair<int, int> now = get_super(1, 0, len - 1, l, r);
        if (now.first == 0) return now.second;
        return 0;
    }
};

inline int solve1(int n, vector<int> &a) {
    SegTree nul(n / 2 + 1), one(n / 2 + 1);
    nul.build(1, 0, nul.len - 1);
    one.build(1, 0, one.len - 1);
    int cur_pl = 0, cur_mn = 0;
    for (int i = 0; i < n; ++i) {
        int tmp_pl = cur_mn + a[i];
        cur_mn = cur_pl - a[i];
        cur_pl = tmp_pl;
        if (i % 2 == 0) {
            nul.upd(i / 2, i / 2, cur_mn);
        } else {
            one.upd(i / 2, i / 2, cur_mn);
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int val_nul = nul.get_flex((i + 1) / 2, n / 2);
        int val_one = one.get_flex(i / 2, n / 2);
        int kek = min({n, val_nul * 2, val_one * 2 + 1}) - 1;
        result += nul.get_super_flex((i + 1) / 2, kek / 2);
        if (kek > 0) result += one.get_super_flex(i / 2, (kek - 1) / 2);
        if (i % 2 == 0) {
            nul.upd(0, n / 2, a[i]);
            one.upd(0, n / 2, -a[i]);
        } else {
            nul.upd(0, n / 2, -a[i]);
            one.upd(0, n / 2, a[i]);
        }
    }
    return result;
}

inline int solve2(int n, vector <int>& a) {
    int result = 0;
    for (int l = 0; l < n; ++l) {
        int cur = 0;
        for (int r = l; r < n; ++r) {
            if (cur > a[r]) break;
            cur = a[r] - cur;
            if (cur == 0) ++result;
        }
    }
    return result;
}
signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int q;
        cin >> q;
        while (q--) {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            cout << solve1(n, a) << "\n";
        }
    } else {
        int t;
        cin >> t;
        while (t--) {
            int n = rand() % 5 + 1;
            vector <int> a(n);
            for (int i = 0; i < n; ++i) {
                a[i] = rand() % 5;
            }
            if (solve1(n, a) != solve2(n, a)) {
                cout << n << "\n";
                for (int i : a) cout << i << " ";
                cout << "\n";
                return 0;
            }
        }
    }
}

/*

 */