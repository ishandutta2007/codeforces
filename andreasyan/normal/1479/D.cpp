#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnf(2106);
const int N = 600005, L = 21;
 
int n, qq;
int a[N];
vector<int> g[N];
ll u[N];
 
vector<int> v;
int p[N][L];
void dfs(int x, int p0)
{
    p[x][0] = p0;
    for (int i = 1; i < L; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
 
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs(h, x);
    }
    v.push_back(x);
}
 
int f[N], s[N];
 
bool isp(int x, int y)
{
    return (f[x] <= f[y] && f[y] <= s[x]);
}
 
int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = L - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}
 
ll t[N * L];
int z;
int ul[N * L], ur[N * L];
 
int ubd(int tl, int tr, int x, ll y, int pos)
{
    int ypos = ++z;
    ul[ypos] = ul[pos];
    ur[ypos] = ur[pos];
    if (tl == tr)
    {
        t[ypos] = (t[pos] ^ y);
        return ypos;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ul[ypos] = ubd(tl, m, x, y, ul[pos]);
    else
        ur[ypos] = ubd(m + 1, tr, x, y, ur[pos]);
    t[ypos] = (t[ul[ypos]] ^ t[ur[ypos]]);
    return ypos;
}
 
ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), ul[pos]) ^
            qry(m + 1, tr, max(m + 1, l), r, ur[pos]));
}
 
int qryf(int tl, int tr, int l, int r, int z, ll h, int posx, int posy)
{
    if (tl == l && tr == r)
    {
        ll hh = (t[posx] ^ t[posy]);
        if (a[z] <= r)
            hh ^= u[a[z]];
        if (hh == h)
            return -1;
        if (tl == tr)
            return tl;
 
        int m = (tl + tr) / 2;
        int u = qryf(tl, m, l, m, z, h, ul[posx], ul[posy]);
        if (u != -1)
            return u;
        return qryf(m + 1, tr, m + 1, r, z, (h ^ t[ul[posx]] ^ t[ul[posy]]), ur[posx], ur[posy]);
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        return qryf(tl, m, l, r, z, h, ul[posx], ul[posy]);
    if (l > m)
        return qryf(m + 1, tr, l, r, z, (h ^ t[ul[posx]] ^ t[ul[posy]]), ur[posx], ur[posy]);
    int u = qryf(tl, m, l, m, z, h, ul[posx], ul[posy]);
    if (u != -1)
        return u;
    return qryf(m + 1, tr, m + 1, r, z, (h ^ t[ul[posx]] ^ t[ul[posy]]), ur[posx], ur[posy]);
}
 
int root[N];
 
ll qryy(int x, int y, int z, int t)
{
    if (a[z] <= t)
        return (qry(1, n, 1, t, root[f[x]]) ^ u[a[z]] ^ qry(1, n, 1, t, root[f[y]]));
    return (qry(1, n, 1, t, root[f[x]]) ^ qry(1, n, 1, t, root[f[y]]));
}
 
void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        u[i] = rnd();
 
    v.push_back(-1);
    dfs(1, 1);
 
    for (int i = 1; i <= n * 2; ++i)
    {
        if (f[v[i]] == 0)
            f[v[i]] = i;
        else
            s[v[i]] = i;
    }
    for (int i = 1; i <= n * 2; ++i)
        root[i] = ubd(1, n, a[v[i]], u[a[v[i]]], root[i - 1]);
 
    while (qq--)
    {
        int x, y, l, r;
        scanf("%d%d%d%d", &x, &y, &l, &r);
        int z = lca(x, y);
 
        ll h = qryy(x, y, z, l - 1);
        printf("%d\n", qryf(1, n, l, r, z, h, root[f[x]], root[f[y]]));
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
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}