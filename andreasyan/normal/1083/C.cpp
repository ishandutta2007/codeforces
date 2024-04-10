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

int n;
int p[N];

vector<int> g[N];

int d[N];
vector<int> v;
void dfs0(int x)
{
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        d[h] = d[x] + 1;
        dfs0(h);
        v.push_back(x);
    }
}

int f[N];

const int m = 20;
int minu[N * 2][m];
int uu[N * 2];

int qry(int l, int r)
{
    if (l > r)
        swap(l, r);
    return min(minu[r][uu[r - l + 1]], minu[l + (1 << uu[r - l + 1]) - 1][uu[r - l + 1]]);
}

int dist(int x, int y)
{
    return d[x] + d[y] - 2 * qry(f[x], f[y]);
}

void pre()
{
    dfs0(1);

    for (int i = sz(v) - 1; i >= 0; --i)
    {
        f[v[i]] = i;
    }

    for (int i = 0; i < sz(v); ++i)
    {
        minu[i][0] = d[v[i]];
        for (int j = 1; i - (1 << j) + 1 >= 0; ++j)
            minu[i][j] = min(minu[i][j - 1], minu[i - (1 << (j - 1))][j - 1]);
    }

    for (int i = 1; i <= sz(v); ++i)
    {
        while ((1 << (uu[i] + 1)) <= i)
            ++uu[i];
    }
}

pair<int, int> t[N * 4];

int vv[4];
pair<int, int> mer(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a == m_p(0, 0) || b == m_p(0, 0))
        return m_p(0, 0);

    vv[0] = a.fi;
    vv[1] = a.se;
    vv[2] = b.fi;
    vv[3] = b.se;

    int maxu = -1;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            maxu = max(maxu, dist(vv[i], vv[j]));
        }
    }

    pair<int, int> ans;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            if (maxu == dist(vv[i], vv[j]))
            {
                ans = m_p(vv[i], vv[j]);
            }
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (dist(ans.fi, ans.se) != dist(ans.fi, vv[i]) + dist(vv[i], ans.se))
        {
            ans = m_p(0, 0);
            break;
        }
    }

    return ans;
}

int s[N];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = m_p(s[tl], s[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = m_p(y, y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, pair<int, int> u, int pos)
{
    if (tl == tr)
    {
        if (mer(u, t[pos]) == m_p(0, 0))
            return tl;
        return tl + 1;
    }
    int m = (tl + tr) / 2;
    if (mer(u, t[pos * 2]) != m_p(0, 0))
        return qry(m + 1, tr, mer(u, t[pos * 2]), pos * 2 + 1);
    return qry(tl, m, u, pos * 2);
}

void solv()
{
    cin >> n;
    for (int x = 1; x <= n; ++x)
        cin >> p[x];

    for (int x = 2; x <= n; ++x)
    {
        int p;
        cin >> p;
        g[p].push_back(x);
    }

    pre();

    for (int x = 1; x <= n; ++x)
        s[p[x]] = x;
    bil(0, n - 1, 1);

    int qq;
    cin >> qq;
    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x, y;
            cin >> x >> y;
            swap(p[x], p[y]);
            s[p[x]] = x;
            s[p[y]] = y;

            ubd(0, n - 1, p[x], x, 1);
            ubd(0, n - 1, p[y], y, 1);
        }
        else
        {
            cout << qry(0, n - 1, m_p(s[0], s[0]), 1) << "\n";
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