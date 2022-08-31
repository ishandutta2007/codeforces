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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 5e5 + 7;
const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a < 0) a += M;
    if (a >= M) a -= M;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

void dfs(int v, vector <vector <int> > &g, vector <bool> &u)
{
    u[v] = true;
    for (int to : g[v])
    {
        if (!u[to])
        {
            dfs(to, g, u);
        }
    }
}

map <ll, vector <pair <int, int> > > res;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <ll> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ll x = (c[u] ^ c[v]);
        res[x].push_back({u, v});
    }
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = mul(ans, 2);
    }
    for (int i = 0; i < n; i++)
    {
        ans = mul(ans, 2);
    }
    vector <int> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = mul(pw[i - 1], 2);
    }
    for (auto c : res)
    {
        ans = add(ans, -pw[n]);
        vector <int> ret;
        for (auto d : c.second)
        {
            ret.push_back(d.first);
            ret.push_back(d.second);
        }
        sort(ret.begin(), ret.end());
        ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
        vector <vector <int> > g(ret.size());
        for (auto d : c.second)
        {
            int u = lower_bound(ret.begin(), ret.end(), d.first) - ret.begin();
            int v = lower_bound(ret.begin(), ret.end(), d.second) - ret.begin();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int m = n - (int) ret.size();
        vector <bool> u(ret.size());
        for (int i = 0; i < (int) ret.size(); i++)
        {
            if (!u[i])
            {
                dfs(i, g, u);
                m++;
            }
        }
        ans = add(ans, pw[m]);
    }
    cout << ans << '\n';
}