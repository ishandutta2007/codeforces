#include <functional>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;

const int MOD = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= a) %= MOD;
        p >>= 1;
        (a *= a) %= MOD;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    ll w = 0;
    multiset<ll, greater<ll>> a;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.insert(x);
        w += x;
    }
    multiset<ll, greater<ll>> b;
    b.insert(w);
    while (!b.empty()) {
        if (*b.begin() < *a.begin())
            break;
        if (*b.begin() == *a.begin()) {
            b.erase(b.begin());
            a.erase(a.begin());
            continue;
        }
        ll x = *b.begin();
        if (x == 1)
            break;
        b.erase(b.begin());
        b.insert(x / 2);
        b.insert(x - x / 2);
    }
    if (a.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}