#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 404;

int n, m;
char a[N][N];

int pt[N][N], ps[N][N], pv[N][N], pn[N][N];

bool stgt(int i, int j, int d)
{
    if (!(i >= 1 && i <= n && j >= 1 && j <= m))
        return false;
    if (!(j - d >= 0))
        return false;
    return (pt[i][j] - pt[i][j - d] == 0);
}

bool stgs(int i, int j, int d)
{
    if (!(i >= 1 && i <= n && j >= 1 && j <= m))
        return false;
    if (!(i - d >= 0))
        return false;
    return (ps[i][j] - ps[i - d][j] == 0);
}

bool stgv(int i, int j, int d)
{
    if (!(i >= 1 && i <= n && j >= 1 && j <= m))
        return false;
    if (!(i - d >= 0 && j - d >= 0))
        return false;
    return (pv[i][j] - pv[i - d][j - d] == 0);
}

bool stgn(int i, int j, int d)
{
    if (!(i >= 1 && i <= n && j >= 1 && j <= m))
        return false;
    if (!(i + d <= n + 1 && j - d >= 0))
        return false;
    return (pn[i][j] - pn[i + d][j - d] == 0);
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            ps[i][j] = ps[i - 1][j] + (a[i][j] - '0');
            pt[i][j] = pt[i][j - 1] + (a[i][j] - '0');
            pv[i][j] = pv[i - 1][j - 1] + (a[i][j] - '0');
            pn[i][j] = pn[i + 1][j - 1] + (a[i][j] - '0');
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int d = 2; d <= max(n, m); ++d)
            {
                if (stgv(i, j, d) && stgn(i - d + 1, j + d - 1, d) && stgt(i - d + 1, j + d - 1, d * 2 - 1))
                    ++ans;
                if (stgn(i, j, d) && stgv(i + d - 1, j + d - 1, d) && stgt(i + d - 1, j + d - 1, d * 2 - 1))
                    ++ans;
                if (stgv(i, j, d) && stgn(i, j, d) && stgs(i + d - 1, j - d + 1, d * 2 - 1))
                    ++ans;
                if (stgn(i - d + 1, j + d - 1, d) && stgv(i + d - 1, j + d - 1, d) && stgs(i + d - 1, j + d - 1, d * 2 - 1))
                    ++ans;
                if (stgt(i, j, d) && stgs(i, j, d) && stgn(i - d + 1, j, d))
                    ++ans;
                if (stgt(i, j + d - 1, d) && stgs(i + d - 1, j, d) && stgn(i, j + d - 1, d))
                    ++ans;
                if (stgt(i, j, d) && stgs(i + d - 1, j, d) && stgv(i + d - 1, j, d))
                    ++ans;
                if (stgt(i, j + d - 1, d) && stgs(i, j, d) && stgv(i, j + d - 1, d))
                    ++ans;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}