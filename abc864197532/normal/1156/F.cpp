#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 1e5, mod = 998244353;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    vector <int> cnt(n, 0);
    for (int i = 0; i < n; ++i) cin >> tmp, cnt[--tmp]++;
    vector <lli> pre(n, 0), inv(n + 1, 0);
    for (int i = 1; i <= n; ++i) inv[i] = modpow(i, mod - 2);
    for (int i = 0; i < n; ++i) pre[i] = inv[n] * cnt[i] % mod;
    lli ans = 0;
    for (int i = 1; i < n; ++i) {
        vector <lli> cur(n, 0);
        lli now = 0;
        for (int j = 0; j < n; ++j) if (cnt[j] > 0) {
            cur[j] = now * cnt[j] % mod * inv[n - i] % mod;
            ans = (ans + pre[j] * (cnt[j] - 1) % mod * inv[n - i] % mod) % mod;
            now = (now + pre[j]) % mod;
        }
        swap(cur, pre);
    }
    cout << ans << endl;
}