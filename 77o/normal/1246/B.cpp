#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int m = a[i];
        ll b = 1;
        ll c = 1;
        for (int j = 2; j * j <= m; j++) {
            int cnt = 0;
            while (a[i] % j == 0) {
                a[i] /= j;
                cnt++;
            }
            for (int t = 0; t < (k - (cnt % k)) % k && b < 1e5; t++) {
                b *= j;
            }
            for (int t = 0; t < cnt % k; t++) {
                c *= j;
            }
        }
        if (a[i] > 1) {
            int cnt = 1;
            int j = a[i];
            for (int t = 0; t < (k - (cnt % k)) % k && b < 1e5; t++) {
                b *= j;
            }
            for (int t = 0; t < cnt % k; t++) {
                c *= j;
            }
        }
        ans += cnt[b];
        cnt[c]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}