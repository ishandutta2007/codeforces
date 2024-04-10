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
const int N = 200005, m = 20;

int n;
vector<int> g[N];

int tin[N], tout[N], ti;
int rtin[N];
int p[N][m];
void dfs0(int x, int p0)
{
    tin[x] = ++ti;
    rtin[tin[x]] = x;
    p[x][0] = p0;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
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
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return x;
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    return p[go(x, y)][0];
}

int minu[N * 4];
void bil(int tl, int tr, int pos)
{
    minu[pos] = N;
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        minu[pos] = min(minu[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return N;
    if (tl == l && tr == r)
        return minu[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

vector<int> v[N];
int z;
int ul[N * m], ur[N * m];
int s[N * m];

int ubds(int tl, int tr, int x, int pos)
{
    int ypos = ++z;
    ul[ypos] = ul[pos];
    ur[ypos] = ur[pos];
    s[ypos] = s[pos];
    if (tl == tr)
    {
        s[ypos]++;
        return ypos;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ul[ypos] = ubds(tl, m, x, ul[pos]);
    else
        ur[ypos] = ubds(m + 1, tr, x, ur[pos]);

    s[ypos] = s[ul[ypos]] + s[ur[ypos]];
    return ypos;
}

int qrys(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return s[pos];
    int m = (tl + tr) / 2;
    return (qrys(tl, m, l, min(m, r), ul[pos]) +
            qrys(m + 1, tr, max(m + 1, l), r, ur[pos]));
}

int root[N];

int u[N][m];

void solv()
{
    cin >> n;
    for (int x = 2; x <= n; ++x)
    {
        int p;
        cin >> p;
        g[p].push_back(x);
    }

    dfs0(1, 1);

    bil(1, n, 1);
    int qq;
    cin >> qq;
    while (qq--)
    {
        int x, y;
        cin >> x >> y;
        int z = lca(x, y);

        ubd(1, n, tin[x], tin[z], 1);
        ubd(1, n, tin[y], tin[z], 1);

        if (tin[x] > tin[y])
            swap(x, y);
        v[tin[y]].push_back(tin[x]);
    }
    for (int i = 1; i <= n; ++i)
    {
        root[i] = root[i - 1];
        for (int j = 0; j < sz(v[i]); ++j)
            root[i] = ubds(1, n, v[i][j], root[i]);
    }

    for (int x = 1; x <= n; ++x)
    {
        u[x][0] = rtin[min(tin[x], qry(1, n, tin[x], tout[x], 1))];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < m; ++j)
            u[i][j] = u[u[i][j - 1]][j - 1];
    }

    cin >> qq;
    while (qq--)
    {
        int x, y;
        cin >> x >> y;

        if (isp(x, y))
            swap(x, y);

        int ans = 0;
        if (isp(y, x))
        {
            for (int i = m - 1; i >= 0; --i)
            {
                if (!isp(u[x][i], y))
                {
                    x = u[x][i];
                    ans += (1 << i);
                }
            }
            if (isp(u[x][0], y))
                ++ans;
            else
                ans = -1;
            cout << ans << "\n";
            continue;
        }

        for (int i = m - 1; i >= 0; --i)
        {
            if (!isp(u[x][i], y))
            {
                x = u[x][i];
                ans += (1 << i);
            }
        }
        for (int i = m - 1; i >= 0; --i)
        {
            if (!isp(u[y][i], x))
            {
                y = u[y][i];
                ans += (1 << i);
            }
        }

        if (!isp(u[x][0], y) || !isp(u[y][0], x))
            ans = -1;
        else
        {
            ans += 2;
            if (tin[x] > tin[y])
                swap(x, y);

            if (qrys(1, n, tin[x], tout[x], root[tout[y]]) - qrys(1, n, tin[x], tout[x], root[tin[y] - 1]) > 0)
                --ans;
        }

        cout << ans << "\n";
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