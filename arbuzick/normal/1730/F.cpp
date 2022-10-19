#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005, maxk = 8, inf = 1e9 + 7;

int dp[maxn][1 << maxk];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pos[j] > pos[i]) {
                cnt[i]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            dp[i][j] = inf;
        }
    }
    int mask_nw = 0;
    for (int i = 0; i < min(n, k + 1); ++i) {
        dp[i][mask_nw] = 0;
        mask_nw <<= 1;
        mask_nw += 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int mask = (1 << k) - 1; mask >= 0; --mask) {
            if (dp[i][mask] == inf) {
                continue;
            }
            for (int j = max(0, i - k); j < i; ++j) {
                if (mask & (1 << (i - j - 1))) {
                    int kek = cnt[j];
                    for (int j2 = max(0, i - k); j2 < j; ++j2) {
                        if (mask & (1 << (i - j2 - 1))) {
                            if (pos[j2] > pos[j]) {
                                kek--;
                            }
                        }
                    }
                    for (int j2 = j + 1; j2 < i; ++j2) {
                        if (!(mask & (1 << (i - j2 - 1)))) {
                            if (pos[j2] > pos[j]) {
                                kek++;
                            }
                        }
                    }
                    if (pos[i] > pos[j]) {
                        kek++;
                    }
                    dp[i][mask ^ (1 << (i - j - 1))] = min(dp[i][mask ^ (1 << (i - j - 1))], dp[i][mask] + kek);
                }
            }
            int mask_nw = mask;
            for (int j = i + 1; j < min(n, i + k + 2); ++j) {
                if (mask_nw & (1 << (k - 1))) {
                    break;
                }
                mask_nw <<= 1;
                if (j != i + 1) {
                    mask_nw += 1;
                }
                int kek = cnt[j];
                // cout << i << ' ' << j << ' ' << mask_nw << '\n';
                for (int j2 = max(0, j - k); j2 < j; ++j2) {
                    if (mask_nw & (1 << (j - j2 - 1))) {
                        if (pos[j2] > pos[j]) {
                            kek--;
                        }
                    }
                }
                dp[j][mask_nw] = min(dp[j][mask_nw], dp[i][mask] + kek);
            }
        }
    }
    cout << dp[n - 1][0] << '\n';
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