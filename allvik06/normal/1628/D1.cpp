#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <map>
#include <algorithm>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

int power(int a, int x) {
    if (x == 0) return 1;
    if (x & 1) return (a * power(a, x - 1)) % mod;
    else return power((a * a) % mod, x >> 1);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int rev2 = power(2, mod - 2);
        vector<int> dp(n - m + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = min(i + 1, n - m); j > 0; --j) {
                dp[j] = (dp[j] + dp[j - 1]) * rev2 % mod;
            }
            dp[0] = (i + 1) * k % mod;
        }
        cout << dp[n - m] << "\n";
    }
}