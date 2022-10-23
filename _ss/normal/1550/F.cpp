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
const int N = 2e5 + 10, inf = 1e9;
int n, m, s, d, a[N];

struct ds
{
    int w, v, dir;

    bool operator < (const ds &obj) const
    {
        return w > obj.w;
    }
};

int best[N], p[N], vis[N];
set<int> ST;

pii nearest(int val)
{
    int res = lower_bound(a + 1, a + n + 1, val) - a;
    return mp(res - 1, res);
}

int dist(int x, int y)
{
    if (vis[y]) return inf;
    return abs(d - abs(a[x] - a[y]));
}

int find_right(int v)
{
    return *ST.lower_bound(v);
}

int find_left(int v)
{
    auto it = ST.upper_bound(v);
    it--;
    return *it;
}

void update_near(int u, priority_queue<ds> &q)
{
    pii tmp = nearest(a[u] - d);
    tmp.fi = find_left(tmp.fi);
    if (tmp.fi > 0 && dist(u, tmp.fi) < best[tmp.fi])
    {
        best[tmp.fi] = dist(u, tmp.fi);
        p[tmp.fi] = u;
        q.push({best[tmp.fi], tmp.fi, -1});
    }
    tmp.se = find_right(tmp.se);
    if (tmp.se <= n && dist(u, tmp.se) < best[tmp.se])
    {
        best[tmp.se] = dist(u, tmp.se);
        p[tmp.se] = u;
        q.push({best[tmp.se], tmp.se, 1});
    }
    tmp = nearest(a[u] + d);
    tmp.fi = find_left(tmp.fi);
    if (tmp.fi > 0 && dist(u, tmp.fi) < best[tmp.fi])
    {
        best[tmp.fi] = dist(u, tmp.fi);
        p[tmp.fi] = u;
        q.push({best[tmp.fi], tmp.fi, -1});
    }
    tmp.se = find_right(tmp.se);
    if (tmp.se <= n && dist(u, tmp.se) < best[tmp.se])
    {
        best[tmp.se] = dist(u, tmp.se);
        p[tmp.se] = u;
        q.push({best[tmp.se], tmp.se, 1});
    }
}

vector<pii> G[N];
int mn[N];

void dfs(int u)
{
    for (pii e : G[u])
    {
        mn[e.fi] = max(mn[u], e.se);
        dfs(e.fi);
    }
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    priority_queue<ds> q;
    for (int i = 1; i <= n; ++i) best[i] = inf, ST.insert(i);
    ST.insert(0);
    ST.insert(n + 1);
    best[s] = 0;
    ST.erase(s);
    vis[s] = 1;
    update_near(s, q);
    while (!q.empty())
    {
        ds t = q.top();
        q.pop();
        if (t.w > best[t.v]) continue;
        int v = t.v, u = p[v], dir = t.dir;
        vis[v] = 1;
        ST.erase(v);
        update_near(v, q);
        if (dir == 1) v = find_right(v + 1);
        else v = find_left(v - 1);
        if (v > 0 && v <= n && dist(u, v) < best[v])
        {
            best[v] = dist(u, v);
            p[v] = u;
            q.push({best[v], v, dir});
        }
    }
    for (int i = 1; i <= n; ++i)
        if (i != s) G[p[i]].eb(i, best[i]);
    dfs(s);
    for (int i = 1, x, k; i <= m; ++i)
    {
        cin >> x >> k;
        if (mn[x] <= k) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}