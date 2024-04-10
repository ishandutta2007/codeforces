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
int u[N];
int a[N];
vector<int> g[N];

bool leaf[N];

int c[N];
int s, f;
int p0[N];
bool dfsc(int x)
{
    c[x] = 1;
    if (c[u[x]] == 1)
    {
        s = u[x];
        f = x;
        c[x] = 2;
        return true;
    }
    if (c[u[x]] == 0)
    {
        p0[u[x]] = x;
        if (dfsc(u[x]))
        {
            c[x] = 2;
            return true;
        }
    }
    c[x] = 2;
    return false;
}

pair<int, int> t[N];

const int m = 19;
int p[N][m];
int d[N];
void dfs(int x, int p0)
{
    if (x == p0)
        d[x] = 0;
    else
        d[x] = d[p0] + 1;

    p[x][0] = p0;
    for (int i = 1; i < m; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        t[h] = t[x];
        dfs(h, x);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> u[i];
        g[u[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int maxu = 0;
    for (int i = 1; i <= n; ++i)
        maxu = max(maxu, a[i]);

    for (int i = 1; i <= n; ++i)
        leaf[i] = true;
    for (int i = 1; i <= n; ++i)
        leaf[u[i]] = false;
    int lq = 0;
    for (int i = 1; i <= n; ++i)
        lq += leaf[i];

    assert((maxu - n) % lq == 0);
    int q = (maxu - n) / lq;

    vector<vector<int> > vv;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        if (dfsc(i))
        {
            vector<int> v;
            for (int x = f; x != s; x = p0[x])
                v.push_back(x);
            v.push_back(s);
            reverse(all(v));
            vv.push_back(v);
        }
    }

    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    for (int i = 0; i < sz(vv); ++i)
    {
        for (int j = 0; j < sz(vv[i]); ++j)
            c[vv[i][j]] = 1;
    }

    for (int i = 0; i < sz(vv); ++i)
    {
        for (int j = 0; j < sz(vv[i]); ++j)
        {
            t[vv[i][j]] = m_p(i, j);
            dfs(vv[i][j], vv[i][j]);
        }
    }

    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] <= n)
            s.erase(a[i]);
    }
    for (int i = 1; i <= n; ++i)
        c[i] = 0;

    for (int x = 1; x <= n; ++x)
    {
        int xx;
        if (d[x] >= q)
        {
            xx = x;
            for (int i = m - 1; i >= 0; --i)
            {
                if ((q & (1 << i)))
                    xx = p[xx][i];
            }
        }
        else
        {
            xx = p[x][m - 1];
            xx = vv[t[xx].fi][(t[xx].se + q - d[x]) % sz(vv[t[xx].fi])];
        }

        if (!c[xx])
        {
            c[xx] = 1;
            cout << a[xx] << ' ';
        }
        else
        {
            auto it = s.lower_bound(a[xx]);
            assert(it != s.end());
            cout << *it << ' ';
            s.erase(it);
        }
    }
    cout << "\n";
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