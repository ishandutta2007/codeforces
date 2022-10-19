#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003;
const int xx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int yy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int n, m;
char a[N][N];

int q[N][N];

void dfs(int x, int y)
{
    stack<pair<int, int> > s;
    s.push(m_p(x, y));
    while (!s.empty())
    {
        x = s.top().first;
        y = s.top().second;
        s.pop();
        if (q[x][y] != 1)
            continue;
        int ux, uy;
        if (a[x][y] == '*')
        {
            ux = x;
            uy = y;
        }
        else if (a[x + 1][y] == '*')
        {
            ux = x + 1;
            uy = y;
        }
        else if (a[x][y + 1] == '*')
        {
            ux = x;
            uy = y + 1;
        }
        else
        {
            ux = x + 1;
            uy = y + 1;
        }
        a[ux][uy] = '.';
        --q[x][y];
        for (int i = 0; i < 8; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (hx >= 1 && hy >= 1 && hx < n && hy < m)
            {
                if (hx <= ux && ux <= hx + 1 && hy <= uy && uy <= hy + 1)
                {
                    --q[hx][hy];
                }
            }
        }
        for (int i = 0; i < 8; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (hx >= 1 && hy >= 1 && hx < n && hy < m)
            {
                if (q[hx][hy] == 1)
                    s.push(m_p(hx, hy));
            }
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", (a[i] + 1));
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = 1; j <= m - 1; ++j)
        {
            if (a[i][j] == '*')
                ++q[i][j];
            if (a[i][j + 1] == '*')
                ++q[i][j];
            if (a[i + 1][j] == '*')
                ++q[i][j];
            if (a[i + 1][j + 1] == '*')
                ++q[i][j];
        }
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = 1; j <= m - 1; ++j)
        {
            if (q[i][j] == 1)
            {
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            putchar(a[i][j]);
        }
        putchar('\n');
    }
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