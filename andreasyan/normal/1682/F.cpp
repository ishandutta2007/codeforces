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
const int N = 200005, M = 1000000007;

int n, qq;
int a[N];
int b[N];

ll p[N];

int l0[N], r0[N];

pair<int, int> mer(const pair<int, int>& l, const pair<int, int>& r)
{
    return m_p((l.fi + r.fi) % M, (l.se + r.se) % M);
}
pair<int, int> t[N * 4];

void ubd(int tl, int tr, int x, pair<int, int> y, int pos)
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

int ans[N];

void solv()
{
    cin >> n >> qq;

    for (int i = 1; i <= n; ++i)
        a[i] = rnf() % 1000000000;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        while (1)
        {
            b[i] = rnf() % 1000000000;
            if (b[i])
                break;
        }
        if (rnf() % 2)
            b[i] *= -1;
    }

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + b[i];

    vector<pair<ll, int> > v;
    for (int i = 0; i <= n; ++i)
    {
        v.push_back(m_p(p[i], -i));
    }

    for (int i = 1; i <= qq; ++i)
    {
        cin >> l0[i] >> r0[i];

        /*int ans = 0;
        ll s = 0;
        int l = l0[i];
        int r = r0[i];
        for (int i = l; i < r; ++i)
        {
            s += b[i];
            ans = (ans + (abs(s) % M) * (a[i + 1] - a[i])) % M;
        }
        ans = (ans + M) % M;
        cout << ans << "\n";*/

        v.push_back(m_p(p[l0[i] - 1], i));
    }
    cout << endl;

    for (int i = 0; i <= n; ++i)
    {
        ubd(0, n, i, m_p(((p[i] % M) * (a[i + 1] - a[i])) % M, -(a[i + 1] - a[i])), 1);
    }

    sort(all(v));
    for (int ii = 0; ii < sz(v); ++ii)
    {
        int i = v[ii].se;
        if (i <= 0)
        {
            i *= -1;
            ubd(0, n, i, m_p(((p[i] % M) * -(a[i + 1] - a[i])) % M, (a[i + 1] - a[i])), 1);
        }
        else
        {
            pair<int, int> u = qry(0, n, l0[i], r0[i] - 1, 1);
            ans[i] = (u.fi + u.se * 1LL * (p[l0[i] - 1] % M)) % M;
        }
    }

    for (int i = 1; i <= qq; ++i)
    {
        ans[i] = (ans[i] + M) % M;
        cout << ans[i] << "\n";
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