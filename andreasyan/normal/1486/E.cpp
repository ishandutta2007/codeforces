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
const int N = 100005, K = 55, INF = 1000000009;

int n, m;
vector<pair<int, int> > g[N];

struct ban
{
    int x, u, d;
    ban(){}
    ban(int x, int u, int d)
    {
        this->x = x;
        this->u = u;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban &b)
{
    return m_p(a.d, m_p(a.x, a.u)) < m_p(b.d, m_p(b.x, b.u));
}

int d[N][K];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < K; ++i)
            d[x][i] = INF;
    }

    set<ban> s;

    d[1][0] = 0;
    s.insert(ban(1, 0, 0));
    while (1)
    {
        ban t;
        if (s.empty())
        {
            for (int x = 1; x <= n; ++x)
            {
                if (d[x][0] == INF)
                    d[x][0] = -1;
            }
            for (int x = 1; x <= n; ++x)
                printf("%d ", d[x][0]);
            printf("\n");
            return;
        }
        t = *s.begin();
        s.erase(s.begin());
        if (t.u == 0)
        {
            for (int i = 0; i < g[t.x].size(); ++i)
            {
                ban h;
                h.x = g[t.x][i].fi;
                h.d = t.d + g[t.x][i].se * g[t.x][i].se;
                h.u = g[t.x][i].se;
                if (h.d < d[h.x][h.u])
                {
                    d[h.x][h.u] = h.d;
                    if (s.find(ban(h.x, h.u, d[h.x][h.u])) != s.end())
                        s.erase(ban(h.x, h.u, d[h.x][h.u]));
                    s.insert(h);
                }
            }
        }
        else
        {
            for (int i = 0; i < g[t.x].size(); ++i)
            {
                ban h;
                h.x = g[t.x][i].fi;
                h.d = t.d + g[t.x][i].se * g[t.x][i].se + 2 * t.u * g[t.x][i].se;
                h.u = 0;
                if (h.d < d[h.x][h.u])
                {
                    d[h.x][h.u] = h.d;
                    if (s.find(ban(h.x, h.u, d[h.x][h.u])) != s.end())
                        s.erase(ban(h.x, h.u, d[h.x][h.u]));
                    s.insert(h);
                }
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