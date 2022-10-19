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

int n;
vector<int> g[N];

ll ans[N];

int tin[N], tout[N], ti;
int p[N];
int q[N];
void dfs(int x, int p)
{
    tin[x] = ++ti;
    ::p[x] = p;
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        if (x)
            ans[0] += (q[x] * 1LL * q[h]);
        else
            ans[1] += (q[x] * 1LL * q[h]);
        q[x] += q[h];
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tin[y] <= tout[x]);
}

bool c[N];

ll tans[N];
set<int> s;
void dfs0(int x, int p)
{
    s.insert(x);
    if (sz(s) != 1)
    {
        for (int i = 0; ; ++i)
        {
            if (s.find(i) == s.end())
            {
                tans[i]++;
                break;
            }
        }
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
    }
    s.erase(x);
}

void solv()
{
    cin >> n;
    for (int x = 0; x <= n; ++x)
    {
        c[x] = false;
        ans[x] = 0;
        g[x].clear();
    }
    ti = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, 0);

    int x = 0, y = 0;
    int ux;

    int u = 1;
    while (1)
    {
        c[u] = true;
        ux = u;
        u = p[u];
        if (u == 0)
            break;
    }
    x = 1;
    c[0] = true;

    ans[1] -= (q[1] * 1LL * (n - q[ux]));

    int maxu = 0;
    for (int i = 0; i < n; ++i)
        maxu = max(maxu, sz(g[i]));
    if (maxu <= 2)
        ans[n] = 1;

    for (int i = 2; i < n; ++i)
    {
        int u = i - 1;
        if (!c[u])
        {
            if (y == 0)
            {
                if (isp(x, u))
                {
                    while (1)
                    {
                        c[u] = true;
                        u = p[u];
                        if (u == x)
                            break;
                    }
                    x = i - 1;
                }
                else if (!isp(ux, u))
                {
                    while (1)
                    {
                        c[u] = true;
                        u = p[u];
                        if (u == 0)
                            break;
                    }
                    y = i - 1;
                }
                else
                    break;
            }
            else
            {
                if (isp(x, u))
                {
                    while (1)
                    {
                        c[u] = true;
                        u = p[u];
                        if (u == x)
                            break;
                    }
                    x = i - 1;
                }
                else if (isp(y, u))
                {
                    while (1)
                    {
                        c[u] = true;
                        u = p[u];
                        if (u == y)
                            break;
                    }
                    y = i - 1;
                }
                else
                    break;
            }
        }

        if (c[i])
            continue;

        if (y == 0)
        {
            if (!isp(x, i) && isp(ux, i))
            {
                ans[i] = q[x] * 1LL * (n - q[ux]);
            }
            else if (isp(x, i))
            {
                ans[i] = (q[x] - q[i]) * 1LL * (n - q[ux]);
            }
            else if (!isp(ux, i))
            {
                ans[i] = q[x] * 1LL * (n - q[ux] - q[i]);
            }
            else
                assert(false);
        }
        else
        {
            if (!isp(x, i) && !isp(y, i))
            {
                ans[i] = q[x] * 1LL * q[y];
            }
            else if (isp(x, i))
            {
                ans[i] = (q[x] - q[i]) * 1LL * q[y];
            }
            else if (isp(y, i))
            {
                ans[i] = q[x] * 1LL * (q[y] - q[i]);
            }
            else
                assert(false);
        }
    }

    for (int i = 0; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
    return;

    for (int i = 0; i <= n; ++i)
        tans[i] = 0;
    for (int i = 0; i < n; ++i)
        dfs0(i, i);
    for (int i = 0; i <= n; ++i)
        cout << tans[i] << ' ';
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
        solv();
    return 0;
}