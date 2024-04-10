#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1111;
const int INF = (int)(1e+9) + 7;

int n;
int f[MAXN][MAXN];
pair <int, int> prev[MAXN][MAXN], last[MAXN][MAXN];
int a[MAXN];

int add(const int i, const int j, const pair <int, int> &p, const pair <int, int> &l)
{
    int x = f[p.first][p.second] + max(a[l.first], a[l.second]);
    if (f[i][j] <= x) return 0;

    f[i][j] = x;
    prev[i][j] = p;
    last[i][j] = l;
    return 0;
}         


int rec(int x, int y)
{
    if (prev[x][y] != make_pair(0, 0))
    {
        rec(prev[x][y].first, prev[x][y].second);
        printf("%d", last[x][y].first);
        if (last[x][y].second) printf(" %d", last[x][y].second);
        printf("\n");
    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = 0;

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            f[i][j] = INF;

    f[1][2] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n + 1; j++)
            if (f[i][j] < INF)
            {
                if (j + 1 <= n) add(i, j + 2, make_pair(i, j), make_pair(j, j + 1));
                if (j + 1 <= n) add(j, j + 2, make_pair(i, j), make_pair(i, j + 1));
                if (j <= n) add(j + 1, j + 2, make_pair(i, j), make_pair(i, j));
                if (j == n + 1) add(n + 1, n + 2, make_pair(i, j), make_pair(i, 0));
            }
    printf("%d\n", f[n + 1][n + 2]);
    rec(n + 1, n + 2);
    return 0;
}