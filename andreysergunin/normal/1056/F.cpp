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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 101;
const ld INF = 1e18;

ld dp[2][MAXN][10 * MAXN];

void solve() {
    int n;
    cin >> n;
    ld c, t;
    cin >> c >> t;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    sort(all(p));

    int cur = 0;

    dp[cur][0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            for (int pt = 0; pt <= 10 * j; ++pt) {
                dp[cur ^ 1][j][pt] = INF;
            }
        }

        for (int j = 0; j <= i; ++j) {
            for (int pt = 0; pt <= 10 * j; ++pt) {
                // if (dp[cur][j][pt] < INF / 2) {
                //     cout << cur << " " << j << " " << pt << endl;
                // }
                dp[cur ^ 1][j + 1][pt + p[i].second] = min(dp[cur ^ 1][j + 1][pt + p[i].second], 
                                                        (dp[cur][j][pt] + p[i].first) / 0.9);
                dp[cur ^ 1][j][pt] = min(dp[cur ^ 1][j][pt], dp[cur][j][pt]);
            }
        }

        cur ^= 1;
    }

    // cout << dp[cur][2][7] << endl;

    int res = 0;
    for (int k = 1; k <= n; ++k) {
        ld x = max((t - 10 * k - 1 / c) / 2, (ld)0.); 
        ld y = (t - 10 * k - x) * (1 + c * x);

        for (int pt = 0; pt <= 10 * k; ++pt) {
            if (dp[cur][k][pt] <= y) {
                res = max(res, pt);
            }
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve();
    }
}