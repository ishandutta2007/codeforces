#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 205, MAXS = 105, MAXK = 1005, MOD = 1000 * 1000 * 1000 + 7;
int a[MAXN], dp[MAXN][MAXS][MAXK];

int mul(int a, int b) {
    return (long long)a * b % MOD;
}

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, maxk;
    cin >> n >> maxk;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    dp[0][0][0] = 1;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < MAXS; j++)
            for(int k = 0; k <= maxk; k++) {
                if(!dp[i][j][k])
                    continue;
                int len = (a[i + 1] - a[i]);
                if(k + len * j <= maxk)
                    add(dp[i + 1][j][k + len * j], mul(dp[i][j][k], j + 1));
                if(j && k + len * (j - 1) <= maxk)
                    add(dp[i + 1][j - 1][k + len * (j - 1)],
                        mul(dp[i][j][k], j));
                if(j + 1 < MAXS && k + len * (j + 1) <= maxk)
                    add(dp[i + 1][j + 1][k + len * (j + 1)], dp[i][j][k]);
            }
    int ans = 0;
    for(int j = 0; j <= 1; j++)
        for(int k = 0; k <= maxk; k++)
            add(ans, dp[n - 1][j][k]);
    cout << ans << '\n';
    return 0;
}