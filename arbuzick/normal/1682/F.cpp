#include <bits/stdc++.h>

using namespace std;

const int R = 1 << 18, mod = 1e9 + 7;

int a[R], b[R];
vector<pair<long long, int>> t[R * 2];
vector<int> pr[R * 2], pr2[R * 2];

void build() {
    for (int i = R - 1; i > 0; --i) {
        merge(t[i * 2].begin(), t[i * 2].end(), t[i * 2 + 1].begin(), t[i * 2 + 1].end(), back_inserter(t[i]));
    }
    for (int i = 1; i < R * 2; ++i) {
        pr[i].push_back(0);
        pr2[i].push_back(0);
        for (int j = 0; j < (int) t[i].size(); ++j) {
            pr[i].push_back((pr[i].back() + t[i][j].first % mod * 1LL * (a[t[i][j].second + 1] - a[t[i][j].second]) % mod) % mod);
            pr2[i].push_back((pr2[i].back() + a[t[i][j].second + 1] - a[t[i][j].second]) % mod);
        }
    }
}

pair<int, int> get(int l, int r, long long val) {
    l += R;
    r += R;
    int ans = 0, ans2 = 0;
    while (l < r) {
        if (l & 1) {
            ans = (ans + pr[l][lower_bound(t[l].begin(), t[l].end(), make_pair(val, 0)) - t[l].begin()]) % mod;
            ans2 = (ans2 + pr2[l][lower_bound(t[l].begin(), t[l].end(), make_pair(val, 0)) - t[l].begin()]) % mod;
            l++;
        }
        if (r & 1) {
            r--;
            ans = (ans + pr[r][lower_bound(t[r].begin(), t[r].end(), make_pair(val, 0)) - t[r].begin()]) % mod;
            ans2 = (ans2 + pr2[r][lower_bound(t[r].begin(), t[r].end(), make_pair(val, 0)) - t[r].begin()]) % mod;
        }
        l >>= 1;
        r >>= 1;
    }
    return {ans, ans2};
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<long long> pr(n + 1);
    for (int i = 0; i + 1 < n; ++i) {
        pr[i + 1] = pr[i] + b[i];
        t[i + R].push_back({pr[i + 1], i});
    }
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        auto p = get(l, r, pr[l]);
        int ans = ((pr[l] % mod * 1LL * p.second - p.first) % mod + mod) % mod;
        auto p2 = get(l, r, 1e18);
        ans += ((p2.first - p.first - pr[l] % mod * 1LL * (p2.second - p.second) + mod) % mod + mod) % mod;
        ans %= mod;
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}