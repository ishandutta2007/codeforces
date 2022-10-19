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
const int mod = 1e9 + 7;
const int INF = 1e9;

void merge(pair <int, int>& a, pair <int, int> b) {
    if (a.first > b.first) a = b;
    else if (a.first == b.first) a.second = (a.second + b.second) % mod;
}

void solve1() {
    string a, b;
    cin >> a >> b;
    int n = (int)a.size(), m = (int)b.size();
    vector <bool> ok(n);
    bool kek = false;
    for (int i = 0; i + m - 1 < n; ++i) {
        if (a.substr(i, m) == b) {
            ok[i] = true;
            kek = true;
        }
    }
    if (!kek) {
        cout << "0 1\n";
        return;
    }
    vector <pair <int, int>> dp(n, make_pair(INF, 0));
    for (int i = 0; i < n; ++i) {
        if (!ok[i]) continue;
        bool flex = false;
        for (int j = 0; j < i; ++j) {
            if (ok[j]) {
                if (j + m - 1 >= i) dp[i] = make_pair(1, 1);
                flex = true;
                break;
            }
        }
        if (!flex) dp[i] = make_pair(1, 1);
        int bad = i - 1;
        while (bad >= 0 && (!ok[bad] || bad + m - 1 >= i)) --bad;
        for (int prv = 0; prv < i; ++prv) {
            if (!ok[prv]) continue;
            if (prv + m - 1 >= bad && prv + m - 1 < i) merge(dp[i], make_pair(dp[prv].first + 1, dp[prv].second));
        }
    }
    pair <int, int> ans(INF, 0);
    for (int i = 0; i < n; ++i) {
        bool flex = true;
        for (int j = i + m; j < n; ++j) {
            if (ok[j]) flex = false;
        }
        if (flex) merge(ans, dp[i]);
    }
    cout << ans.first << " " << ans.second << "\n";
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
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */