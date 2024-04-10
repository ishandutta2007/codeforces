#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 35, Kmax = 205;

double dp[Kmax][Nmax][Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[0][i][j] = A[i] > A[j];

    double invp = 2.0D / (N * (N + 1));
    for (int step = 1; step <= K; ++step) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int lq = 0; lq < N; ++lq) {
                    for (int rq = lq; rq < N; ++rq) {
                        int ni = lq <= i && i <= rq ? lq + rq - i: i;
                        int nj = lq <= j && j <= rq ? lq + rq - j: j;
                        dp[step][ni][nj] += dp[step - 1][i][j] * invp;
                    }
                }
            }
        }
    }

    double ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            ans += dp[K][i][j];

    cout << setprecision(14) << fixed;
    cout << ans << '\n';
}