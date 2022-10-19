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
const int N = 500005;

int n;
int a[N];
int u[N];

pair<int, int> mer(const pair<int, int>& l, const pair<int, int>& r)
{
    if (l == m_p(-1, -1) || r == m_p(-1, -1))
        return m_p(-1, -1);
    if (l == m_p(0, 0))
        return r;
    if (r == m_p(0, 0))
        return l;

    if (l.fi <= l.se && l.se <= r.fi && r.fi <= r.se)
        return m_p(l.fi, r.se);
    if (l.fi >= l.se && l.se >= r.fi && r.fi >= r.se)
        return m_p(l.fi, r.se);

    return m_p(-1, -1);
}

pair<int, int> t[N * 4];

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

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int maxu[N * 4];
void ubdm(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubdm(tl, m, x, y, pos * 2);
    else
        ubdm(m + 1, tr, x, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

int qrym(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return maxu[pos];
    int m = (tl + tr) / 2;
    return max(qrym(tl, m, l, min(m, r), pos * 2),
               qrym(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int dp[N], ds[N];

bool rec(int l, int r, int ul, int ur)
{
    if (l > r)
        return true;

    int m = u[qrym(1, n, l, r, 1)];

    if (a[m] > ur)
    {
        pair<int, int> g = qry(1, n, l, m - 1, 1);
        g = mer(m_p(ul, ul), g);
        if (g != m_p(-1, -1) && g.fi <= g.se)
        {
            if (rec(m + 1, r, g.se, ur))
                return true;
        }
    }

    if (a[m] > ul)
    {
        pair<int, int> g = qry(1, n, m + 1, r, 1);
        g = mer(g, m_p(ur, ur));
        if (g != m_p(-1, -1) && g.fi >= g.se)
        {
            if (rec(l, m - 1, ul, g.fi))
                return true;
        }
    }

    return false;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> aa;
    for (int i = 1; i <= n; ++i)
        aa.push_back(a[i]);
    sort(all(aa));
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(all(aa), a[i]) - aa.begin() + 1;

    for (int i = 1; i <= n; ++i)
        u[a[i]] = i;

    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        maxu = max(maxu, a[i]);
        if (dp[i - 1] == -1)
        {
            dp[i] = -1;
            continue;
        }
        if (a[i] == maxu)
            dp[i] = dp[i - 1];
        else
        {
            if (dp[i - 1] < a[i])
                dp[i] = a[i];
            else
                dp[i] = -1;
        }
    }
    maxu = 0;
    for (int i = n; i >= 1; --i)
    {
        maxu = max(maxu, a[i]);
        if (ds[i + 1] == -1)
        {
            ds[i] = -1;
            continue;
        }
        if (a[i] == maxu)
            ds[i] = ds[i + 1];
        else
        {
            if (ds[i + 1] < a[i])
                ds[i] = a[i];
            else
                ds[i] = -1;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, i, a[i], 1);
        ubdm(1, n, i, a[i], 1);
    }

    int ans = 0;
    int L = u[n], R = u[n];
    ubd(1, n, u[n], 0, 1);
    ubdm(1, n, u[n], 0, 1);
    for (int i = n - 1; i >= 1; --i)
    {
        ubd(1, n, u[i], 0, 1);
        ubdm(1, n, u[i], 0, 1);
        if (L <= u[i] && u[i] <= R)
        {
            pair<int, int> gl = qry(1, n, L, u[i], 1);
            gl = mer(m_p(dp[L - 1], dp[L - 1]), gl);
            pair<int, int> gr = qry(1, n, u[i], R, 1);
            gr = mer(gr, m_p(ds[R + 1], ds[R + 1]));
            if (gl != m_p(-1, -1) && gl.fi <= gl.se)
            {
                if (gr != m_p(-1, -1) && gr.fi >= gr.se)
                {
                    ++ans;
                }
            }
            break;
        }

        if (u[i] < L)
        {
            pair<int, int> g = qry(1, n, L, R, 1);
            if (g != m_p(-1, -1) && g.fi >= g.se)
            {
                if (ds[R + 1] != -1)
                {
                    g = mer(g, m_p(ds[R + 1], ds[R + 1]));
                    if (g != m_p(-1, -1) && g.fi >= g.se)
                    {
                        if (dp[u[i] - 1] != -1)
                        {
                            if (rec(u[i] + 1, L - 1, dp[u[i] - 1], g.fi))
                                ++ans;
                        }
                    }
                }
            }
            L = u[i];
        }
        else
        {
            pair<int, int> g = qry(1, n, L, R, 1);
            if (g != m_p(-1, -1) && g.fi <= g.se)
            {
                if (dp[L - 1] != -1)
                {
                    g = mer(m_p(dp[L - 1], dp[L - 1]), g);
                    if (g != m_p(-1, -1) && g.fi <= g.se)
                    {
                        if (ds[u[i] + 1] != -1)
                        {
                            if (rec(R + 1, u[i] - 1, g.se, ds[u[i] + 1]))
                                ++ans;
                        }
                    }
                }
            }
            R = u[i];
        }
    }

    cout << ans << "\n";
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