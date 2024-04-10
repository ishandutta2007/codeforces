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

int n, a, b, da, db;
vector<int> g[N];

int d[N];
void dfs(int x, int p)
{
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        d[h] = d[x] + 1;
        dfs(h, x);
    }
}

void solv()
{
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if (2 * da >= db)
    {
        printf("Alice\n");
        return;
    }

    dfs(a, a);
    if (d[b] <= da)
    {
        printf("Alice\n");
        return;
    }

    int maxu = -1;
    int maxx;
    for (int x = 1; x <= n; ++x)
    {
        if (d[x] > maxu)
        {
            maxu = d[x];
            maxx = x;
        }
    }
    dfs(maxx, maxx);
    for (int x = 1; x <= n; ++x)
        maxu = max(maxu, d[x]);
    if (2 * da >= maxu)
    {
        printf("Alice\n");
        return;
    }

    printf("Bob\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}