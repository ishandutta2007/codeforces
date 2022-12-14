#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int fac[maxn], rev[maxn];

int power(int a, int b) {
    if (b == 0)
        return 1;
    int ret = power(a, b / 2);
    ret = 1ll * ret * ret % mod;
    if (b & 1)
        ret = 1LL * ret * a % mod;
    return ret;
}

int Choose(int n, int r) {
    return 1LL * fac[n] * rev[r] % mod * rev[n - r] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    k = min(k, n);
    int answer = 0;
    for (int i = 0; i <= k; i++)
        answer = (answer + Choose(n, i)) % mod;
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    fac[0] = 1;
    for (int i = 1; i < maxn; i++)
        fac[i] = 1LL * fac[i - 1] * i % mod;
    rev[maxn - 1] = power(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; i--)
        rev[i] = 1LL * rev[i + 1] * (i + 1) % mod;
    int tc = 1;
    while (tc--) {
        solve();
    }
}