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
const int N = 1003, INF = 1000000009;

int n, m, k;

struct ban
{
    int x, d;
    ban(){}
    ban(int x, int d)
    {
        this->x = x;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

vector<ban> g[N];
pair<pair<int, int>, int> b[N];

int a[N][N];

int d0[N];
bool c[N];
void djk(int x)
{
    memset(c, false, sizeof c);
    priority_queue<ban> q;
    q.push(ban(x, 0));
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
                return;
            t = q.top();
            q.pop();
        } while (c[t.x]);
        c[t.x] = true;
        d0[t.x] = t.d;
        for (int i = 0; i < g[t.x].size(); ++i)
        {
            ban h = g[t.x][i];
            h.d += t.d;
            if (!c[h.x])
                q.push(h);
        }
    }
}

pair<int, int> u[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(ban(y, z));
        g[y].push_back(ban(x, z));
        b[i] = m_p(m_p(x, y), z);
    }
    for (int x = 1; x <= n; ++x)
    {
        djk(x);
        for (int y = 1; y <= n; ++y)
            a[x][y] = d0[y];
    }

    for (int i = 1; i <= k; ++i)
        scanf("%d%d", &u[i].fi, &u[i].se);
    int ans = INF;
    for (int i = 1; i <= m; ++i)
    {
        int x = b[i].fi.fi;
        int y = b[i].fi.se;
        int z = b[i].se;
        int yans = 0;
        for (int i = 1; i <= k; ++i)
        {
            yans += min(a[u[i].fi][u[i].se],
                        min(a[u[i].fi][x] + 0 + a[y][u[i].se],
                            a[u[i].se][x] + 0 + a[y][u[i].fi]));
        }
        ans = min(ans, yans);
    }
    printf("%d\n", ans);
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}