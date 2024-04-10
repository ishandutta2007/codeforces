#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

int qpow(int a, int n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return (a * qpow(a, n - 1)) % mod;
    else {
        int h = qpow(a, n / 2);
        return (h * h) % mod;
    }
}

int inv(int a) {
    return qpow(a, mod - 2);
}

signed main() {
    int n;
    cin >> n;
    int f1 = 0;
    int f2 = 1;
    for (int i = 0; i < n; ++i) {
        int s = (f1 + f2) % mod;
        f1 = f2;
        f2 = s;
    }
    cout << (f1 * inv(qpow(2, n))) % mod << endl;
}