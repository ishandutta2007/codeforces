#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 200009;
int dp[2][MAXN];
int a[MAXN];
int n, k;
int mod = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][1] = 1;
    dp[0][3] = k - 1;
    dp[1][2] = 1;
    dp[1][3] = k - 2;
    for (int len = 4; len <= n; len++)
    {
        dp[0][len] = (dp[1][len - 1] * (k - 1)) % mod;
        dp[1][len] = (dp[0][len - 1] + dp[1][len - 1] * (k - 2)) % mod;
    }
    int ans = 1;
    int len = 0;
    int pr = -1;
    for (int i = 0; i < n; i += 2)
    {
        len++;
        if (a[i] != -1)
        {
            if (pr == -1)
                ans = (((dp[0][len] + dp[1][len] * (k - 1)) % mod) * ans) % mod;
            else if (len >= 2 && a[i] == pr)
                ans = (ans * dp[0][len]) % mod;
            else if (len >= 2)
                ans = (ans * dp[1][len]) % mod;
            len = 1;
            pr = a[i];
        }
    }
    if (pr == -1)
        ans = (((((dp[0][len] + dp[1][len] * (k - 1)) % mod) * ans) % mod) * k) % mod;
    else if (len >= 2)
        ans = (((dp[0][len] + dp[1][len] * (k - 1)) % mod) * ans) % mod;
    len = 0;
    pr = -1;
    for (int i = 1; i < n; i += 2)
    {
        len++;
        if (a[i] != -1)
        {
            if (pr == -1)
                ans = (((dp[0][len] + dp[1][len] * (k - 1)) % mod) * ans) % mod;
            else if (len >= 2 && a[i] == pr)
                ans = (ans * dp[0][len]) % mod;
            else if (len >= 2)
                ans = (ans * dp[1][len]) % mod;
            len = 1;
            pr = a[i];
        }
    }
    if (pr == -1)
        ans = (((((dp[0][len] + dp[1][len] * (k - 1)) % mod) * ans) % mod) * k) % mod;
    else if (len >= 2)
        ans = (((dp[0][len] + dp[1][len] * (k - 1)) % mod) * ans) % mod;
    cout << ans;
}