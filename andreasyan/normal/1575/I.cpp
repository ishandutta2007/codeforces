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

int n, qq;
int a[N];
vector<int> g[N];

int q[N];
int p0[N];
void dfs0(int x, int p)
{
    p0[x] = p;
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            swap(g[x][i], g[x].back());
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (q[h] > q[g[x][0]])
            swap(g[x][i], g[x][0]);
    }
}

int f[N];
int tin[N], tout[N], ti;
void dfs1(int x, int p)
{
    tin[x] = ++ti;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (i == 0)
        {
            f[h] = f[x];
            dfs1(h, x);
        }
        else
        {
            f[h] = h;
            dfs1(h, x);
        }
    }
    tout[x] = ti;
}

ll t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

ll qryy(int x, int y)
{
    ll ans = 0;
    while (1)
    {
        if (tin[x] < tin[y])
            swap(x, y);
        if (f[x] == f[y])
        {
            ans += qry(1, n, tin[y], tin[x], 1);
            return ans;
        }
        ans += qry(1, n, tin[f[x]], tin[x], 1);
        x = p0[f[x]];
    }
}

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1, 1);
    f[1] = 1;
    dfs1(1, 1);

    for (int x = 1; x <= n; ++x)
        ubd(1, n, tin[x], a[x], 1);

    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x, y;
            cin >> x >> y;
            a[x] = y;
            a[x] = abs(a[x]);
            ubd(1, n, tin[x], a[x], 1);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << qryy(x, y) * 2 - a[x] - a[y] << "\n";
        }
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
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}