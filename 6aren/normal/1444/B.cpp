#include<bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MOD = 998244353;

int fac[N], ifac[N];

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        y >>= 1;
        x = 1LL * x * x % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int &e : a) cin >> e;
    int res = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        res += a[2 * n - i - 1] - a[i]; 
        res %= MOD;
    }

    fac[0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    ifac[2 * n] = power(fac[2 * n], MOD - 2);
    for (int i = 2 * n - 1; i >= 0; i--) {
        ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;
    }
    // cout << fac[2 * n] << ' ' << ifac[n] << ' ' << res << endl;
    res = 1LL * res * fac[2 * n] % MOD * ifac[n] % MOD * ifac[n] % MOD;
    cout << res << '\n';

    return 0;
}