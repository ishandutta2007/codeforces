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
const int N = 300005, INF = 1000000009;

int n;
vector<int> g[N];

int d[N];
int p0[N];
void dfs(int x, int p)
{
    p0[x] = p;
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
}

bool c[N];

int maxu[N];
void dfs1(int x, int p)
{
    maxu[x] = d[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (c[h])
            continue;
        dfs1(h, x);
        maxu[x] = max(maxu[x], maxu[h]);
    }
}

int s[N];
int t;
vector<int> v;
bool stg(int dd, int m)
{
    if (d[t] <= m)
        return true;

    int dx = dd + d[t] - m;
    if (dx > d[t])
        return false;

    int x = v[dx];

    return (s[m + 1] + dd + d[x] <= m);
}

void solv()
{
    cin >> n;

    for (int i = 0; i <= n + 1; ++i)
    {
        g[i].clear();
        c[i] = false;
        s[i] = -INF;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);

    t = 1;
    for (int x = 1; x <= n; ++x)
    {
        if (d[x] > d[t])
            t = x;
    }

    v.clear();
    {
        int x = t;
        while (x != 1)
        {
            v.push_back(x);
            x = p0[x];
        }
        v.push_back(x);
        reverse(all(v));
    }

    for (int i = 0; i < sz(v); ++i)
    {
        c[v[i]] = true;
    }

    for (int i = 0; i < sz(v); ++i)
    {
        dfs1(v[i], v[i]);
    }

    for (int i = 0; i < sz(v); ++i)
    {
        s[maxu[v[i]]] = max(s[maxu[v[i]]], maxu[v[i]] - 2 * d[v[i]]);
    }
    for (int i = n; i >= 1; --i)
        s[i] = max(s[i], s[i + 1]);

    for (int dd = 1; dd <= n; ++dd)
    {
        int l = 1, r = n;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (stg(dd, m))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << ans << ' ';
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}