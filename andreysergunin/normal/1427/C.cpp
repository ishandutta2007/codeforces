#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(6) << fixed;
    cerr << setprecision(6) << fixed;

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
    int r, n;
    cin >> r >> n;
    vector<int> t(n + 1), x(n + 1), y(n + 1);
    t[0] = 0;
    x[0] = 1;
    y[0] = 1;

    for (int i = 0; i < n; ++i) {
        cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
    }

    vector<int> dp(n + 1);

    int val = 0;
    for (int i = n; i >= 0; --i) {
        if (i + 2 * r <= n) {
            val = max(val, dp[i + 2 * r]);
        }
        dp[i] = 1 + val;
        for (int j = 1; i + j <= n && j < 2 * r; ++j) {
            if (abs(x[i] - x[i + j]) + abs(y[i] - y[i + j]) <= t[i + j] - t[i]) {
                dp[i] = max(dp[i], dp[i + j] + 1);
            }
        }
    }

    cout << dp[0] - 1 << endl;
}