#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 10;

int mod;
int dp[N][N], C[N][N];
int fac[N];
int a[N];

void solve() {
    int n;
    cin >> n >> mod;
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = 1LL * fac[i - 1] * i % mod;
    int m = n / 2;
    for (int k = m; k < n; k++) {
        a[k] = 1LL * n * C[n - m - 1][k - m] % mod;
        a[k] = 1LL * fac[k] * a[k] % mod;
    }
    for (int i = n - 1; i >= 2; i--)
        a[i] = (a[i] - 1LL * (n - i + 1) * a[i - 1] % mod + mod) % mod;
    long long answer = 0;
    for (int i = 1; i <= n - 1; i++)
        answer = (answer + a[i]) % mod;
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}