#include <bits/stdc++.h>

using ll = long long;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector<pair<ll, ll>> v;
    ll cur = -1;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (cur == -1) {
                cur = i;
            }
        } else {
            if (cur != -1) {
                v.push_back({cur, i - 1});
                cur = -1;
            }
        }
    }
    if (cur != -1) {
        v.push_back({cur, n - 1});
    }
    ll mx = 0;
    for (ll i = 0; i < v.size(); i++) {
        mx += (v[i].second - v[i].first + 1) / b;
    }
    cout << mx - a + 1 << '\n';
    ll cnt = 0;
    vector<ll> pos;
    for (ll i = 0; i < v.size(); i++) {
        ll l = v[i].first, r = v[i].second;
        for (ll j = l + b - 1; j <= r; j += b) {
            if (cnt != mx - a + 1) {
                pos.push_back(j);
                cnt++;
            }
        }
    }
    for (ll i = 0; i < pos.size(); i++) {
        cout << pos[i] + 1 << ' ';
    }
}