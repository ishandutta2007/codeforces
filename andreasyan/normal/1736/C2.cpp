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
int a[N];

int u[N];
vector<int> vu[N];

int q;
vector<pair<int, int> > v[N];

ll yans[N];

pair<ll, int> t[N * 4];
pair<ll, int> sum(const pair<ll, int>& l, const pair<ll, int>& r)
{
    return m_p(l.fi + r.fi, l.se + r.se);
}
void ubd(int tl, int tr, int x, pair<ll, int> y, int pos)
{
    if (tl == tr)
    {
        t[pos] = sum(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = sum(t[pos * 2], t[pos * 2 + 1]);
}
pair<ll, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return sum(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

const int m = 20;
int maxu[N][m];
int d[N];
void bil()
{
    for (int i = 1; i <= n; ++i)
    {
        maxu[i][0] = a[i];
        for (int j = 1; j < m; ++j)
        {
            if (i - (1 << (j - 1)) >= 1)
                maxu[i][j] = max(maxu[i][j - 1], maxu[i - (1 << (j - 1))][j - 1]);
            else
                break;
        }
        while ((1 << (d[i] + 1)) <= i)
            ++d[i];
    }
}
int qry(int l, int r)
{
    return max(maxu[r][d[r - l + 1]], maxu[l + (1 << d[r - l + 1]) - 1][d[r - l + 1]]);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        a[i] = i + 1 - a[i];
    }

    ll ans = 0;
    int j = 0;
    for (int i = 1; i <= n; ++i)
    {
        j = max(j, i - 1);
        while (j + 1 <= n && a[j + 1] <= i)
            ++j;
        ans += (j - i + 1);

        u[i] = j;
        vu[j + 1].push_back(i);
    }

    cin >> q;
    for (int j = 1; j <= q; ++j)
    {
        int i, x;
        cin >> i >> x;
        v[i].push_back(m_p(i + 1 - x, j));
    }

    bil();
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, i, m_p(u[i], 1), 1);
        for (int j = 0; j < sz(vu[i]); ++j)
            ubd(1, n, vu[i][j], m_p(-u[vu[i][j]], -1), 1);

        sort(all(v[i]));
        for (int j = 0; j < sz(v[i]); ++j)
        {
            yans[v[i][j].se] = ans;
            pair<ll, int> t = qry(1, n, 1, v[i][j].fi - 1, 1);
            yans[v[i][j].se] -= (t.fi - t.se * 1LL * (i - 1));
        }

        vector<ll> p;
        p.assign(sz(v[i]) + 1, 0);
        int k = -1;
        for (int j = 0; j < sz(vu[i]); ++j)
        {
            int l = i + 1, r = n;
            int nu = i;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (qry(i + 1, m) <= vu[i][j])
                {
                    nu = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            while (k + 1 < sz(v[i]) && v[i][k + 1].fi <= vu[i][j])
                ++k;
            if (k >= 0)
                p[k] += (nu - i + 1);
        }

        for (int j = sz(v[i]) - 1; j >= 0; --j)
        {
            p[j] += p[j + 1];
            yans[v[i][j].se] += p[j];
        }
    }

    for (int i = 1; i <= q; ++i)
        cout << yans[i] << "\n";
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