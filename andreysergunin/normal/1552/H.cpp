#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() { 
    int n = 200;

    auto ask_strips = [&](int l) {
        vector<pii> p;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i % l == 0) {
                    p.push_back({i, j});
                }
            }
        }
        cout << "? " << sz(p) << endl;
        for (auto [x, y] : p) {
            cout << x << " " << y << endl;
        }
        int res;
        cin >> res;
        return res;
    };

    int s = ask_strips(1);

    int a = s;

    int l = 0, r = 8;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        // cerr << "------------> " << m << endl;
        int x = ask_strips(1 << m);
        a = gcd(a, x);
        if (x * (1 << m) == s) {
            l = m;
        } else {
            r = m;
        }
    }

    if (a > 200) {
        a = 128;
    }
    int b = s / a;
    cout << "! " << 2 * (a + b - 2) << endl;
}