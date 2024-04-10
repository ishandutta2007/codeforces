#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define int long long
const int mod = 998244353;
vector <int> fact, rfact;

inline int power(int a, int n) {
    if (n == 0) return 1;
    if (n & 1) return power(a, n - 1) * a % mod;
    return power(a * a % mod, n >> 1);
}

inline int cnk(int n, int k) {
    return (fact[n] * rfact[k] % mod) * rfact[n - k] % mod;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, k;
    cin >> n >> k;
    if (n == 2) {
        cout << k;
        return 0;
    }
    n--;
    vector <int> dp(n + 1), dp1(n + 1);
    fact.resize(n + 1, 1);
    rfact.resize(n + 1);
    for (int i = 2; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;
    for (int i = 0; i <= n; ++i) rfact[i] = power(fact[i], mod - 2);
    dp[0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int prev = 0; prev <= n; ++prev) {
            for (int now = 0; now + prev <= n; ++now) {
                int cnt = (now * prev + now * (now - 1) / 2) % mod;
                dp1[now + prev] = (dp1[now + prev] + dp[prev] * power(k + 1 - i, cnt) % mod * cnk(n - prev, now)) % mod;
            }
        }
        dp.swap(dp1);
        dp1.assign(n + 1, 0);
    }
    cout << dp[n];
}