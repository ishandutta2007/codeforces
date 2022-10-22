#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long li;

const int maxN = 100500;
const int logMaxN = 17;

vector<vector<int>> e;
int par[logMaxN][maxN];
vector<int> in, out, h;
int timer;

void dfs(int v)
{
    in[v] = timer++;
    for (int u: e[v])
    {
        par[0][u] = v;
        h[u] = h[v] + 1;
        dfs(u);
    }
    out[v] = timer++;
}

bool isPc(int p, int c)
{
    return in[c] >= in[p] && out[c] <= out[p];
}

int lca(int u, int v)
{
    if (isPc(u, v)) return u;
    if (isPc(v, u)) return v;
    
    for (int log = logMaxN - 1; log >= 0; log--)
        if (!isPc(par[log][u], v))
            u = par[log][u];
        
    return par[0][u];
}

int dist(int u, int v, int l = -1)
{
    if (isPc(u, v)) return h[v] - h[u];
    if (isPc(v, u)) return h[u] - h[v];
    
    if (l == -1)
        l = lca(u, v);
    
    return h[u] + h[v] - 2 * h[l];
}

int n;

int query(int a, int b, int c)
{
    int l1 = lca(a, b);
    int l2 = lca(b, c);
    int l3 = lca(a, c);
    
    if (a == b) return dist(b, c, l2) + 1;
    if (b == c) return dist(a, c, l3) + 1;
    if (a == c) return dist(a, b, l1) + 1;
    
    if (dist(a, b, l1) + dist(b, c, l2) == dist(a, c, l3)) return max(dist(a, b, l1), dist(b, c, l2)) + 1;
    if (dist(a, c, l3) + dist(c, b, l2) == dist(a, b, l1)) return max(dist(a, c, l3), dist(b, c, l2)) + 1;
    if (dist(b, a, l1) + dist(c, a, l3) == dist(b, c, l2)) return max(dist(b, a, l1), dist(c, a, l3)) + 1;
    
    vector<int> hs = { h[l1], h[l2], h[l3] };
    int i = max_element(all(hs)) - hs.begin();
    
    int lcas[3] = { l1, l2, l3 };
    int root = lcas[i];
    //printf("root %d\n", root + 1);
    
    return max ({ dist(root, a), dist(root, b), dist(root, c) }) + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> n >> q;
    e.resize(n);
    in.resize(n);
    out.resize(n);
    h.resize(n);
    
    par[0][0] = 0;
    
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        e[p].push_back(i);
    }
    
    dfs(0);
    
    for (int log = 1; log < logMaxN; log++)
        for (int i = 0; i < n; i++)
            par[log][i] = par[log - 1][par[log - 1][i]];
        
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        int ans = query(a, b, c);
        cout << ans << '\n';
    }
    
    return 0;
}