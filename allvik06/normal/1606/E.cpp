#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;

#define int long long
const int mod = 998244353;
const int MAXN = 1010;

int power(int a, int n) {
    if (n == 0) return 1;
    if (n & 1) return power(a, n - 1) * a % mod;
    else return power(a * a % mod, n >> 1);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, x;
    cin >> n >> x;
    vector <vector <int>> dp(MAXN, vector <int> (n + 1));
    vector <vector <int>> p(MAXN, vector <int> (MAXN));
    vector <int> fact(MAXN, 1), rfact(MAXN, 1);
    for (int i = 2; i < MAXN; ++i) fact[i] = (fact[i - 1] * i) % mod;
    rfact[MAXN - 1] = power(fact[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i > 1; --i) rfact[i] = (rfact[i + 1] * (i + 1)) % mod;

    auto cnk = [&](int nn, int kk) -> int {
        return fact[nn] * rfact[kk] % mod * rfact[nn - kk] % mod;
    };

    for (int i = 0; i < MAXN; ++i) {
        p[i][0] = 1;
        for (int j = 1; j < MAXN; ++j) {
            p[i][j] = p[i][j - 1] * i % mod;
        }
    }
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (dp[i][j] == 0) continue;
            int l = i + 1, r = min(x, i + n - j - 1);
            int c = r - l + 1;
            if (c <= 0) continue;
            for (int cnt = 0; cnt <= n - j; ++cnt) {
                dp[i + c][j + cnt] += dp[i][j] * p[c][cnt] % mod * cnk(n - j, cnt) % mod;
                dp[i + c][j + cnt] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        ans = (ans + dp[i][n]) % mod;
    }
    cout << ans << "\n";
}

/*

 */