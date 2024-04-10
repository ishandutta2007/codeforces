#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 7;

vector <int> g[N];
int cnt[N];
bool u[N];
int tin[N];
int par[N];
int add[N];

int sz = 0;

void dfs(int v, int pr)
{
    tin[v] = sz++;
    par[v] = pr;
    u[v] = true;
    for (int to : g[v])
    {
        if (!u[to])
        {
            dfs(to, v);
        }
    }
}

void zhfs(int v)
{
    for (int to : g[v])
    {
        if (par[to] == v)
        {
            zhfs(to);
            cnt[v] += cnt[to];
        }
    }
    if (cnt[v] != 1)
    {
        add[v]++;
    }
}

void up_zhfs(int v)
{
    for (int to : g[v])
    {
        if (par[to] == v)
        {
            add[to] += add[v];
            up_zhfs(to);
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int> > e;
    map <pair <int, int>, int> ind;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ind[{u, v}] = ind[{v, u}] = i;
        e.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> roots;
    for (int i = 0; i < n; i++)
    {
        if (!u[i])
        {
            roots.push_back(i);
            dfs(i, -1);
        }
    }
    for (auto c : e)
    {
        int u = c.first, v = c.second;
        if (par[u] != v && par[v] != u)
        {
            if (tin[u] > tin[v])
            {
                swap(u, v);
            }
            cnt[v]++;
            cnt[u]--;
        }
    }
    for (int v : roots)
    {
        zhfs(v);
    }
    for (int v : roots)
    {
        up_zhfs(v);
    }
    vector <int> ans;
    for (auto c : e)
    {
        int u = c.first, v = c.second;
        if (par[u] != v && par[v] != u)
        {
            if (tin[u] > tin[v])
            {
                swap(u, v);
            }
            if (add[v] == add[u])
            {
                ans.push_back(ind[{u, v}]);
                int cur = v;
                while (cur != u)
                {
                    ans.push_back({ind[{par[cur], cur}]});
                    cur = par[cur];
                }
            }
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i + 1 << ' ';
    }
    cout << '\n';
}