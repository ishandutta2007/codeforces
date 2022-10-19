#include <bits/stdc++.h>
using namespace std;
const int N = 1003, M = 200005;
int ka()
{
    int x = 0;
    while (1)
    {
        char y = getchar();
        if (y == ' ' || y == '\n')
            return x;
        x = (x * 10) + (y - '0');
    }
}
struct ban
{
    int x, y;
    ban(){}
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
struct ban1
{
    int i;
    int x, y;
    int r;
    ban1(){}
    ban1(int i, int x, int y, int r)
    {
        this->i = i;
        this->x = x;
        this->y = y;
        this->r = r;
    }
};

int n, m, q;
ban a[M];
vector<ban1> v[M];

int dp[N][N];

bool ans[M];
int main()
{
    //freopen("input.txt", "r", stdin);
    n = ka();
    m = ka();
    q = ka();
    for (int i = 1; i <= m; ++i)
    {
        a[i].x = ka();
        a[i].y = ka();
    }
    for (int i = 0; i < q; ++i)
    {
        int l, r, x, y;
        l = ka();
        r = ka();
        x = ka();
        y = ka();
        v[l].push_back(ban1(i, x, y, r));
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            if (x == y)
                continue;
            dp[x][y] = M;
        }
    }
    for (int l = m; l >= 1; --l)
    {
        int x = a[l].x;
        int y = a[l].y;
        dp[x][y] = dp[y][x] = l;
        for (int z = 1; z <= n; ++z)
        {
            dp[x][z] = min(dp[x][z], max(l, dp[y][z]));
            dp[y][z] = min(dp[y][z], max(l, dp[x][z]));
        }
        for (int j = 0; j < v[l].size(); ++j)
        {
            int i = v[l][j].i;
            int x = v[l][j].x;
            int y = v[l][j].y;
            int r = v[l][j].r;
            if (dp[x][y] <= r)
                ans[i] = true;
        }
    }
    for (int i = 0; i < q; ++i)
    {
        if (ans[i])
        {
            putchar('Y');
            putchar('e');
            putchar('s');
            putchar('\n');
        }
        else
        {
            putchar('N');
            putchar('o');
            putchar('\n');
        }
    }
    return 0;
}