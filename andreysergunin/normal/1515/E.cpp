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
        // cout << "Case #" << test << ": ";s
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 500;

int mod;

void mul(int &a, int b) {
    a = ll(a) * b % mod;
}

void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int dp[MAXN][MAXN];
int c[MAXN][MAXN];
int p[MAXN];

void solve() {
    int n;
    cin >> n >> mod;

    for (int i = 0; i <= n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1];
            add(c[i][j], c[i - 1][j]);
        }
    }

    p[0] = 1;
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i];
        mul(p[i + 1], 2);
    }


    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = p[i - 1];

        for (int j = 1; j < i; ++j) {
            for (int k = 1; k <= j && k + 1 < i; ++k) {
                int cur = dp[i - k - 1][j - k];
                mul(cur, p[k - 1]);
                mul(cur, c[j][k]);
                add(dp[i][j], cur);
            }
        }
    }   

    int res = 0;
    for (int i = 0; i <= n; ++i) {
        add(res, dp[n][i]);
    }
    
    cout << res << endl;    
}