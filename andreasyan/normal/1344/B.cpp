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
const int N = 1003;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;
char a[N][N];

bool c[N][N];

void dfs(int x, int y)
{
    if (c[x][y])
        return;
    c[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (hx >= 1 && hx <= n && hy >= 1 && hy <= m && a[hx][hy] == '#')
            dfs(hx, hy);
    }
}

int solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    int t = 0;
    for (int i = 1; i <= n; ++i)
    {
        int q = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '#' && a[i][j - 1] != '#')
                ++q;
        }
        if (q > 1)
            return -1;
        if (q == 0)
            ++t;
    }
    int s = 0;
    for (int j = 1; j <= m; ++j)
    {
        int q = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][j] == '#' && a[i - 1][j] != '#')
                ++q;
        }
        if (q > 1)
            return -1;
        if (q == 0)
            ++s;
    }
    if (t && !s)
        return -1;
    if (!t && s)
        return -1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '#')
            {
                if (!c[i][j])
                {
                    ++ans;
                    dfs(i, j);
                }
            }
        }
    }
    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    printf("%d\n", solv());
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}