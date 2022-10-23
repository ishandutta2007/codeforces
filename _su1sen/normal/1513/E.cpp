#include<bits/stdc++.h>

using namespace std;

constexpr long long mod = 1000000007;

constexpr long long mul(long long x, long long y) {
    return x * y % mod;
}

long long inv(long long a) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << 0 << '\n';
        return 0;
    }
    long long v = sum / n;
    sort(a.begin(), a.end());

    vector<long long> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    vector<long long> fac_inv(n + 1);
    fac_inv[n] = inv(fac[n]);
    for (int i = n; i > 0; --i) {
        fac_inv[i - 1] = fac_inv[i] * i % mod;
    }
    auto comb = [&](int n, int r) {
        if (n < 0 or r < 0 or n < r) return 0LL;
        return fac[n] * fac_inv[r] % mod * fac_inv[n - r] % mod;
    };

    vector<int> lc, rc;
    int mc = 0;
    for (int i = 0; i < n;) {
        long long t = a[i];
        int j = i;
        while (j < n and a[j] == t) ++j;
        int l = j - i;
        if (t < v) {
            lc.push_back(l);
        } else if (t == v) {
            mc = l;
        } else {
            rc.push_back(l);
        }
        i = j;
    }
    long long ans = comb(n, mc);
    if (lc.size()) {
        int sum_l = 0;
        for (int c : lc) {
            sum_l += c;
            ans = mul(ans, fac_inv[c]);
        }
        ans = mul(ans, fac[sum_l]);
        int sum_r = 0;
        for (int c : rc) {
            sum_r += c;
            ans = mul(ans, fac_inv[c]);
        }
        ans = mul(ans, fac[sum_r]);
        if (sum_l == 1 or sum_r == 1) {
            ans = mul(ans, sum_l + sum_r);
        } else {
            ans = mul(ans, 2);
        }
    }
    cout << ans << '\n';
    return 0;
}