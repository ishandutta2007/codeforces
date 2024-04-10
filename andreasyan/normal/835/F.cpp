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
const int N = 200005;
const ll INF = 1000000009000000009;

int n;
vector<pair<int, int> > g[N];

bool c[N];
int pa[N];
int st, fi;
bool dfsc(int x, int p)
{
    c[x] = true;
    pa[x] = p;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        if (!c[h])
        {
            if (dfsc(h, x))
                return true;
        }
        else
        {
            st = h;
            fi = x;
            return true;
        }
    }
    return false;
}

vector<int> v;
vector<int> k;

ll ans;

ll d[N];
void dfs0(int x, int p)
{
    ll max1 = -INF, max2 = -INF;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        int dd = g[x][i].se;
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs0(h, x);
        d[x] = max(d[x], d[h] + dd);
        if (d[h] + dd >= max1)
        {
            max2 = max1;
            max1 = d[h] + dd;
        }
        else if (d[h] + dd >= max2)
            max2 = d[h] + dd;
    }
    ans = max(ans, max1 + max2);
    ans = max(ans, d[x]);
}

ll p[N], s[N];
ll p0[N], s0[N];

void solv()
{
    cin >> n;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));

        mp[m_p(x, y)] = mp[m_p(y, x)] = z;
    }

    assert(dfsc(1, 1));

    for (int x = fi; x != st; x = pa[x])
        v.push_back(x);
    v.push_back(st);

    for (int i = 0; i < sz(v); ++i)
        k.push_back(mp[m_p(v[i], v[(i + 1) % sz(v)])]);

    memset(c, false, sizeof c);
    for (int i = 0; i < sz(v); ++i)
        c[v[i]] = true;
    for (int i = 0; i < sz(v); ++i)
    {
        dfs0(v[i], v[i]);
    }

    p[0] = d[v[0]];
    ll u = d[v[0]];
    for (int i = 1; i < sz(v); ++i)
    {
        p[i] = p[i - 1];
        u += k[i - 1];
        p[i] = max(p[i], u + d[v[i]]);
        u = max(u, d[v[i]]);
    }

    s[sz(v) - 1] = d[v.back()];
    u = d[v.back()];
    for (int i = sz(v) - 2; i >= 0; --i)
    {
        s[i] = s[i + 1];
        u += k[i];
        s[i] = max(s[i], u + d[v[i]]);
        u = max(u, d[v[i]]);
    }

    p0[0] = d[v[0]];
    u = 0;
    for (int i = 1; i < sz(v); ++i)
    {
        u += k[i - 1];
        p0[i] = max(p0[i - 1], u + d[v[i]]);
    }

    s0[sz(v) - 1] = d[v.back()];
    u = 0;
    for (int i = sz(v) - 2; i >= 0; --i)
    {
        u += k[i];
        s0[i] = max(s0[i + 1], u + d[v[i]]);
    }

    ll yans = max(p[sz(v) - 1], ans);
    for (int i = 0; i < sz(v) - 1; ++i)
    {
        ll yyans = max(p[i], s[i + 1]);
        yyans = max(yyans, p0[i] + s0[i + 1] + k[sz(v) - 1]);
        yyans = max(yyans, ans);
        yans = min(yans, yyans);
    }

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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}