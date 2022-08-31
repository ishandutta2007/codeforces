/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

int dpd[N];
int res[N];
int cmp[N];
int lul[N];
int dim[N];
vector <int> a;
vector <int> comp[N];
int sz = 0;
vector <ll> pref[N];
vector <int> g[N];
bool u[N];

void dfs_d(int v)
{
    a.push_back(v);
    u[v] = true;
    for (auto to : g[v])
    {
        if (!u[to])
        {
            dfs_d(to);
            dpd[v] = max(dpd[v], dpd[to] + 1);
        }
    }
}

void dfs_u(int v, int cur)
{
    lul[sz]++;
    cmp[v] = sz;
    res[v] = max(cur, dpd[v]);
    dim[sz] = max(dim[sz], res[v]);
    comp[sz].push_back(res[v]);
    u[v] = true;
    int m1 = -1, m2 = -1;
    for (auto to : g[v])
    {
        if (!u[to])
        {
            int x = dpd[to];
            if (x > m1)
            {
                swap(x, m1);
            }
            if (x > m2)
            {
                swap(x, m2);
            }
        }
    }
    for (auto to : g[v])
    {
        if (!u[to])
        {
            int lul = m1;
            if (dpd[to] == m1)
            {
                lul = m2;    
            }
            lul++;
            dfs_u(to, max(cur, lul) + 1);
        }
    }
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
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!u[i])
        {
            a.clear();
            dfs_d(i);
            for (auto c : a)
            {
                u[c] = 0;
            }
            dfs_u(i, 0);
            sort(comp[sz].rbegin(), comp[sz].rend());
            ll sem = 0;
            for (auto c : comp[sz])
            {
                sem += c;
                pref[sz].push_back(sem);
            }
            sz++;
        }
    }
    map <pair <int, int>, ld> ans;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (cmp[a] == cmp[b])
        {
            cout << -1 << '\n';
            continue;
        }
        a = cmp[a], b = cmp[b];
        if (lul[a] > lul[b])
        {
            swap(a, b);
        }
        if (ans.count({a, b}))
        {
            cout << fixed << setprecision(20) << ans[{a, b}] << '\n';
            continue;
        }
        ll cnt = 0;
        ll sum = 0;
        for (auto go : comp[a])
        {
            if (comp[b][0] + 1 + go < max(dim[a], dim[b]))
            {
                continue;
            }
            int l = 0, r = (int) comp[b].size();
            while (l < r - 1)
            {
                int m = (l + r) / 2;
                if (comp[b][m] + 1 + go >= max(dim[a], dim[b]))
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            cnt += l + 1;
            sum += pref[b][l] + (l + 1) * (ll) (go + 1);
        }
        ll res = 0;
        res += (lul[a] * (ll) lul[b] - cnt) * (ll) max(dim[a], dim[b]);
        res += sum;
        ans[{a, b}] = res / (ld) (lul[a] * (ll) lul[b]);
        cout << fixed << setprecision(20) << ans[{a, b}] << '\n';
    }
}