#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int MOD = 1000000007;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

// int inv(int x) {
//     return power(x, MOD - 2);
// }

// int fac[N], ifac[N];

// void init_combi() {
//     fac[0] = 1;
//     ifac[0] = 1;
//     for (int i = 1; i < N; i++) {
//         fac[i] = 1LL * fac[i - 1] * i % MOD;
//         ifac[i] = inv(fac[i]); 
//     }
// }

// int C(int n, int k) {
//     return 1LL * ifac[k] * ifac[n - k] % MOD * fac[n] % MOD;
// }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(all(x));
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * (power(2, i - 1) - 1) * x[i];
        ans -= 1LL * (power(2, n - i) - 1) * x[i];
        ans %= MOD;
        if (ans < 0) ans += MOD;
    }
    cout << (ans) % MOD;
    return 0;
}