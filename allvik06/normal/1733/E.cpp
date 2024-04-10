#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
#define int long long
int dp[130][130];

int solve1(int t, int x, int y) {
    int l = x + y;
    if (l > t) {
        return 0;
    }
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = t - l + 1;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            dp[i + 1][j] += dp[i][j] / 2;
            dp[i][j + 1] += (dp[i][j] + 1) / 2;
        }
    }
    return dp[x][y];
}

inline void solve() {
    int t, x, y;
    cin >> t >> x >> y;
    if (solve1(t - 1, x, y) != solve1(t, x, y)) cout << "YES\n";
    else cout << "NO\n";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */