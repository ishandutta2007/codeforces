#include <cstdio>
using namespace std;

const int MAXN = 2005;
const int MOD = 1000000007;

int N, M;
int dp[MAXN][MAXN];
int memo[MAXN][MAXN];
int pref[MAXN][MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d%d", &N, &M);
}

int solve() {
    for (int i = 2; i <= M; i++) {
        dp[1][i] = 1;
        memo[1][i] = 1;
        pref[1][i] = i * (i - 1) / 2;
    }
    
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            dp[i][j] = pref[i - 1][j];
            memo[i][j] = add(dp[i][j], -dp[i - 1][j]);
        }
        
        for (int j = 1; j <= M; j++)
            pref[i][j] = add(pref[i][j - 1], dp[i][j]);
        for (int j = 1; j <= M; j++)
            pref[i][j] = add(pref[i][j - 1], pref[i][j]);
    }
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            memo[i][j] = add(memo[i - 1][j], memo[i][j]);
            dp[i][j] = add(dp[i - 1][j], dp[i][j]);
        }
        
    int sol = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 2; j <= M; j++) 
            sol = add(sol, mul(M - j + 1, mul(dp[i][j], memo[N - i + 1][j])));
            
    return sol;      
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}