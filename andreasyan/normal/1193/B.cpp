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
const int N = 100005;

int n, m, k;
vector<int> g[N];

int z;
ll t[N * 400];
int ul[N * 400], ur[N * 400];
int ubd(int tl, int tr, int l, int r, ll y, int pos)
{
    int ypos = ++z;
    ul[ypos] = ul[pos];
    ur[ypos] = ur[pos];
    t[ypos] = t[pos];
    if (tl == l && tr == r)
    {
        t[ypos] += y;
        return ypos;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        ul[ypos] = ubd(tl, m, l, r, y, ul[pos]);
    else if (l > m)
        ur[ypos] = ubd(m + 1, tr, l, r, y, ur[pos]);
    else
    {
        ul[ypos] = ubd(tl, m, l, m, y, ul[pos]);
        ur[ypos] = ubd(m + 1, tr, m + 1, r, y, ur[pos]);
    }
    return ypos;
}

ll qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return t[pos] + qry(tl, m, x, ul[pos]);
    return t[pos] + qry(m + 1, tr, x, ur[pos]);
}

int o[N], w[N];
int r[N];

set<int> s[N];

void dfs(int x)
{
    if (x == 4)
        cout << "";
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
        if (sz(s[x]) < sz(s[h]))
        {
            swap(s[x], s[h]);
            swap(r[x], r[h]);
        }
        for (auto it = s[h].begin(); it != s[h].end(); ++it)
        {
            auto it2 = it;
            ++it2;
            int u = k;
            if (it2 != s[h].end())
                u = *it2 - 1;

            r[x] = ubd(1, k, *it, u, qry(1, k, *it, r[h]), r[x]);
            s[x].insert(*it);
        }
    }
    if (o[x])
    {
        s[x].insert(o[x]);
        ll d = w[x] + qry(1, k, o[x], r[x]);
        bool z = false;
        while (o[x] <= k)
        {
            ll dd = qry(1, k, o[x], r[x]);
            if (d <= dd)
                break;

            if (z)
                s[x].erase(o[x]);

            auto it = s[x].upper_bound(o[x]);
            int u = k;
            if (it != s[x].end())
                u = *it - 1;

            r[x] = ubd(1, k, o[x], u, d - dd, r[x]);
            o[x] = u + 1;
            z = true;
        }
    }
}

void solv()
{
    cin >> n >> m >> k;
    for (int x = 2; x <= n; ++x)
    {
        int p = 1;
        cin >> p;
        g[p].push_back(x);
    }

    for (int i = 0; i < m; ++i)
    {
        int x = i + 2;
        int o = rnf() % k + 1;
        int w = 1;
        cin >> x >> o >> w;
        ::o[x] = o;
        ::w[x] = w;
    }

    dfs(1);

    cout << qry(1, k, k, r[1]) << "\n";
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