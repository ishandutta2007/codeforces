#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    ll n;
    ll p;
    cin >> n;
    const int N = 10000;
    {
        double x;
        cin >> x;
        p = round(x * N);
    }
    for (ll c = 0; c < n; c++) {
        ll a = c * (c - 1) * (c - 2) + 3 * c * (c - 1) * (n - c) + 3 * c * (n - c) * (n - c - 1) / 2;
        ll b = n * (n - 1) * (n - 2); 
        if (a * N >= p * b) {
            cout << c << endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}