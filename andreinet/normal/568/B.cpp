#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 4005, Mod = 1e9 + 7;

int Comb[Nmax][Nmax];

int dp[Nmax];
int dpc[Nmax];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i <= N; ++i) {
        Comb[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            Comb[i][j] = (Comb[i - 1][j - 1] + Comb[i - 1][j]) % Mod;
    }

    dpc[0] = 1;

    dp[1] = 1;
    dpc[1] = 2;

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < i - 1; ++j) {
            dp[i] = (dp[i] + (i64) dp[i - j - 1] * Comb[i - 1][j]) % Mod;
        }
        dp[i] = (dp[i] + dpc[i - 1]) % Mod;

        for (int j = 0; j <= i; ++j)
            dpc[i] = (dpc[i] + (i64) dpc[i - j - 1] * Comb[i - 1][j]) % Mod;
        dpc[i] = (dpc[i] + dpc[i - 1]) % Mod;
    }

    cout << dp[N] << '\n';
}