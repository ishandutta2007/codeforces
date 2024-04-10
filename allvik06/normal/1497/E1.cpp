#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;
const int MAXV = 1e7 + 10;
const int INF = 1e9;

struct SegTree {
    int n;
    vector <int> t;

    inline SegTree(int n) : n(n) {
        t.resize(4 * n, INF);
    }

    void update(int v, int l, int r, int A, int B, int x) {
        if (l > B || A > r) return;
        if (A <= l && r <= B) {
            t[v] = min(t[v], x);
            return;
        }
        int m = (l + r) / 2;
        update(2 * v, l, m, A, B, x);
        update(2 * v + 1, m + 1, r, A, B, x);
    }

    inline void update(int l, int r, int x) {
        update(1, 0, n - 1, l, r, x);
    }

    int get_val(int v, int l, int r, int i) {
        if (l > i || i > r) return INF;
        if (l == r) return t[v];
        int m = (l + r) / 2;
        return min({get_val(2 * v, l, m, i), get_val(2 * v + 1, m + 1, r, i), t[v]});
    }

    inline int get_val(int i) {
        return get_val(1, 0, n - 1, i);
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector <int> mind(MAXV, -1), pr;
    for (int i = 2; i < MAXV; ++i) {
        if (mind[i] == -1) {
            mind[i] = i;
            pr.push_back(i);
        }
        for (int j : pr) {
            if (j > mind[i] || j * i >= MAXV) break;
            mind[i * j] = j;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        map <vector <int>, int> d;
        vector <int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            vector <int> all;
            while (x > 1) {
                int md = mind[x], c = 0;
                while (x % md == 0) {
                    c ^= 1;
                    x /= md;
                }
                if (c) all.push_back(md);
            }
            if (d.count(all)) a.push_back(d[all]);
            else {
                a.push_back(cnt);
                d[all] = cnt++;
            }
        }
        vector <vector <int>> bad(n);
        vector <int> last(n, -1);
        last[a[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            bad[i] = bad[i + 1];
            int x = -1;
            if (last[a[i]] != -1) {
                x = last[a[i]];
            }
            last[a[i]] = i;
            if (x == -1) continue;
            bad[i].insert(upper_bound(bad[i].begin(), bad[i].end(), x), x);
            if ((int)bad[i].size() == k + 2) bad[i].pop_back();
        }
        vector <SegTree> dp(k + 1, SegTree(n + 1));
        dp[0].update(0, 0, 0);
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= k; ++c) {
                int val = dp[c].get_val(i);
                if (val == INF) continue;
                for (int pl = 0; pl + c <= k && (int)bad[i].size() >= pl; ++pl) {
                    int l, r;
                    if (pl == 0) {
                        l = i + 1;
                        if (bad[i].empty()) r = n;
                        else r = bad[i][0];
                    } else {
                        l = bad[i][pl - 1] + 1;
                        if (pl == (int)bad[i].size()) r = n;
                        else r = bad[i][pl];
                    }
                    dp[c + pl].update(l, r, val + 1);
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= k; ++i) {
            ans = min(ans, dp[i].get_val(n));
        }
        cout << ans << "\n";
    }
}

/*

 */