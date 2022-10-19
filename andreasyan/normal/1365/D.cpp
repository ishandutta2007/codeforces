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
const int N = 55;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;
char a[N][N];

bool c[N][N];
void dfs(int x, int y)
{
    if (c[x][y])
        return;
    if (a[x][y] == '#')
        return;
    c[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (hx >= 0 && hx < n && hy >= 0 && hy < m)
            dfs(hx, hy);
    }
}

bool solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < m; ++y)
        {
            if (a[x][y] == 'B')
            {
                for (int i = 0; i < 4; ++i)
                {
                    int hx = x + xx[i];
                    int hy = y + yy[i];
                    if (hx >= 0 && hx < n && hy >= 0 && hy < m)
                    {
                        if (a[hx][hy] == '.')
                            a[hx][hy] = '#';
                    }
                }
            }
        }
    }
    memset(c, false, sizeof c);
    dfs(n - 1, m - 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'G' && !c[i][j])
                return false;
            if (a[i][j] == 'B' && c[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}