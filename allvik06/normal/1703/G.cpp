#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
#define int long long
const int maxl = 32;
const int INF = 1e15;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <vector <int>> dp(n + 1, vector <int> (maxl, -INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int prev = 0; prev < maxl; ++prev) {
                dp[i + 1][prev] = max(dp[i + 1][prev], dp[i][prev] + a[i] / (1LL << prev) - k);
                int nx = min(maxl - 1, prev + 1);
                dp[i + 1][nx] = max(dp[i + 1][nx], dp[i][prev] + a[i] / (1LL << nx));
            }
        }
        cout << *max_element(dp.back().begin(), dp.back().end()) << "\n";
    }
}

/*

 */