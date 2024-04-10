#include <bits/stdc++.h>
using namespace std;
const int N = 2003;

int n;
double p;
int t;

double dp[N][N];
int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(8);
    cin >> n >> p >> t;
    dp[0][0] = 1;
    for (int i = 1; i <= t; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (j == 0)
                dp[i][j] = (dp[i - 1][j] * (1 - p));
            else if (j == n)
                dp[i][j] = (dp[i - 1][j]) + (dp[i - 1][j - 1] * p);
            else
                dp[i][j] = (dp[i - 1][j] * (1 - p)) + (dp[i - 1][j - 1] * p);
        }
    }
    double ans = 0;
    for (int i = 0; i <= n; ++i)
        ans += i * dp[t][i];
    cout << ans << endl;
    return 0;
}