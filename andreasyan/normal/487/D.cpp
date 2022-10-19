#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005, M = 12;
int s;

int n, m, qq;
char a[N][M];

pair<int, int> u[N][M];

int main()
{
    scanf("%d%d%d", &n, &m, &qq);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }
    s = sqrt(n);
    for (int j = 1; j <= m; ++j)
        u[0][j] = m_p(0, j);
    for (int i = 1; i <= n; ++i)
    {
        u[i][0] = m_p(i, 0);
        u[i][m + 1] = m_p(i, m + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '^')
            {
                if ((i / s) != ((i - 1) / s))
                {
                    u[i][j] = m_p((i - 1), j);
                }
                else
                {
                    u[i][j] = u[i - 1][j];
                }
            }
            else if (a[i][j] == '<')
            {
                if (u[i][j - 1] != m_p(0, 0))
                    u[i][j] = u[i][j - 1];
                if (a[i][j - 1] == '>')
                    u[i][j] = m_p(-1, -1);
            }
        }
        for (int j = m; j >= 1; --j)
        {
            if (a[i][j] == '>')
            {
                u[i][j] = u[i][j + 1];
            }
        }
    }
    while (qq--)
    {
        char ty;
        scanf(" %c", &ty);
        if (ty == 'A')
        {
            int x, y;
            scanf("%d%d", &x, &y);
            while (1)
            {
                pair<int, int> uu = u[x][y];
                x = uu.first;
                y = uu.second;
                if (!(1 <= x && x <= n && 1 <= y && y <= m))
                    break;
            }
            printf("%d %d\n", x, y);
        }
        else
        {
            int x, y;
            char v;
            scanf("%d%d %c", &x, &y, &v);
            a[x][y] = v;
            for (int i = x; (i / s) == (x / s) && i <= n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                    u[i][j] = m_p(0, 0);
                for (int j = 1; j <= m; ++j)
                {
                    if (a[i][j] == '^')
                    {
                        if ((i / s) != ((i - 1) / s))
                        {
                            u[i][j] = m_p((i - 1), j);
                        }
                        else
                        {
                            u[i][j] = u[i - 1][j];
                        }
                    }
                    else if (a[i][j] == '<')
                    {
                        if (u[i][j - 1] != m_p(0, 0))
                            u[i][j] = u[i][j - 1];
                        if (a[i][j - 1] == '>')
                            u[i][j] = m_p(-1, -1);
                    }
                }
                for (int j = m; j >= 1; --j)
                {
                    if (a[i][j] == '>')
                    {
                        u[i][j] = u[i][j + 1];
                    }
                }
            }
        }
    }
    return 0;
}