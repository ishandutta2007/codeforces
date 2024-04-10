#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

    int tests = 1;
    // cin >> tests;

    while (tests--) {
       solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 3030;
const int P = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];

void solve() {
    string s, t;
    cin >> s;
    cin >> t;

    int n = sz(s);
    int m = sz(t);

    for (int i = 0; i < m; ++i) {
        if (s[0] == t[i]) {
            dp1[i][i + 1] = 2;
        }
    }

    for (int len = 1; len < m; ++len) {
        for (int i = 0; i + len <= m; ++i) {
            int j = i + len;
            if (i > 0 && s[len] == t[i - 1]) {
                add(dp1[i - 1][j], dp1[i][j]);
            }
            if (j < m && s[len] == t[j]) {
                add(dp1[i][j + 1], dp1[i][j]);
            }
        }
    }

    // for (int i = 0; i < m; ++i) {
    //     for (int j = i + 1; j <= m; ++j) {
    //         cout << dp1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    dp2[1][0] = 2;
    for (int i = 0; i < m; ++i) {
        add(dp2[m - i + 1][m - i], dp1[i][m]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            add(dp2[i + 1][j], dp2[i][j]);
            if (j == 0) {
                add(dp2[i + 1][j], dp2[i][j]);
            } 
            if (j < m && t[m - j - 1] == s[i]) {
                add(dp2[i + 1][j + 1], dp2[i][j]);
            }
        }
    }

    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= m; ++j) {
    //         cout << dp2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int res = dp1[0][m];
    for (int i = 0; i <= n; ++i) {
        add(res, dp2[i][m]);
    }

    cout << res << endl;
}