#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 155;
const int INF = 0x3f3f3f3f;

int N, K, S;
int a[MAXN];
int dp[2][MAXN][MAXN * MAXN];
int opt[2][MAXN][MAXN * MAXN];

void load() {
    scanf("%d%d%d", &N, &K, &S);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
}

int solve() {
    int bound = N * (N - 1) / 2;
    S = min(S, bound);
    int c = 0;
    memset(dp[0], INF, sizeof dp[0]);
    memset(dp[0][0], 0, sizeof dp[0][0]);
    int limit = min(K, N - K);
    for (int k = K; k < N; k++) {
        c ^= 1;
        for (int i = 0; i <= limit; i++)
            for (int j = 0; j <= bound; j++) {
                dp[c][i][j] = dp[c ^ 1][i][j];
                if (i && j >= k) dp[c][i][j] = min(dp[c][i][j], dp[c ^ 1][i - 1][j - k] + a[k]);
            }
    }
    
    int d = 0;
    memset(opt[0], -INF, sizeof opt[0]);
    opt[0][0][0] = 0;
    for (int k = 0; k < K; k++) {
        d ^= 1;
        for (int i = 0; i <= limit; i++)
            for (int j = 0; j <= bound; j++) {
                opt[d][i][j] = opt[d ^ 1][i][j];
                if (i) opt[d][i][j] = max(opt[d][i][j], opt[d ^ 1][i - 1][max(j - k, 0)] + a[k]);
            }
    }
    
    int sol = INF;
    for (int i = 0; i <= limit; i++) {
        int sum = 0;
        for (int j = 1; j <= i; j++)
            sum += K - j;
        for (int j = 0; j <= S; j++)
            if (sum + j <= bound && sum + j >= S)
                sol = min(sol, dp[c][i][sum + j] - opt[d][i][sum - S + j]);
    }
    
    for (int i = 0; i < K; i++) 
        sol += a[i];
        
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}