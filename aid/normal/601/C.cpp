#include <iostream>

using namespace std;

const int MAXN = 105, MAXM = 1005, MAXS = MAXN * MAXM;
int x[MAXN];
long double dp[2][MAXS];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    if(m == 1) {
        cout << (long double)1 << '\n';
        return 0;
    }
    int s = n * m;
    for(int i = 0; i <= s; i++)
        dp[n & 1][i] = 1;
    for(int i = n - 1; i >= 0; i--) {
        int ii = (i & 1), ni = ((i + 1) & 1);
        dp[ii][0] = 0;
        for(int j = 1; j <= s; j++) {
            int l = 1, r = min(m, j);
            dp[ii][j] = dp[ii][j - 1] + (dp[ni][j - l] -
                                         (j - r - 1 >= 0?
                                          dp[ni][j - r - 1] : 0)) / (m - 1);
            if(l <= x[i] && x[i] <= r)
                dp[ii][j] -= (dp[ni][j - x[i]] -
                              (j - x[i] - 1 >= 0?
                               dp[ni][j - x[i] - 1] : 0)) / (m - 1);
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += x[i];
    cout << 1 + (m - 1) * dp[0][sum - 1] << '\n';
    return 0;
}