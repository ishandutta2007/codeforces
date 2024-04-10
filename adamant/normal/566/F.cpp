#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000007;
int dp[maxn];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        dp[a[i]] = 1;
        for(int j = 2 * a[i]; j < maxn; j += a[i])
            dp[a[i]] = max(dp[a[i]], dp[j] + 1);
        ans = max(ans, dp[a[i]]);
    }
    cout << ans << "\n";
    return 0;
}