#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
const int mod = 1e9 + 7;
 
ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    ll ans = 0;
    ll cur = 0;
    reverse(s.begin(), s.end());
    for (char c : s) {
        if (c == 'b') {
            cur++;
        } else {
            (ans += cur) %= mod;
            (cur += cur) %= mod;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}