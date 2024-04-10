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
const int N = 12, INF = 1000000009;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};
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

int n, t;
char a[N][N], b[N][N];

int sx, sy;
int v[N][N];

void bfs(int d[N][N], int sx, int sy)
{
    bool c[N][N] = {};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            d[i][j] = INF;
        }
    }
    queue<ban> q;
    c[sx][sy] = true;
    d[sx][sy] = 0;
    q.push(ban(sx, sy));
    while (!q.empty())
    {
        ban t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            ban h = t;
            h.x += xx[i];
            h.y += yy[i];
            if (h.x >= 0 && h.x < n && h.y >= 0 && h.y < n && !c[h.x][h.y] && '0' <= a[h.x][h.y] && a[h.x][h.y] <= '9')
            {
                c[h.x][h.y] = true;
                d[h.x][h.y] = d[t.x][t.y] + 1;
                q.push(h);
            }
        }
    }
}

bool dp[N * 6][N][N][N][N];
bool u[N][N][N][N];

int g[2 * N * N][2 * N * N];

int p[2 * N * N];
bool c[2 * N * N];
bool bfs1()
{
    memset(c, false, sizeof c);
    memset(p, 0, sizeof p);
    queue<int> q;
    c[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == 2 * n * n + 1)
            return true;
        for (int h = 0; h <= 2 * n * n + 1; ++h)
        {
            if (g[x][h])
            {
                if (!c[h])
                {
                    c[h] = true;
                    p[h] = x;
                    q.push(h);
                }
            }
        }
    }
    return false;
}

void solv()
{
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int i = 0; i < n; ++i)
        scanf(" %s", b[i]);
    scanf("%d%d", &sx, &sy);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 'Z')
            {
                sx = i;
                sy = j;
            }
        }
    }
    bfs(v, sx, sy);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ('0' <= a[i][j] && a[i][j] <= '9')
            {
                dp[0][i][j][i][j] = true;
            }
        }
    }
    for (int yt = 0; yt < t; ++yt)
    {
        for (int sx = 0; sx < n; ++sx)
        {
            for (int sy = 0; sy < n; ++sy)
            {
                for (int x = 0; x < n; ++x)
                {
                    for (int y = 0; y < n; ++y)
                    {
                        if (!dp[yt][sx][sy][x][y])
                            continue;
                        if (v[x][y] <= yt)
                            continue;
                        for (int i = 0; i < 4; ++i)
                        {
                            int hx = x + xx[i];
                            int hy = y + yy[i];
                            if (hx >= 0 && hx < n && hy >= 0 && hy < n && '0' <= a[hx][hy] && a[hx][hy] <= '9')
                            {
                                if (v[hx][hy] >= yt + 1)
                                    dp[yt + 1][sx][sy][hx][hy] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int yt = 0; yt <= t; ++yt)
    {
        for (int sx = 0; sx < n; ++sx)
        {
            for (int sy = 0; sy < n; ++sy)
            {
                for (int x = 0; x < n; ++x)
                {
                    for (int y = 0; y < n; ++y)
                    {
                        if (dp[yt][sx][sy][x][y])
                        {
                            u[sx][sy][x][y] = true;
                        }
                    }
                }
            }
        }
    }
    for (int x1 = 0; x1 < n; ++x1)
    {
        for (int y1 = 0; y1 < n; ++y1)
        {
            if ('0' <= a[x1][y1] && a[x1][y1] <= '9')
                g[0][x1 * n + y1 + 1] = a[x1][y1] - '0';
        }
    }
    for (int x2 = 0; x2 < n; ++x2)
    {
        for (int y2 = 0; y2 < n; ++y2)
        {
            if ('0' <= b[x2][y2] && b[x2][y2] <= '9')
                g[n * n + x2 * n + y2 + 1][2 * n * n + 1] = b[x2][y2] - '0';
        }
    }
    for (int x1 = 0; x1 < n; ++x1)
    {
        for (int y1 = 0; y1 < n; ++y1)
        {
            for (int x2 = 0; x2 < n; ++x2)
            {
                for (int y2 = 0; y2 < n; ++y2)
                {
                    if (!('0' <= a[x1][y1] && a[x1][y1] <= '9'))
                        continue;
                    if (!('0' <= a[x2][y2] && a[x2][y2] <= '9'))
                        continue;
                    if (!u[x1][y1][x2][y2])
                        continue;
                    g[x1 * n + y1 + 1][n * n + x2 * n + y2 + 1] = INF;
                }
            }
        }
    }
    while (bfs1())
    {
        int minu = INF;
        for (int i = 2 * n * n + 1; i; i = p[i])
        {
            minu = min(minu, g[p[i]][i]);
        }
        for (int i = 2 * n * n + 1; i; i = p[i])
        {
            g[p[i]][i] -= minu;
            g[i][p[i]] += minu;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n * n + 1; ++i)
        ans += g[i][0];
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