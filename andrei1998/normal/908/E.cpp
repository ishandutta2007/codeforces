#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int MOD = 1000000000 + 7;
const int MMAX = 1000 + 5;

int M, N;
lint nrs[MMAX];

map <lint, int> Map;

int dp[MMAX][MMAX];
int bell[MMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    dp[0][0] = 1;
    for (int i = 1; i <= 1001; ++ i)
        for (int j = 1; j <= 1001; ++ j)
            dp[i][j] = (dp[i - 1][j - 1] + 1LL * j * dp[i - 1][j]) % MOD;

    for (int i = 0; i <= 1001; ++ i)
        for (int j = 0; j <= 1001; ++ j) {
            bell[i] += dp[i][j];
            if (bell[i] >= MOD)
                bell[i] -= MOD;
        }

    cin >> M >> N;

    string str;
    for (int i = 0; i < N; ++ i) {
        cin >> str;
        for (int j = 0; j < M; ++ j)
            if (str[j] == '1')
                nrs[j] += ((1LL) << i);
    }

    for (int i = 0; i < M; ++ i)
        ++ Map[nrs[i]];

    int ans = 1;
    for (auto it: Map)
        ans = (1LL * ans * bell[it.second]) % MOD;
    cout << ans << '\n';
    return 0;
}