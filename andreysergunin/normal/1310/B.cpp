// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <iomanip>
// #include <random>

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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

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

const int MAXN = 17;

int dp[2][1 << MAXN][2][2];
int a[1 << MAXN];

void solve() {  
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int pos;
        cin >> pos;
        --pos;
        a[pos] = 1;
    }


    int k = 0;
    memset(dp[k], -1, sizeof(dp[k]));
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        dp[k][i][a[2 * i]][a[2 * i + 1]] = a[2 * i] | a[2 * i + 1]; 
        dp[k][i][a[2 * i + 1]][a[2 * i]] = a[2 * i] | a[2 * i + 1]; 
    }


    for (int s = 2; s <= n; ++s) {
       memset(dp[k ^ 1], -1, sizeof(dp[k ^ 1]));

        for (int i = 0; i < (1 << (n - s)); ++i) {
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    for (int z = 0; z < 2; ++z) {
                        for (int t = 0; t < 2; ++t) {
                            int u = dp[k][2 * i][x][y];
                            int v = dp[k][2 * i + 1][z][t];
                            if (u == -1 || v == -1) {
                                continue;
                            }
                            int val = u + v + (x | z) + (y | t);
           
                            dp[k ^ 1][i][x][y] = max(dp[k ^ 1][i][x][y], val + (z | y));
                            dp[k ^ 1][i][x][z] = max(dp[k ^ 1][i][x][z], val + (z | y));

                            dp[k ^ 1][i][x][t] = max(dp[k ^ 1][i][x][t], val + (z | t));
                            dp[k ^ 1][i][x][z] = max(dp[k ^ 1][i][x][z], val + (z | t));

                            dp[k ^ 1][i][z][y] = max(dp[k ^ 1][i][z][y], val + (x | y));
                            dp[k ^ 1][i][z][x] = max(dp[k ^ 1][i][z][x], val + (x | y));

                            dp[k ^ 1][i][z][t] = max(dp[k ^ 1][i][z][t], val + (x | t));
                            dp[k ^ 1][i][z][x] = max(dp[k ^ 1][i][z][x], val + (x | t));

                        }
                    }
                }
            }
        }

        k ^= 1;
    }

    int res = 0;
    for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
            res = max(res, dp[k][0][x][y] + (x | y));
        }
    }

    cout << res << endl;


}