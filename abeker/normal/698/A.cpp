#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int N;
int a[MAXN];
int dp[MAXN][5];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int solve() {
    memset(dp, INF, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i < 4; i++)
        if ((i & a[0]) == i) dp[0][i] = 0;
        
    for (int i = 1; i < N; i++)
        for (int j = 0; j < 4; j++) {
            if ((j & a[i]) != j) continue;
            for (int k = 0; k < 4; k++)
                if (!(k & j)) dp[i][j] = min(dp[i][j], dp[i - 1][k]);
            dp[i][j] += !j;
        }    
            
    return *min_element(dp[N - 1], dp[N - 1] + 4);
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}