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
#define int ll
const int N = 503;
const int INF = 1000000009000000009;

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
int x1[N], y1_[N], x2[N], y2[N];

vector<int> vx, vy;

bool c[N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> x1[i] >> y1_[i] >> x2[i] >> y2[i];

    vx.push_back(1);
    vy.push_back(1);
    for (int i = 1; i <= m; ++i)
    {
        vx.push_back(x1[i]);
        vx.push_back(x2[i] + 1);
        vy.push_back(y1_[i]);
        vy.push_back(y2[i] + 1);
    }
    vx.push_back(n + 1);
    vy.push_back(n + 1);

    sort(all(vx));
    sort(all(vy));

    vector<int> v;
    for (int i = 0; i < sz(vx); ++i)
    {
        if (!i || vx[i] != vx[i - 1])
            v.push_back(vx[i]);
    }
    vx = v;

    v.clear();
    for (int i = 0; i < sz(vy); ++i)
    {
        if (!i || vy[i] != vy[i - 1])
            v.push_back(vy[i]);
    }
    vy = v;

    for (int i = 1; i <= m; ++i)
    {
        int xx1 = lower_bound(all(vx), x1[i]) - vx.begin();
        int yy1 = lower_bound(all(vy), y1_[i]) - vy.begin();
        int xx2 = lower_bound(all(vx), x2[i] + 1) - vx.begin() - 1;
        int yy2 = lower_bound(all(vy), y2[i] + 1) - vy.begin() - 1;
        for (int x = xx1; x <= xx2; ++x)
        {
            for (int y = yy1; y <= yy2; ++y)
            {
                c[x][y] = true;
            }
        }
    }

    flow F;

    F.n = sz(vx) + sz(vy) + 5;

    F.s = 0;
    F.t = F.n;

    for (int x = 0; x < sz(vx) - 1; ++x)
        F.add_edge(F.s, x + 1, (vx[x + 1] - vx[x]));

    for (int x = 0; x < sz(vx) - 1; ++x)
    {
        for (int y = 0; y < sz(vy) - 1; ++y)
        {
            if (c[x][y])
                F.add_edge(x + 1, sz(vx) + y + 1, (vx[x + 1] - vx[x]) * (vy[y + 1] - vy[y]));
        }
    }

    for (int y = 0; y < sz(vy) - 1; ++y)
        F.add_edge(sz(vx) + y + 1, F.t, (vy[y + 1] - vy[y]));

    cout << F.go() << "\n";
}

int32_t main()
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