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
const int N = 1000006;

int n, qq;
int a[N];
int p[N];
vector<int> g[N];

int ans[N];

struct ban
{
    int l, k, i;
};

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (x == 0)
        return;
    if (tl == tr)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int k;
int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return -1;
    if (tl == l && tr == r)
    {
        if (t[pos] < k)
        {
            k -= t[pos];
            return -1;
        }
    }
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    int u = qry(tl, m, l, min(m, r), pos * 2);
    if (u != -1)
        return u;
    return qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

vector<ban> v[N];
set<int> s[N];

int q[N];
void dfs(int x)
{
    if (q[a[x]])
        s[q[a[x]]].erase(a[x]);
    ubd(1, n, q[a[x]], -1, 1);
    ++q[a[x]];
    ubd(1, n, q[a[x]], 1, 1);
    if (q[a[x]])
        s[q[a[x]]].insert(a[x]);

    for (int i = 0; i < v[x].size(); ++i)
    {
        k = v[x][i].k;
        int u = qry(1, n, v[x][i].l, n, 1);
        if (u == -1)
            ans[v[x][i].i] = -1;
        else
            ans[v[x][i].i] = *s[u].begin();
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
    }

    if (q[a[x]])
        s[q[a[x]]].erase(a[x]);
    ubd(1, n, q[a[x]], -1, 1);
    --q[a[x]];
    ubd(1, n, q[a[x]], 1, 1);
    if (q[a[x]])
        s[q[a[x]]].insert(a[x]);
}

void solv()
{
    cin >> n >> qq;

    for (int i = 1; i <= n; ++i)
    {
        v[i].clear();
        g[i].clear();
    }

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i <= n; ++i)
    {
        cin >> p[i];
        g[p[i]].push_back(i);
    }

    for (int i = 1; i <= qq; ++i)
    {
        int x;
        ban t;
        cin >> x >> t.l >> t.k;
        t.i = i;

        v[x].push_back(t);
    }

    dfs(1);

    for (int i = 1; i <= qq; ++i)
        cout << ans[i] << ' ';
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