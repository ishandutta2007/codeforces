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
vector<int> g[N], rg[N];

int c[N];

bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h] == 1)
            return true;
        if (!c[h])
        {
            if (dfs(h))
                return true;
        }
    }
    c[x] = 2;
    return false;
}

int c1[N];
void dfs1(int x)
{
    c1[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c1[h])
        {
            dfs1(h);
        }
    }
}

int c2[N];
void dfs2(int x)
{
    c2[x] = 1;
    for (int i = 0; i < rg[x].size(); ++i)
    {
        int h = rg[x][i];
        if (!c2[h])
        {
            dfs2(h);
        }
    }
}

char ans[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            if (dfs(x))
            {
                printf("-1\n");
                return;
            }
        }
    }
    memset(c, 0, sizeof c);

    for (int x = 1; x <= n; ++x)
    {
        ans[x - 1] = 'E';
        if (!c1[x] && !c2[x])
        {
            ans[x - 1] = 'A';
        }
        if (!c1[x])
            dfs1(x);
        if (!c2[x])
            dfs2(x);
    }
    int yans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ans[i] == 'A')
            ++yans;
    }
    printf("%d\n", yans);
    printf("%s\n", ans);
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