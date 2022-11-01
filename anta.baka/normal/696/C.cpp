#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int pw(int a, ll b) {
    if(!b) return 1;
    if(b & 1) return (ll)a * pw(a, b - 1) % mod;
    a = pw(a, b >> 1);
    return (ll)a * a % mod;
}

int k, m = 2;
bool even;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> k;
    for(int i = 0; i < k; i++) {
        ll x; cin >> x;
        even |= (x % 2 == 0);
        m = pw(m, x);
    }
    m = (ll)m * pw(2, mod - 2) % mod;
    cout << (ll)(even ? m + 1 : m - 1) % mod * pw(3, mod - 2) % mod << '/' << m;
}