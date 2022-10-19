#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int N = 200005, k = 20;

int n, m, q;

int pd[N];
int fin(int x)
{
    if (x == pd[x])
        return x;
    return pd[x] = fin(pd[x]);
}
void kpc(int x, int y)
{
    x = fin(x);
    y = fin(y);
    pd[x] = y;
}
vector<pair<int, int> > t[N];

int tin[N], tout[N], ti;
int p[N][k];
int maxu[N][k];
void dfs0(int x, int p0)
{
    tin[x] = ++ti;
    p[x][0] = p0;
    maxu[x][0] = 0;
    for (int i = 0; i < t[x].size(); ++i)
    {
        if (t[x][i].fi == p0)
            maxu[x][0] = t[x][i].se;
    }
    for (int i = 1; i < k; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
        maxu[x][i] = max(maxu[x][i - 1], maxu[p[x][i - 1]][i - 1]);
    }
    for (int i = 0; i < t[x].size(); ++i)
    {
        int h = t[x][i].fi;
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

int go(int x, int y)
{
    if (isp(x, y))
        return 0;
    int ans = 0;
    for (int i = k - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
        {
            ans = max(ans, maxu[x][i]);
            x = p[x][i];
        }
    }
    ans = max(ans, maxu[x][0]);
    return ans;
}

int u[N];
int tmax[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        tmax[pos] = u[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    tmax[pos] = max(tmax[pos * 2], tmax[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return tmax[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        pd[i] = i;
        t[i].clear();
    }
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (fin(x) != fin(y))
        {
            kpc(x, y);
            t[x].push_back(m_p(y, i));
            t[y].push_back(m_p(x, i));
        }
    }

    dfs0(1, 1);
    for (int i = 1; i < n; ++i)
        u[i] = max(go(i, i + 1), go(i + 1, i));
    bil(1, n - 1, 1);

    vector<int> anss;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        anss.push_back(qry(1, n - 1, l, r - 1, 1));
    }

    for (int i = 0; i < q; ++i)
        cout << anss[i] << ' ';
    cout << "\n";
}

int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}