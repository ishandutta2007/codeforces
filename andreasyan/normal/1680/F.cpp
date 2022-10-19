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
const int k = 21;

int n, m;
bool c[N];
vector<int> g[N];
pair<int, int> b[N];

int p0[N];
int fin(int x)
{
    if (x == p0[x])
        return x;
    return p0[x] = fin(p0[x]);
}

void kpc(int x, int y)
{
    x = fin(x);
    y = fin(y);
    p0[x] = y;
}

int tin[N], tout[N], ti;
int d[N];
int p[N][k];
void dfs0(int x, int p0)
{
    tin[x] = ++ti;

    d[x] = (d[p0] ^ 1);

    p[x][0] = p0;
    for (int i = 1; i < k; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs0(h, x);
    }

    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tin[y] <= tout[x]);
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = k - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

vector<int> gg[N];

int q[N], q1[N];
void dfs(int x, int p0)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs(h, x);

        q[x] += q[h];
        q1[x] += q1[h];
    }

    int xx = x;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int j = gg[x][i];
        if (j < 0)
            continue;
        int x = b[j].fi;
        int y = b[j].se;
        if (d[x] == d[y])
            ++q[xx];
        else
            ++q1[xx];
    }
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int j = gg[x][i];
        if (j > 0)
            continue;
        j *= -1;
        int x = b[j].fi;
        int y = b[j].se;
        if (d[x] == d[y])
            q[xx] -= 2;
        else
            q1[xx] -= 2;
    }
}

void dfs1(int x, int p0)
{
    d[x] ^= 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs1(h, x);
    }
}

void solv()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        p0[i] = i;
        gg[i].clear();
        q[i] = 0;
        q1[i] = 0;
    }

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;

        c[i] = false;
        if (fin(x) != fin(y))
        {
            g[x].push_back(y);
            g[y].push_back(x);
            kpc(x, y);
            c[i] = true;
        }

        b[i] = m_p(x, y);
    }

    dfs0(1, 1);

    int q = 0;
    bool rr = false;
    for (int i = 1; i <= m; ++i)
    {
        int x = b[i].fi;
        int y = b[i].se;

        if (d[x] == d[y])
        {
            ++q;
            if (d[x] == 0)
            {
                rr = true;
            }
        }
    }

    if (q <= 1)
    {
        if (rr)
        {
            for (int x = 1; x <= n; ++x)
                d[x] ^= 1;
        }

        cout << "YES\n";
        for (int x = 1; x <= n; ++x)
        {
            cout << d[x];
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= m; ++i)
    {
        if (c[i])
            continue;
        int x = b[i].fi;
        int y = b[i].se;
        gg[x].push_back(i);
        gg[y].push_back(i);
        gg[lca(x, y)].push_back(-i);
    }

    dfs(1, 1);

    for (int x = 1; x <= n; ++x)
    {
        if (::q[x] == q && q1[x] == 0)
        {
            dfs1(x, p[x][0]);
            if (d[x] == 0)
            {
                for (int i = 1; i <= n; ++i)
                    d[i] ^= 1;
            }

            cout << "YES\n";
            for (int x = 1; x <= n; ++x)
            {
                cout << d[x];
            }
            cout << "\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}