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

using namespace std;
#define int long long

inline void solve1() {
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0, cnt = 0, now = 0;
    vector <int> dp(n + 1), tmp(200);
    dp[1] = 1;
    for (int i = 2; i <= min(n, 100LL); ++i) {
        for (int j = 0; j < i; ++j) {
            tmp[dp[max(0LL, j - 1)] ^ dp[max(0LL, i - j - 2)]] = 1;
        }
        for (int me = 0;; ++me) {
            if (tmp[me]) continue;
            dp[i] = me;
            break;
        }
        for (int j = 0; j < i; ++j) {
            tmp[dp[max(0LL, j - 1)] ^ dp[max(0LL, i - j - 2)]] = 0;
        }
    }
    for (int i = 101; i <= n; ++i) {
        dp[i] = dp[i - 34];
    }
    string s;
    cin >> s;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') ++cnt1;
        else ++cnt0;
        if (!i) continue;
        if (s[i] == s[i - 1]) {
            x ^= dp[now];
            now = 0;
        } else {
            ++now;
        }
    }
    x ^= dp[now];
    if (cnt0 > cnt1) cout << "Alice\n";
    else if (cnt0 < cnt1) cout << "Bob\n";
    else if (x) cout << "Alice\n";
    else cout << "Bob\n";
}

signed main() {
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
    } else {
        mt19937 rnd(228);
        int t;
        cin >> t;
        while (t--) {

        }
    }
}

/*

 */