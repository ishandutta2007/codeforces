#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;
const int xx[4] = {-1, 1, 0, 0};
const int yy[4] = {0, 0, 1, -1};
const char cc[4] = {'U', 'D', 'R', 'L'};

int n;
pair<int, int> a[N][N];
char ans[N][N];

bool c[N][N];

void dfs(pair<int, int> x)
{
    if (c[x.first][x.second])
        return;
    c[x.first][x.second] = true;
    for (int i = 0; i < 4; ++i)
    {
        pair<int, int> h = x;
        h.first += xx[i];
        h.second += yy[i];
        if (a[h.first][h.second] == a[x.first][x.second])
            dfs(h);
    }
}

void dfs1(pair<int, int> x)
{
    c[x.first][x.second] = true;
    for (int i = 0; i < 4; ++i)
    {
        pair<int, int> h = x;
        h.first += xx[i];
        h.second += yy[i];
        if (a[h.first][h.second] == a[x.first][x.second])
        {
            if (!c[h.first][h.second])
            {
                ans[h.first][h.second] = cc[(i ^ 1)];
                dfs1(h);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            scanf("%d%d", &a[i][j].first, &a[i][j].second);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == m_p(i, j))
            {
                ans[i][j] = 'X';
                dfs(m_p(i, j));
            }
            else if (a[i][j] == m_p(-1, -1))
            {
                c[i][j] = true;
                bool z = false;
                for (int k = 0; k < 4; ++k)
                {
                    pair<int, int> h = m_p(i, j);
                    h.first += xx[k];
                    h.second += yy[k];
                    if (a[h.first][h.second] == a[i][j])
                    {
                        z = true;
                        break;
                    }
                }
                if (!z)
                {
                    printf("INVALID\n");
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (!c[i][j])
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }
    printf("VALID\n");
    memset(c, false, sizeof c);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (ans[i][j] == 'X')
            {
                dfs1(m_p(i, j));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != m_p(-1, -1))
                continue;
            if (ans[i][j])
                continue;
            for (int k = 0; k < 4; ++k)
            {
                pair<int, int> h = m_p(i, j);
                h.first += xx[k];
                h.second += yy[k];
                if (a[h.first][h.second] == a[i][j])
                {
                    if (ans[h.first][h.second])
                    {
                        ans[i][j] = cc[k];
                    }
                    else
                    {
                        ans[i][j] = cc[k];
                        ans[h.first][h.second] = cc[(k ^ 1)];
                    }
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}