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
const int N = 300005;

int n, m;
vector<int> g[N];

int c[N];

void dfs(int x)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        c[h] = 3 - c[x];
        dfs(h);
    }
}

bool stg(int x)
{
    int q = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h] == c[x])
            ++q;
    }
    return (q <= 1);
}

void dfs1(int x)
{
    if (stg(x))
        return;
    c[x] = 3 - c[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs1(h);
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            c[i] = 1;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i)
        dfs1(i);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d", c[i] - 1);
    }
    printf("\n");
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}