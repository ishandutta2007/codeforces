#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll dp[11][11][11];

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string n;
    cin >> t;
    while (t--) {
        cin >> n;
        reverse(n.begin(), n.end());
        for (int i = 0; i <= 10; ++i) {
            for (int j = 0; j <= 10; ++j) {
                for (int z = 0; z <= 10; ++z) dp[i][j][z] = 0;
            }
        }
        dp[0][0][0] = 1;
        n = "#" + n;
        for (int i = 1; i < (int)n.size(); ++i) {
            for (int now = 0; now <= 10; ++now) {
                for (int nxt = 0; nxt <= 10; ++nxt) {
                    if (dp[i - 1][now][nxt] == 0) continue;
                    for (int a = 0; a <= 9; ++a) {
                        for (int b = 0; b <= 9; ++b) {
                            int val = (a + b + now);
                            if (val % 10 == n[i] - '0') {
                                dp[i][nxt][val / 10] += dp[i - 1][now][nxt];
                            }
                        }
                    }
                }
            }
        }
        ll ans = dp[n.size() - 1][0][0] - 2;
        cout << ans << '\n';
    }
    return 0;
}