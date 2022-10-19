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
const pair<int, int> M = m_p(703414147, 929742241);
const int P = 307;

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

int prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int n;
int cc[N];
char a[N];
vector<int> g[N];

pair<int, int> ast[N];

void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i <= n; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
}

int d[N];
pair<int, int> hh[N];
int qg[N];

void dfs0(int x, int p)
{
    d[x] = d[p] + 1;
    hh[x] = sum(hh[p], pro(ast[d[x]], m_p(a[x], a[x])));
    qg[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        qg[x] += qg[h];
    }
}

vector<pair<int, int> > vv;
int xh[N];

int ans1 = -1, ans2;

int yans;
int q[N];

void ave(int x, int y)
{
    if (q[x])
        --yans;
    q[x] += y;
    if (q[x])
        ++yans;
}

vector<int> v[N];

void dfs(int x, int p)
{
    int maxu = -1, maxx = -1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (qg[h] > maxu)
        {
            maxu = qg[h];
            maxx = h;
        }
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p || h == maxx)
            continue;
        dfs(h, x);
        for (int j = 0; j < v[h].size(); ++j)
        {
            ave(xh[v[h][j]], -1);
        }
        assert(yans == 0);
    }
    if (maxu != -1)
    {
        dfs(maxx, x);
        swap(v[x], v[maxx]);
    }
    ave(xh[x], 1);
    v[x].push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p || h == maxx)
            continue;
        for (int j = 0; j < v[h].size(); ++j)
        {
            ave(xh[v[h][j]], 1);
            v[x].push_back(v[h][j]);
        }
    }
    if (cc[x] + yans > ans1)
    {
        ans1 = cc[x] + yans;
        ans2 = 1;
    }
    else if (cc[x] + yans == ans1)
        ++ans2;
}

/*set<int> s[N];

void dfs(int x, int p)
{
    s[x].insert(xh[x]);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        if (s[h].size() > s[x].size())
            swap(s[x], s[h]);
        for (auto it = s[h].begin(); it != s[h].end(); ++it)
            s[x].insert(*it);
    }
    if (sz(s[x]) + cc[x] > ans1)
    {
        ans1 = sz(s[x]) + cc[x];
        ans2 = 1;
    }
    else if (s[x].size() + cc[x] == ans1)
        ++ans2;
}*/

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &cc[i]);
    scanf(" %s", (a + 1));
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pre();
    dfs0(1, 1);
    for (int i = 1; i <= n; ++i)
        vv.push_back(hh[i]);
    sort(all(vv));
    for (int i = 1; i <= n; ++i)
        xh[i] = lower_bound(all(vv), hh[i]) - vv.begin() + 1;
    dfs(1, 1);
    printf("%d\n%d\n", ans1, ans2);
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