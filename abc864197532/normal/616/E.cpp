#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, K = 3e6;

long long sum(long long l, long long r) {
    return (r - l + 1) % mod * ((r + l) % mod) % mod * ((mod + 1) / 2) % mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    long long re = n % mod * (m % mod);
    for (int i = 1; i < K; ++i) {
        long long l = n / (i + 1) + 1, r = n / i;
        if (m < l) continue;
        r = min(r, m);
        (re -= sum(l, r) * i) %= mod;
    }
    for (int i = 1; i <= min(n / K, m); ++i) {
        (re -= 1ll * i * (n / i)) %= mod;
    }
    cout << (re + mod) % mod << endl;
}