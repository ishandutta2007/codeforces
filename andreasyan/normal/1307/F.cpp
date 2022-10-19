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
const int N = 400005;

int n, k, m;
vector<int> g[N];

bool c[N];
int d[N];

int p0[N];
int fi(int x)
{
    if (x == p0[x])
        return x;
    return p0[x] = fi(p0[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p0[x] = y;
}

const int l = 19;
int p[N][l];

int tin[N], tout[N], ti;

void dfs(int x, int p0)
{
    tin[x] = ++ti;
    p[x][0] = p0;
    for (int i = 1; i < l; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        d[h] = d[x] + 1;
        dfs(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = l - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

int go(int x, int y)
{
    for (int i = 0; i < l; ++i)
    {
        if ((y & (1 << i)))
        {
            x = p[x][i];
        }
    }
    return x;
}

int dist(int x, int y)
{
    return d[x] + d[y] - 2 * d[lca(x, y)];
}

bool stg(int x, int y)
{
    if (dist(x, y) <= k * 2)
        return true;

    int z = lca(x, y);

    int xx;
    if (dist(x, z) >= k)
        xx = go(x, k);
    else
        xx = go(y, dist(x, y) - k);

    int yy;
    if (dist(y, z) >= k)
        yy = go(y, k);
    else
        yy = go(x, dist(x, y) - k);

    return (fi(xx) == fi(yy));
}

void solv()
{
    scanf("%d%d%d", &n, &k, &m);
    int n0 = n;
    for (int i = 0; i < n0 - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ++n;
        g[x].push_back(n);
        g[n].push_back(x);
        g[y].push_back(n);
        g[n].push_back(y);
    }

    queue<int> q;
    for (int i = 1; i <= m; ++i)
    {
        int x;
        scanf("%d", &x);

        c[x] = true;
        q.push(x);
    }

    for (int i = 1; i <= n; ++i)
        p0[i] = i;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (d[x] >= k)
            break;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            kpc(x, h);
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }

    dfs(1, 1);

    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (stg(x, y))
            printf("YES\n");
        else
            printf("NO\n");
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