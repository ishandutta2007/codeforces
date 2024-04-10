#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int NMAX = 5005;
const int MOD = (int) 1e9 + 7;

int dp[NMAX][NMAX];
int last[26];

int main()
{
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // LOCAL_RUN
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i <= n; ++i) {
        dp[1][i] = 1;
    }
    memset(last, -1, sizeof last);
    last[s[0] - 'a'] = 1;
    for (int i = 2; i <= n; ++i) {
        int c = s[i - 1] - 'a';
        dp[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
            if (last[c] != -1) {
                dp[i][j] -= dp[last[c]][j - 1];
                dp[i][j] %= MOD;
            }
        }
        last[c] = i;
    }
    int ans = dp[n][n];
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}