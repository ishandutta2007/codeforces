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
const int N = 1000006;

int n, m;
char** a;
int q[N];

int** u;

bool cc[N];
vector<int> g[N];
vector<int> rg[N];

vector<int> v;
int c[N];
void dfs0(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs0(h);
    }
    v.push_back(x);
}

int k;
void dfs1(int x)
{
    c[x] = k;
    for (int i = 0; i < rg[x].size(); ++i)
    {
        int h = rg[x][i];
        if (!c[h])
            dfs1(h);
    }
}

vector<int> gg[N];

int qu[N];
int rqu[N];
void dfs2(int x)
{
    cc[x] = true;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        if (!cc[h])
            dfs2(h);
    }
}

int qug[N];

int l[N], r[N];
void dfs3(int x)
{
    cc[x] = true;
    if (!qug[x])
    {
        l[x] = N;
        r[x] = -N;
    }
    else
    {
        l[x] = r[x] = qug[x];
    }
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        if (!cc[h])
            dfs3(h);
        l[x] = min(l[x], l[h]);
        r[x] = max(r[x], r[h]);
    }
}

int maxu[N];
void solv()
{
    cin >> n >> m;
    a = new char*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        a[i] = new char[m + 5];
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][j] == '#')
                ++q[j];
        }
    }

    for (int j = 1; j <= m; ++j)
        cin >> q[j];

    u = new int*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        u[i] = new int[m + 5];

    for (int j = 1; j <= m; ++j)
    {
        u[n + 1][j] = -1;
        for (int i = n; i >= 1; --i)
        {
            if (a[i][j] == '#')
            {
                u[i][j] = (i - 1) * m + j;
            }
            else
            {
                u[i][j] = u[i + 1][j];
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '#')
            {
                cc[(i - 1) * m + j] = true;
                if (u[i + 1][j] != -1)
                    g[(i - 1) * m + j].push_back(u[i + 1][j]);
                if (j > 1 && u[i][j - 1] != -1)
                    g[(i - 1) * m + j].push_back(u[i][j - 1]);
                if (j < m && u[i][j + 1] != -1)
                    g[(i - 1) * m + j].push_back(u[i][j + 1]);
                if (i > 1 && a[i - 1][j] == '#')
                    g[(i - 1) * m + j].push_back(u[i - 1][j]);
            }
        }
    }
    for (int x = 1; x <= n * m; ++x)
    {
        if (!cc[x])
            continue;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            rg[h].push_back(x);
        }
    }

    for (int x = 1; x <= n * m; ++x)
    {
        if (!cc[x])
            continue;
        if (!c[x])
            dfs0(x);
    }

    reverse(all(v));
    memset(c, 0, sizeof c);
    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++k;
            dfs1(x);
        }
    }

    for (int x = 1; x <= n * m; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (c[x] != c[h])
            {
                gg[c[x]].push_back(c[h]);
            }
        }
    }

    memset(cc, false, sizeof cc);
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j < gg[i].size(); ++j)
            cc[gg[i][j]] = true;
    }

    int ans0 = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (!cc[i])
            ++ans0;
    }
    //cout << ans0 << "\n";

//////////////////////////////////////////////////////////////////////////////

    for (int j = 1; j <= m; ++j)
    {
        if (!q[j])
            continue;
        int qq = 0;
        for (int i = n; i >= 1; --i)
        {
            if (a[i][j] == '#')
                ++qq;
            if (qq == q[j])
            {
                qu[j] = (i - 1) * m + j;
                break;
            }
        }
        rqu[qu[j]] = j;
    }

    memset(cc, false, sizeof cc);

    for (int j = 1; j <= m; ++j)
    {
        if (qu[j])
        {
            if (!cc[qu[j]])
            {
                qug[c[qu[j]]] = j;
            }
        }
    }

    for (int i = 1; i <= k; ++i)
    {
        if (!qug[i])
            continue;
        if (!cc[i])
        {
            dfs2(i);
            cc[i] = false;
        }
    }

    vector<int> v;
    for (int i = 1; i <= k; ++i)
    {
        if (qug[i] && !cc[i])
            v.push_back(qug[i]);
    }
    sort(all(v));

    memset(qug, 0, sizeof qug);
    for (int i = 0; i < sz(v); ++i)
        qug[c[qu[v[i]]]] = v[i];

    memset(cc, false, sizeof cc);
    for (int i = 1; i <= k; ++i)
    {
        if (!cc[i])
            dfs3(i);
    }

    vector<pair<int, int> > vv;
    for (int i = 1; i <= k; ++i)
    {
        if (l[i] != N)
        {
            vv.push_back(m_p(lower_bound(all(v), l[i]) - v.begin(), lower_bound(all(v), r[i]) - v.begin()));
        }
    }

    for (int i = 0; i < sz(vv); ++i)
        maxu[vv[i].fi] = max(maxu[vv[i].fi], vv[i].se);
    for (int i = 1; i < sz(v); ++i)
        maxu[i] = max(maxu[i], maxu[i - 1]);

    int ans = 0;
    int i = 0;
    while (i < sz(v))
    {
        ++ans;
        i = maxu[i] + 1;
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}