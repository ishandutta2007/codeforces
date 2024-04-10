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
const int N = 200005, INF = 1000000009;

struct edge
{
    int x, y;
    int f, c;
    edge(){}
    edge(int x, int y, int f, int c)
    {
        this->x = x;
        this->y = y;
        this->f = f;
        this->c = c;
    }
};

struct flow
{
    int n;
    int s, t;

    vector<edge> ev;
    vector<int> g[N];
    void add_edge(int x, int y, int z)
    {
        g[x].push_back(sz(ev));
        ev.push_back(edge(x, y, 0, z));
        g[y].push_back(sz(ev));
        ev.push_back(edge(y, x, z, z));
    }

    void delete_edge(int x, int y)
    {
        ev.pop_back();
        g[y].pop_back();
        ev.pop_back();
        g[x].pop_back();
    }

    int d[N];
    void bfs()
    {
        for (int x = 0; x <= n; ++x)
        {
            d[x] = -1;
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < g[x].size(); ++i)
            {
                int j = g[x][i];
                if (ev[j].f == ev[j].c)
                    continue;
                int h = ev[j].y;
                if (d[h] == -1)
                {
                    d[h] = d[x] + 1;
                    q.push(h);
                }
            }
        }
    }

    int u[N];
    int dfs(int x, int minu)
    {
        if (minu == 0)
            return 0;
        if (x == t)
            return minu;

        for (; u[x] < g[x].size(); ++u[x])
        {
            int j = g[x][u[x]];
            if (ev[j].f == ev[j].c)
                continue;
            int h = ev[j].y;
            if (d[h] != d[x] + 1)
                continue;
            int pf = dfs(h, min(minu, ev[j].c - ev[j].f));
            if (pf)
            {
                ev[j].f += pf;
                ev[(j ^ 1)].f -= pf;
                return pf;
            }
        }
        return 0;
    }

    ll go()
    {
        ll ans = 0;
        while (1)
        {
            bfs();
            if (d[t] == -1)
                break;
            memset(u, 0, sizeof u);
            while (1)
            {
                int pans = dfs(s, INF);
                if (!pans)
                    break;
                ans += pans;
            }
        }
        return ans;
    }
};

int n, m;
int s[N];
int a[N];
pair<int, int> b[N];

vector<pair<int, int> > ans;

vector<int> g[N], gi[N];
bool c[N];
void dfs(int x)
{
    while (!g[x].empty())
    {
        int h = g[x].back();
        g[x].pop_back();
        int hi = gi[x].back();
        gi[x].pop_back();
        if (c[hi])
            continue;
        c[hi] = true;
        if (x && h)
            ans.push_back(m_p(x, h));
        dfs(h);
    }
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i].fi >> b[i].se;

    flow f;
    f.n = n + 1;
    f.s = 0;
    f.t = n + 1;
    for (int i = 1; i <= m; ++i)
    {
        f.add_edge(b[i].fi, b[i].se, 1);
        f.add_edge(b[i].se, b[i].fi, 1);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (s[i])
        {
            if (a[i] > 0)
                f.add_edge(i, f.t, a[i]);
            else if (a[i] < 0)
                f.add_edge(f.s, i, -a[i]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!s[i])
            f.add_edge(f.s, i, INF);
    }

    f.go();

    for (int i = n; i >= 1; --i)
    {
        if (!s[i])
            f.delete_edge(f.s, i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!s[i])
            f.add_edge(i, f.t, INF);
    }

    f.go();

    for (int i = 1; i <= m; ++i)
    {
        if (f.ev[(i - 1) * 4].f != f.ev[(i - 1) * 4 + 2].f)
        {
            if (f.ev[(i - 1) * 4].f)
            {
                ans.push_back(m_p(b[i].fi, b[i].se));
                ++a[b[i].fi];
                --a[b[i].se];
            }
            else
            {
                ans.push_back(m_p(b[i].se, b[i].fi));
                ++a[b[i].se];
                --a[b[i].fi];
            }
        }
        else
        {
            g[b[i].fi].push_back(b[i].se);
            gi[b[i].fi].push_back(i);
            g[b[i].se].push_back(b[i].fi);
            gi[b[i].se].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (s[i] && a[i])
        {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (sz(g[i]) % 2 == 1)
        {
            assert(!s[i]);
            ++m;
            g[0].push_back(i);
            gi[0].push_back(m);
            g[i].push_back(0);
            gi[i].push_back(m);
        }
    }

    for (int i = 0; i <= n; ++i)
    {
        dfs(i);
    }

    cout << "YES\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
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