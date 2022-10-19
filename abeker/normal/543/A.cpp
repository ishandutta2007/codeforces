#include <cstdio>
using namespace std;

const int MAXN = 505;

int N, M, B, MOD;
int a[MAXN];
int dp[MAXN][MAXN];
int nxt[MAXN][MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

void load() {
    scanf("%d%d%d%d", &N, &M, &B, &MOD);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int solve() {
    for (int i = 0; i < N; i++)
        dp[i][0] = 1;
    
    while (M--) {
        for (int i = 0; i < N; i++) 
            for (int j = 0; j <= B; j++) 
                nxt[i][j] = j < a[i] ? 0 : dp[i][j - a[i]];
        for (int i = 0; i < N; i++)
            for (int j = 0; j <= B; j++)
                dp[i][j] = add(i ? dp[i - 1][j] : 0, nxt[i][j]);
    }
    
    int sol = 0;
    for (int i = 0; i <= B; i++)
        sol = add(sol, dp[N - 1][i]);
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}