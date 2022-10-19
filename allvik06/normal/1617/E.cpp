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

const int MX_SZ = 31;

inline int get_p(int x) {
    for (int k = 0; k < MX_SZ; ++k) {
        if ((1 << k) >= x) return (1 << k) - x;
    }
}

void solve1() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> all;
    map <int, pair <int, int>> dp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int x = a[i];
        dp[a[i]] = make_pair(0, i);
        while (true) {
            all.push_back(x);
            if (x == 0) break;
            x = get_p(x);
        }
    }
    if (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end())) {
        cout << "1 2 " << a[0];
        return;
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    pair <int, pair <int, int>> ans;
    reverse(all.begin(), all.end());
    for (int i : all) {
        if (i == 0) break;
        int p = get_p(i);
        if (dp.count(p)) ans = max(ans, make_pair(dp[p].first + dp[i].first + 1, make_pair(dp[p].second, dp[i].second)));
        dp[p] = max(dp[p], make_pair(dp[i].first + 1, dp[i].second));
    }
    cout << ans.second.first + 1 << " " << ans.second.second + 1 << " " << ans.first;
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */