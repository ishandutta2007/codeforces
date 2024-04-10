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
    vector<pair<int, int>> cells[2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cells[(i + j) % 2].emplace_back(i, j);
        }
    }
    for (int turn = 0; turn < n * n; turn++) {
        int a;
        cin >> a;
        int b;
        int x, y;

        int low = ((cells[0].size() < cells[1].size() || cells[1].empty()) && !cells[0].empty()) ? 0 : 1;
        if (a != low + 1) {
            b = low + 1;
            tie(x, y) = cells[low].back();
            cells[low].pop_back();
        } else {
            if (!cells[low ^ 1].empty()) low ^= 1;
            b = low + 1;
            tie(x, y) = cells[low].back();
            cells[low].pop_back();
            if (a == low + 1) {
                b = 3;
            }
        }

        cout << b << ' ' << x << ' ' << y << endl;
    }
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