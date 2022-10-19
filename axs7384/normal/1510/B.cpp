#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10;

int d, n, u, v, a[N];
char s[N];
vector<int> g[N];
int lnk[N], r[N]; bool vis[N];
bool dfs (int u)
{
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (lnk[v] == u || vis[lnk[v]]) continue;
        if (lnk[v] && !dfs (lnk[v])) continue;
        lnk[v] = u;
        return 1;
    }
    return 0;
}
int cnt; vector<int> ans;
inline void sc(int x)
{
    for (int o = 0; o < d; o++) if (x & (1 << o)) ans.push_back (o);
}
set<int> se;
void solve (int u)
{
    //printf ("? %d %d %d\n", u, a[u], r[u]);
    se.insert (u);
    if (!lnk[u])
    {
        sc (a[u]);
        return ;
    }
    else
    {
        sc (a[u] ^ a[lnk[u]]);
        solve (lnk[u]);
        return ;
    }
}

bool cmp (int x, int y) {return __builtin_popcount(x) > __builtin_popcount(y);}

int main()
{
    scanf ("%d %d", &d, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%s", s + 1);
        for (int j = d; j >= 1; j--)
        {
            a[i] = a[i] * 2 + s[j] - '0';
        }
    }
    sort (a + 1, a + 1 + n, cmp);
    //for (int i = 1; i <= n; i++) printf ("%d ", a[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == a[j]) continue;
            if ((a[i] & a[j]) == a[i]) g[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        fill_n (vis + 1, n + 1, 0);
        dfs (i);
    }
    for (int i = 1; i <= n; i++) if (lnk[i]) r[lnk[i]] = i;
    for (int i = 1; i <= n; i++)
    {
        if (se.find(i) != se.end()) continue;
        if (i != 1)
            ans.push_back (-1);
        solve (i);
    }
    printf ("%d\n", (int) ans.size());
    reverse (ans.begin(), ans.end());
    for (auto it : ans)
    {
        if (it == -1) printf ("R ");
        else printf ("%d ", it);
    }
    return 0;
}