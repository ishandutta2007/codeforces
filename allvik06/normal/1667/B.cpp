#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <array>
#include <algorithm>

using namespace std;
#define ll long long
const int INF = 1e9;

inline array <int, 3> merge(array <int, 3> a, array <int, 3> b) {
    return {max(a[0], b[0]), max(a[1], b[1]), max(a[2], b[2])};
}

struct SegTree {
    int len;
    vector <array <int, 3>> t;

    inline SegTree(int n) {
        len = 1 << (int)ceil(log2(n));
        t.resize(2 * len, {-INF, -INF, -INF});
    }

    inline void update(int i, array <int, 3> val) {
        i += len;
        t[i] = merge(t[i], val);
        i >>= 1;
        while (i > 0) {
            t[i] = merge(t[2 * i], t[2 * i + 1]);
            i >>= 1;
        }
    }

    inline array <int, 3> get_max(int l, int r) {
        l += len;
        r += len;
        array <int, 3> ans({-INF, -INF, -INF});
        while (l <= r) {
            if (l & 1) {
                ans = merge(ans, t[l]);
                ++l;
            }
            if (!(r & 1)) {
                ans = merge(ans, t[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};

signed main() {
    srand(1303);
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        ll cur_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector <ll> all = {0};
        for (int i = 0; i < n; ++i) {
            all.push_back(all.back() + a[i]);
        }
        sort(all.begin(), all.end());
        all.resize(unique(all.begin(), all.end()) - all.begin());
        map <ll, int> d;
        int ln = (int)all.size();
        for (int i = 0; i < ln; ++i) {
            d[all[i]] = i;
        }
        SegTree tree(ln);
        tree.update(d[0], {-1, 1, 0});
        for (int i = 0; i < n; ++i) {
            cur_sum += a[i];
            int pos = d[cur_sum];
            int val = max({tree.get_max(0, pos - 1)[1] + i, tree.get_max(pos, pos)[2], tree.get_max(pos + 1, ln - 1)[0] - i});
            if (i == n - 1) {
                cout << val << "\n";
            } else {
                tree.update(pos, {val + i, val - i, val});
            }
        }
    }
}