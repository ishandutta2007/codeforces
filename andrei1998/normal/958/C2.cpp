#include <bits/stdc++.h>

using namespace std;

const int NMAX = 20000 + 5;
const int KMAX = 50 + 5;
const int PMAX = 100 + 5;

int N, K, p;
int A[NMAX];

int dp[2][KMAX][PMAX];

inline void upd(int &where, int val) {
    if (val > where)
        where = val;
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);

    cin >> N >> K >> p;
    for (int i = 1; i <= N; ++ i)
        cin >> A[i];

    memset(dp, -1, sizeof dp);

    dp[1][1][A[1] % p] = 0;
    for (int i = 1; i < N; ++ i) {
        memset(dp[(i + 1) & 1], -1, sizeof(dp[(i + 1) & 1]));
        for (int k = 1; k <= K; ++ k)
            for (int sum = 0; sum < p; ++ sum)
                if (dp[i & 1][k][sum] != -1) {
                    upd(dp[(i + 1) & 1][k][(sum + A[i + 1]) % p], dp[i & 1][k][sum]);
                    if (k + 1 <= K)
                        upd(dp[(i + 1) & 1][k + 1][A[i + 1] % p], dp[i & 1][k][sum] + sum);
                }
    }

    int ans = -1;
    for (int sum = 0; sum < p; ++ sum)
        if (dp[N & 1][K][sum] != -1)
            upd(ans, dp[N & 1][K][sum] + sum);
    cout << ans << '\n';
    return 0;
}