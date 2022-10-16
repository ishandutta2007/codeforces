#include <iostream>

using namespace std;

const int MAXN = 20, POWN = (1 << MAXN),
    SIGMA = 26, INF = 1000 * 1000 * 1000 + 5;
char c[MAXN][MAXN];
int a[MAXN][MAXN], dp[2][POWN], msk[(MAXN + 1) * MAXN],
    cost[(MAXN + 1) * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int k = 0;
    for(int i = 0; i < n; i++) {
        msk[k] = (1 << i);
        cost[k] = a[i][0];
        for(int j = 1; j < m; j++)
            cost[k] = min(cost[k], a[i][j]);
        k++;
    }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < SIGMA; j++) {
            int sum = 0, maxa = -1;
            for(int l = 0; l < n; l++)
                if(c[l][i] - 'a' == j) {
                    msk[k] |= (1 << l);
                    sum += a[l][i];
                    maxa = max(maxa, a[l][i]);
                }
            if(!msk[k])
                continue;
            cost[k] = sum - maxa;
            k++;
        }
    for(int i = 0; i < (1 << n); i++)
        dp[0][i] = INF;
    dp[0][0] = 0;
    for(int i = 0; i < k; i++) {
        int ii = (i & 1), ni = ((i + 1) & 1);
        for(int j = 0; j < (1 << n); j++)
            dp[ni][j] = INF;
        for(int j = 0; j < (1 << n); j++)
            if(dp[ii][j] < INF) {
                dp[ni][j] = min(dp[ni][j], dp[ii][j]);
                dp[ni][j | msk[i]] = min(dp[ni][j | msk[i]], dp[ii][j] + cost[i]);
            }
    }
    cout << dp[k & 1][(1 << n) - 1] << '\n';
    return 0;
}