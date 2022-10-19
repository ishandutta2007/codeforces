#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, maxn = 4e4 + 5;

int dp[maxn];

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v;
    for (int i = 1; i < maxn; ++i) {
        int val = i, j = 0;
        while (val) {
            j *= 10;
            j += val % 10;
            val /= 10;
        }
        if (j == i) {
            v.push_back(i);
        }
    }
    dp[0] = 1;
    for (auto val : v) {
        for (int i = 0; i + val < maxn; ++i) {
            dp[i + val] += dp[i];
            if (dp[i + val] >= mod) {
                dp[i + val] -= mod;
            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}