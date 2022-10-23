#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
int mask[N], n, vis[N], p[N], c[N], mark[N], deg[N];
vi G[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < (1 << n); ++i) G[i].clear(), mask[i] = vis[i] = 0;
        for (int i = 1, u, v; i <= (n << (n - 1)); ++i)
        {
            cin >> u >> v;
            G[u].eb(v);
            G[v].eb(u);
        }
        queue<int> q;
        vis[0] = 1;
        int d = 0;
        for (int u : G[0]) vis[u] = 2, mask[u] = (1 << (d++)), q.push(u);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : G[u])
            {
                if (!vis[v]) vis[v] = vis[u] + 1, q.push(v);
                if (vis[v] > vis[u]) mask[v] |= mask[u];
            }
        }
        for (int i = 0; i < (1 << n); ++i) p[mask[i]] = i;
        for (int i = 0; i < (1 << n); ++i) cout << p[i] << " ";
        cout << "\n";
        int cnt = 0;
        for (int i = 0; i < (1 << n); ++i) G[i].clear(), mark[i] = 0;
        for (int u = 0; u < (1 << n); ++u)
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                {
                    int v = u ^ (1 << i) ^ (1 << j);
                    G[u].eb(v);
                }
        for (int i = 0; i < n; ++i)
        {
            for (int u = 0; u < (1 << n); ++u)
                if (mark[u] == 1) mark[u] = 0;
            for (int u = 0; u < (1 << n); ++u)
                if (!mark[u])
                {
                    mark[u] = 2;
                    cnt++;
                    c[p[u]] = i;
                    for (int v : G[u])
                        if (!mark[v]) mark[v] = 1;
                }
        }
        if (cnt != (1 << n))
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < (1 << n); ++i) cout << c[i] << " ";
        cout << "\n";
    }
    /*n = 10;
    int cnt = 0;
    for (int u = 0; u < (1 << n); ++u)
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int v = u ^ (1 << i) ^ (1 << j);
                G[u].eb(v);
            }
    for (int i = 0; i < n; ++i)
        {
            for (int u = 0; u < (1 << n); ++u)
                if (mark[u] == 1) mark[u] = 0;
            for (int u = 0; u < (1 << n); ++u)
                if (!mark[u])
                {
                    mark[u] = 2;
                    c[p[u]] = i;
                    cnt++;
                    for (int v : G[u])
                        if (!mark[v]) mark[v] = 1;
                }
        }*/
    /*int m = (1 << n);
    for (int i = 0; i < n; ++i)
    {
        for (int u = 0; u < (1 << n); ++u)
            if (mark[u] == 1) mark[u] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > q;
        for (int u = 0; u < m; ++u)
        {
            deg[u] = 0;
            for (int v : G[u])
                if (!mark[v]) deg[u]++;
            q.push(mp(deg[u], u));
        }
        while (!q.empty())
        {
            int u = q.top().se;
            q.pop();
            if (mark[u]) continue;
            mark[u] = 2;
            cnt++;
            c[u] = i;
            for (int v : G[u])
                if (!mark[v])
                {
                    mark[v] = 1;
                    for (int r : G[v]) deg[r]--, q.push(mp(deg[r], r));
                }
        }
    }*/
    //cout << cnt;
    return 0;
}