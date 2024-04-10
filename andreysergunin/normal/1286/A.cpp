#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

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

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

const int MAXN = 111;
int dp[MAXN][MAXN][MAXN][2];

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                dp[i][j][k][0] = n;
                dp[i][j][k][1] = n;
            }
        }
    }

    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int t = 0; t < 2; ++t) {
                    if (!p[i] || (p[i] & 1)) {
                        dp[i + 1][j][k + 1][1] = min(dp[i + 1][j][k + 1][1], dp[i][j][k][t] + (t == 0));
                    }
                    if (!p[i] || !(p[i] & 1)) {
                        dp[i + 1][j + 1][k][0] = min(dp[i + 1][j + 1][k][0], dp[i][j][k][t] + (t == 1));
                    }
                }
            }
        }
    }

    cout << min(dp[n][n / 2][(n + 1) / 2][0], dp[n][n / 2][(n + 1) / 2][1]) << endl;


}