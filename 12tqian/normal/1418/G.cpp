#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
template<class T, int SZ> struct lazy_seg {
    T num[2 * SZ], lazy[2 * SZ], mn[2 * SZ];
    lazy_seg() {
        for (int i = 0; i < 2 * SZ; i++) {
            num[i] = 1;
            lazy[i] = 0;
            mn[i] = 0;
        }
    }
    void push(int ind, int L, int R) {
        mn[ind] += lazy[ind];
        if (L != R) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    void pull(int ind) {
        mn[ind] = min(mn[2 * ind], mn[2 * ind + 1]);
        if (mn[2 * ind] == mn[2 * ind + 1]) {
            num[ind] = num[2 * ind] + num[2 * ind + 1];
        } else if (mn[2 * ind] < mn[2 * ind + 1]) {
            num[ind] = num[2 * ind];
        } else {
            num[ind] = num[2 * ind + 1];
        }
    }
    void build() {
        for (int i = SZ - 1; i >= 1; i--) {
            pull(i);
        }
    }
    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind, L, R);
        if (hi < L || R < lo) return ;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * ind, L, M);
        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }
    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind, L, R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];
        int M = (L + R) / 2;
        return min(qmin(lo, hi, 2 * ind, L, M), qmin(lo, hi, 2 * ind + 1,  M + 1, R));
    }
    T low_count(int lo, int hi) {
        int low = qmin(lo, hi);
        return qcount(lo, hi, low);
    }
    T qcount(int lo, int hi, int low, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind , L, R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) {
            if (mn[ind] == low) return num[ind];
            return 0;
        }
        int M = (L + R) / 2;
        return qcount(lo, hi, low, 2 * ind, L, M) + qcount(lo, hi, low, 2 * ind + 1, M + 1, R);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    vector<int> oc(n);
    vector<set<int>> loc(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        loc[a[i]].insert(i);
    }
    int num = 0;
    lazy_seg<int, (1 << 19)> seg;
    seg.build();
    ll ans = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[a[i]]) continue;
        vis[a[i]] = true;
        int val = a[i];
        auto it = loc[val].find(i);
        vector<int> bad(4, -1);
        auto cur = next(it);
        for (int j = 0; j < 4; j++) {
            if (cur == loc[val].end()) break;
            bad[j] = *cur;
            cur = next(cur);
        }
        if (bad[1] != -1) {
            seg.upd(i, bad[1] - 1, 1);
        } else {
            seg.upd(i, n - 1, 1);
        }
        if (bad[2] != -1) {
            seg.upd(bad[2], n - 1, 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            int val = a[i - 1];
            auto it = loc[val].find(i - 1);
            vector<int> bad(4, -1);
            auto cur = next(it);
            for (int j = 0; j < 4; j++) {
                if (cur == loc[val].end()) break;
                bad[j] = *cur;
                cur = next(cur);
            }
            if (bad[1] != -1) {
                seg.upd(i - 1, bad[1] - 1, -1);
            } else {
                seg.upd(i - 1, n - 1, -1);
            }
            if (bad[2] != -1) {
                seg.upd(bad[2], n - 1, -1);
            }
            if (bad[0] != -1) {
                if (bad[2] != -1) {
                    seg.upd(bad[0], bad[2] - 1, 1);
                } else {
                    seg.upd(bad[0], n - 1, 1);
                }
                if (bad[3] != -1) {
                    seg.upd(bad[3], n - 1, 1);
                }
            }
        }
        int mn = seg.qmin(i, n - 1);
        if (mn == 0) {
            ans += seg.low_count(i, n - 1);
        }
    }
    cout << ans << '\n';
    return 0;
}