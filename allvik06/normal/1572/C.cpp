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


void solve1(int n, vector <int> a) {
    vector <vector <int>> all(*max_element(a.begin(), a.end()) + 1);
    for (int i = 0; i < n; ++i) {
        all[a[i]].push_back(i);
    }
    vector <vector <int>> dp(n, vector <int> (n));
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            if (a[l] == a[r]) dp[l][r] = max(dp[l + 1][r - 1] + 1, dp[l][r]);
            for (int i : all[a[l]]) {
                if (i > l && i < r) dp[l][r] = max(dp[l][r], dp[l + 1][i] + dp[i][r] + 1);
            }
            for (int i : all[a[r]]) {
                if (i > l && i < r) dp[l][r] = max(dp[l][r], dp[l][i] + dp[i][r - 1] + 1);
            }
        }
    }
    cout << n - 1 - dp[0][n - 1] << "\n";
}


void solve() {
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x; --x;
        if (!a.empty() && a.back() == x) continue;
        a.push_back(x);
    }
    solve1((int)a.size(), a);
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