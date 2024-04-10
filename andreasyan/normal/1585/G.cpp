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
const int N = 500015;

int n;
int p[N];
vector<int> g[N];

int tin[N], tout[N], ti;
int d[N];
int dd[N];
void dfs0(int x)
{
    tin[x] = ++ti;
    dd[x] = N;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        d[h] = d[x] + 1;
        dfs0(h);
        dd[x] = min(dd[x], dd[h] + 1);
    }
    if (dd[x] == N)
        dd[x] = 0;
    tout[x] = ti;
}

vector<int> v[N];
int pr[N];
int dp[N];
bool c[N];
vector<int> vv;
void dfs(int x)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
    }

    if (dd[x] == 0)
    {
        while (!vv.empty())
        {
            c[vv.back()] = false;
            vv.pop_back();
        }
        c[0] = true;
        vv.push_back(0);
        dp[x] = 1;
    }
    else
    {
        if (sz(g[x]) >= 2)
        {
            while (!vv.empty())
            {
                c[vv.back()] = false;
                vv.pop_back();
            }
            for (int i = 1; i <= dd[x] + 1; ++i)
            {
                assert(v[x].back() <= tout[x]);
                int u = (pr[v[d[x] + i].back()] ^
                         pr[v[d[x] + i][lower_bound(all(v[d[x] + i]), tin[x]) - v[d[x] + i].begin() - 1]]);
                vv.push_back(u);
                c[u] = true;
            }
            for (int i = 0; ; ++i)
            {
                if (!c[i])
                {
                    dp[x] = i;
                    break;
                }
            }
        }
        else
        {
            assert(sz(g[x]) == 1);
            c[dp[g[x][0]]] = true;
            vv.push_back(dp[g[x][0]]);
            for (int i = dp[g[x][0]]; ; ++i)
            {
                if (!c[i])
                {
                    dp[x] = i;
                    break;
                }
            }
        }
    }

    pr[tin[x]] = (pr[v[d[x]].back()] ^ dp[x]);
    v[d[x]].push_back(tin[x]);
}

void solv()
{
    cin >> n;

    ti = 0;
    for (int i = 0; i <= n + 5; ++i)
    {
        g[i].clear();

        v[i].clear();
        v[i].push_back(0);
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        g[p[i]].push_back(i);
    }

    dfs0(0);
    dfs(0);

    while (!vv.empty())
    {
        c[vv.back()] = false;
        vv.pop_back();
    }

    if (pr[v[1].back()])
        cout << "YES\n";
    else
        cout << "NO\n";
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