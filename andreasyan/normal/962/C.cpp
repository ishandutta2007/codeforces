#include <bits/stdc++.h>
using namespace std;

int n;

int ans = -1;

int dp[11][11];
void stg(int x, int y)
{
    vector<int> xx;
    while (x)
    {
        xx.push_back(x % 10);
        x /= 10;
    }
    reverse(xx.begin(), xx.end());
    vector<int> yy;
    while (y)
    {
        yy.push_back(y % 10);
        y /= 10;
    }
    reverse(yy.begin(), yy.end());
    for (int i = 0; i < xx.size(); ++i)
    {
        for (int j = 0; j < yy.size(); ++j)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < yy.size(); ++i)
    {
        if (xx[0] == yy[i])
        {
            for (; i < yy.size(); ++i)
                dp[0][i] = 1;
            break;
        }
    }
    for (int i = 0; i < xx.size(); ++i)
    {
        if (xx[i] == yy[0])
        {
            for (; i < xx.size(); ++i)
                dp[i][0] = 1;
            break;
        }
    }
    for (int i = 1; i < xx.size(); ++i)
    {
        for (int j = 1; j < yy.size(); ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (xx[i] == yy[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    if (dp[xx.size() - 1][yy.size() - 1] == xx.size())
        ans = yy.size() - xx.size();
}

int main()
{
    cin >> n;
    for (int i = 1; i * i <= n; ++i)
    {
        stg(i * i, n);
    }
    cout << ans << endl;
    return 0;
}