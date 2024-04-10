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
const int INF = 1e15;

void solve1() {
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) ++cnt;
    }
    if (cnt == 0) {
        cout << "0\n";
        return;
    }
    if (cnt % 2 == 1) {
        cout << "-1\n";
        return;
    }
    if (x >= y) {
        if (cnt > 2) {
            cout << y * cnt / 2 << "\n";
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                if (a[i + 1] != b[i + 1]) {
                    if (n < 4) {
                        cout << x << "\n";
                    } else if (n == 4 && i == 1) {
                        cout << min(3 * y, x) << "\n";
                    } else {
                        cout << min(2 * y, x) << "\n";
                    }
                    return;
                } else {
                    cout << y << "\n";
                    return;
                }
            }
        }
    } else {
        vector <vector <int>> dp(n + 1, vector <int> (2, INF));
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                dp[i][0] = 0;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                for (int j = 0; j < 2; ++j) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                continue;
            }
            int flex = i + 1;
            while (flex < n && a[flex] == b[flex]) ++flex;
            if (flex != n) {
                for (int prv = 0; prv < 2; ++prv) {
                    dp[flex + 1][prv] = min(dp[flex + 1][prv], dp[i][prv] + x * (flex - i));
                    if (prv) dp[flex][prv - 1] = min(dp[flex][prv - 1], dp[i][prv] + y);
                    else dp[flex][prv + 1] = min(dp[flex][prv + 1], dp[i][prv]);
                }
            } else {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + y);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] != b[i]) {
                cout << dp[i + 1][0] << "\n";
                return;
            }
        }
    }
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