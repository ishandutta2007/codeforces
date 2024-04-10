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
const int Q = 100005, N = 1003;

int n, m, q;

int ans[Q];
vector<int> g[Q];
int x[Q], y[Q];

bitset<N> b;
int yans;
bitset<N> a[N];

void dfs(int u)
{
    bitset<N> aa;
    if (x[u] > 0 && y[u] > 0)
    {
        aa = a[x[u]];
        a[x[u]][y[u]] = 1;
        yans -= aa.count();
        yans += a[x[u]].count();
    }
    else if (x[u] < 0 && y[u] < 0)
    {
        aa = a[-x[u]];
        a[-x[u]][-y[u]] = 0;
        yans -= aa.count();
        yans += a[-x[u]].count();
    }
    else if (x[u] > 0)
    {
        aa = a[x[u] - n];
        a[x[u] - n] ^= b;
        yans -= aa.count();
        yans += a[x[u] - n].count();
    }
    ans[u] = yans;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int h = g[u][i];
        dfs(h);
    }
    if (x[u] > 0 && y[u] > 0)
    {
        yans += aa.count();
        yans -= a[x[u]].count();
        a[x[u]] = aa;
    }
    else if (x[u] < 0 && y[u] < 0)
    {
        yans += aa.count();
        yans -= a[-x[u]].count();
        a[-x[u]] = aa;
    }
    else if (x[u] > 0)
    {
        yans += aa.count();
        yans -= a[x[u] - n].count();
        a[x[u] - n] = aa;
    }
}

void solv()
{
    scanf("%d%d%d", &n, &m, &q);
    int pp = 0;
    for (int i = 1; i <= q; ++i)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            scanf("%d%d", &x[i], &y[i]);
            g[pp].push_back(i);
            pp = i;
        }
        else if (ty == 2)
        {
            scanf("%d%d", &x[i], &y[i]);
            x[i] *= -1;
            y[i] *= -1;
            g[pp].push_back(i);
            pp = i;
        }
        else if (ty == 3)
        {
            scanf("%d", &x[i]);
            x[i] += n;
            y[i] = 0;
            g[pp].push_back(i);
            pp = i;
        }
        else
        {
            scanf("%d", &pp);
            x[i] = y[i] = 0;
            g[pp].push_back(i);
            pp = i;
        }
    }

    for (int j = 1; j <= m; ++j)
        b[j] = 1;
    dfs(0);

    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
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