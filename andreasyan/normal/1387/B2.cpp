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
const int N = 100005, INF = 1000006;

int n;
vector<int> g[N];

int dfs_dist(int x, int p, int y, int d)
{
    if (x == y)
        return d;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        int u = dfs_dist(h, x, y, d + 1);
        if (u != -1)
            return u;
    }
    return -1;
}

int solv0()
{
    int ansg = -INF;
    int ans[20];

    int yans[20];
    for (int i = 1; i <= n; ++i)
        yans[i] = i;

    do
    {
        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            if (yans[i] == i)
            {
                z = false;
                break;
            }
        }
        if (!z)
            continue;

        int yansg = 0;

        for (int x = 1; x <= n; ++x)
        {
            yansg += dfs_dist(x, x, yans[x], 0);
        }

        if (yansg > ansg)
        {
            ansg = yansg;
            for (int i = 1; i <= n; ++i)
                ans[i] = yans[i];
        }
    } while (next_permutation(yans + 1, yans + n + 1));

    /*printf("%d\n", ansg);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");*/

    return ansg;
}

int d[N];
int q[N];
void dfs0(int x, int p)
{
    if (x == p)
        d[x] = 0;
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        d[h] = d[x] + 1;
        dfs0(h, x);
        q[x] += q[h];
    }
}

int dfsc(int x, int p, int xx)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (q[h] > q[xx] / 2)
            return dfsc(h, x, xx);
    }
    return x;
}

vector<int> v;
void dfs1(int x, int p)
{
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
    }
}

void ka()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void gen()
{
    n = 8;
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int x = 2; x <= n; ++x)
    {
        int y = rnf() % (x - 1) + 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

int ans[N];
void solv()
{
    ka();
    //gen();

    dfs0(1, 1);
    int s = dfsc(1, 1, 1);
    dfs0(s, s);

    ll ansg = 0;
    for (int x = 1; x <= n; ++x)
        ansg += d[x] * 2;

    vector<vector<int> > vv;
    for (int i = 0; i < g[s].size(); ++i)
    {
        int h = g[s][i];
        v.clear();
        dfs1(h, s);
        vv.push_back(v);
    }

    set<pair<int, int> > q;
    for (int i = 0; i < sz(vv); ++i)
        q.insert(m_p(sz(vv[i]), i));

    while (1)
    {
        if (sz(q) < 2)
        {
            int x = (--q.end())->se;
            ans[s] = vv[x].back();
            ans[vv[x].back()] = s;
            break;
        }
        else
        {
            int x = (--q.end())->se;
            q.erase(--q.end());
            int y = (--q.end())->se;
            q.erase(--q.end());
            if (q.empty() && sz(vv[x]) == 1 && sz(vv[y]) == 1)
            {
                ans[vv[x].back()] = s;
                ans[s] = vv[y].back();
                ans[vv[y].back()] = vv[x].back();
                break;
            }
            ans[vv[x].back()] = vv[y].back();
            ans[vv[y].back()] = vv[x].back();
            vv[x].pop_back();
            vv[y].pop_back();
            if (!vv[x].empty())
                q.insert(m_p(sz(vv[x]), x));
            if (!vv[y].empty())
                q.insert(m_p(sz(vv[y]), y));
        }
    }

    printf("%lld\n", ansg);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return;

    if (ansg != solv0())
    {
        printf("WA\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}