#include <cstdio>
using namespace std;

const int MAXN = 505;
const int MOD = 1000000007;

int N, K;
int dp[MAXN][MAXN];
int pow[MAXN * MAXN];

void load() {
    scanf("%d%d", &N, &K);
}

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int solve() {
    pow[0] = 1;
    for (int i = 1; i < MAXN * MAXN; i++)
        pow[i] = mul(pow[i - 1], 2);
        
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= K; j++)
            for (int pos = 1; pos <= i; pos++)
                dp[i][j] = add(dp[i][j], mul(dp[pos - 1][j - 1], add(pow[pos * (i - pos + 1)], -pow[(pos - 1) * (i - pos + 1)])));
    }
    
    return dp[N][K];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}