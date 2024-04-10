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

int n, m, k;
vector<ban> g[N];

ll d[N];
bool c[N];
void djk(priority_queue<ban>& q)
{
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
            if (!c[h.x])
                q.push(h);
        }
    }
}

struct bant
{
    ll k, b;
    bant()
    {
        b = INF;
        k = 0;
    }
    bant(ll k, ll b)
    {
        this->k = k;
        this->b = b;
    }
    ll yat(ll x)
    {
        return k * x + b;
    }
};

bant t[N * 4];

void ubd(int tl, int tr, bant u, int pos)
{
    int m = (tl + tr) / 2;
    if (u.yat(m) < t[pos].yat(m))
        swap(u, t[pos]);
    if (tl == tr)
        return;
    if (u.yat(tl) < t[pos].yat(tl))
        ubd(tl, m, u, pos * 2);
    else
        ubd(m + 1, tr, u, pos * 2 + 1);
}

ll qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos].yat(x);
    int m = (tl + tr) / 2;
    if (x <= m)
        return min(qry(tl, m, x, pos * 2), t[pos].yat(x));
    return min(qry(m + 1, tr, x, pos * 2 + 1), t[pos].yat(x));
}

void solv()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(ban(y, z));
        g[y].push_back(ban(x, z));
    }

    for (int x = 1; x <= n; ++x)
        d[x] = INF;
    d[1] = 0;

    for (int ii = 0; ii <= k; ++ii)
    {
        priority_queue<ban> q;
        for (int x = 1; x <= n; ++x)
            c[x] = false;
        for (int x = 1; x <= n; ++x)
            q.push(ban(x, d[x]));
        djk(q);

        if (ii == k)
            break;

        for (int x = 1; x <= n; ++x)
        {
            ubd(1, n, bant(-2 * x, d[x] + x * 1LL * x), 1);
        }

        for (int x = 1; x <= n; ++x)
        {
            d[x] = x * 1LL * x + qry(1, n, x, 1);
        }
    }

    for (int x = 1; x <= n; ++x)
        cout << d[x] << ' ';
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