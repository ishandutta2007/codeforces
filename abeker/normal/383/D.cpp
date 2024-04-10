#include <cstdio>
using namespace std;

const int MAXN = 1005;
const int MAXM = 10005;
const int MOD = 1000000007;

int n;
int a[MAXN];
int dp[MAXN][3 * MAXM];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) 
        for (int j = -MAXM; j < MAXM; j++) { 
            dp[i][j + MAXM] = dp[i - 1][j + a[i] + MAXM];
            if (j + MAXM >= a[i])
                dp[i][j + MAXM] = (dp[i][j + MAXM] + dp[i - 1][j - a[i] + MAXM]) % MOD;
            if (a[i] == j || -a[i] == j) dp[i][j + MAXM] = (dp[i][j + MAXM] + 1) % MOD;
        }
    //for (int i = 1; i <= n; i++, puts(""))
    //  for (int j = -5; j < 5; j++)
    //      printf("%d ", dp[i][j + MAXM]);
    int sol = 0;
    for (int i = 1; i <= n; i++)
        sol = (sol + dp[i][MAXM]) % MOD;
    printf("%d\n", sol);
    return 0;
}