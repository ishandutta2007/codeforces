#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, ll> a, b;

void solve() {
    a.clear(), b.clear();
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        while (x % 2 == 0)
            x /= 2;
        a[x]++;
    }
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        while (x > 0) {
            b[x]++;
            x /= 2;
        }
    }

    for (auto i : a) {
        ll x = i.first;
        if (b[x] < i.second) {
            cout << "NO\n";
            return;
        }
        while (x > 0) {
            b[x] -= i.second;
            x /= 2;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
        solve();
}