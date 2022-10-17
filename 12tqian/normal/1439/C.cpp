#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    // right endpoints are exclusive
    int n;
    vector<int> mn;
    vector<int> lazy;
    vector<long long> sum;
    SegmentTree(const vector<int> &a) {
        n = (int) a.size();
        mn.resize(4 * n);
        lazy.resize(4 * n);
        sum.resize(4 * n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                mn[p] = sum[p] = a[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        mn[p] = min(mn[2 * p], mn[2 * p + 1]);
        sum[p] = sum[2 * p] + sum[2 * p + 1];
    }
    void set(int p, int l, int r, int v) {
        lazy[p] = v;
        mn[p] = v;
        sum[p] = 1LL * (r - l) * v;
    }
    void push(int p, int l, int r) {
        if (lazy[p] > 0) {
            int m = (l + r) / 2;
            set(2 * p, l, m, lazy[p]);
            set(2 * p + 1, m, r, lazy[p]);
            lazy[p] = 0;
        }
    }
    void range_set(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) return set(p, l, r, v);
        int m = (l + r) / 2;
        push(p, l, r);
        range_set(2 * p, l, m, x, y, v);
        range_set(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    int bound(int p, int l, int r, int x) {
        if (r - l == 1) return mn[p] >= x ? r : l;
        int m = (l + r) / 2;
        push(p, l, r);
        if (mn[2 * p] >= x) return bound(2 * p + 1, m, r, x);
        else return bound(2 * p, l, m, x);
    }
    void modify(int x, int y) {
        int l = min(x, bound(1, 0, n, y));
        range_set(1, 0, n, l, x, y);
    }
    int query(int p, int l, int r, int x, int &y) {
        if (r <= x) return 0;
        if (mn[p] > y) return 0;
        if (l >= x && sum[p] <= y) {
            y -= sum[p];
            return r - l;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        int res = query(2 * p, l, m, x, y);
        res += query(2 * p + 1, m, r, x, y);
        return res;
    }
    int query(int x, int y) {
        return query(1, 0, n, x, y);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    SegmentTree seg(a);

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            seg.modify(x, y);
        } else {
            cout << seg.query(x - 1, y) << '\n';
        }
    }

    return 0;
}