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

int n, q;
int a[N];
int u[N];

int ul[N], ur[N];

vector<int> b[N];

bool so(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.se < b.se)
        return true;
    if (a.se > b.se)
        return false;
    return a.fi > b.fi;
}

vector<pair<int, int> > g[N];
vector<pair<int, int> > gg[N];

ll sum[N * 4];
ll laz[N * 4];

ll sum0[N * 4];
ll laz0[N * 4];

void ave(ll sum[], ll laz[], int tl, int tr, int pos, ll y)
{
    sum[pos] += (tr - tl + 1) * y;
    laz[pos] += y;
}

void shi(ll sum[], ll laz[], int tl, int tr, int pos)
{
    if (!laz[pos])
        return;
    int m = (tl + tr) / 2;
    ave(sum, laz, tl, m, pos * 2, laz[pos]);
    ave(sum, laz, m + 1, tr, pos * 2 + 1, laz[pos]);
    laz[pos] = 0;
}

void ubd(ll sum[], ll laz[], int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        ave(sum, laz, tl, tr, pos, y);
        return;
    }
    shi(sum, laz, tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(sum, laz, tl, m, l, min(m, r), y, pos * 2);
    ubd(sum, laz, m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
}

ll qry(ll sum[], ll laz[], int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return sum[pos];
    shi(sum, laz, tl, tr, pos);
    int m = (tl + tr) / 2;
    return (qry(sum, laz, tl, m, l, min(m, r), pos * 2) +
            qry(sum, laz, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

ll ans[N * 10];

void solv()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        u[a[i]] = i;

    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();
        if (s.empty())
            ul[i] = 1;
        else
            ul[i] = s.top() + 1;
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();
        if (s.empty())
            ur[i] = n;
        else
            ur[i] = s.top() - 1;
        s.push(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            b[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        vector<pair<int, int> > v;
        for (int j = 0; j < b[a[i]].size(); ++j)
        {
            int x = b[a[i]][j];
            if (x * 1LL * x >= a[i])
                break;
            int y = a[i] / x;

            x = u[x];
            y = u[y];

            if (!(ul[i] <= x && x <= ur[i]))
                continue;
            if (!(ul[i] <= y && y <= ur[i]))
                continue;

            if (x > y)
                swap(x, y);
            y = max(y, i);
            x = min(x, i);

            v.push_back(m_p(x, y));
        }

        sort(all(v), so);

        vector<pair<int, int> > vv;
        int maxu = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            if (maxu >= v[i].fi)
                continue;
            vv.push_back(v[i]);
            maxu = v[i].fi;
        }
        v = vv;

        int ii = i;
        if (!v.empty())
            g[ur[ii] + 1].push_back(m_p(-v.back().fi, ul[ii]));
        for (int i = 0; i < sz(v); ++i)
        {
            if (i)
            {
                g[v[i].se].push_back(m_p(v[i].fi, v[i - 1].fi + 1));
            }
            else
            {
                g[v[i].se].push_back(m_p(v[i].fi, ul[ii]));
            }
        }
    }

    for (int i = 1; i <= q; ++i)
    {
        int l, r;
        cin >> l >> r;
        gg[r].push_back(m_p(l, i));
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < g[i].size(); ++j)
        {
            if (g[i][j].fi > 0)
            {
                ubd(sum, laz, 1, n, g[i][j].se, g[i][j].fi, -i + 1, 1);
                ubd(sum0, laz0, 1, n, g[i][j].se, g[i][j].fi, 1, 1);
            }
            else
            {
                g[i][j].fi *= -1;
                ubd(sum, laz, 1, n, g[i][j].se, g[i][j].fi, i - 1, 1);
                ubd(sum0, laz0, 1, n, g[i][j].se, g[i][j].fi, -1, 1);
            }
        }
        for (int j = 0; j < gg[i].size(); ++j)
        {
            ans[gg[i][j].se] = qry(sum0, laz0, 1, n, gg[i][j].fi, i, 1) * i + qry(sum, laz, 1, n, gg[i][j].fi, i, 1);
        }
    }

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
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