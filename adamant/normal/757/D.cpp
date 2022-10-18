#include <bits/stdc++.h>

using namespace std;

string to_bin(int i)
{
    string r;
    while(i)
    {
        r.push_back('0' + i % 2);
        i /= 2;
    }
    reverse(begin(r), end(r));
    return r;
}

int to_dec(string s)
{
    int ans = 0;
    for(auto c: s)
    {
        ans = 2 * ans + (c - '0');
        if(ans > 40)
            return ans;
    }
    return ans;
}

const int maxn = 76, maxm = 20, maxs = 1 << maxm, mod = 1e9 + 7;
int dp[maxn][maxs];



signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
        dp[i][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
        {
            int d = to_dec(s.substr(j, i - j + 1));
            if(d > 0 && d <= maxm)
                for(int k = 0; k < maxs; k++)
                {
                    dp[i + 1][k | (1 << d - 1)] += dp[j][k];
                    if(dp[i + 1][k | (1 << d - 1)] >= mod)
                        dp[i + 1][k | (1 << d - 1)] -= mod;
                }
        }
    int ans = 0;
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= n; j++)
            ans = (ans + dp[j][(1 << i) - 1]) % mod;
    cout << ans << endl;
    return 0;
}