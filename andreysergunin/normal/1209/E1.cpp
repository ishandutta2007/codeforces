#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;
using Complex = complex<double>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 12;
const int MAXM = 2020;

int dp[2][1 << MAXN];
int sum[1 << MAXN];
int a[MAXN][MAXM];


void solve() {

    int n, m;
    cin >> n >> m;

    vector<pii> p(m);
    for (int j = 0; j < m; ++j) {
        p[j].second = j;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            p[j].first = max(p[j].first, a[i][j]);
        }
    }
    sort(all(p));
    reverse(all(p));

    int k = 0;
    memset(dp[0], 0, sizeof(dp[0]));

    for (int i = 0; i < min(n, m); ++i) {
        int id = p[i].second;

        memcpy(dp[k ^ 1], dp[k], sizeof(dp[k]));
        memset(sum, 0, sizeof(sum));

        for (int j = 0; j < n; ++j) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                int cur = 0;
                for (int b = 0; b < n; ++b) {
                    if (mask & (1 << b)) {
                        cur += a[(b + j) % n][id];
                    }
                }
                sum[mask] = max(sum[mask], cur);
            }
        }

        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int smask = mask; smask > 0; smask = (mask & (smask - 1))) {
                dp[k ^ 1][mask] = max(dp[k ^ 1][mask], dp[k][mask ^ smask] + sum[smask]);
            }
        }
        k ^= 1;
    }

    cout << dp[k][(1 << n) - 1] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif  

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve();
    }

    
#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}