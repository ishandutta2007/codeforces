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

int n;
vector<int> a[N];

int d[N];
int maxu[N];

void dfs(int x, int p)
{
    d[x] = d[p] + 1;
    maxu[x] = d[x];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        maxu[x] = max(maxu[x], maxu[h]);
    }
}

bool c[N];
vector<int> v;

bool dfs1(int x, int p, int y)
{
    v.push_back(x);
    if (x == y)
        return true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (dfs1(h, x, y))
            return true;
    }
    v.pop_back();
    return false;
}

int g[N];
void dfs2(int x, int p)
{
    if (x != p)
    {
        d[x] = d[p] + 1;
        g[x] = g[p];
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p || c[h])
            continue;
        dfs2(h, x);
    }
}

ll ans;
vector<pair<pair<int, int>, int> > ansv;

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    int x = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] > d[x])
        {
            x = i;
        }
    }
    dfs(x, x);
    int y = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] > d[y])
        {
            y = i;
        }
    }
    dfs1(x, x, y);
    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i];
        c[x] = true;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i];
        if (i > sz(v) - i - 1)
        {
            g[x] = v[0];
            d[x] = i;
        }
        else
        {
            g[x] = v.back();
            d[x] = sz(v) - i - 1;
        }
        dfs2(x, x);
    }
    vector<pair<int, int> > vv;
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            vv.push_back(m_p(d[x], x));
        }
    }
    sort(all(vv));
    reverse(all(vv));
    for (int i = 0; i < vv.size(); ++i)
    {
        ans += vv[i].fi;
        ansv.push_back(m_p(m_p(vv[i].se, g[vv[i].se]), vv[i].se));
    }
    for (int i = 0; i < sz(v) - 1; ++i)
    {
        ans += (sz(v) - i - 1);
        ansv.push_back(m_p(m_p(v[i], v.back()), v[i]));
    }
    printf("%lld\n", ans);
    for (int i = 0; i < n - 1; ++i)
        printf("%d %d %d\n", ansv[i].fi.fi, ansv[i].fi.se, ansv[i].se);
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