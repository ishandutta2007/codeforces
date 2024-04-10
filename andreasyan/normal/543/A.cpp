#include <bits/stdc++.h>
using namespace std;
const int N = 502;

int n, m, b, M;
int a[N];

int dpn[N][N];
int dp[N][N];
int main()
{
    cin >> n >> m >> b >> M;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dpn[0][0] = 1 % M;
    for (int i = 1; i <= n; ++i)
    {
        for (int t = 0; t <= m; ++t)
            for (int s = 0; s <= b; ++s)
                dp[t][s] = 0;
        for (int t = 0; t <= m; ++t)
        {
            for (int s = 0; s <= b; ++s)
            {
                if (s - a[i] >= 0 && t - 1 >= 0)
                    dp[t][s] = (dp[t - 1][s - a[i]] + dpn[t][s]) % M;
                else
                    dp[t][s] = dpn[t][s];
            }
        }
        for (int t = 0; t <= m; ++t)
            for (int s = 0; s <= b; ++s)
                dpn[t][s] = dp[t][s];
    }
    int ans = 0;
    for (int s = 0; s <= b; ++s)
        ans = (ans + dp[m][s]) % M;
    cout << ans << endl;
    return 0;
}