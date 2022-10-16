#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 300 * 1000 + 5, MAXK = 5005;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
long long a[MAXN], dp[2][MAXK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < MAXK; i++)
        dp[0][i] = INF;
    dp[0][0] = 0;
    int l = n % k;
    for(int i = 0; i < k; i++) {
        int ii = (i & 1), ni = ((i + 1) & 1);
        for(int j = 0; j < MAXK; j++)
            dp[ni][j] = INF;
        for(int j = 0; j <= i && j <= l; j++) {
            int pos = i * (n / k) + j;
            dp[ni][j] = min(dp[ni][j], dp[ii][j] +
                            a[pos + (n / k) - 1] - a[pos]);
            if(j < l)
                dp[ni][j + 1] = min(dp[ni][j + 1],
                                    dp[ii][j] + a[pos + (n / k)] - a[pos]);
        }
    }
    cout << dp[k & 1][l] << '\n';
    return 0;
}