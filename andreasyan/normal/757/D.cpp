#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102, m = 20;
const int M = 1000000007;

int n;
char a[N];

int dp[(1 << m)];
int p[N][(1 << m)];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
    {
        memset(dp, 0, sizeof dp);
        int x = 0;
        for (int j = i; j >= 1; --j)
        {
            if (a[j] == '1')
            {
                if ((i - j) > m)
                    break;
                x |= (1 << (i - j));
                if (x > m)
                    break;
                int ll = j - 1;
                while (a[ll] == '0')
                    --ll;
                for (int y = 0; y < (1 << m); ++y)
                {
                    if (ll)
                        dp[(y | (1 << (x - 1)))] = (dp[(y | (1 << (x - 1)))] + (p[j - 1][y] - p[ll - 1][y] + M) % M) % M;
                    else
                        dp[(y | (1 << (x - 1)))] = (dp[(y | (1 << (x - 1)))] + p[j - 1][y]) % M;
                }
                dp[(1 << (x - 1))] = (dp[(1 << (x - 1))] + (j - ll)) % M;
            }
        }
        for (int x = 0; x < (1 << m); ++x)
        {
            p[i][x] = (p[i - 1][x] + dp[x]) % M;
        }
    }
    int ans = 0;
    int x = 0;
    for (int i = 0; i < m; ++i)
    {
        x |= (1 << i);
        ans = (ans + p[n][x]) % M;
    }
    printf("%d\n", ans);
    return 0;
}