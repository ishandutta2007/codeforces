#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;
constexpr long long i2 = 499122177;

int main() {
    int n, m;
    cin >> n >> m;
    int w = 0;
    vector<vector<bool>> s(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        for (int j = 0; j < m; ++j) {
            if (t[j] == 'o') {
                s[i][j] = true;
                ++w;
            }
        }
    }
    vector<long long> p(n * m + 1), ip(n * m + 1);
    p[0] = ip[0] = 1;
    for (int i = 1; i <= n * m; ++i) {
        p[i] = p[i - 1] * 2 % mod;
        ip[i] = ip[i - 1] * i2 % mod;
    }
    vector<long long> f(n + m + 1);
    f[0] = f[1] = 0;
    long long rsum = 0;
    long long sum = 0;
    for (int i = 2; i <= n + m; i++) {
        int h = i / 2;
        f[i] = (h + sum + p[i - 1] * rsum) % mod;
        sum = (sum + f[i]) % mod;
        rsum = (rsum + h * ip[i]) % mod;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < m) {
            while (j < m and not s[i][j]) ++j;
            int k = j;
            while (k < m and s[i][k]) ++k;
            int l = k - j;
            ans += f[l] * p[w - l] % mod;
            j = k;
        }
    }
    for (int j = 0; j < m; j++) {
        int i = 0;
        while (i < n) {
            while (i < n and not s[i][j]) ++i;
            int k = i;
            while (k < n and s[k][j]) ++k;
            int l = k - i;
            ans += f[l] * p[w - l] % mod;
            i = k;
        }
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
    return 0;
}