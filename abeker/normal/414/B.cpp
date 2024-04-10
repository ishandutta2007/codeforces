#include <cstdio>
using namespace std;

const int MAXN = 2005;
const int MOD = 1000000007;

int N, K;
int dp[MAXN][MAXN];

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void load() {
    scanf("%d%d", &N, &K);
}

int solve() {
    dp[0][1] = 1;
    for (int i = 0; i < K; i++)
        for (int j = 1; j <= N; j++)
            for (int k = j; k <= N; k += j)
                add(dp[i + 1][k], dp[i][j]);
    int sol = 0;
    for (int i = 1; i <= N; i++)    
        add(sol, dp[K][i]);
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}