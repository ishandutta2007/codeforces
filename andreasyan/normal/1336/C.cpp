#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 3003;
const int M = 998244353;

int n, m;
char s[N], t[N];

int dp[N][N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf(" %s", s);
    scanf(" %s", t);
    n = strlen(s);
    m = strlen(t);
    for (int i = m; i < n; ++i)
        t[i] = '?';
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 0; l < n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (l == r)
            {
                if (s[d - 1] == t[l] || t[l] == '?')
                {
                    dp[l][r] = 2;
                }
                continue;
            }
            if (s[d - 1] == t[l] || t[l] == '?')
                dp[l][r] = (dp[l][r] + dp[l + 1][r]) % M;
            if (s[d - 1] == t[r] || t[r] == '?')
                dp[l][r] = (dp[l][r] + dp[l][r - 1]) % M;
        }
    }
    int ans = 0;
    for (int r = m - 1; r < n; ++r)
        ans = (ans + dp[0][r]) % M;
    printf("%d\n", ans);
    return 0;
}