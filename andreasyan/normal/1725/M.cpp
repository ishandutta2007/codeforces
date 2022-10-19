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
const int N = 100005;
const ll INF = 1000000009000000009;

struct ban
{
    int x;
    ll d;
    ban(){}
    ban(int x, ll d)
    {
        this->x = x;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

int n, m;
vector<ban> g[N], rg[N];

bool c[N];
ll d[N];
priority_queue<ban> q;

void djk(vector<ban> g[])
{
    for (int i = 1; i <= n; ++i)
    {
        d[i] = INF;
        c[i] = false;
    }
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
        d[t.x] = t.d;
        for (int i = 0; i < g[t.x].size(); ++i)
        {
            ban h = g[t.x][i];
            h.d += t.d;
            q.push(h);
        }
    }
}

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(ban(y, z));
        rg[y].push_back(ban(x, z));
    }

    q.push(ban(1, 0));
    djk(g);

    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            q.push(ban(x, d[x]));
    }
    djk(rg);

    for (int x = 2; x <= n; ++x)
    {
        if (c[x])
            cout << d[x] << ' ';
        else
            cout << "-1 ";
    }
    cout << "\n";
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