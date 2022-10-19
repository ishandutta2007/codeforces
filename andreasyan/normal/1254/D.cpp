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
const int N = 150005;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % 998244353;
        x = (x * 1LL * x) % 998244353;
        n /= 2;
    }
    return ans;
}

int n, qq;
vector<int> g[N];

int p0[N];
ll q[N];
void dfs0(int x, int p)
{
    p0[x] = p;
    q[x] = 1;
    int maxu = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
        maxu = max(maxu, (int)q[h]);
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (q[h] == maxu)
        {
            swap(g[x][i], g[x][0]);
            break;
        }
    }
}

int tin[N], tout[N], ti;
int f[N];
void dfs1(int x, int p)
{
    tin[x] = ++ti;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (i == 0)
            f[h] = f[x];
        else
            f[h] = h;
        dfs1(h, x);
    }
    tout[x] = ti;
}

ll y[N];

ll t[N * 4];
void ubd(int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

ll qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return t[pos] + qry(tl, m, x, pos * 2);
    return t[pos] + qry(m + 1, tr, x, pos * 2 + 1);
}

void solv()
{
    cin >> n >> qq;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int rn = ast(n, 998244353 - 2);

    dfs0(1, 1);
    f[1] = 1;
    dfs1(1, 1);

    ll ys = 0;
    while (qq--)
    {
        int ty;
        cin >> ty;

        if (ty == 2)
        {
            int v;
            cin >> v;

            ll ans = ys;
            ans -= y[v] * q[v];
            ans += y[v] * n;
            ans += qry(1, n, tin[v], 1);

            while (1)
            {
                v = f[v];
                if (v == 1)
                    break;
                ans -= y[p0[v]] * q[p0[v]];
                ans += y[p0[v]] * (n - q[v]);
                v = p0[v];
            }

            ans = (ans % 998244353);
            ans = (ans * rn) % 998244353;
            cout << ans << "\n";
        }
        else
        {
            int v, d;
            cin >> v >> d;

            ys += q[v] * d;
            y[v] += d;

            if ((v == 1 && n > 1) || (sz(g[v]) > 1))
            {
                ubd(1, n, tin[g[v][0]], tout[g[v][0]], -q[v] * d + (n - q[g[v][0]]) * d, 1);
            }
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
    {
        solv();
    }
    return 0;
}