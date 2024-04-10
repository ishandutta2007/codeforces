#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 53;

int n;
char a[N][N];

int p[N][N];

int sum(int x1, int x2, int y1, int y2)
{
    return p[x2][y2] - p[x2][y1 - 1] - p[x1 - 1][y2] + p[x1 - 1][y1 - 1];
}

int dp[N][N][N][N];
bool c[N][N][N][N];

int rec(int x1, int x2, int y1, int y2)
{
    if (x1 > x2)
        return 0;
    if (y1 > y2)
        return 0;
    if (c[x1][x2][y1][y2])
        return dp[x1][x2][y1][y2];
    c[x1][x2][y1][y2] = true;
    dp[x1][x2][y1][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
    for (int i = x1; i <= x2; ++i)
    {
        if (sum(i, i, y1, y2) == 0)
        {
            dp[x1][x2][y1][y2] = min(dp[x1][x2][y1][y2], rec(x1, i - 1, y1, y2) + rec(i + 1, x2, y1, y2));
        }
    }
    for (int i = y1; i <= y2; ++i)
    {
        if (sum(x1, x2, i, i) == 0)
        {
            dp[x1][x2][y1][y2] = min(dp[x1][x2][y1][y2], rec(x1, x2, y1, i - 1) + rec(x1, x2, i + 1, y2));
        }
    }
    return dp[x1][x2][y1][y2];
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            if (a[i][j] == '#')
                ++p[i][j];
        }
    }
    printf("%d\n", rec(1, n, 1, n));
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