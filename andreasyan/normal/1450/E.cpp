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
const int N = 203, INF = 1000006;

int n, m;
vector<pair<int, int> > g[N];
int a[N][N];

int c[N];
void dfs(int x, int u)
{
    c[x] = u;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (!c[h])
            dfs(h, 3 - u);
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
            a[x][y] = INF;
    for (int x = 1; x <= n; ++x)
        a[x][x] = 0;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (z == 0)
        {
            g[x].push_back(m_p(y, 1));
            g[y].push_back(m_p(x, 1));
            a[x][y] = min(a[x][y], 1);
            a[y][x] = min(a[y][x], 1);
        }
        else
        {
            g[x].push_back(m_p(y, 1));
            g[y].push_back(m_p(x, -1));
            a[x][y] = min(a[x][y], 1);
            a[y][x] = min(a[y][x], -1);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
            dfs(x, 1);
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int y = g[x][i].fi;
            if (c[x] == c[y])
            {
                printf("NO\n");
                return;
            }
        }
    }

    for (int z = 1; z <= n; ++z)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                a[x][y] = min(a[x][y], a[x][z] + a[z][y]);
            }
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        if (a[x][x] < 0)
        {
            printf("NO\n");
            return;
        }
    }

    int maxu = 0;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            maxu = max(maxu, a[x][y]);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        int ymaxu = 0;
        for (int y = 1; y <= n; ++y)
        {
            ymaxu = max(ymaxu, a[x][y]);
        }
        if (ymaxu == maxu)
        {
            printf("YES\n");
            printf("%d\n", maxu);
            for (int y = 1; y <= n; ++y)
                printf("%d ", a[x][y]);
            printf("\n");
            return;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}