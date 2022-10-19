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
const int N = 100005;

int n;
vector<int> a[N];

multiset<int> s[N];

int dp[N];
void dfs0(int x, int p)
{
    s[x].insert(0);
    s[x].insert(0);
    s[x].insert(0);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        s[x].insert(dp[h] + 1);
    }
    while (s[x].size() > 3)
    {
        s[x].erase(s[x].begin());
    }
    dp[x] = *(--s[x].end());
}

int dpp[N];
void dfs1(int x, int p)
{
    if (x == 1)
        dpp[x] = -1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (s[x].find(dp[h] + 1) != s[x].end())
            s[x].erase(s[x].find(dp[h] + 1));
        dpp[h] = *(--s[x].end());
        dpp[h] = max(dpp[h], dpp[x] + 1);
        dfs1(h, x);
        s[x].insert(dp[h] + 1);
        while (s[x].size() > 3)
            s[x].erase(s[x].begin());
    }
}

int tin[N], tout[N], ti;
const int m = 18;
int p[N][m];
int u[N][m], d[N][m];
int dd[N];
void dfs2(int x, int pp)
{
    tin[x] = ++ti;
    p[x][0] = pp;
    if (x != pp)
    {
        if (s[pp].find(dp[x] + 1) != s[pp].end())
            s[pp].erase(s[pp].find(dp[x] + 1));
        u[x][0] = *(--s[pp].end()) + 1;
        d[x][0] = max(1, *(--s[pp].end()));
        s[pp].insert(dp[x] + 1);
        while (s[pp].size() > 3)
            s[pp].erase(s[pp].begin());
    }
    for (int i = 1; i < m; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
        u[x][i] = max(u[x][i - 1], (1 << (i - 1)) + u[p[x][i - 1]][i - 1]);
        d[x][i] = max(d[p[x][i - 1]][i - 1], (1 << (i - 1)) + d[x][i - 1]);
    }
    dd[x] = dd[pp] + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == pp)
            continue;
        dfs2(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int go(int x, int y)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return x;
}

int dist(int x, int y)
{
    int z;
    if (isp(x, y))
        z = x;
    else if (isp(y, x))
        z = y;
    else
        z = p[go(x, y)][0];
    return dd[x] + dd[y] - 2 * dd[z];
}

int go1(int x, int y)
{
    for (int i = m - 1; i >= 0; --i)
    {
        if ((y & (1 << i)))
            x = p[x][i];
    }
    return x;
}

int gou1(int x, int y)
{
    int ans = 0;
    int dd = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        if ((y & (1 << i)))
        {
            ans = max(ans, dd + u[x][i]);
            dd += (1 << i);
            x = p[x][i];
        }
    }
    return ans;
}

int god1(int x, int y)
{
    int ans = 0;
    int dd = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        if ((y & (1 << i)))
        {
            ans += (1 << i);
            ans = max(ans, d[x][i]);
            x = p[x][i];
        }
    }
    return ans;
}

int solvv0(int x, int y)
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, min(dist(i, x), dist(i, y)));
    }
    return ans;
}

int solvv(int x, int y)
{
    int ans = 0;
    if (dd[x] < dd[y])
        swap(x, y);

        /*if (isp(y, x))
        {
            int z = go1(x, dist(x, y) / 2);
            ans = max(ans, dp[x]);
            ans = max(ans, gou1(x, dist(x, z)));

            z = p[z][0];
            ans = max(ans, god1(z, dist(z, y)));
            if (y != 1)
                ans = max(ans, dpp[y] + 1);

            printf("%d\n", ans);
            continue;
        }*/

    int l = p[go(x, y)][0];

    ans = max(ans, dp[x]);
    int z = go1(x, dist(x, y) / 2);
    if (z == l)
        z = go(x, y);
    ans = max(ans, gou1(x, dist(x, z)));

    z = p[z][0];
    if (!isp(y, x))
        ans = max(ans, dp[y]);
    ans = max(ans, gou1(y, dist(y, go(y, l))));
    ans = max(ans, god1(z, dist(z, go(z, l))) + dist(go(z, l), y));
    if (z != l)
    {
        if (s[z].find(dp[go(x, z)] + 1) != s[z].end())
            s[z].erase(s[z].find(dp[go(x, z)] + 1));
        ans = max(ans, *(--s[z].end()) + dist(z, y));
        s[z].insert(dp[go(x, z)] + 1);
        while (s[z].size() > 3)
            s[z].erase(s[z].begin());
    }
    if (s[l].find(dp[go(x, l)] + 1) != s[l].end())
        s[l].erase(s[l].find(dp[go(x, l)] + 1));
    if (y != l && s[l].find(dp[go(y, l)] + 1) != s[l].end())
        s[l].erase(s[l].find(dp[go(y, l)] + 1));
    ans = max(ans, *(--s[l].end()) + dist(l, y));
    s[l].insert(dp[go(x, l)] + 1);
    if (y != l)
        s[l].insert(dp[go(y, l)] + 1);
    while (s[l].size() > 3)
        s[l].erase(s[l].begin());
    if (l != 1)
        ans = max(ans, dpp[l] + 1 + dist(l, y));
    return ans;
}

void kar()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void clr()
{
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
        s[i].clear();
    }
}

void gen()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
    {
        int p = rnd() % (i - 1) + 1;
        a[p].push_back(i);
        a[i].push_back(p);
        printf("%d %d\n", p, i);
    }
}

void solv()
{
    //gen();
    kar();
    dfs0(1, 1);
    dfs1(1, 1);
    dfs2(1, 1);

    /*for (int x = 1; x <= n; ++x)
    {
        for (int y = x + 1; y <= n; ++y)
        {
            if (solvv(x, y) != solvv0(x, y))
            {
                printf("WA\n");
                printf("%d %d\n", x, y);
                printf("%d\n", solvv(x, y));
            }
        }
    }
    return;*/

    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int ans = solvv(x, y);
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