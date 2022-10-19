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
const int N = 2003;
const ll INF = 1000000009000000009, M = 1000000007;

ll ast(ll x, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

int n, m, q;
vector<pair<int, int> > g[N];

ll ans;

ll d[N];
ll nd[N];

struct ban
{
    ll b, k;
    ban(){}
    ban(ll b, ll k)
    {
        this->b = b;
        this->k = k;
    }
    ll yat(ll x)
    {
        return b + k * x;
    }
};

bool operator<(const ban& t1, const ban& t2)
{
    if (t1.k < t2.k)
        return true;
    if (t1.k > t2.k)
        return false;
    return t1.b > t2.b;
}

double hat(const ban& t1, const ban& t2)
{
    return (t2.b - t1.b) / (double)(t1.k - t2.k);
}

void solv()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i)
    {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        g[x].push_back(m_p(y, d));
        g[y].push_back(m_p(x, d));
    }

    for (int x = 1; x <= n; ++x)
        d[x] = -INF;
    d[1] = 0;
    for (int ii = 1; ii <= m; ++ii)
    {
        for (int x = 1; x <= n; ++x)
            nd[x] = -INF;
        for (int x = 1; x <= n; ++x)
        {
            for (int i = 0; i < g[x].size(); ++i)
            {
                nd[g[x][i].fi] = max(nd[g[x][i].fi], d[x] + g[x][i].se);
            }
        }
        ll maxu = -INF;
        for (int x = 1; x <= n; ++x)
        {
            d[x] = nd[x];
            maxu = max(maxu, d[x]);
        }
        ans += maxu;
        ans %= M;
    }
    q -= m;

    vector<ban> s;
    for (int x = 1; x <= n; ++x)
    {
        ll maxu = -INF;
        for (int i = 0; i < g[x].size(); ++i)
            maxu = max(maxu, (ll)g[x][i].se);
        s.push_back(ban(d[x], maxu));
    }
    sort(all(s));
    vector<ban> t;
    vector<double> v;
    for (int i = 0; i < n; ++i)
    {
        if (i && s[i].k == s[i - 1].k)
            continue;
        while (t.size() >= 2 && v.back() >= hat(t.back(), s[i]))
        {
            t.pop_back();
            v.pop_back();
        }
        if (!t.empty())
            v.push_back(hat(s[i], t.back()));
        t.push_back(s[i]);
    }

    ll r2 = ast(2, M - 2);
    ll z = 1;
    for (int i = 0; i < t.size(); ++i)
    {
        ll u;
        if (i < t.size() - 1)
            u = v[i];
        else
            u = INF;
        u = min(u, (ll)q);
        if (z <= u)
        {
            ans += (t[i].yat(z) + t[i].yat(u)) % M * (u - z + 1) % M * r2 % M;
            ans %= M;
            z = u + 1;
        }
    }

    printf("%lld\n", ans);
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