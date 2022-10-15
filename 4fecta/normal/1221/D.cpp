#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (; q > 0; q--) {
        int n;
        cin >> n;
        lli h[n];
        lli cost[n];
        lli dp[n][3]; //dp[i][j] represents the minimum cost of a valid fence ending at i such that the last fence has a height + j
        memset(dp, 0x3f3f3f3f3f, sizeof(dp));
        for (int i = 0; i < n; i++) {
            cin >> h[i] >> cost[i];
        }
        dp[0][0] = 0; //base cases
        dp[0][1] = cost[0];
        dp[0][2] = 2 * cost[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) { //increase to current value
                for (int k = 0; k < 3; k++) { //increase to previous value
                    if (h[i] + j != h[i - 1] + k) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost[i] * j);
                    }
                }
            }
        }
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
    }
    return 0;
}