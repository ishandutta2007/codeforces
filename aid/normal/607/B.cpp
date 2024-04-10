#include <iostream>

using namespace std;

const int MAXN = 505;
int c[MAXN], dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++)
        dp[i][i] = 1;
    for(int i = 0; i + 1 < n; i++)
        dp[i][i + 1] = (c[i] == c[i + 1]? 1 : 2);
    for(int len = 3; len <= n; len++)
        for(int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = MAXN;
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            if(c[i] == c[j])
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
        }
    cout << dp[0][n - 1] << '\n';
    return 0;
}