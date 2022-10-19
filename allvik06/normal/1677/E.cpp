#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>

using namespace std;
const int INF = 1e9;
#define ll long long
const int MAXN = 8e5;

inline int min(int a, int b) {
    if (a < b) return a;
    return b;
}

struct SegmentTree {
    int len;
    ll p[MAXN];
    ll t[MAXN];

    SegmentTree(int n) {
        len = 1 << (int)ceil(log2(n));
        for (int i = 0; i < 2 * len; ++i) p[i] = t[i] = 0;
    }

    inline void push(int v, int l, int r) {
        ll le = (r - l + 1) / 2;
        t[2 * v] += le * p[v];
        t[2 * v + 1] += le * p[v];
        p[2 * v] += p[v];
        p[2 * v + 1] += p[v];
        p[v] = 0;
    }

    void update(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (A <= l && r <= B) {
            t[v] += (ll)(r - l + 1) * x;
            p[v] += x;
            return;
        }
        push(v, l, r);
        int m = (l + r) / 2;
        update(2 * v, l, m, A, B, x);
        update(2 * v + 1, m + 1, r, A, B, x);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    inline void update(int l, int r, int x) {
        update(1, 0, len - 1, l, r, x);
    }

    ll get_sum(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return 0;
        if (A <= l && r <= B) return t[v];
        push(v, l, r);
        int m = (l + r) / 2;
        return get_sum(2 * v, l, m, A, B) + get_sum(2 * v + 1, m + 1, r, A, B);
    }

    ll get_sum(int l, int r) {
        return get_sum(1, 0, len - 1, l, r);
    }
};

struct event {
    int x, l, r, ind, k;

    event(int x, int l, int r, int ind, int k) : x(x), l(l), r(r), ind(ind), k(k) {}

    event() {}
};

inline bool cmp1(const event& a, const event& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.ind < b.ind;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    vector <int> a(n), pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector <int> bll(n, -1), blr(n, n), st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] < a[i]) {
            blr[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] < a[i]) {
            bll[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    vector <event> all;
    vector <vector <pair <int, int>>> kek(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; (ll)i * j <= n; ++j) {
            int val = i * j;
            int l = bll[pos[val]];
            int r = blr[pos[val]];
            int p1 = pos[i], p2 = pos[j];
            if (p1 > p2) swap(p1, p2);
            if (l < p1 && p2 < r) {
                kek[val].emplace_back(min(p1, pos[val]), max(p2, pos[val]));
            }
        }
    }
    vector <pair <int, int>> flex;
    for (int i = 1; i <= n; ++i) {
        int l = bll[pos[i]];
        int r = blr[pos[i]];
        flex = kek[i];
        sort(flex.begin(), flex.end());
        int cur_min = INF;
        for (int j = (int)flex.size() - 1; j >= 0; --j) {
            cur_min = min(cur_min, flex[j].second);
            int lx = l + 1;
            int rx = flex[j].first;
            if (j > 0) lx = flex[j - 1].first + 1;
            int ly = cur_min;
            int ry = r - 1;
            all.emplace_back(lx - 1, ly, ry, -1, -1);
            all.emplace_back(rx, ly, ry, -1, 1);
        }
    }
    vector <ll> ans(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r; --l; --r;
        all.emplace_back(l - 1, l, r, i, -1);
        all.emplace_back(r, l, r, i, 1);
    }
    sort(all.begin(), all.end(), cmp1);
    SegmentTree now(n);
    for (auto i : all) {
        if (i.ind == -1) {
            now.update(i.l, i.r, (i.x + 1) * i.k);
        } else {
            ans[i.ind] += now.get_sum(i.l, i.r) * i.k;
        }
    }
    reverse(all.begin(), all.end());
    now = SegmentTree(n);
    for (auto i : all) {
        if (i.ind == -1) {
            now.update(i.l, i.r, i.k);
        } else {
            ans[i.ind] += now.get_sum(i.l, i.r) * i.k * (i.x + 1);
        }
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << "\n";
    return 0;
}