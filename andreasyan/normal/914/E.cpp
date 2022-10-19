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

int n;
vector<int> g[N];
char a[N];

bool c[N];

int q[N];
void dfs0(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p || c[h])
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }
}

int dfsc(int x, int p, int xx)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p || c[h])
            continue;
        if (q[h] > q[xx] / 2)
            return dfsc(h, x, xx);
    }
    return x;
}

ll ans[N];

int mp[(1 << 20)];

void dfs1(int x, int p, int y, int z)
{
    y ^= (1 << a[x]);
    mp[y] += z;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p || c[h])
            continue;
        dfs1(h, x, y, z);
    }
}

ll dfs2(int x, int p, int y)
{
    y ^= (1 << a[x]);
    ll yans = 0;
    yans += mp[y];
    for (int i = 0; i < 20; ++i)
    {
        yans += mp[(y ^ (1 << i))];
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p || c[h])
            continue;
        yans += dfs2(h, x, y);
    }
    ans[x] += yans;
    return yans;
}

void solvv(int r)
{
    dfs1(r, r, 0, 1);
    ll yans = 0;
    for (int i = 0; i < g[r].size(); ++i)
    {
        int h = g[r][i];
        if (c[h])
            continue;
        dfs1(h, r, (1 << (a[r])), -1);
        yans += dfs2(h, r, 0);
        dfs1(h, r, (1 << (a[r])), 1);
    }
    yans += mp[0];
    for (int i = 0; i < 20; ++i)
        yans += mp[(1 << i)];
    yans /= 2;
    ++yans;
    ans[r] += yans;
    dfs1(r, r, 0, -1);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
        a[i] -= 'a';
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        dfs0(x, x);
        x = dfsc(x, x, x);
        solvv(x);
        c[x] = true;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (c[h])
                continue;
            q.push(h);
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
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