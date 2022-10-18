#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

signed main()
{
    //freopen("input.txt", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int dp[n];
    int sm = 0;
    dp[n - 1] = sm = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        dp[i] = max(a[i] + sm - dp[i + 1], dp[i + 1]);
        sm += a[i];
    }
    cout << sm - dp[0] << ' ' << dp[0] << endl;
    return 0;
}