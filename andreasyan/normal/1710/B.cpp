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
const ll INF = 1000000009000000009;

int n, m;
int x[N], p[N];

ll ans[N];
void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> p[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = 0;
    }

    vector<pair<int, ll> > f;
    map<int, ll> ff;

    vector<pair<int, pair<int, int> > > v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(m_p(x[i], m_p(p[i], -1)));
        v.push_back(m_p(x[i] + p[i], m_p(0, 1)));
        v.push_back(m_p(x[i] - p[i], m_p(0, 0)));
    }

    sort(all(v));
    ll q = 0;
    int u = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        q += v[i].se.fi;
        u += v[i].se.se;

        if (i == sz(v) - 1 || v[i + 1].fi != v[i].fi)
        {
            ff[v[i].fi] += q;
        }

        if (i + 1 < sz(v))
        {
            q += (v[i + 1].fi - v[i].fi) * 1LL * u;
        }
    }

    v.clear();
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(m_p(x[i], m_p(p[i], -1)));
        v.push_back(m_p(x[i] - p[i], m_p(0, 1)));
        v.push_back(m_p(x[i] + p[i], m_p(0, 0)));
    }

    sort(all(v));
    q = 0;
    u = 0;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        q += v[i].se.fi;
        u += v[i].se.se;

        if (i == 0 || v[i - 1].fi != v[i].fi)
        {
            ff[v[i].fi] += q;
        }

        if (i - 1 >= 0)
        {
            q += (v[i].fi - v[i - 1].fi) * 1LL * u;
        }
    }

    for (int i = 1; i <= n; ++i)
        ff[x[i]] -= p[i];

    for (auto it = ff.begin(); it != ff.end(); ++it)
    {
        if (it->se > m)
            f.push_back(m_p(it->fi, it->se - m));
    }

    /*for (int i = 0; i < sz(f); ++i)
    {
        ll q = 0;
        for (int j = 1; j <= n; ++j)
        {
            q += max(0, p[j] - abs(f[i].fi - x[j]));
        }
        assert(q == m + f[i].se);
    }*/

    for (int i = 1; i <= n; ++i)
    {
        f.push_back(m_p(x[i], -i));
    }

    sort(all(f));
    ll maxu = -INF;
    for (int i = 0; i < sz(f); ++i)
    {
        if (f[i].se > 0)
        {
            maxu = max(maxu, f[i].se - f[i].fi);
        }
        else
        {
            ans[-f[i].se] = max(ans[-f[i].se], f[i].fi + maxu);
        }
    }

    maxu = -INF;
    for (int i = sz(f) - 1; i >= 0; --i)
    {
        if (f[i].se > 0)
        {
            maxu = max(maxu, f[i].se + f[i].fi);
        }
        else
        {
            ans[-f[i].se] = max(ans[-f[i].se], -f[i].fi + maxu);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (p[i] >= ans[i])
            cout << '1';
        else
            cout << '0';
    }
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}