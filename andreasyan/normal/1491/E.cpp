#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int f[30];

void pre()
{
    f[0] = f[1] = 1;
    for (int i = 2; i < 30; ++i)
        f[i] = f[i - 1] + f[i - 2];
}

int n;
vector<int> g[N];

bool c[N];
int q[N];
int p0[N];
void dfs(int x, int p)
{
    q[x] = 0;
    if (!c[x])
        return;
    q[x] = 1;
    p0[x] = p;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        q[x] += q[h];
    }
}

vector<int> v1;
void dfs1(int x, int p)
{
    if (!c[x])
        return;
    v1.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
    }
}

ll u[N];
unordered_map<ll, bool> mp;
bool stg(vector<int> v)
{
    if (sz(v) == 1)
        return true;

    ll h = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i];
        h ^= u[x];
    }
    if (mp.find(h) != mp.end())
        return mp[h];
    mp[h] = false;

    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i];
        c[x] = true;
    }

    dfs(v[0], v[0]);

    int k = -1;
    for (int i = 1; i < 30; ++i)
    {
        if (sz(v) == f[i])
        {
            k = i;
            break;
        }
    }

    vector<pair<vector<int>, vector<int> > > vv;
    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i];
        if (q[x] == f[k - 1] || q[x] == f[k - 2])
        {
            pair<vector<int>, vector<int> > t;
            v1.clear();
            dfs1(x, p0[x]);
            t.fi = v1;
            v1.clear();
            dfs1(p0[x], x);
            t.se = v1;
            vv.push_back(t);

            for (int i = 0; i < sz(v); ++i)
            {
                int x = v[i];
                c[x] = false;
            }
            if (stg(t.fi) && stg(t.se))
                return mp[h] = true;
            return mp[h];
        }
    }
    return mp[h];

    for (int i = 0; i < sz(vv); ++i)
    {
        if (stg(vv[i].fi) && stg(vv[i].se))
            return mp[h] = true;
    }
    return mp[h];
}

void solv()
{
    /*n = f[5];
    for (int i = 1; i < n; ++i)
    {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }*/

    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool z = false;
    for (int i = 1; i < 30; ++i)
    {
        if (n == f[i])
        {
            z = true;
            break;
        }
    }
    if (!z)
    {
        printf("NO\n");
        return;
    }

    for (int x = 1; x <= n; ++x)
        u[x] = rnd();
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    if (stg(v))
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}