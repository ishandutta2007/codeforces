#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <cmath>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <functional>

using namespace std;
#define int long long
const int INF = 1e15;

struct SegTreeMax {
    int len;
    vector <int> t;

    SegTreeMax(int n) {
        len = (1 << (int)ceil(log2(n)));
        t.resize(2 * len, -INF);
    }

    inline void update(int i, int x) {
        i += len;
        t[i] = x;
        i >>= 1;
        while (i > 0) {
            t[i] = max(t[i << 1], t[(i << 1) | 1]);
            i >>= 1;
        }
    }

    inline int get_max(int l, int r) {
        l += len;
        r += len;
        int ans = -INF;
        while (l <= r) {
            if (l & 1) {
                ans = max(ans, t[l]);
                ++l;
            }
            if (!(r & 1)) {
                ans = max(ans, t[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};

struct Segment {
    int l, r, k;

    Segment() {}

    Segment(int l, int r, int k) : l(l), r(r), k(k) {}
};

inline bool cmp(Segment a, Segment b) {
    return a.r < b.r;
}

struct Vertex {
    int max1 = -INF, max2 = -INF, sum = -INF;
};

inline Vertex merge(Vertex a, Vertex b) {
    Vertex ans;
    ans.max1 = max(a.max1, b.max1);
    ans.max2 = max(a.max2, b.max2);
    ans.sum = max({a.sum, b.sum, a.max1 + b.max2});
    return ans;
}

struct SegTreeTwoMax {
    int n;
    vector <Vertex> t;

    SegTreeTwoMax(int n) : n(n) {
        t.resize(4 * n);
    }

    void update(int v, int l, int r, int i, int x, int type) {
        if (l > i || i > r) return;
        if (l == r) {
            if (type == 1) t[v].max1 = x;
            else t[v].max2 = x;
            t[v].sum = t[v].max1 + t[v].max2;
            return;
        }
        int m = (l + r) / 2;
        update(2 * v, l, m, i, x, type);
        update(2 * v + 1, m + 1, r, i, x, type);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    Vertex get_ans(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return Vertex();
        if (A <= l && r <= B) return t[v];
        int m = (l + r) / 2;
        return merge(get_ans(2 * v, l, m, A, B), get_ans(2 * v + 1, m + 1, r, A, B));
    }

    inline void update(int i, int x, int type) {
        update(1, 0, n - 1, i, x, type);
    }

    inline int get_ans(int l, int r) {
        return get_ans(1, 0, n - 1, l, r).sum;
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    int a[3][n];
    int psum[3][n + 1];
    psum[0][0] = psum[1][0] = psum[2][0] = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            psum[i][j + 1] = psum[i][j] + a[i][j];
        }
    }
    vector <int> dp(n, -INF);
    vector <Segment> all(q);
    for (int i = 0; i < q; ++i) {
        cin >> all[i].l >> all[i].r >> all[i].k; --all[i].l; --all[i].r;
    }
    sort(all.begin(), all.end(), cmp);
    SegTreeMax t(n), dp_t(n);
    for (int i = 0; i < n; ++i) {
        t.update(i, psum[0][i + 1] - psum[1][i]);
    }
    for (auto i : all) {
        int val = t.get_max(i.l, i.r) - i.k;
        val = max(val, dp_t.get_max(max(i.l - 1, 0LL), i.r - 1) - i.k);
        dp[i.r] = max(dp[i.r], val);
        dp_t.update(i.r, dp[i.r]);
    }
    SegTreeTwoMax t1(n), t2(n);
    for (int i = 0; i < n; ++i) {
        t1.update(i, psum[0][i + 1] - psum[1][i], 1);
        t1.update(i, psum[1][i + 1] + psum[2][n] - psum[2][i], 2);
        t2.update(i, dp[i], 1);
        t2.update(i, psum[1][i + 1] + psum[2][n] - psum[2][i], 2);
    }
    int ans = -INF;
    for (auto i : all) {
        ans = max(ans, t1.get_ans(i.l, i.r) - i.k);
        ans = max(ans, t2.get_ans(i.l - 1, i.r) - i.k);
    }
    cout << ans;
    return 0;
}

/*

 */