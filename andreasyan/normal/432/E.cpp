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
const int N = 102;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;

char a[N][N];

bool c[N][N];
int minx, maxx, miny, maxy;

void dfs(int x, int y)
{
    c[x][y] = true;
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (hx >= 1 && hx <= n && hy >= 1 && hy <= m && !c[hx][hy] && a[hx][hy] == a[x][y])
        {
            dfs(hx, hy);
        }
    }
}

bool stg(int sx, int sy)
{
    memset(c, false, sizeof c);
    minx = maxx = sx;
    miny = maxy = sy;
    dfs(sx, sy);
    int d = max(maxx - minx + 1, maxy - miny + 1);
    maxx = minx + d - 1;
    maxy = miny + d - 1;
    if (maxx > n || maxy > m)
        return false;
    for (int i = minx; i <= maxx; ++i)
    {
        for (int j = miny; j <= maxy; ++j)
        {
            if (a[i][j] == 0)
                continue;
            if (a[i][j] != a[sx][sy])
                return false;
        }
    }
    for (int i = minx; i <= maxx; ++i)
    {
        for (int j = miny; j <= maxy; ++j)
        {
            a[i][j] = a[sx][sy];
        }
    }
    return true;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j])
                continue;
            for (char k = 'A'; ; ++k)
            {
                a[i][j] = k;
                if (!stg(i, j))
                    continue;
                if (i > 1 && a[i][j] != a[i - 1][j] && !stg(i - 1, j))
                    continue;
                if (j > 1 && a[i][j] != a[i][j - 1] && !stg(i, j - 1))
                    continue;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            putchar(a[i][j]);
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