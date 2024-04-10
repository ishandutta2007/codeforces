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

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
    // cout << setprecision(10) << fixed;
    // cerr << setprecision(10) << fixed;

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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> b(n);
    ll res = 1e18;
    for (int k = 0; k < n; ++k) {
        b[k] = 0;
        ll cur = 0;
        for (int i = k + 1; i < n; ++i) {
            ll x = b[i - 1] / a[i] + 1;
            b[i] = x * a[i];
            cur += x;
        }
        for (int i = k - 1; i >= 0; --i) {
            ll x = -((-b[i + 1]) / a[i]) - 1;
            b[i] = x * a[i];
            cur -= x;
        }
        res = min(cur, res);
    }
    cout << res << endl;
}