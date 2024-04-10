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
const int N = 10004, INF = 1000000009;

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

int n;
int a[N];
int b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    flow f;
    f.n = n + 1;
    f.s = 0;
    f.t = n + 1;

    for (int i = 1; i <= n; ++i)
    {
        if (b[i] > 0)
            f.add_edge(f.s, i, b[i]);
        else
            f.add_edge(i, f.t, -b[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int d = 1; d <= a[i]; ++d)
        {
            if (a[i] % d == 0)
            {
                for (int j = i - 1; j >= 1; --j)
                {
                    if (a[j] == d)
                    {
                        f.add_edge(i, j, INF);
                        break;
                    }
                }
            }
        }
    }

    ll ans = f.go();
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] > 0)
            ans -= b[i];
    }

    cout << -ans << "\n";
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