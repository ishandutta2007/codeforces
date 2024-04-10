#include <cstdio>
#include <algorithm>

using namespace std;

const int
    xi[4] = {-1, 0, 1, 0},
    yi[4] = {0, 1, 0, -1};

const int MAXN = 1111;
const int MAXK = MAXN * MAXN;
const int MAXM = MAXK * 4;

char a[MAXN][MAXN];

int next[MAXM], dest[MAXM];
int last[MAXK], prev[MAXK], curr[MAXK];
int upd[MAXK], cnt;

int ans[MAXN][MAXN];
int n, m, l;

int M[MAXK];
int c1, c2;

int update(int p, int i)
{
    int
        x = (p - 1) / m,
        y = (p - 1) % m;
    ans[x][y] = i;
    return 0;
}

int add(int x1, int y1, int x2, int y2)
{
    int x = x1 * m + y1 + 1;
    int y = x2 * m + y2 + 1;

//    printf("%d %d %d %d\n", x1, y1, x2, y2);

    l++;
    dest[l] = y;
    next[l] = last[x];
    last[x] = l;

    if (curr[x] == 0 && prev[y] == 0)
    {
        curr[x] = y;
        prev[y] = x;
    }
    return 0;
}

bool dfs(int x)
{
    if (upd[x] == cnt) return false;
    upd[x] = cnt;

    for (int i = last[x]; i; i = next[i])
    {
        int y = dest[i];
        if (prev[y] == 0 || dfs(prev[y]))
        {
            prev[y] = x;
            curr[x] = y;
            return true;
        }
    }
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%c", &a[i][j]);
        scanf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (a[i][j] == '.' && (i + j) % 2 == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int
                        x = i + xi[k],
                        y = j + yi[k];
                    if (x < 0 || n <= x || y < 0 || m <= y || a[x][y] != '.') continue;
                    add(i, j, x, y);
                }
            }
    }
/*

    for (int i = 1; i <= n * m; i++)
        if (curr[i] == 0)
        {
            cnt++;
            dfs(i);
        }
//*/
    for (int i = 1; i <= n * m; i++)
        if (curr[i])
        {
            update(i, i);
            update(curr[i], i);
        }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '.' && ans[i][j] == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int
                        x = i + xi[k],
                        y = j + yi[k];
                    if (x < 0 || n <= x || y < 0 || m <= y || ans[x][y] == 0) continue;
                    ans[i][j] = ans[x][y];
                }
                if (ans[i][j] == 0)
                {
                    printf("-1\n");
                    return 0;
                }
            }

    c1 = 0;
    c2 = 1;
    for (int i = 0; i < n; i++)
    {
        int last = 0;
        for (int j = 0; j < m; j++)
        {
            if (j && ans[i][j] && ans[i][j] != last && M[ans[i][j]] == 0)
                swap(c1, c2);                      

            if (M[ans[i][j]] == 0)
                M[ans[i][j]] = c1 + 1;

            if (ans[i][j])
                last = ans[i][j];
        }
        c1 = (c1 + 2) % 10;
        c2 = (c2 + 2) % 10;
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%c", a[i][j] == '.'? M[ans[i][j]] - 1 + '0' : a[i][j]);
        printf("\n");
    }

    return 0;
}