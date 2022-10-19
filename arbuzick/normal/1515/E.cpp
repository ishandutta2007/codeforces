#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

const int maxn = 405;
int kek[maxn];
int dp[maxn][maxn][2];
int f[maxn], _f[maxn];

int binpow(int a, int n, int mod) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return binpow(a, n - 1, mod) * a % mod;
    }
    int b = binpow(a, n / 2, mod);
    return b * b % mod;
}

void solve() {
    int n, mod;
    cin >> n >> mod;
    kek[0] = kek[1] = 1;
    for (int i = 2; i <= n; ++i) {
//        kek[i] = kek[i - 2] * 2 * (i - 1) % mod;
        kek[i] = kek[i - 1] * 2 % mod;
    }
    f[0] = f[1] = _f[0] = _f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] * i % mod;
        _f[i] = binpow(f[i], mod - 2, mod);
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            dp[i + 1][j][0] = dp[i][j][1];
            for (int cnt = 1; cnt <= j; ++cnt) {
                int val = f[j] * _f[cnt] % mod * _f[j - cnt] % mod *
                          dp[i - cnt + 1][j - cnt][0] % mod * kek[cnt] % mod;
                dp[i + 1][j][1] += val;
                dp[i + 1][j][1] %= mod;
            }
//            cout << i + 1 << ' ' << j << ' ' << dp[i + 1][j][0] << ' ' << dp[i + 1][j][1] << '\n';
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += dp[n][i][1];
        ans %= mod;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}