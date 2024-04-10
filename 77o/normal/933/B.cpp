#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll p, k;
    cin >> p >> k;
    vector<ll> a;
    while (p) {
        ll t = p / k;
        while (p - t * k < 0) {
            t--;
        }
        a.push_back(p - t * k);
        p = -t;
    }

    cout << a.size() << '\n';
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " \n"[i + 1 == a.size()];
    }
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