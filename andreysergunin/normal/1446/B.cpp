#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
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


const int MAXN = 5050;

int dp[MAXN][MAXN];

void solve() { 
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i + 1][j + 1] = 0;
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1] - 1);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j] - 1);
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
            }
            res = max(res, dp[i + 1][j + 1]);
        }
    }
    
    cout << res << endl;

}