#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

vector<long long> fact(int n) {
    vector<long long> a;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        a.push_back(n);
    }
    return a;
}

long long my_pow(long long n, long long m) {
    if (m == 0) {
        return 1;
    }
    long long now = my_pow(n, m / 2);
    if (m % 2 == 0) {
        return (now * now) % mod;
    }
    return (((now * now) % mod) * n) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, x;
    cin >> n >> x;
    vector<long long> factn = fact(n);
    long long ans = 1;
    for (auto &c : factn) {
        long long now = 1;
        while (x / now >= c) {
            now *= c;
            ans *= my_pow(c, x / now);
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}