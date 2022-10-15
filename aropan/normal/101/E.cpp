#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 50000;

int n, m, p, k;
int x[MAXN], y[MAXN];
pair <int, int> a[MAXN];
long long f[MAXN];

int t;
pair <pair <int, int>, int> g[MAXN];

int dfs(int x1, int y1, int x2, int y2)
{
    int xx = x2 - x1, yy = y2 - y1;
    int l = xx + yy;

    if (l == 1)
    {
        a[k++] = make_pair(x1, y1);
        return 0;
    }

    int d = l / 2;

    for (int i = 0; i <= yy; i++)
        f[i] = 0;

    t = 0;
    for (int i = 0; i <= xx; i++)
        for (int j = 0; j <= yy && i + j <= d; j++)
        {
            if (j) f[j] = max(f[j], f[j - 1]);
            f[j] += (x[i + x1] + y[j + y1]) % p;

            if (i + j == d)
                g[t++] = make_pair(make_pair(x1 + i, y1 + j), f[j]);
        }

    for (int i = 0; i <= yy; i++)
        f[i] = 0;

    int tt = t;
    for (int i = xx; i >= 0; i--)
        for (int j = yy; j >= 0 && i + j >= d; j--)
        {
            if (j < yy) f[j] = max(f[j], f[j + 1]);

            if (i + j == d)
                g[--tt].second += f[j];

            f[j] += (x[i + x1] + y[j + y1]) % p;
        }

    int xa, ya;
    long long ans = -1;
    for (int i = 0; i < t; i++)
    {
        if (g[i].second > ans)
        {
            xa = g[i].first.first;
            ya = g[i].first.second;
            ans = g[i].second;
        }
    }

    dfs(x1, y1, xa, ya);
//    a[k++] = make_pair(xa, ya);
    dfs(xa, ya, x2, y2);

    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);

    for (int i = 0; i < m; i++)
        scanf("%d", &y[i]);

    if (n > 1 || m > 1) dfs(0, 0, n - 1, m - 1);
    a[k++] = make_pair(n - 1, m - 1);

    long long ans = 0;
    for (int i = 0; i < k; i++)
        ans += (x[a[i].first] + y[a[i].second]) % p;

    printf("%I64d\n", ans);
    for (int i = 1; i < k; i++)
        printf("%c", a[i].first == a[i - 1].first? 'S' : 'C');
    printf("\n");
    return 0;
}