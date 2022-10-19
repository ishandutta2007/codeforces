#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5010;

int n, m, sol;
char mat[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) 
        scanf("%s", mat[i] + 1);
    for (int i = 1; i <= n; i++) {
        mat[i][m + 1] = '0'; 
        for (int j = 1; j <= m + 1; j++) 
            if (mat[i][j] == '0') 
                for (int k = j - 1; k && mat[i][k] == '1'; k--) {
                    dp[k][k]++;
                    dp[k][j]--; 
                }
    }
    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i][j - 1];
            sol = max(sol, (j - i + 1) * dp[i][j]);
        }
    printf("%d\n", sol);
    return 0;
}