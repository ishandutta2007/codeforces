#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42;
int par[maxn], sz[maxn], cnt[maxn];
int get(int v)
{
    return v == par[v] ? v : par[v] = get(par[v]);
}

void uni(int u, int v)
{
    u = get(u);
    v = get(v);
    cnt[u]++;
    if(u == v)
        return;
    par[u] = v;
    cnt[v] += cnt[u];
    sz[v] += sz[u];
}

int c[maxn], u[maxn], v[maxn];
int used[maxn];

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + maxn, 0);
    fill(sz, sz + maxn, 1);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
        cin >> c[i];
    for(int i = 0; i < m; i++)
        cin >> u[i] >> v[i];
    for(int i = 0; i < m; i++)
        uni(u[i], v[i]);
    int mx = 0;
    int64_t unuse = 0;
    int64_t ans = 0;
    for(int i = 0; i < k; i++)
        used[get(c[i])] = 1;
    for(int i = 1; i <= n; i++)
        if(i == get(i))
        {
            if(used[i])
            {
                mx = max(mx, sz[i]);
                ans += 1LL * sz[i] * (sz[i] - 1) / 2;
            }
            else
            {
                unuse += sz[i];
            }
        }
    ans -= 1LL * mx * (mx - 1) / 2;
    ans += 1LL * (unuse + mx) * (unuse + mx - 1) / 2;
    cout << ans - m << endl;
    return 0;
}