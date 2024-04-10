#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 31;
const int MAXK = 51;
const int INF = 0x3f3f3f3f;

int dp[MAXN][MAXN][MAXK];

void init() {
    memset(dp, INF, sizeof dp);
    for (int a = 1; a < MAXN; a++)
        for (int b = 1; b < MAXN; b++)
            for (int c = 0; c < MAXK; c++) {
                int &ref = dp[a][b][c];
                if (!c || a * b == c) {
                    ref = 0;
                    continue;
                }
                for (int k = 0; k <= c; k++) {
                    for (int i = 1; i < a; i++)
                        ref = min(ref, b * b + dp[i][b][k] + dp[a - i][b][c - k]);
                    for (int i = 1; i < b; i++)
                        ref = min(ref, a * a + dp[a][i][k] + dp[a][b - i][c - k]);
                }
            }
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", dp[n][m][k]);
    }
    return 0;
}