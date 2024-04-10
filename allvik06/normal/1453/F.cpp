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
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        int dp[n - 1][n];
        int suf[n - 1][n];
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INF;
                suf[i][j] = INF;
            }
        }
        vector <int> tmp(n);
        for (int i = n - 2; i >= 0; --i) {
            if (i + a[i] < n - 1) {
                int cur = 0;
                for (int j = i + 1; j < n - 1 && j <= i + a[i]; ++j) {
                    dp[i][j] = min(INF, suf[j][i + a[i] + 1] + cur);
                    cur -= tmp[j];
                    if (a[j] != 0) {
                        ++cur;
                        tmp[j + a[j]]++;
                    }
                }
                for (int j = 0; j < n; ++j) tmp[j] = 0;
            } else {
                int cur = 0;
                for (int j = i + 1; j < n - 1; ++j) {
                    if (j + a[j] == n - 1) ++cur;
                }
                dp[i][n - 1] = cur;
            }
            suf[i][n - 1] = dp[i][n - 1];
            for (int j = n - 2; j >= 0; --j) {
                suf[i][j] = min(suf[i][j + 1], dp[i][j]);
            }
        }
        cout << suf[0][0] << "\n";
    }
}

/*


 */