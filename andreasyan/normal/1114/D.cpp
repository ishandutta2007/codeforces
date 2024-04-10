#include <bits/stdc++.h>
using namespace std;
const int N = 5003, INF = 1000006;

int n;
int a[N];

int dp[N][N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
            v.push_back(a[i]);
    }
    n = v.size();
    for (int i = 1; i <= n; ++i)
        a[i] = v[i - 1];

    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            dp[l][r] = min(dp[l + 1][r] + 1, dp[l][r - 1] + 1);
            if (a[l] == a[r])
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + 1);
            if (l == r)
                dp[l][r] = 0;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}