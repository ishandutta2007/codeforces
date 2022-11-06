#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;


struct V { // define
    ll sum = 0, mn = 0, mx = 0;

    V() {}

    V(const ll x) : sum(x), mn(x), mx(x) {} // optional
    V(const V &val1, const V &val2) {
        sum = val1.sum + val2.sum;
        mn = min(val1.mn, val2.mn);
        mx = max(val1.mx, val2.mx);
    }
};

struct U { // define
    ll y = 0;

    U() {}

    U(const ll _y) : y(_y) {} // optional
    U(const U &u1, const U &u2) { y = max(u1, u2); }

    operator ll() const { return y; } // optional
    bool apply(V &val, const int lo, const int hi) const { // lo == hi if non-lazy segment tree
        if (val.mn >= y) return true;
        if (val.mx > y) return false;
        val.sum = y * (hi - lo + 1LL);
        val.mn = val.mx = y;
        return true;
    }
};

struct SegTree {
    int n;
    vector<V> st;
    vector<U> lazy;

    SegTree(const int n) : n(n) {
        init(1, 0, n - 1);
        lazy.resize(st.size());
    }

    void init(const int si, const int lo, const int hi) { // init st[]
        if (lo == hi) {
            if (si >= (int) st.size()) st.resize(si + 1);
            int x;
            cin >> x;
            st[si] = V(x);
        } else {
            const int mid = (lo + hi) >> 1;
            init(si << 1, lo, mid);
            init(si << 1 | 1, mid + 1, hi);
            st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if internal nodes are V()
        }
    }

    void updateLazy(const int si, const int lo, const int hi) {
        bool ret = lazy[si].apply(st[si], lo, hi);
        assert(ret);
        if (lo != hi) {
            lazy[si << 1] = U(lazy[si << 1], lazy[si]);
            lazy[si << 1 | 1] = U(lazy[si << 1 | 1], lazy[si]);
        }
        lazy[si] = U();
    }

    V queryV(const int l, const int r) { return (l <= r && l < n && r >= 0) ? queryV(l, r, 1, 0, n - 1) : V(); }

    V queryV(const int l, const int r, const int si, const int lo, const int hi) {
        updateLazy(si, lo, hi);
        if (l <= lo && hi <= r) return st[si];

        const int mid = (lo + hi) >> 1;
        if (r <= mid) return queryV(l, r, si << 1, lo, mid);
        if (mid < l) return queryV(l, r, si << 1 | 1, mid + 1, hi);
        return V(queryV(l, r, si << 1, lo, mid), queryV(l, r, si << 1 | 1, mid + 1, hi));
    }

    ll queryXY(const int  x, int y) {
        return queryXY(x, y, 1, 0, n - 1);
    }

    int queryXY(const int x, int &y, const int si, const int lo, const int hi) {
        updateLazy(si, lo, hi);

        if (x <= lo) {
            if (st[si].sum <= y) {
                y -= st[si].sum;
                return hi - lo + 1;
            }

            if (st[si].mn > y) {
                return 0;
            }
            assert(lo < hi);
        }

        const int mid = (lo + hi) >> 1;
        if (mid < x) return queryXY(x, y, si << 1 | 1, mid + 1, hi);
        int ans = queryXY(x, y, si << 1, lo, mid);
        ans += queryXY(x, y, si << 1 | 1, mid + 1, hi);
        return ans;
    }


    void update(const int l, const int r, const U u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }

    void update(const int l, const int r, const U &u, const int si, const int lo, const int hi) {
        updateLazy(si, lo, hi);
        if (l <= lo && hi <= r && u.apply(st[si], lo, hi)) {
            if (lo != hi) {
                lazy[si << 1] = U(lazy[si << 1], u);
                lazy[si << 1 | 1] = U(lazy[si << 1 | 1], u);
            }
        } else {
            if (hi < l || r < lo) return;
            assert(lo < hi);
            const int mid = (lo + hi) >> 1;
            update(l, r, u, si << 1, lo, mid);
            update(l, r, u, si << 1 | 1, mid + 1, hi);
            st[si] = V(st[si << 1], st[si << 1 | 1]);
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    SegTree st(n);
    while(q--) {
        int type, x, y;
        cin >> type >> x >> y;
        --x;
        if(type == 1) {
            st.update(0, x, U(y));
        } else {
            assert(type == 2);
            cout << st.queryXY(x, y) << '\n';
        }
    }

    return 0;
}