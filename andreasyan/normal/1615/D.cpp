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

int n, m;
pair<pair<int, int>, int> b[N], c[N];
vector<pair<int, int> > g[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

bool cc[N];
int d[N];
void dfs(int x, int p)
{
    cc[x] = true;
    if (x == p)
        d[x] = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        d[h] = (d[x] ^ g[x][i].se);
        dfs(h, x);
    }
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        g[i].clear();
        cc[i] = false;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        b[i] = m_p(m_p(x, y), z);

        if (z != -1)
        {
            kpc(x, y);
            int q = 0;
            for (int j = 0; j < 30; ++j)
            {
                if ((z & (1 << j)))
                    q ^= 1;
            }
            g[x].push_back(m_p(y, q));
            g[y].push_back(m_p(x, q));
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        c[i] = m_p(m_p(x, y), z);

        if (fi(x) != fi(y))
        {
            kpc(x, y);
            g[x].push_back(m_p(y, z));
            g[y].push_back(m_p(x, z));
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!cc[x])
        {
            dfs(x, x);
        }
    }

    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x = b[i].fi.fi;
        int y = b[i].fi.se;
        int z = b[i].se;

        if (z == -1)
        {
            z = (d[x] ^ d[y]);
            b[i].se = z;
        }
        else
        {
            int q = 0;
            for (int j = 0; j < 30; ++j)
            {
                if ((z & (1 << j)))
                    q ^= 1;
            }
            z = q;
        }

        g[x].push_back(m_p(x, z));
        g[y].push_back(m_p(y, z));
    }

    dfs(1, 1);

    for (int i = 0; i < m; ++i)
    {
        int x = c[i].fi.fi;
        int y = c[i].fi.se;
        int z = c[i].se;

        if ((d[x] ^ d[y]) != z)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n - 1; ++i)
    {
        cout << b[i].fi.fi << ' ' << b[i].fi.se << ' ' << b[i].se << "\n";
    }
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