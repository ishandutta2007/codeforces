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

int n;
ll s;
vector<pair<int, int> > g[N];
vector<int> gty[N];

struct ban
{
    ll d;
    int q;
    ban()
    {
        d = 0;
        q = 0;
    }
};

bool operator<(const ban& a, const ban& b)
{
    ll ua = (a.d / 2 + a.d % 2) * a.q;
    ll ub = (b.d / 2 + b.d % 2) * b.q;
    return ua < ub;
}

ban a[N];
int tyx[N];

void dfs0(int x, int p)
{
    if (x == p)
        a[x].d = 0;
    if (sz(g[x]) == 1 && x != p)
        a[x].q = 1;
    else
        a[x].q = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        a[h].d = g[x][i].se;
        tyx[h] = gty[x][i];
        dfs0(h, x);
        a[x].q += a[h].q;
    }
}

void solv()
{
    scanf("%d%lld", &n, &s);
    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        gty[x].clear();
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z, ty;
        scanf("%d%d%d%d", &x, &y, &z, &ty);
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
        gty[x].push_back(ty);
        gty[y].push_back(ty);
    }
    dfs0(1, 1);
    priority_queue<ban> q[3];
    for (int x = 2; x <= n; ++x)
    {
        s -= a[x].d * a[x].q;
        q[tyx[x]].push(a[x]);
    }

    int ans = N * 100;
    int yans = 0;
    vector<ll> v;
    while (s < 0)
    {
        if (q[1].empty() || q[1].top().d == 0)
            break;
        ++yans;
        ban t = q[1].top();
        q[1].pop();
        s += (t.d / 2 + t.d % 2) * t.q;
        v.push_back((t.d / 2 + t.d % 2) * t.q);
        t.d /= 2;
        q[1].push(t);
    }
    while (s < 0)
    {
        if (q[2].empty() || q[2].top().d == 0)
            break;
        yans += 2;
        ban t = q[2].top();
        q[2].pop();
        s += (t.d / 2 + t.d % 2) * t.q;
        t.d /= 2;
        q[2].push(t);
    }
    if (s >= 0)
        ans = min(ans, yans);
    reverse(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        s -= v[i];
        --yans;
        while (s < 0)
        {
            if (q[2].empty() || q[2].top().d == 0)
                break;
            yans += 2;
            ban t = q[2].top();
            q[2].pop();
            s += (t.d / 2 + t.d % 2) * t.q;
            t.d /= 2;
            q[2].push(t);
        }
        if (s >= 0)
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}