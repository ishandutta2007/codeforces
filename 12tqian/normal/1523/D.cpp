#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

const int TRIES = 25;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string line; cin >> line;
        for (int j = 0; j < m; ++j) {
            a[i][j] = line[j] - '0';
        }   
    }
    pair<int, vector<int>> ans;
    ans.first = -1;
    for (int attempt = 0; attempt < TRIES; ++attempt) {
        vector<int> use;
        int idx = rng() % n;
        for (int i = 0; i < m; ++i) {
            if (a[idx][i]) {
                use.push_back(i);
            }
        }
        int sz = use.size();
        vector<int> cnt(1 << sz);
        vector<int> dp(1 << sz);
        for (int i = 0; i < n; ++i) {
            int msk = 0;
            for (int j = 0; j < sz; ++j) {
                if (a[i][use[j]]) {
                    msk |= (1 << j);
                }
            }
            ++cnt[msk];
        }
        for (int msk = 0; msk < (1 << sz); ++msk) {
            for (int nmsk = msk; nmsk; nmsk = (nmsk - 1) & msk) {
                dp[nmsk] += cnt[msk];
            }
        }
        int best = 0;
        for (int msk = 0; msk < (1 << sz); ++msk) {
            if (dp[msk] >= (n + 1) / 2) {
                if (__builtin_popcount(msk) > __builtin_popcount(best)) {
                    best = msk;
                }
            }
        }
        if (__builtin_popcount(best) > ans.first) {
            ans.first = __builtin_popcount(best);
            ans.second.clear();
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (a[idx][i]) {
                    if (best & (1 << cnt)) {
                        ans.second.push_back(1);
                    } else {
                        ans.second.push_back(0);
                    }
                    ++cnt;
                } else {
                    ans.second.push_back(0);
                }
            }
        }
    }
    for (int x : ans.second) {
        cout << x;
    }
    cout << '\n';
    return 0;
}