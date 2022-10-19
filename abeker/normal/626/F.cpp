#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 205;
const int MAXK = 1005;
const int MOD = 1000000007;

int N, K;
int a[MAXN];
int dp[MAXN][MAXK][2];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) 
        x -= MOD;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int solve() {
    sort(a, a + N);
    a[N] = (int)1e6;
    
    int c = 0;
    for (int i = 0; i <= K; i++)
        dp[0][i][c] = 1;
        
    for (int i = N - 1; i >= 0; i--) {
        c ^= 1;
        for (int j = 0; j <= N; j++)
            for (int k = 0; k <= K; k++) {
                dp[j][k][c] = 0;
                int delta = a[i + 1] - a[i];
                int nxt = k + j * delta;
                if (nxt <= K) {
                    dp[j][k][c] = mul(j + 1, dp[j][nxt][c ^ 1]);
                    if (nxt + delta <= K) 
                        add(dp[j][k][c], dp[j + 1][nxt + delta][c ^ 1]);
                }
                if (j && nxt - delta <= K)  
                    add(dp[j][k][c], mul(j, dp[j - 1][nxt - delta][c ^ 1]));
            }
    }
    
    return dp[0][0][c];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}