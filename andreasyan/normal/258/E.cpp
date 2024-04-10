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
const int N = 200005;

int n, m;
vector<int> g[N], a[N];

int q[N * 4], t[N * 4];

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        q[pos] += y;
        if (q[pos])
        {
            t[pos] = (tr - tl + 1);
        }
        else
        {
            if (tl == tr)
                t[pos] = 0;
            else
                t[pos] = t[pos * 2] + t[pos * 2 + 1];
        }
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    if (q[pos])
        t[pos] = (tr - tl + 1);
    else
        t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int tin[N], tout[N], ti;
void dfs0(int x, int p)
{
    tin[x] = ++ti;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
    }
    tout[x] = ti;
}

int ans[N];

void dfs(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int y = a[x][i];
        ubd(1, n, tin[x], tout[x], 1, 1);
        ubd(1, n, tin[y], tout[y], 1, 1);
    }
    ans[x] = t[1];
    if (ans[x])
        --ans[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int y = a[x][i];
        ubd(1, n, tin[x], tout[x], -1, 1);
        ubd(1, n, tin[y], tout[y], -1, 1);
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs0(1, 1);
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}