#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e18 + 1;

#define pb push_back

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <vector<pair<int, long long>>> a(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (auto &c : a[i]) {
            cin >> c.first >> c.second;
        }
    }
    vector <vector<long long>> dp(n + 1, vector <long long> (10, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        long long max_three = -1;
        long long max_two = -1;
        long long max1_one = -1;
        long long max2_one = -1;
        long long max3_one = -1;
        for (auto &c : a[i]) {
            if (c.first == 3) {
                max_three = max(max_three, c.second);
            }
            if (c.first == 2) {
                max_two = max(max_two, c.second);
            }
            if (c.first == 1) {
                if (c.second >= max1_one) {
                    max3_one = max2_one;
                    max2_one = max1_one;
                    max1_one = c.second;
                    continue;
                }
                if (c.second >= max2_one) {
                    max3_one = max2_one;
                    max2_one = c.second;
                    continue;
                }
                if (c.second > max3_one) {
                    max3_one = c.second;
                }
            }
        }
        for (int j = 0; j < 10; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j == 9) {
                if (max_three != -1) {
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + max_three * 2);
                }
                if (max_two != -1) {
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + max_two * 2);
                }
                if (max1_one != -1) {
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + max1_one * 2);
                }
                if (max_two != -1 && max1_one != -1) {
                    dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + max(max1_one, max_two) * 2 + min(max1_one, max_two));
                }
                if (max1_one != -1 && max2_one != -1) {
                    dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + max1_one * 2 + max2_one);
                }
                if (max1_one != -1 && max2_one != -1 && max3_one != -1) {
                    dp[i + 1][2] = max(dp[i + 1][2], dp[i][j] + max1_one * 2 + max2_one + max3_one);
                }
            }
            if (j == 8) {
                if (max_three != -1) {
                    dp[i + 1][9] = max(dp[i + 1][9], dp[i][j] + max_three);
                }
                if (max_two != -1) {
                    dp[i + 1][9] = max(dp[i + 1][9], dp[i][j] + max_two);
                }
                if (max1_one != -1) {
                    dp[i + 1][9] = max(dp[i + 1][9], dp[i][j] + max1_one);
                }
                if (max_two != -1 && max1_one != -1) {
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + max(max1_one, max_two) * 2 + min(max1_one, max_two));
                }
                if (max1_one != -1 && max2_one != -1) {
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + max1_one * 2 + max2_one);
                }
                if (max1_one != -1 && max2_one != -1 && max3_one != -1) {
                    dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + max1_one * 2 + max2_one + max3_one);
                }
            }
            if (j == 7) {
                if (max_three != -1) {
                    dp[i + 1][8] = max(dp[i + 1][8], dp[i][j] + max_three);
                }
                if (max_two != -1) {
                    dp[i + 1][8] = max(dp[i + 1][8], dp[i][j] + max_two);
                }
                if (max1_one != -1) {
                    dp[i + 1][8] = max(dp[i + 1][8], dp[i][j] + max1_one);
                }
                if (max_two != -1 && max1_one != -1) {
                    dp[i + 1][9] = max(dp[i + 1][9], dp[i][j] + max1_one + max_two);
                }
                if (max1_one != -1 && max2_one != -1) {
                    dp[i + 1][9] = max(dp[i + 1][9], dp[i][j] + max1_one + max2_one);
                }
                if (max1_one != -1 && max2_one != -1 && max3_one != -1) {
                    dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + max1_one * 2 + max2_one + max3_one);
                }
            }
            if (j >= 0 && j <= 6) {
                if (max_three != -1) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + max_three);
                }
                if (max_two != -1) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + max_two);
                }
                if (max1_one != -1) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + max1_one);
                }
                if (max_two != -1 && max1_one != -1) {
                    dp[i + 1][j + 2] = max(dp[i + 1][j + 2], dp[i][j] + max1_one + max_two);
                }
                if (max1_one != -1 && max2_one != -1) {
                    dp[i + 1][j + 2] = max(dp[i + 1][j + 2], dp[i][j] + max1_one + max2_one);
                }
                if (max1_one != -1 && max2_one != -1 && max3_one != -1) {
                    dp[i + 1][j + 3] = max(dp[i + 1][j + 3], dp[i][j] + max1_one + max2_one + max3_one);
                }
            }
        }
    }
    long long ans = -1;
    for (auto &c : dp[n]) {
        ans = max(ans, c);
    }
    cout << ans;
    return 0;
}