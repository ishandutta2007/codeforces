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
const int N = 603;
const ll INF = 1000000009000000009;

int n, m;
vector<pair<int, int> > g[N];
vector<int> gi[N];

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
    return a.d < b.d;
}

vector<ban> v[N];

ll d[N][N];

bool ans[N * N];
priority_queue<ban> q;
bool c[N];
int dd[N];
void djk(int y)
{
    while (!q.empty())
        q.pop();
    for (int x = 1; x <= n; ++x)
    {
        c[x] = false;
        dd[x] = -1;
    }
    for (int i = 0; i < v[y].size(); ++i)
        q.push(v[y][i]);

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
        if (t.d < 0)
            break;
        for (int i = 0; i < g[t.x].size(); ++i)
        {
            int h = g[t.x][i].fi;
            int hd = g[t.x][i].se;
            int hi = gi[t.x][i];
            if (t.d - hd - d[h][y] >= 0)
                ans[hi] = true;
            if (!c[h] && t.d - hd > dd[h])
            {
                dd[h] = t.d - hd;
                q.push(ban(h, t.d - hd));
            }
        }
    }
}

void solv()
{
    cin >> n >> m;

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            if (x == y)
                continue;
            d[x][y] = INF;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
        gi[x].push_back(i);
        gi[y].push_back(i);
        d[x][y] = d[y][x] = z;
    }

    for (int z = 1; z <= n; ++z)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                d[x][y] = min(d[x][y], d[x][z] + d[z][y]);
            }
        }
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[y].push_back(ban(x, z));
    }

    for (int y = 1; y <= n; ++y)
        djk(y);

    int yans = 0;
    for (int i = 0; i < m; ++i)
        yans += ans[i];

    cout << yans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}