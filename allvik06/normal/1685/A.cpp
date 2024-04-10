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
#include <iomanip>

using namespace std;
#define int long long
const int INF = 1e9;

inline bool check(int n, vector <int>& a) {
    for (int i = 0; i < n; ++i) {
        int p = (i - 1 + n) % n;
        int nx = (i + 1) % n;
        if (a[i] > a[p] && a[i] > a[nx]) continue;
        if (a[i] < a[p] && a[i] < a[nx]) continue;
        return false;
    }
    return true;
}

struct SegTree {
    int n;
    vector <pair <int, int>> t;

    SegTree(int n) : n(n) {
        t.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int v, int l, int r) {
        if (l == r) {
            t[v].second = l;
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    void update(int v, int l, int r, int i, int x) {
        if (l > i || i > r) return;
        if (l == r) {
            t[v].first += x;
            return;
        }
        int m = (l + r) / 2;
        update(2 * v, l, m, i, x);
        update(2 * v + 1, m + 1, r, i, x);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    inline void update(int i, int x) {
        update(1, 0, n - 1, i, x);
    }

    pair <int, int> get_max(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return {0, 0};
        if (A <= l && r <= B) return t[v];
        int m = (l + r) / 2;
        return max(get_max(2 * v, l, m, A, B), get_max(2 * v + 1, m + 1, r, A, B));
    }

    inline pair <int, int> get_max(int l, int r) {
        return get_max(1, 0, n - 1, l, r);
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector <int> c = a;
        sort(c.begin(), c.end());
        c.resize(unique(c.begin(), c.end()) - c.begin());
        map <int, int> d;
        int ln = (int)c.size();
        for (int i = 0; i < ln; ++i) d[c[i]] = i;
        for (int i = 0; i < n; ++i) a[i] = d[a[i]];
        SegTree t(ln);
        for (int i = 0; i < n; ++i) {
            t.update(a[i], 1);
        }
        vector <int> ans(n);
        ans[0] = d[c[0]];
        t.update(0, -1);
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (i % 2 == 1) {
                int p = ans[i - 1];
                auto mx = t.get_max(p + 1, ln - 1);
                if (mx.first == 0) {
                    ok = false;
                    break;
                }
                if (t.get_max(0, mx.second - 1).first == 0 && i != n - 1) mx = t.get_max(mx.second + 1, ln - 1);
                if (mx.first == 0) {
                    ok = false;
                    break;
                }
                ans[i] = mx.second;
                t.update(mx.second, -1);
            } else {
                int p = ans[i - 1];
                auto mx = t.get_max(0, p - 1);
                if (mx.first == 0) {
                    ok = false;
                    break;
                }
                if (t.get_max(mx.second + 1, ln - 1).first == 0 && i != n - 1) mx = t.get_max(0, mx.second - 1);
                if (mx.first == 0) {
                    ok = false;
                    break;
                }
                ans[i] = mx.second;
                t.update(mx.second, -1);
            }
        }
        if (!ok || !check(n, ans)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i : ans) cout << c[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}