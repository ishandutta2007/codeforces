#pragma GCC optimize(3)
#include <bits/stdc++.h>

using namespace std;

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;
        p[a[i].first] = a[i].second;
    }
    long long ans = 0;
    vector<int> mn(n), mx(n);
    vector<vector<int>> mn_cnt(n * 3), mx_cnt(n * 3);
    vector<int> mn_pos_l(n * 3), mn_pos_r(n * 3), mx_pos_l(n * 3), mx_pos_r(n * 3);
    y_combinator([&](auto solve, int l, int r) -> void {
        if (l == r - 1) {
            ans++;
            return;
        }
        int m = (l + r) / 2;
        solve(l, m);
        solve(m, r);
        mn[m - 1] = mx[m - 1] = p[m - 1];
        for (int i = m - 2; i >= l; --i) {
            mn[i] = min(mn[i + 1], p[i]);
            mx[i] = max(mx[i + 1], p[i]);
        }
        mn[m] = mx[m] = p[m];
        for (int i = m + 1; i < r; ++i) {
            mn[i] = min(mn[i - 1], p[i]);
            mx[i] = max(mx[i - 1], p[i]);
        }
        for (int i = l; i < m; ++i) {
            int pos = i + mx[i] - mn[i];
            if (pos >= m && pos < r && mn[i] <= mn[pos] && mx[pos] <= mx[i]) {
                ans++;
            }
        }
        for (int i = m; i < r; ++i) {
            int pos = i - (mx[i] - mn[i]);
            if (l <= pos && pos < m && mn[i] < mn[pos] && mx[pos] < mx[i]) {
                ans++;
            }
        }
        // mx - mn = r - l
        // l - mn = r - mx;
        // l + mx = r + mn
        for (int i = l; i < r; ++i) {
            mn_cnt[i + mn[i]].clear();
            mx_cnt[i - mx[i] + n].clear();
            mn_cnt[i + mx[i]].clear();
            mx_cnt[i - mn[i] + n].clear();
            mn_pos_l[i + mx[i]] = mn_pos_r[i + mx[i]] = mn_pos_l[i + mn[i]] = mn_pos_r[i + mn[i]] = 0;
            mx_pos_l[i - mn[i] + n] = mx_pos_r[i - mn[i] + n] = mx_pos_l[i - mx[i] + n] = mx_pos_r[i - mx[i] + n] = 0;
        }
        for (int i = m; i < r; ++i) {
            mn_cnt[i + mn[i]].push_back(i);
            mx_cnt[i - mx[i] + n].push_back(i);
        }
        for (int i = m - 1; i >= l; --i) {
            // ans += mn_cnt[i - m]
            // int l_mn = upper_bound(mx_cnt[i - mn[i]].begin(), mx_cnt[i - mn[i]].end(), i, [&](const int a, const int b) {return mx[a] < mx[b];}) - mx_cnt[i - mn[i]].begin();
            // int r_mn = upper_bound(mx_cnt[i - mn[i]].begin(), mx_cnt[i - mn[i]].end(), i, [&](const int a, const int b) {return mn[a] > mn[b];}) - mx_cnt[i - mn[i]].begin();
            // int l_mx = upper_bound(mn_cnt[i + mx[i]].begin(), mn_cnt[i + mx[i]].end(), i, [&](const int a, const int b) {return mn[a] > mn[b];}) - mn_cnt[i + mx[i]].begin();
            // int r_mx = upper_bound(mn_cnt[i + mx[i]].begin(), mn_cnt[i + mx[i]].end(), i, [&](const int a, const int b) {return mx[a] < mx[b];}) - mn_cnt[i + mx[i]].begin();
            while (mn_pos_r[i + mx[i]] < mn_cnt[i + mx[i]].size() && mx[mn_cnt[i + mx[i]][mn_pos_r[i + mx[i]]]] <= mx[i]) {
                mn_pos_r[i + mx[i]]++;
            }
            while (mn_pos_l[i + mx[i]] < mn_pos_r[i + mx[i]] && mn[mn_cnt[i + mx[i]][mn_pos_l[i + mx[i]]]] >= mn[i]) {
                mn_pos_l[i + mx[i]]++;
            }
            while (mx_pos_r[i - mn[i] + n] < mx_cnt[i - mn[i] + n].size() && mn[mx_cnt[i - mn[i] + n][mx_pos_r[i - mn[i] + n]]] >= mn[i]) {
                mx_pos_r[i - mn[i] + n]++;
            }
            while (mx_pos_l[i - mn[i] + n] < mx_pos_r[i - mn[i] + n] && mx[mx_cnt[i - mn[i] + n][mx_pos_l[i - mn[i] + n]]] <= mx[i]) {
                mx_pos_l[i - mn[i] + n]++;
            }
            ans += mn_pos_r[i + mx[i]] - mn_pos_l[i + mx[i]];
            ans += mx_pos_r[i - mn[i] + n] - mx_pos_l[i - mn[i] + n];
        }
    })(0, n);
    cout << ans;
    return 0;
}