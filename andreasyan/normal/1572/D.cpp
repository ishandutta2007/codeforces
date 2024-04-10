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

int n, k;
int a[(1 << 21)];

int z;
int mp[(1 << 21)];
int t[(1 << 21)];

void solv()
{
    cin >> n >> k;
    for (int x = 0; x < (1 << n); ++x)
    {
        cin >> a[x];
    }

    flow F;

    for (int i = n - 1; i >= 0; --i)
    {
        vector<pair<int, pair<int, int> > > v;
        for (int x = 0; x < (1 << n); ++x)
        {
            if ((x & (1 << i)) == 0)
            {
                int q = 0;
                for (int j = 0; j < n; ++j)
                {
                    if ((x & (1 << j)))
                        ++q;
                }
                if (q % 2 == 0)
                    v.push_back(m_p(a[x] + a[(x ^ (1 << i))], m_p(x, (x ^ (1 << i)))));
                else
                    v.push_back(m_p(a[x] + a[(x ^ (1 << i))], m_p((x ^ (1 << i)), x)));
            }
        }
        sort(all(v));
        reverse(all(v));

        for (int i = 0; i < min(sz(v), k); ++i)
        {
            if (!mp[v[i].se.fi])
            {
                mp[v[i].se.fi] = ++z;
                t[z] = 1;
            }
            if (!mp[v[i].se.se])
            {
                mp[v[i].se.se] = ++z;
                t[z] = -1;
            }

            F.add_edge(mp[v[i].se.fi], mp[v[i].se.se], 1, -v[i].fi);
        }
    }

    for (int i = 1; i <= z; ++i)
    {
        if (t[i] == 1)
            F.add_edge(z + 1, i, 1, 0);
        else
            F.add_edge(i, z + 2, 1, 0);
    }
    F.add_edge(0, z + 1, k, 0);

    F.n = z + 2;
    F.s = 0;
    F.t = z + 2;

    cout << -F.go().se << "\n";
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