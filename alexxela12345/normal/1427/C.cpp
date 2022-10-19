#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, n;
    cin >> r >> n;
    vector<int> dp(n, -1e9);
    vector<vector<int>> arr(n, vector<int> (3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    vector<int> pref(n + 1, -1e9);
    for (int i = 0; i < n; i++) {
        if (arr[i][1] + arr[i][2] - 2 <= arr[i][0]) {
            dp[i] = 1;
        }
        int min_time = arr[i][0] - 2 * r;
        int j = i - 1;
        while (j >= 0 && arr[j][0] > min_time) {
            if (abs(arr[i][1] - arr[j][1]) + abs(arr[i][2] - arr[j][2]) <= arr[i][0] - arr[j][0]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            j--;
        }
        dp[i] = max(dp[i], 1 + pref[j + 1]);
        pref[i + 1] = max(pref[i], dp[i]);
    }
    cout << max(0, pref.back()) << endl;
}