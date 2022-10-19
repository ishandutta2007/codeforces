#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const char t[4] = {'h', 'a', 'r', 'd'};

int n;
char s[N];
int a[N];

long long dp[N][4];
int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (s[i] != t[j])
            {
                if (i == 0)
                    continue;
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                if (i == 0)
                {
                    if (j == 0)
                        dp[i][j] = a[i];
                    continue;
                }
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + a[i];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + a[i]);
            }
        }
    }
    cout << dp[n - 1][3] << endl;
    return 0;
}