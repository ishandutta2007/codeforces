#include<bits/stdc++.h>

using namespace std;

int const maxn = 205;
int r[maxn], g[maxn], b[maxn];
int dp[maxn][maxn][maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R, G, B;
    cin >> R >> G >> B;
    for (int i = 1; i <= R; ++i) cin >> r[i];
    sort(r + 1, r + R + 1);
    for (int i = 1; i <= G; ++i) cin >> g[i];
    sort(g + 1, g + G + 1);
    for (int i = 1; i <= B; ++i) cin >> b[i];
    sort(b + 1, b + B + 1);
    for (int i = 0; i <= R; ++i) {
        for (int j = 0; j <= G; ++j) {
            for (int z = 0; z <= B; ++z) {
                int val = dp[i][j][z];
                dp[i + 1][j][z] = max(dp[i + 1][j][z], val);
                dp[i][j + 1][z] = max(dp[i][j + 1][z], val);
                dp[i][j][z + 1] = max(dp[i][j][z + 1], val);
                dp[i + 1][j + 1][z] = max(dp[i + 1][j + 1][z], val + r[i + 1] * g[j + 1]);
                dp[i + 1][j][z + 1] = max(dp[i + 1][j][z + 1], val + r[i + 1] * b[z + 1]);
                dp[i][j + 1][z + 1] = max(dp[i][j + 1][z + 1], val + g[j + 1] * b[z + 1]);
            }
        }
    }
    cout << dp[R][G][B] << '\n';
    return 0;
}