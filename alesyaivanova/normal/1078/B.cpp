#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
const int MAX_N = 109;
const int MAX_S = 10009;
int a[MAX_N];
int dp[MAX_N][MAX_S];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    dp[0][0] = 1;
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            cnt++;
    }
    if (cnt <= 1)
    {
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cnt = 1;
        while (i + 1 < n && a[i + 1] == a[i])
        {
            cnt++;
            i++;
        }
        for (int s = MAX_S - 1; s >= 0; s--)
        {
            for (int k = n; k >= 0; k--)
            {
                for (int e = 1; e <= cnt; e++)
                {
                    if (s + e * a[i] < MAX_S && k + e <= n)
                        dp[k + e][s + e * a[i]] += dp[k][s];
                }
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int e = i; (e < n) && (a[i] == a[e]); e++)
        {
            int sum = a[i] * (e - i + 1);
            if (dp[e - i + 1][sum] <= 1)
                ans = max(ans, e - i + 1);
        }
    }
    cout << ans;
}