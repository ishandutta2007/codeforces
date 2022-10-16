#include <iostream>

using namespace std;

const int MAXN = 405, MAXK = 55, INF = 1000 * 1000 * 1000 + 5;
int a[MAXN], s[MAXN], dp[2][MAXN][MAXN];

int getSum(int l, int r) {
    return s[r] - (l? s[l - 1] : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    s[0] = a[0];
    for(int i = 1; i < n; i++)
        s[i] = a[i] + s[i - 1];
    for(int i = 2; i <= k; i++) {
        int ii = i & 1, pi = ((i - 1) & 1);
        int max0 = -INF, max1 = -INF;
        for(int l = 0; l < n; l++) {
            if(max0 == -INF) {
                for(int r = l; r < n; r++)
                    dp[ii][l][r] = -1;
            }
            else {
                for(int r = l; r < n; r++)
                    dp[ii][l][r] = max(max0 + getSum(l, r),
                                       max1 - getSum(l, r));
            }
            for(int ll = 0; ll <= l; ll++)
                if(dp[pi][ll][l] != -1) {
                    max0 = max(max0, dp[pi][ll][l] - getSum(ll, l));
                    max1 = max(max1, dp[pi][ll][l] + getSum(ll, l));
                }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            ans = max(ans, dp[k & 1][i][j]);
    cout << ans << '\n';
    return 0;
}