#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int L = (1 << 20);
const int N = 76;
const int M = 1e9 + 7;

int dp[N][L];
int go[N];
int g[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int a = 0; a < 20; a++)
    {
        g[a + 1] = (1 << a);
    }
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && s[j] == '0')
        {
            j++;
        }
        go[i] = j;
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = (dp[i][0] + 1) % M;
        for (int mask = 0; mask < L; mask++)
        {
            int cur = 0;
            for (int j = go[i]; j < n; j++)
            {
                cur = cur * 2 + s[j] - '0';
                if (cur > 20)
                {
                    break;
                }
                (dp[j + 1][mask | g[cur]] += dp[i][mask]) %= M;
            }
        }
    }
    int mask = 0;
    int ans = 0;
    for (int i = 0; i < 20; i++)
    {
        mask |= (1 << i);
        for (int j = 0; j <= n; j++)
        {
            (ans += (dp[j][mask]) % M) %= M;
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur = cur * 2 + s[i] - '0';
        if (cur != 0 && cur != 1)
        {
            cur = -1;
            break;
        }
    }
    cout << ans << '\n';
}