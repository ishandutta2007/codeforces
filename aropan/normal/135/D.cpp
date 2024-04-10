#include <cstdio>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;


const int MAXN = 1003;

int n, m, u;
char a[MAXN][MAXN];
int d[MAXN][MAXN];
int cnt, f[MAXN * MAXN], g[MAXN][MAXN];
queue < pair <int, int> > q;
vector < pair <int, int> > v;

int addf(int x, int y)
{
    if (x < 1 || n < x || y < 1 || m < y || a[x][y] == '0' || d[x][y]) return 0;
    d[x][y] = cnt;
    q.push(make_pair(x, y));
    return 0;
}


int adds(int x, int y)
{
    if (x < 1 || n < x || y < 1 || m < y)
    {
        u++;
        return 0;
    }

    if (a[x][y] == '1')
    {
        if (f[d[x][y]] != cnt) u++, f[d[x][y]] = cnt;
        if (g[x][y] != cnt) g[x][y] = cnt, v.push_back(make_pair(x, y));
        return 0;
    }

    if (d[x][y]) return 0;

    d[x][y] = -1;
    q.push(make_pair(x, y));
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        gets(a[i] + 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (d[i][j] == 0 && a[i][j] == '1')
            {
                cnt++;
                addf(i, j);
                while (q.size())
                {
                    int
                        x = q.front().X,
                        y = q.front().Y;
                    q.pop();

                    for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1 + (dx != 0); dy <= 1; dy += 2)
                            addf(x + dx, y + dy);
                }
            }
    
    int ans = 0;
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m - 1; j++)
            if (a[i][j] == '1' && a[i][j + 1] == '1' && a[i + 1][j] == '1' && a[i + 1][j + 1] == '1')
                ans = 4;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '0' && d[i][j] == 0)
            {
                u = 0;
                v.clear();
                cnt++;
                adds(i, j);
                while (q.size())
                {
                    int
                        x = q.front().X,
                        y = q.front().Y;
                    q.pop();

                    for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1; dy <= 1; dy++)
                            adds(x + dx, y + dy);
                }

                if (u > 1) continue;

                for (int i = 0; i < v.size(); i++)
                    g[v[i].X][v[i].Y] = 0;

                for (int i = 0; i < v.size(); i++)
                    for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1 + (dx != 0); dy <= 1; dy += 2)
                            g[v[i].X + dx][v[i].Y + dy]++;

                bool flag = true;
                for (int i = 0; i < v.size(); i++)
                    if (g[v[i].X][v[i].Y] != 2)
                    {
                        flag = false;
                        break;
                    }
                if (!flag) continue;

                ans = max(ans, (int)v.size());
            }
    printf("%d\n", ans);
    return 0;
}