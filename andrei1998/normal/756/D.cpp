#include <iostream>
#include <string>

//16:20
using namespace std;

const int NMAX = 5000 + 5;
const int MOD = 1000000000 + 7;

int N;
string str;

int comb[NMAX][NMAX];
int dp[NMAX][26];
int sum[NMAX];

int main()
{
    cin >> N;
    cin >> str;

    for (int i = 0; i <= N; ++ i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if (comb[i][j] >= MOD)
                comb[i][j] -= MOD;
        }
    }

    string str2;
    for (int i = 0; i < N; ++ i)
        if (str2.empty() || str2.back() != str[i])
            str2 += str[i];
    str = str2;

    int cnt = 0;
    for (auto ch: str) {
        ++ cnt;

        if (!dp[1][ch - 'a']) {
            dp[1][ch - 'a'] = 1;
            ++ sum[1];
            if (sum[1] >= MOD)
                sum[1] -= MOD;
        }

        for (int i = 2; i <= cnt; ++ i) {
            sum[i] -= dp[i][ch - 'a'];
            if (sum[i] < 0)
                sum[i] += MOD;
            dp[i][ch - 'a'] = sum[i - 1] - dp[i - 1][ch - 'a'];
            if (dp[i][ch - 'a'] < 0)
                dp[i][ch - 'a'] += MOD;
            sum[i] += dp[i][ch - 'a'];
            if (sum[i] >= MOD)
                sum[i] -= MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= cnt; ++ i)
        for (int j = 0; j < 26; ++ j)
            ans = (ans + 1LL * dp[i][j] * comb[N - 1][i - 1]) % MOD;

    cout << ans << '\n';
    return 0;
}