#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 105, Mmax = 10005;

int A[Nmax];
int dp[2][Mmax];
int canAdd[Nmax];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int total = 0;
    for (int i = 1, u = 1; i <= N; ++i, u ^= 1) {
        int K;
        cin >> K;
        total += K;
        for (int j = 1; j <= K; ++j) cin >> A[j];
        
        for (int j = 1; j <= K; ++j) {
            canAdd[j] = 0;
            int s = 0;
            for (int k = K; k > K - j; --k)
                s += A[k];
            int s1 = 0;
            for (int k = 0; k <= j; ++k) {
                canAdd[j] = max(canAdd[j], s + s1);
                s1 += A[k + 1];
                s -= A[K - j + k + 1];
            }
        }
        
        memcpy(dp[u], dp[u ^ 1], sizeof dp[u]);
        int P = min(M, total);
        for (int j = 1; j <= P; ++j) {
            for (int k = 1; k <= K && j - k >= 0; ++k)
                dp[u][j] = max(dp[u][j], dp[u ^ 1][j - k] + canAdd[k]);
        }
    }

    cout << dp[N & 1][M] << '\n';
}