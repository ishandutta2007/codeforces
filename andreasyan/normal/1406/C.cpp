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
vector<int> g[N];

int q[N];
void dfs0(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }
}

int minu;
void dfs1(int x, int p)
{
    int maxu = n - q[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        maxu = max(maxu, q[h]);
    }
    minu = min(minu, maxu);
}

void dfs2(int x, int p)
{
    int maxu = n - q[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        maxu = max(maxu, q[h]);
    }
    minu = min(minu, maxu);
    if (maxu == minu)
    {
        if (maxu == 1)
        {
            printf("%d %d\n", x, g[x][0]);
            printf("%d %d\n", x, g[x][0]);
            return;
        }
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p)
                continue;
            if (q[h] == maxu)
            {
                if (g[h][0] != x)
                    printf("%d %d\n", h, g[h][0]);
                else
                    printf("%d %d\n", h, g[h][1]);
                if (g[h][0] != x)
                    printf("%d %d\n", x, g[h][0]);
                else
                    printf("%d %d\n", x, g[h][1]);
                return;
            }
        }
        printf("%d %d\n", x, g[x][0]);
        printf("%d %d\n", x, g[x][0]);
        return;
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs2(h, x);
    }
}

void solv()
{
    scanf("%d", &n);
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    minu = N;
    dfs0(1, 1);
    dfs1(1, 1);
    dfs2(1, 1);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}