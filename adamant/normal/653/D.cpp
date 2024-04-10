#include <bits/stdc++.h>

using namespace std;

int n;
int ans;
int mx = 1 << 28;

const int maxn = 3e2 + 7;
vector<int> g[maxn];
int to[6 * maxn], cap[6 * maxn], dist[maxn], e[maxn];
int capi[6 * maxn];

void init()
{
    ans = 0;
    mx = 1LL << 25;
}

int dfs(int v = 0, int f = 2e9 + 9)
{
    if(f < mx)
        return 0;
    if(v == n - 1)
    {
        ans += f;
        return f;
    }
    for(; e[v] < g[v].size(); e[v]++)
    {
        int id = g[v][e[v]];
        int u = to[id];
        if(dist[u] != dist[v] + 1)
            continue;
        int k = dfs(u, min(f, cap[id]));
        if(k)
        {
            f = min(k, f);
            cap[id] -= f;
            cap[id ^ 1] += f;
            return f;
        }
    }
    return 0;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a, b, c;
    int m;
    cin >> m;
    int x;
    cin >> x;
    for(int i = 0; i < 2 * m; i += 2)
    {
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back(i);
        g[b].push_back(i + 1);
        to[i] = b;
        to[i + 1] = a;
        capi[i] = capi[i + 1] = c;
    }
    double l = 0, r = 1e6;
    for(int i = 0; i < 60; i++)
    {
        double mm = (l + r) / 2;
        for(int i = 0; i < 2 * m; i += 2)
        {
            cap[i] = min(1. * x, capi[i] / mm);
        }
        init();
        while(mx >>= 1)
        {
        bool ok = 1;
        while(ok)
        {
            ok = 0;
            int que[n];
            int st = 0, fi = 1;
            memset(dist, -1, n * sizeof(int));
            dist[0] = 0;
            que[0] = 0;
            while(st < fi)
            {
                int v = que[st++];
                for(auto it: g[v])
                {
                    if(cap[it] < mx)
                        continue;
                    int u = to[it];
                    if(dist[u] == -1)
                    {
                        dist[u] = dist[v] + 1;
                        que[fi++] = u;
                    }
                }
            }
            memset(e, 0, n * sizeof(int));
            while(dfs())
                ok = 1;
        }
        }
        if(ans >= x)
            l = mm;
        else
            r = mm;
    }
    cout << fixed << setprecision(7) << l * x << "\n";
    return 0;
}