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
const int N = 100025, INF = 1000000009;

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

const string ss[7] = {"", "S", "M", "L", "XL", "XXL", "XXXL"};
int n;

int q[7];

flow F;

void solv()
{
    for (int i = 1; i <= 6; ++i)
        scanf("%d", &q[i]);
    scanf("%d", &n);

    F.n = n + 6 + 1;
    F.s = 0;
    F.t = n + 6 + 1;

    map<string, int> mp;
    for (int i = 1; i <= 6; ++i)
        mp[ss[i]] = i;

    for (int x = 1; x <= n; ++x)
    {
        char s[20];
        scanf(" %s", s);
        int m = strlen(s);

        bool z = false;
        for (int i = 0; i < m; ++i)
        {
            if (s[i] == ',')
            {
                z = true;
                break;
            }
        }

        if (z)
        {
            for (int i = 0; i < m; ++i)
            {
                if (s[i] == ',')
                {
                    string s1, s2;
                    for (int j = 0; j < i; ++j)
                    {
                        s1 += s[j];
                    }
                    for (int j = i + 1; j < m; ++j)
                    {
                        s2 += s[j];
                    }
                    F.add_edge(x, n + mp[s1], 1);
                    F.add_edge(x, n + mp[s2], 1);
                    break;
                }
            }
        }
        else
        {
            string s1;
            for (int i = 0; i < m; ++i)
                s1 += s[i];
            F.add_edge(x, n + mp[s1], 1);
        }
    }

    for (int x = 1; x <= n; ++x)
        F.add_edge(F.s, x, 1);
    for (int i = 1; i <= 6; ++i)
        F.add_edge(n + i, F.t, q[i]);

    if (F.go() != n)
    {
        printf("NO\n");
        return;
    }

    printf("YES\n");
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < F.g[x].size(); ++i)
        {
            int j = F.g[x][i];
            int h = F.ev[j].y;
            if (h > n && F.ev[j].f == F.ev[j].c)
            {
                for (int k = 0; k < ss[h - n].size(); ++k)
                    putchar(ss[h - n][k]);
                putchar('\n');
                break;
            }
        }
    }
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