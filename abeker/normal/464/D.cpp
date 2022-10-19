#include <cstdio>
using namespace std;

typedef long double ld;

const int MAXB = 705;

int N, K;
ld dp[MAXB][2];

void load() {
    scanf("%d%d", &N, &K);
}

ld solve() {
    ld sol = 0;
    dp[1][0] = 1;
    int c = 0;
    for (int i = 1; i <= N; i++) {
        c ^= 1;
        for (int j = 1; j <= N + 1 && j < MAXB; j++) {
            dp[j][c] = dp[j][c ^ 1] * (1. - 1. / (K * (j + 1))) + dp[j - 1][c ^ 1] * 1. / (K * j);
            sol += dp[j][c ^ 1] / 2 * j + dp[j - 1][c ^ 1] * (j - 1) / j;
        }
    }
    return sol;
}

int main() {
    load();
    printf("%.10lf\n", (double)solve());
    return 0;
}