#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2203;
const char s[20][20] =
{
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int n, k;
char a[N][20];

int q[N][20];

bool dp[N][N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", a[i]);
    dp[n + 1][0] = true;
    for (int i = n; i >= 1; --i)
    {
        for (int u = 0; u < 10; ++u)
        {
            for (int j = 0; j < 7; ++j)
            {
                if (a[i][j] == s[u][j])
                    continue;
                if (a[i][j] == '1')
                {
                    q[i][u] = -1;
                    break;
                }
                ++q[i][u];
            }
        }
        for (int j = 0; j <= k; ++j)
        {
            if (dp[i + 1][j])
            {
                for (int u = 0; u < 10; ++u)
                {
                    if (q[i][u] == -1)
                        continue;
                    dp[i][j + q[i][u]] = true;
                }
            }
        }
    }
    if (!dp[1][k])
    {
        printf("-1");
        return;
    }
    int j = k;
    for (int i = 1; i <= n; ++i)
    {
        for (int u = 9; u >= 0; --u)
        {
            if (q[i][u] == -1)
                continue;
            if (j - q[i][u] >= 0 && dp[i + 1][j - q[i][u]])
            {
                putchar(u + '0');
                j -= q[i][u];
                break;
            }
        }
    }
    putchar('\n');
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