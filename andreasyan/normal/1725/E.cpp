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
const int N = 200005, MM = 998244353;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int u[N];
void pre()
{
    u[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}

int n;
int a[N];
vector<int> g[N];

const int m = 20;
int p[N][m];
int tin[N], tout[N], ti;
int rtin[N];
int d[N];
void dfs0(int x, int p0)
{
    tin[x] = ++ti;
    rtin[ti] = x;
    if (x == p0)
        d[x] = 0;
    else
        d[x] = d[p0] + 1;
    p[x][0] = p0;
    for (int i = 1; i < m; ++i)
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
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

vector<int> v[N];

int nn;
vector<int> gg[N];
ll dp[N];
ll q[N];
void dfs1(int x, int k)
{
    q[x] = 0;
    if (a[x] % k == 0)
        q[x] = 1;
    dp[x] = 0;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        dfs1(h, k);
        dp[x] += (dp[h]);
        dp[x] += ((d[h] - d[x]) * q[h]);
        q[x] += q[h];
    }
}

ll ans;
void dfs2(int x, int p, int k)
{
    if (x != p)
        gg[x].push_back(p);
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        if (h == p)
            dp[h] += (d[x] - d[h]) * (nn - q[x]);
        else
            dp[h] += (d[h] - d[x]) * q[h];
    }

    ll s = 0;
    ll ss = 0;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        ll qh = q[h];
        if (h == p)
            qh = nn - q[x];
        ll a = 0;
        if (::a[x] % k == 0)
            a = (nn - qh - 1);
        a += s * (nn - s - !!(::a[x] % k == 0) - qh);
        a += ss;

        ans += (a * dp[h]);
        ans %= MM;

        ss += (qh * s);
        s += qh;
    }

    s = 0;
    ss = 0;
    reverse(all(gg[x]));
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        ll qh = q[h];
        if (h == p)
            qh = nn - q[x];

        ans += (ss * dp[h]);
        ans %= MM;

        ss += (qh * s);
        s += qh;
    }
    reverse(all(gg[x]));

    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        if (h == p)
            dp[h] -= (d[x] - d[h]) * (nn - q[x]);
        else
            dp[h] -= ((d[h] - d[x]) * q[h]);
    }
    if (x != p)
        gg[x].pop_back();

    if (x != p)
    {
        dp[x] += dp[p];
        dp[x] += ((d[x] - d[p]) * (nn - q[x]));
    }
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        dp[x] -= (dp[h]);
        dp[x] -= ((d[h] - d[x]) * q[h]);
        dfs2(h, x, k);
        dp[x] += (dp[h]);
        dp[x] += ((d[h] - d[x]) * q[h]);
    }
    if (x != p)
    {
        dp[x] -= dp[p];
        dp[x] -= ((d[x] - d[p]) * (nn - q[x]));
    }
}

ll solv()
{
    for (int i = 0; i < N; ++i)
    {
        g[i].clear();
        v[i].clear();
    }
    ti = 0;
    ans = 0;

    /*n = 100;
    for (int i = 1; i <= n; ++i)
        a[i] = rnd() % 10 + 1;
    for (int i = 2; i <= n; ++i)
    {
        int p = rnd() % (i - 1) + 1;
        g[p].push_back(i);
        g[i].push_back(p);
    }*/
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1, 1);

    for (int i = 1; i <= n; ++i)
    {
        vector<int> v;
        int x = a[i];
        while (x > 1)
        {
            if (v.empty() || v.back() != u[x])
                v.push_back(u[x]);
            x /= u[x];
        }
        for (int j = 0; j < sz(v); ++j)
            ::v[v[j]].push_back(i);
    }

    for (int i = 1; i < N; ++i)
    {
        if (v[i].empty())
            continue;

        vector<int> c;
        set<int> s;
        for (int j = 0; j < sz(v[i]); ++j)
        {
            s.insert(tin[v[i][j]]);
            c.push_back(v[i][j]);
        }
        while (sz(s) >= 2)
        {
            int x = *(--s.end());
            s.erase((--s.end()));
            int y = *(--s.end());
            //s.erase((--s.end()));
            x = rtin[x];
            y = rtin[y];
            int z = lca(x, y);
            assert(z != x);
            gg[z].push_back(x);
            s.insert(tin[z]);
            c.push_back(z);
        }

        int r = rtin[*s.begin()];
        dfs1(r, i);
        nn = q[r];
        dfs2(r, r, i);

        for (int i = 0; i < sz(c); ++i)
            gg[c[i]].clear();
    }

    cout << (ans % MM) << "\n";
    return ans;
}

vector<int> t;
bool dfst(int x, int p, int y)
{
    t.push_back(x);
    if (x == y)
        return true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (dfst(h, x, y))
            return true;
    }
    t.pop_back();
    return false;
}

int solv0()
{
    int ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = x + 1; y <= n; ++y)
        {
            for (int z = y + 1; z <= n; ++z)
            {
                set<int> s;
                t.clear();
                dfst(x, x, y);
                for (int i = 0; i < sz(t); ++i)
                    s.insert(t[i]);
                t.clear();
                dfst(x, x, z);
                for (int i = 0; i < sz(t); ++i)
                    s.insert(t[i]);

                int i = gcd(gcd(a[x], a[y]), a[z]);
                vector<int> v;
                while (i > 1)
                {
                    if (v.empty() || v.back() != u[i])
                        v.push_back(u[i]);
                    i /= u[i];
                }
                ans += sz(v) * (sz(s) - 1);
            }
        }
    }

    cout << ans << "\n";
    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    /*int st = 1000;
    while (st--)
    {
        if (solv() != solv0())
        {
            cout << "WA\n";
            cout << n << "\n";
            for (int i = 1; i <= n; ++i)
                cout << a[i] << ' ';
            cout << "\n";
            for (int x = 1; x <= n; ++x)
            {
                for (int i = 0; i < g[x].size(); ++i)
                {
                    int h = g[x][i];
                    if (x < h)
                        cout << x << ' ' << h << "\n";
                }
            }
            return 0;
        }
    }
    cout << "OK\n";
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
        //solv0();
    }
    return 0;
}