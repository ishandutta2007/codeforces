#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 5005;
int p[MAXN], t[MAXN];
long double dp[2][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> t[i];
    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--) {
            int ii = (i & 1), pi = ((i + 1) & 1);
            dp[ii][j] = dp[ii][j + 1] * ((long double)(100 - p[i]) / 100);
            dp[ii][j] += ((long double)p[i] / 100) * (1 + dp[pi][j + 1]);
            if(j + t[i] == m)
                dp[ii][j] += pow((long double)(100 - p[i]) / 100, t[i]) *
                    (1 + dp[pi][j + t[i]]);
            else if(j + t[i] < m)
                dp[ii][j] += pow((long double)(100 - p[i]) / 100, t[i]) *
                    (1 + dp[pi][j + t[i]] - (1 + dp[pi][j + t[i] + 1]));
        }
    cout << dp[0][0] << '\n';
    return 0;
}