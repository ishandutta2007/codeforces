#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ss second
#define ff first

const int MAXN = 5009;
int a[MAXN];
int cnt[MAXN];
int n;
int mod = 998244353;
int dp[MAXN][MAXN];
int c[MAXN][MAXN];

int binpow(int b, int p)
{
    if (p == 1)
        return b;
    int u = binpow(b, p / 2);
    u = (u * u) % mod;
    if (p % 2)
        u = (u * b) % mod;
    return u;
}

int divide(int a, int b)
{
    return (a * binpow(b, mod - 2)) % mod;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int k = 1; k <= n; k++)
    {
        c[1][k] = divide(1, k);
        for (int i = 2; i <= n; i++)
            c[i][k] = (c[1][k] * i) % mod;
    }
    for (int last = 1; last <= n; last++)
        dp[n][last] = c[cnt[last]][n];
    int ans = 0;
    for (int k = n - 1; k >= 1; k--)
    {
        int cur_sum = 0;
        for (int last = 1; last <= n; last++)
        {
            dp[k][last] = (c[cnt[last]][k] * cur_sum) % mod;
            cur_sum = (cur_sum + dp[k + 1][last]) % mod;
        }
    }
    for (int k = n; k >= 1; k--)
    {
        for (int last = 1; last <= n; last++)
        {
            if (cnt[last] >= 2)
                ans = (ans + c[cnt[last] - 1][k - 1] * dp[k][last]) % mod;
        }
    }
    cout << ans;
}