#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 1005, Mod = 1e9 + 7;

int dp[Nmax][Nmax][2][2];
int sdp[Nmax];

int fact[Nmax];
int comb[Nmax][Nmax];

int ans[Nmax];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    dp[1][0][0][0] = 1;
    if (N > 1) dp[1][1][0][1] = 1;

    for (int i = 2; i <= N; ++i) {
        dp[i][0][0][0] = 1;
        for (int j = 1; j <= i; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int p = 0; p < 2; ++p) {
                    if (k == 0)
                        dp[i][j][p][0] = (dp[i][j][p][0] + dp[i - 1][j - 1][k][p]) % Mod;
                    if (i < N)
                        dp[i][j][p][1] = (dp[i][j][p][1] + dp[i - 1][j - 1][k][p]) % Mod;
                    dp[i][j][p][0] = (dp[i][j][p][0] + dp[i - 1][j][k][p]) % Mod;
                }
            }
        }
    }

    for (int i = 0; i <= N; ++i)
        for (int k = 0; k < 2; ++k)
            for (int p = 0; p < 2; ++p)
                sdp[i] = (sdp[i] + dp[N][i][k][p]) % Mod;

    //cerr << sdp[1] << '\n';

    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = (i64) fact[i - 1] * i % Mod;

    for (int i = 0; i <= N; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % Mod;
    }

   for (int i = N; i >= K; --i) {
       ans[i] = (i64) sdp[i] * fact[N - i] % Mod;
       for (int j = i + 1; j <= N; ++j) {
           ans[i] = (ans[i] - (i64) ans[j] * comb[j][i]) % Mod;
           if (ans[i] < 0) ans[i] += Mod;
       }
   }

   cout << ans[K] << '\n';
}