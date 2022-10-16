#include <iostream>
#include <string>

using namespace std;

const int MAXN = 2005, MOD = 1000 * 1000 * 1000 + 7;
int dp[MAXN][MAXN][2];

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int solve(int m, int d, const string &s, bool le) {
    int n = s.length();
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < 2; k++) {
                if(!dp[i][j][k])
                    continue;
                if(i & 1) {
                    if(k == 1 || d < (s[i] - '0'))
                        add(dp[i + 1][(j * 10 + d) % m][1], dp[i][j][k]);
                    else if(k == 0 && d == (s[i] - '0'))
                        add(dp[i + 1][(j * 10 + d) % m][k], dp[i][j][k]);
                }
                else {
                    for(int dig = (i? 0 : 1); dig < (k? 10 : (s[i] - '0')); dig++) {
                        if(dig == d)
                            continue;
                        add(dp[i + 1][(j * 10 + dig) % m][1], dp[i][j][k]);
                    }
                    if(!k && d != (s[i] - '0'))
                        add(dp[i + 1][(j * 10 + (s[i] - '0')) % m][k], dp[i][j][k]);
                }
            }
    return (le? dp[n][0][1] : dp[n][0][1] + dp[n][0][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, d;
    string a, b;
    cin >> m >> d >> a >> b;
    int ans = (solve(m, d, b, false) + MOD - solve(m, d, a, true)) % MOD;
    cout << ans << '\n';
    return 0;
}