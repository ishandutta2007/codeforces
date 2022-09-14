#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
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
    int n;
    cin >> n;

    map<int, int> cnt1;
    map<pii, int> cnt2;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }

        ++cnt1[x];
        if (x != y) {
            ++cnt2[{x, y}];
            ++cnt1[y];
        }
    }

    ll res = 0;
    for (auto [_, val] : cnt1) {
        res += ll(val) * (val - 1) / 2;
    }

    for (auto [_, val] : cnt2) {
        res -= ll(val) * (val - 1) / 2;
    }

    cout << res << endl;
}