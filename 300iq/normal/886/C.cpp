#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> dp(n + 1, 0);
    dp[0] = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (dp[x]) ans++;
        dp[x] = 1;
    }
    cout << ans;
}