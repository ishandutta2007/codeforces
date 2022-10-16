#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000 + 7;

inline void add(int &where, const int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

const int KMAX = 5000 + 5;

int N, K;
int dp[KMAX][KMAX];

int raise(int a, int b) {
    int ans = 1, aux = a;
    while (b) {
        if (b & 1)
            ans = (1LL * ans * aux) % MOD;
        aux = (1LL * aux * aux) % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cin >> N >> K;

    dp[0][0] = 1;
    for (int i = 0; i < K; ++ i)
        for (int j = 0; j <= i; ++ j) {
            add(dp[i + 1][j], (1LL * j * dp[i][j]) % MOD);
            add(dp[i + 1][j + 1], (1LL * max(0, N - j) * dp[i][j]) % MOD);
        }

    int ans = 0;
    for (int cnt = 1; cnt <= N && cnt <= K; ++ cnt)
        add(ans, (1LL * dp[K][cnt] * raise(2, (N - cnt))) % MOD);

    cout << ans << '\n';
    return 0;
}