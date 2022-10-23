#include <bits/stdc++.h>

using namespace std;

constexpr long long inf = 1LL << 50;
constexpr long long den = 100000;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> dp(m + 1, inf);
    bitset<1 << 17> vis;
    dp[0] = 0;
    deque<long long> dq;
    vector<long long> ks;
    ks.reserve(m + 1);
    for (long long i = 1; i <= n; ++i) {
        long long t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            x = (x + den - 1) / den;
            for (long long j = 0; j < x; ++j) {
                ks.clear();
                for (long long k = j; k <= m; k += x) {
                    ks.push_back(k);
                }
                dq.clear();
                for (long long idx = 0; idx < ks.size(); ++idx) {
                    if (dq.size() and dq.front() < idx - y) {
                        dq.pop_front();
                    }
                    long long k = ks[idx];
                    if (dp[k] != inf) {
                        dq.push_back(idx);
                    }
                    if (dq.size()) {
                        dp[k] = min(dp[k], (long long) i);
                    }
                }
            }
        } else {
            vis.reset();
            for (long long j = 1; j <= m; ++j) {
                if (vis[j]) continue;
                ks.clear();
                for (long long k = j; k <= m;) {
                    ks.push_back(k);
                    vis.set(k);
                    long long nk = (k * x + den - 1) / den;
                    if (nk <= k) break;
                    k = nk;
                }
                dq.clear();
                for (long long idx = 0; idx < ks.size(); ++idx) {
                    if (dq.size() and dq.front() < idx - y) {
                        dq.pop_front();
                    }
                    long long k = ks[idx];
                    if (dp[k] != inf) {
                        dq.push_back(idx);
                    }
                    if (dq.size()) {
                        dp[k] = min(dp[k], (long long) i);
                    }
                }
            }
        }
    }
    for (long long j = 1; j <= m; ++j) {
        if (dp[j] == inf) cout << -1;
        else cout << dp[j];
        cout << " \n"[j == m];
    }
    return 0;
}