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
const int N = 2003, INF = 1000000009;

struct edge
{
    int x, y;
    int f, c;
    int w;
    edge(){}
    edge(int x, int y, int f, int c, int w)
    {
        this->x = x;
        this->y = y;
        this->f = f;
        this->c = c;
        this->w = w;
    }
};

struct flow
{
    int n;
    int s, t;

    vector<edge> ev;
    vector<int> g[N];
    void add_edge(int x, int y, int z, int w)
    {
        g[x].push_back(sz(ev));
        ev.push_back(edge(x, y, 0, z, w));
        g[y].push_back(sz(ev));
        ev.push_back(edge(y, x, z, z, -w));
    }

    int d[N];
    int p[N];
    bool c[N];
    void spfa()
    {
        for (int x = 0; x <= n; ++x)
        {
            d[x] = INF;
            c[x] = false;
            p[x] = -1;
        }
        queue<int> q;
        d[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            c[x] = false;
            for (int i = 0; i < sz(g[x]); ++i)
            {
                int j = g[x][i];
                if (ev[j].f == ev[j].c)
                    continue;
                int h = ev[j].y;
                if (d[x] + ev[j].w < d[h])
                {
                    p[h] = j;
                    d[h] = d[x] + ev[j].w;
                    if (!c[h])
                    {
                        c[h] = true;
                        q.push(h);
                    }
                }
            }
        }
    }

    pair<int, int> go()
    {
        int ansf = 0;
        while (1)
        {
            spfa();
            if (d[t] == INF)
                break;
            int x = t;
            int minu = INF;
            while (p[x] != -1)
            {
                minu = min(minu, ev[p[x]].c - ev[p[x]].f);
                x = ev[p[x]].x;
            }
            x = t;
            while (p[x] != -1)
            {
                ev[p[x]].f += minu;
                ev[(p[x] ^ 1)].f -= minu;
                x = ev[p[x]].x;
            }
            ansf += minu;
        }
        int answ = 0;
        for (int i = 0; i < sz(ev); i += 2)
        {
            answ += ev[i].w * ev[i].f;
        }
        return m_p(ansf, answ);
    }
};

int n, r1, r2;
int a[N];
vector<vector<int> > g1, g2;
int q1, q2;
int k1[N], x1[N];
int k2[N], x2[N];

int p1[N], p2[N];
void dfs0(int x, int p, int p0[], vector<vector<int> >& g)
{
    p0[x] = p;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x, p0, g);
    }
}

int u1[N], u2[N];

bool c[N];
void dfs(int x, int p, int k, int u[], vector<vector<int> >& g)
{
    u[x] = k;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (c[h])
            continue;
        dfs(h, x, k, u, g);
    }
}

int kk1[N], kk2[N];

void solv()
{
    cin >> n >> r1 >> r2;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    g1.assign(n + 1, {});
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g1[x].push_back(y);
        g1[y].push_back(x);
    }
    g2.assign(n + 1, {});
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g2[x].push_back(y);
        g2[y].push_back(x);
    }
    cin >> q1;
    for (int i = 1; i <= q1; ++i)
        cin >> x1[i] >> k1[i];
    cin >> q2;
    for (int i = 1; i <= q2; ++i)
        cin >> x2[i] >> k2[i];

    dfs0(r1, r1, p1, g1);
    dfs0(r2, r2, p2, g2);

    for (int i = 1; i <= q1; ++i)
        c[x1[i]] = true;
    for (int i = 1; i <= q1; ++i)
        dfs(x1[i], p1[x1[i]], i, u1, g1);

    memset(c, false, sizeof c);
    for (int i = 1; i <= q2; ++i)
        c[x2[i]] = true;
    for (int i = 1; i <= q2; ++i)
        dfs(x2[i], p2[x2[i]], i, u2, g2);

    if (k1[u1[r1]] != k2[u2[r2]])
    {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= q1; ++i)
        kk1[i] = k1[i];
    for (int i = 1; i <= q2; ++i)
        kk2[i] = k2[i];
    for (int i = 1; i <= n; ++i)
    {
        if (u1[p1[i]] != u1[i])
            kk1[u1[p1[i]]] -= k1[u1[i]];
        if (u2[p2[i]] != u2[i])
            kk2[u2[p2[i]]] -= k2[u2[i]];
    }

    for (int i = 1; i <= q1; ++i)
    {
        if (kk1[i] < 0)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= q2; ++i)
    {
        if (kk2[i] < 0)
        {
            cout << "-1\n";
            return;
        }
    }

    flow F;
    for (int i = 1; i <= q1; ++i)
        F.add_edge(0, i, kk1[i], 0);
    for (int i = 1; i <= n; ++i)
        F.add_edge(u1[i], q1 + u2[i], 1, -a[i]);
    for (int i = 1; i <= q2; ++i)
        F.add_edge(q1 + i, q1 + q2 + 1, kk2[i], 0);

    F.n = q1 + q2 + 1;
    F.s = 0;
    F.t = q1 + q2 + 1;

    pair<int, int> ans = F.go();
    if (ans.fi == k1[u1[r1]])
        cout << -ans.se << "\n";
    else
        cout << "-1\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}