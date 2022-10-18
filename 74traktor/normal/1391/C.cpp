#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e6 + 5;
int f[maxn], rev[maxn];
int mod = 1e9 + 7;

int st(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        int d = st(x, y / 2);
        return d * d % mod;
    }
    return x * st(x, y - 1) % mod;
}

inline int C(int n, int k) {
    return f[n] * rev[k] % mod * rev[n - k] % mod;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    f[0] = 1, rev[0] = 1;
    for (int i = 1; i <= n; ++i) f[i] = f[i - 1] * i % mod, rev[i] = st(f[i], mod - 2);
    ans = f[n];
    for (int i = 1; i <= n; ++i) {
        ans = (ans - C(n - 1, i - 1) + mod) % mod;
    }
    cout << ans << '\n';
    return 0;
}