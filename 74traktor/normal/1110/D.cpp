#include <bits/stdc++.h>

using namespace std;

int dp[1000005][3][3];
int cnt[1000005];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= m + 2; i++) {
        for (int t1 = 0; t1 <= 2; t1++) {
            for (int t2 = 0; t2 <= 2; t2++) {
                if (t1 + t2 > cnt[i]) {
                    continue;
                }
                for (int t3 = 0; t3 <= 2; t3++) {
                    if (t1 + t2 + t3 > cnt[i]) {
                        continue;
                    }
                    x = t3 + (cnt[i] - t1 - t2 - t3) / 3;
                    dp[i + 1][t2][t3] = max(dp[i + 1][t2][t3], dp[i][t1][t2] + x);
                }
            }
        }
    }
    cout << dp[m + 2][0][0] << '\n';
    return 0;
}