#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

int Mod;
const int Nmax = 1005, Kmax = 105;

int Dp[Nmax][Kmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K >> Mod;

    for (int i = 1; i < 10; ++i)
        Dp[1][i % K]++;
    if (N > 1) Dp[1][K] = 1;

    for (int i = 2, pw = 10 % K; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            for (int k = i == N ? 1: 0; k < 10; ++k) {
                int nj = (1LL * pw * k + j) % K;
                Dp[i][nj] = (Dp[i][nj] + Dp[i - 1][j]) % Mod;
            }
        }
        Dp[i][K] = 1;
        pw = 10LL * pw % K;
    }

    int ans = 0, pw = 1;
    for (int i = 1; i < N; ++i) {
        pw = 10LL * pw % Mod;
    }
    pw = 9LL * pw % Mod;

    for (int i = 1; i < K; ++i)
        ans = (ans + Dp[N][i]) % Mod;

    ans = (pw - ans + Mod) % Mod;

    cout << ans << '\n';
}