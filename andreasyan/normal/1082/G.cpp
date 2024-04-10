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
const int N = 2023, INF = 1000000009;

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

    int dfs(int x, int minu)
    {
        if (x == t)
            return minu;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int j = g[x][i];
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

    vector<int> v1;
    bool c[N];
    void dfs1(int x)
    {
        c[x] = true;
        v1.push_back(x);
        for (int i = 0; i < g[x].size(); ++i)
        {
            int j = g[x][i];
            int h = ev[j].y;
            if (ev[j].f != ev[j].c)
            {
                if (!c[h])
                    dfs1(h);
            }
        }
    }

    vector<int> ktr()
    {
        v1.clear();
        memset(c, false, sizeof c);
        dfs1(s);
        return v1;
    }
};

int n, m;
int a[N];
int x[N], y[N], z[N];

flow F;

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &x[i], &y[i], &z[i]);

    F.n = n + m + 1;
    F.s = 0;
    F.t = n + m + 1;

    for (int i = 1; i <= m; ++i)
    {
        F.add_edge(0, i, z[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        F.add_edge(i, m + x[i], INF);
        F.add_edge(i, m + y[i], INF);
    }
    for (int i = 1; i <= n; ++i)
    {
        F.add_edge(m + i, m + n + 1, a[i]);
    }

    F.go();

    ll ans = 0;

    vector<int> v = F.ktr();
    set<int> s;
    for (int i = 1; i < sz(v); ++i)
    {
        ans += z[v[i]];
        s.insert(x[v[i]]);
        s.insert(y[v[i]]);
    }

    for (auto it = s.begin(); it != s.end(); ++it)
        ans -= a[*it];

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}