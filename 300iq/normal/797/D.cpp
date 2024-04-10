#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

int val[N];
int l[N], r[N];
int par[N];
bool vis[N];
int cnt;
set <int> s;

void dfs(int v, int mx_l, int mn_r)
{
    if (v == -1)
    {
        return;
    }
    vis[v] = true;
    if (mx_l <= val[v] && mn_r >= val[v])
    {
        s.insert(val[v]);
    }
    dfs(r[v], max(mx_l, val[v]), mn_r);
    dfs(l[v], mx_l, min(mn_r, val[v]));
}


int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int v, a, b;
        scanf("%d%d%d", &v, &a, &b);
        if (a != -1)
        {
            par[a] = i;
        }
        if (b != -1)
        {
            par[b] = i;
        }
        val[i] = v;
        l[i] = a, r[i] = b;
    }
    int r = -1;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == 0)
        {
            r = i;
        }
    }
    dfs(r, 0, 1e9);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!s.count(val[i]))
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}