#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ll;
vector < vector < pair < int, int > > > g;
int blocked_edge;
int n, m;
ll dp[5555];
ll dpcnt[5555];

int count(int v, int p)
{
    int res = 1;
    
    for (int i = 0; i < g[v].size(); i++)
    {
        if (g[v][i].first != p)
            res += count(g[v][i].first, v);
    }
    
    dpcnt[v] = res;
    
    return res;
}

ll res = 0;
ll res2 = 0;
void dfs1(int v, int p, int cnt)
{
   for (int i = 0; i < g[v].size(); i++)
   {
       if (g[v][i].first != p)
       {
           res += ll(g[v][i].second) * dpcnt[g[v][i].first];
           res2 += ll(g[v][i].second) * dpcnt[g[v][i].first] * (cnt - dpcnt[g[v][i].first]);
           dfs1(g[v][i].first, v, cnt);
       }
   }
}

ll dfs2(int v, int p, ll ww, ll cnt, bool first)
{
    
    if (!first)
        dp[v] = dp[p] + (ww * (cnt - 2ULL*dpcnt[v]));
    ll res = dp[v];
    for (int i = 0; i < g[v].size(); i++)
    {
        if (g[v][i].first != p)
        {
            res = min(res, dfs2(g[v][i].first, v, g[v][i].second, cnt, false));
        }
    }
    return res;
}
pair < int, int > edges[10005];
ll w[10005];
int main()
{
    scanf("%d", &n);
    m = n - 1;
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
        edges[i].first = a;
        edges[i].second = b;
        w[i] = c;
    }
    ll ans = 1ULL << 63;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        a = edges[i].first;
        b = edges[i].second;
        int cnt1 = count(a, b);
        int cnt2 = count(b, a);
        res = 0;
        res2 = 0;
        dfs1(a, b, cnt1);
        ll r1 = res2;
        dp[a] = res;
        res = 0;
        res2 = 0;
        dfs1(b, a, cnt2);
        ll r2 = res2;
        dp[b] = res;
        ll ans1 = dfs2(a, b, -1, cnt1, true);
        ll ans2 = dfs2(b, a, -1, cnt2, true);
        ll curr = cnt1*cnt2*w[i] + ans1*cnt2 + ans2 * cnt1 + r1 + r2;
        ans = min(ans, curr);        
    }
    
    printf("%I64d", ans);
}