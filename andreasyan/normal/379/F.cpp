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
const int N = 1000006;

int n;
vector<int> a[N];

int tin[N], tout[N], ti;

int d[N];
const int m = 20;
int p[N][m];

void dfs(int x)
{
    tin[x] = ++ti;
    d[x] = d[p[x][0]] + 1;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h);
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
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

int dist(int x, int y)
{
    int z = lca(x, y);
    return d[x] + d[y] - 2 * d[z];
}

int xx, yy;

void ave(int x)
{
    if (x == 1)
    {
        xx = yy = x;
        return;
    }
    if (dist(x, xx) > dist(xx, yy))
    {
        yy = x;
    }
    else if (dist(x, yy) > dist(xx, yy))
    {
        xx = x;
    }
}

void solv()
{
    int qq;
    scanf("%d", &qq);
    p[1][0] = 1;
    a[1].push_back(2);
    p[2][0] = 1;
    a[1].push_back(3);
    p[3][0] = 1;
    a[1].push_back(4);
    p[4][0] = 1;
    n = 4;
    vector<int> v;
    for (int i = 0; i < qq; ++i)
    {
        int pp;
        scanf("%d", &pp);
        v.push_back(pp);
        a[pp].push_back(++n);
        p[n][0] = pp;
        a[pp].push_back(++n);
        p[n][0] = pp;
    }
    dfs(1);
    ave(1);
    ave(2);
    ave(3);
    ave(4);
    n = 4;
    for (int i = 0; i < qq; ++i)
    {
        ave(++n);
        ave(++n);
        printf("%d\n", dist(xx, yy));
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