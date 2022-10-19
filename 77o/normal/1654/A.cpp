#include <iostream>
#include <vector>
#include <algorithm>

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
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    sort(a.rbegin(), a.rend());
    cout << a[0] + a[1] << '\n';
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