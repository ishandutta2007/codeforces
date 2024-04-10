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

int n, m, k;
pair<int, int> b[N];
vector<int> g[N];
vector<int> gi[N];

bool c[N];
int q[N];

int yans;
int ans[N];

void dfs(int x, int ki)
{
    if (!c[x])
        return;
    if (q[x] >= k)
        return;
    c[x] = false;
    --yans;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        int hi = gi[x][i];
        if (hi >= ki)
            continue;
        if (c[h])
        {
            --q[h];
            dfs(h, ki);
        }
    }
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
        b[i] = m_p(x, y);
    }

    yans = n;
    for (int x = 1; x <= n; ++x)
    {
        c[x] = true;
        q[x] = sz(g[x]);
    }

    for (int x = 1; x <= n; ++x)
    {
        dfs(x, m);
    }

    for (int i = m - 1; i >= 0; --i)
    {
        ans[i] = yans;
        int x = b[i].fi;
        int y = b[i].se;
        if (!c[x] || !c[y])
            continue;
        --q[x];
        --q[y];
        dfs(x, i);
        dfs(y, i);
    }

    for (int i = 0; i < m; ++i)
        printf("%d\n", ans[i]);
    printf("\n");
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