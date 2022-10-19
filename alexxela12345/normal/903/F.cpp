#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(4);
    for (int i = 0; i < 4; i++) {
        cin >> cost[i];
    }
    vector<string> arr(4);
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    arr[0] += "....";
    arr[1] += "....";
    arr[2] += "....";
    arr[3] += "....";
    vector<vector<int>> dp(n + 1, vector<int> (1 << 16, 1e9));
    int maskInit = 0;
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            if (arr[i][j] == '*') {
                maskInit ^= 1 << (4 * j + i);
            }
        }
    }
    dp[0][maskInit] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = (1 << 16) - 1; mask >= 0; mask--) {
            if (dp[i][mask] == 1e9)
                continue;
            for (int sz = 1; sz <= 4; sz++) {
                for (int j = 0; j + sz <= 4; j++) {
                    int mask2 = mask;
                    for (int x = j; x < j + sz; x++) {
                        for (int y = 0; y < sz; y++) {
                            int pos = 4 * y + x;
                            if (mask2 & (1 << pos)) {
                                mask2 ^= 1 << pos;
                            }
                        }
                    }
                    dp[i][mask2] = min(dp[i][mask2], dp[i][mask] + cost[sz - 1]);
                }
            }
        }
        for (int mask = 0; mask < (1 << 16); mask += (1 << 4)) {
            int mask2 = mask >> 4;
            for (int j = 0; j < 4; j++) {
                if (arr[j][i + 4] == '*') {
                    mask2 ^= 1 << (12 + j);
                }
            }
            dp[i + 1][mask2] = min(dp[i + 1][mask2], dp[i][mask]);
        }
    }
    cout << dp[n][0] << endl;
}