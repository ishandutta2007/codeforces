#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

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
    int n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        ans += a[i].second;
    }
    sort(a.begin(), a.end());
    ll best = a[0].first + a[0].second;
    for (int i = 1; i < n; i++) {
        ans += max(0LL, a[i].first - best);
        best = max(best, a[i].first + a[i].second);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}