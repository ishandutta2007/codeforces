#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int cnt[60];
int mod = 1000 * 1000 * 1000 + 7;
int dp[MAX_N];
int ans[60][60];

int fast_pow(int a, int p)
{
    if (p == 1)
        return a;
    int b = fast_pow(a, p / 2);
    b = (b * b) % mod;
    if (p % 2 == 1)
        b = (b * a) % mod;
    return b;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            cnt[s[i] - 'a']++;
        else
            cnt[(s[i] - 'A') + 26]++;
    }
    dp[0] = 1;
    for (int i = 0; i < 52; i++)
    {
        if (cnt[i] == 0)
            continue;
        for (int e = MAX_N - 1; e >= cnt[i]; e--)
        {
            dp[e] += dp[e - cnt[i]];
            if (dp[e] >= mod)
                dp[e] -= mod;
        }
    }
    for (int i = 0; i < 52; i++)
    {
        if (cnt[i] == 0)
            continue;
        for (int j = cnt[i]; j < MAX_N; j++)
        {
            dp[j] -= dp[j - cnt[i]];
            if (dp[j] < 0)
                dp[j] += mod;
        }
        ans[i][52] = dp[n / 2];
        for (int e = 0; e < 52; e++)
        {
            if (cnt[e] == 0)
                continue;
            for (int j = cnt[e]; j < MAX_N; j++)
            {
                dp[j] -= dp[j - cnt[e]];
                if (dp[j] < 0)
                    dp[j] += mod;
            }
            ans[i][e] = dp[n / 2];
            for (int j = MAX_N - 1; j >= cnt[e]; j--)
            {
                dp[j] += dp[j - cnt[e]];
                if (dp[j] >= mod)
                    dp[j] -= mod;
            }
        }
        for (int j = MAX_N - 1; j >= cnt[i]; j--)
        {
            dp[j] += dp[j - cnt[i]];
            if (dp[j] >= mod)
                dp[j] -= mod;
        }
    }
    int magic = 1;
    for (int i = 0; i < 52; i++)
    {
        for (int e = 2; e <= cnt[i]; e++)
            magic = (magic * e) % mod;
    }
    magic = fast_pow(magic, mod - 2);
    int t = 1;
    for (int e = 2; e <= n / 2; e++)
        t = (t * e) % mod;
    t = (2 * t * t) % mod;
    magic = (t * magic) % mod;
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;

        if (s[x] >= 'a' && s[x] <= 'z')
            x = s[x] - 'a';
        else
            x = (s[x] - 'A') + 26;

        if (s[y] >= 'a' && s[y] <= 'z')
            y = s[y] - 'a';
        else
            y = (s[y] - 'A') + 26;

        if (x == y)
            cout << (ans[x][52] * magic) % mod << "\n";
        else
            cout << (ans[x][y] * magic) % mod << "\n";
    }
}