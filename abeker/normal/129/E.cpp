#include <cstdio>
using namespace std;

const int MAXN = 1005;
const int MOD = 1000000007;

int N, M, K;
int dp[MAXN][MAXN];
int pref[MAXN][MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d%d%d", &N, &M, &K);
}

int solve() {
    for (int i = 1; i < MAXN; i++)
        pref[0][i] = i * (i + 1) / 2;
    for (int i = 1; i <= K; i++) {
        for (int j = 2; j < MAXN; j++) 
            dp[i][j] = pref[i - 1][j - 2];
        for (int j = 1; j < MAXN; j++) 
            pref[i][j] = add(pref[i][j - 1], dp[i][j]);
        for (int j = 1; j < MAXN; j++)
            pref[i][j] = add(pref[i][j - 1], pref[i][j]);
    }
    return mul(dp[K][N], dp[K][M]);
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}