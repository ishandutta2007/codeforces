#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, K = 102, M = 998244353;

int n, k, m;
int a[N];

int s[K];
int u[N];
int dp[K][N];
int d[K];

void solv()
{
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (m == 1)
    {
        printf("0\n");
        return;
    }
    --m;

    if (a[1] == -1)
    {
        for (int j = 1; j <= k; ++j)
        {
            dp[j][1] = 1;
            s[j] = 1;
        }
    }
    else
    {
        dp[a[1]][1] = 1;
        s[a[1]] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == -1)
        {
            int ss = 0;
            for (int j = 1; j <= k; ++j)
                ss = (ss + s[j]) % M;
            for (int j = 1; j <= k; ++j)
            {
                ss = (ss - s[j] + M) % M;

                dp[j][i] = ss;
                d[j] = ss;

                if (i - m > 0)
                    d[j] = (d[j] - dp[j][i - m] + M) % M;
                dp[j][i - m] = 0;

                ss = (ss + s[j]) % M;
            }
            for (int j = 1; j <= k; ++j)
                s[j] = (s[j] + d[j]) % M;
        }
        else
        {
            int ss = 0;
            for (int j = 1; j <= k; ++j)
                ss = (ss + s[j]) % M;
            for (int j = 1; j <= k; ++j)
            {
                if (j == a[i])
                {
                    ss = (ss - s[j] + M) % M;

                    dp[j][i] = ss;
                    s[j] = (s[j] + ss) % M;

                    if (i - m > 0)
                        s[j] = (s[j] - dp[j][i - m] + M) % M;
                    dp[j][i - m] = 0;
                    continue;
                }
                s[j] = 0;
                while (u[j] < i)
                {
                    ++u[j];
                    dp[j][u[j]] = 0;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= k; ++j)
        ans = (ans + s[j]) % M;
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}