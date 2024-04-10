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
pair<int, pair<int, int> > b[N];
vector<int> g[N];

int c[N];
bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h] == 1)
            return true;
        if (c[h] == 0)
        {
            if (dfs(h))
                return true;
        }
    }
    c[x] = 2;
    return false;
}

vector<int> v;
void dfs1(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs1(h);
    }
    v.push_back(x);
}

int u[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < m; ++i)
    {
        int ty, x, y;
        scanf("%d%d%d", &ty, &x, &y);
        if (ty)
            g[x].push_back(y);
        b[i] = m_p(ty, m_p(x, y));
    }

    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            if (dfs(x))
            {
                printf("NO\n");
                return;
            }
        }
    }

    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    v.clear();
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            dfs1(x);
        }
    }
    for (int i = 0; i < n; ++i)
        u[v[i]] = i;

    printf("YES\n");
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].se.fi;
        int y = b[i].se.se;
        if (u[x] > u[y])
            printf("%d %d\n", x, y);
        else
            printf("%d %d\n", y, x);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}