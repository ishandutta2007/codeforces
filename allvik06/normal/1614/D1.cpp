#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <iomanip>
#include <array>
#include <deque>
#include <cmath>
#include <complex>
#include <queue>
#include <iomanip>

using namespace std;
#define int long long
const int MAXC = 5e6;
int all[MAXC + 1];
int dp[MAXC + 1];

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++all[x];
    }
    for (int i = 1; i <= MAXC; ++i) {
        for (int j = 2 * i; j <= MAXC; j += i) {
            all[i] += all[j];
        }
    }
    int ans = 0;
    for (int i = MAXC; i > 0; --i) {
        dp[i] = i * all[i];
        for (int j = 2 * i; j <= MAXC; j += i) {
            dp[i] = max(dp[i], dp[j] + (all[i] - all[j]) * i);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

/*

 */