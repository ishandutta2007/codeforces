#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 22;
const int INF = 1000000009;

int k;

char solv(int n, int m)
{
    if (k == 1)
    {
        if (n % 2 == 0 || m % 2 == 0)
            return '+';
        else
            return '-';
    }
    else
    {
        if ((n - m) % 2 == 0)
        {
            n = min(n, m);
            int l = 1, r = INF;
            int ans;
            while (l <= r)
            {
                int m = (l + r) / 2;
                long long u = (m / 2) * 1LL * k + (m / 2) * 1LL * (k + 2);
                if (m % 2 == 1)
                    u += k;
                if (n <= u)
                {
                    ans = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            if (ans % 2 == 1)
                return '-';
            else
                return '+';
        }
        else
        {
            n = min(n, m);
            int l = 1, r = INF;
            int ans;
            while (l <= r)
            {
                int m = (l + r) / 2;
                long long u = (m / 2) * 1LL * k + (m / 2) * 1LL * (k + 2);
                if (m % 2 == 1)
                    u += (k + 2);
                --u;
                if (n <= u)
                {
                    ans = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            if (ans % 2 == 1)
                return '+';
            else
                return '-';
        }
    }
}

char dp[N][N];

void por()
{
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = N - 1; j >= 0; --j)
        {
            dp[i][j] = '-';
            if (i + 1 < N)
            {
                if (dp[i + 1][j] == '-')
                    dp[i][j] = '+';
            }
            if (j + 1 < N)
            {
                if (dp[i][j + 1] == '-')
                    dp[i][j] = '+';
            }
            if (i + k < N && j + k < N)
            {
                if (dp[i + k][j + k] == '-')
                    dp[i][j] = '+';
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (dp[i][j] != solv(N - i, N - j))
            {
                printf("%d %d\n", (N - i), (N - j));
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            putchar(dp[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    //#ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //#endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    scanf("%d", &k);
    //por();
    while (tt--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%c\n", solv(n, m));
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}