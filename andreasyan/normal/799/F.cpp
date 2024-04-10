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

int n, m;
int l[N], r[N];

int q[N * 4][2];
ll t[N * 4][2];

void shi(int pos)
{
    for (int z = 0; z < 2; ++z)
    {
        if (!q[pos][z])
        {
            q[pos * 2][z] = q[pos * 2 + 1][z] = 0;
            t[pos * 2][z] = t[pos * 2 + 1][z] = 0;
        }
    }
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        q[pos][tl % 2] = 1;
        t[pos][tl % 2] = tl - 1;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);

    for (int z = 0; z < 2; ++z)
    {
        q[pos][z] = q[pos * 2][z] + q[pos * 2 + 1][z];
        t[pos][z] = t[pos * 2][z] + t[pos * 2 + 1][z];
    }
}

void ubd(int tl, int tr, int l, int r, int z, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        q[pos][z] = 0;
        t[pos][z] = 0;
        return;
    }
    shi(pos);

    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), z, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, z, pos * 2 + 1);

    q[pos][z] = q[pos * 2][z] + q[pos * 2 + 1][z];
    t[pos][z] = t[pos * 2][z] + t[pos * 2 + 1][z];
}

pair<int, ll> qry(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
    {
        pair<int, ll> u = m_p(0, 0);
        for (int z = 0; z < 2; ++z)
        {
            if ((y & (1 << z)))
            {
                u.fi += q[pos][z];
                u.se += t[pos][z];
            }
        }
        return u;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    pair<int, ll> ul = qry(tl, m, l, min(m, r), y, pos * 2);
    pair<int, ll> ur = qry(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    return m_p(ul.fi + ur.fi, ul.se + ur.se);
}

vector<int> v[N];

int qd[N];
int minu[N], maxu[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    for (int i = 1; i <= n; ++i)
    {
        v[l[i]].push_back(i);
        v[r[i] + 1].push_back(-i);
    }

    multiset<int> s[2];
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (v[i][j] < 0)
            {
                v[i][j] *= -1;
                s[(l[v[i][j]] % 2)].erase(s[(l[v[i][j]] % 2)].find(l[v[i][j]]));
            }
            else
                s[(l[v[i][j]] % 2)].insert(l[v[i][j]]);
        }

        minu[i] = i + 1;
        if (!s[0].empty())
            minu[i] = *s[0].begin();
        if (!s[1].empty())
            minu[i] = min(minu[i], *s[1].begin());

        maxu[i] = 0;
        if (!s[1 - i % 2].empty())
            maxu[i] = *(--s[1 - i % 2].end());

        if (s[0].empty() && s[1].empty())
            qd[i] = qd[i - 1] + 1;
        else
            qd[i] = 0;
    }

    for (int i = 1; i <= m + 1; ++i)
        v[i].clear();
    for (int i = 1; i <= m; ++i)
        v[r[i]].push_back(i);

    bil(1, m, 1);

    ll ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            ubd(1, m, l[v[i][j]], i, 1 - i % 2, 1);
            if ((i - l[v[i][j]] + 1) % 2 == 0)
            {
                ubd(1, m, 1, l[v[i][j]], 0, 1);
                ubd(1, m, 1, l[v[i][j]], 1, 1);
            }
        }

        pair<int, ll> u = qry(1, m, maxu[i] + 1, minu[i] - 1, 3, 1);

        ans -= u.se;
        ans += u.fi * 1LL * i;

        minu[i] = max(minu[i], maxu[i] + 1);
        u = qry(1, m, minu[i], i, (1 << (i % 2)), 1);

        ans -= u.se;
        ans += u.fi * 1LL * i;

        ans -= qd[i] * 1LL * (qd[i] + 1) / 2;
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