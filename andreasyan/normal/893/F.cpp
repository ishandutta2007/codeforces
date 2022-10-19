#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, S = 400, INF = 1000000009;
int s;

int n, r;
int a[N];
vector<int> g[N];

int tin[N], tout[N], ti;
int rtin[N];
int d[N];
void dfs(int x, int p)
{
    tin[x] = ++ti;
    rtin[ti] = x;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        d[h] = d[x] + 1;
        dfs(h, x);
    }
    tout[x] = ti;
}

int p[S][N];

void solv()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(r, r);
    s = sqrt(n);
    for (int i = 0; i < S; ++i)
    {
        for (int j = 0; j < N; ++j)
            p[i][j] = INF;
    }
    for (int i = 1; i <= n; ++i)
    {
        p[i / s][d[rtin[i]]] = min(p[i / s][d[rtin[i]]], a[rtin[i]]);
    }
    for (int i = 0; i <= n / s; ++i)
    {
        for (int j = 1; j <= n; ++j)
            p[i][j] = min(p[i][j - 1], p[i][j]);
    }
    int qq;
    scanf("%d", &qq);
    int ans = 0;
    while (qq--)
    {
        int x, k;
        scanf("%d%d", &x, &k);
        x = (x + ans) % n + 1;
        k = (k + ans) % n;
        int l = tin[x], r = tout[x];
        ans = INF;
        if (l / s == r / s)
        {
            for (int i = l; i <= r; ++i)
            {
                if (d[rtin[i]] <= d[x] + k)
                    ans = min(ans, a[rtin[i]]);
            }
        }
        else
        {
            for (int i = l; i <= n && i / s == l / s; ++i)
            {
                if (d[rtin[i]] <= d[x] + k)
                    ans = min(ans, a[rtin[i]]);
            }
            for (int i = r; i >= 1 && i / s == r / s; --i)
            {
                if (d[rtin[i]] <= d[x] + k)
                    ans = min(ans, a[rtin[i]]);
            }
            for (int i = l / s + 1; i <= r / s - 1; ++i)
                ans = min(ans, p[i][min(d[x] + k, n)]);
        }
        printf("%d\n", ans);
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