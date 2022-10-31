#include<bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 1e6 + 5;
int f[maxn], rev[maxn], mod = 998244353, dp[maxn], go[maxn];

int st(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) return st(x * x % mod, y / 2);
    return x * st(x, y - 1) % mod;
}

int C(int n, int k) {
    return f[n] * rev[k] % mod * rev[n - k] % mod;
}

int good(vector < int > p) {
    int n = p.size();
    vector < int > rev(n);
    for (int i = 0; i < n; i++) {
        rev[p[i] - 1] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        if (abs(p[i] - rev[i]) > 1) return 0;
    }
    return 1;
}

int solve(int n, int c) {
    return C(n - c, c);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = f[i - 1] * i % mod;
    rev[0] = 1;
    rev[maxn - 1] = st(f[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 1; i--) {
        rev[i] = rev[i + 1] * (i + 1) % mod;
    }
    dp[0] = 1;
    for (int i = 1; i < maxn; i++) {
        dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % mod;
    }
    go[0] = 1;
    for (int i = 2; i < maxn; i += 2) {
        go[i] = go[i - 2] * (i - 1) * 2 % mod;
    }
    while (t--) {
        cin >> n;
        /*vector < int > cur;
        for (int i = 1; i <= n; i++) cur.push_back(i);
        int s = 0;
        for (int i = 1; i <= f[n]; i++) {
            if (good(cur)) {
                s++;
                //for (auto key : cur) cout << key << " ";
                //cout << '\n';
            }
            if (i != f[n]) next_permutation(cur.begin(), cur.end());
        }*/
        int ans = 0;
        for (int c = 0; c <= n / 4; c++) {
            ans = (ans + go[2 * c] * dp[n - 4 * c] % mod * solve(n, 2 * c)) % mod;
            //cout << go[2 * c] << " " << dp[n - 4 * c] << " " << solve(n, 2 * c) << endl;
        }
        cout << ans << '\n';
    }
    return 0;
}