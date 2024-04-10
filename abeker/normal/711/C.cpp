#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 105;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int N, M, K;
int c[MAXN];
int cost[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", c + i);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", cost[i] + j);
}

ll solve() {
    memset(dp, INF, sizeof dp);
    
    dp[0][0][0] = 0;
    for (int pos = 1; pos <= N; pos++) 
        for (int k = 0; k <= N; k++)
            for (int last = 0; last <= M; last++) 
                for (int j = 1; j <= M; j++) 
                    if (!c[pos] || c[pos] == j) {
                        int nxt = k + (j != last);
                        if (pos == 1) nxt = 1;
                        dp[pos][nxt][j] = min(dp[pos][nxt][j], (c[pos] ? 0 : cost[pos][j]) + dp[pos - 1][k][last]);
                    }
    
    ll sol = *min_element(dp[N][K] + 1, dp[N][K] + M + 1);
    if (sol == INF) return -1;
    return sol; 
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}