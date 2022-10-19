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
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int dp[n][2][2];
        pair <int, int> pr[n][2][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    dp[i][j][k] = INF;
                }
            }
        }
        dp[0][0][0] = dp[0][1][0] = -INF;
        for (int i = 1; i < n; ++i) {
            int z = -1;
            for (int j = 0; j < 2; ++j, z += 2) {
                int val = a[i] * z;
                int zz = -1;
                for (int k = 0; k < 2; ++k, zz += 2) {
                    int val_p = a[i - 1] * zz;
                    if (val > val_p && dp[i][j][0] > dp[i - 1][k][0]) {
                        dp[i][j][0] = dp[i - 1][k][0];
                        pr[i][j][0] = make_pair(k, 0);
                    }
                    if (dp[i - 1][k][1] < val && dp[i][j][0] > val_p) {
                        dp[i][j][0] = val_p;
                        pr[i][j][0] = make_pair(k, 1);
                    }
                    if (val < val_p && val > dp[i - 1][k][0] && dp[i][j][1] > val_p) {
                        dp[i][j][1] = val_p;
                        pr[i][j][1] = make_pair(k, 0);
                    }
                    if (val > val_p && val < dp[i - 1][k][1] && dp[i][j][1] > dp[i - 1][k][1]) {
                        dp[i][j][1] = dp[i - 1][k][1];
                        pr[i][j][1] = make_pair(k, 1);
                    }
                }
            }
        }
        int cur0 = -1, cur1 = -1;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (dp[n - 1][i][j] != INF) {
                    cur0 = i;
                    cur1 = j;
                }
            }
        }
        if (cur0 == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            vector <int> ans;
            for (int i = n - 1; i >= 0; --i) {
                if (cur0 == 0) ans.push_back(-a[i]);
                else ans.push_back(a[i]);
                int n_cur0 = pr[i][cur0][cur1].first;
                int n_cur1 = pr[i][cur0][cur1].second;
                cur0 = n_cur0;
                cur1 = n_cur1;
            }
            reverse(ans.begin(), ans.end());
            for (int i : ans) cout << i << " ";
            cout << "\n";
        }
    }

}

/*

 */