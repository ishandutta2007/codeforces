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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    cin >> tests;

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

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    vector<ll> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = abs(a[i] - a[i + 1]);
    }

    ll res = 1;

    vector<pair<ll, ll>> cur, nxt;

    for (int i = 0; i < n - 1; ++i) {
        nxt.clear();
        if (d[i] != 1) {
            cur.push_back({i, d[i]});
        }
        for (auto [j, g] : cur) {
            g = gcd(g, d[i]);
            if (g > 1 && (nxt.empty() || nxt.back().second != g)) {
                nxt.push_back({j, g});
                res = max(res, i - j + 2);
            }
        }

        cur.swap(nxt);
    }

    cout << res << endl;

}