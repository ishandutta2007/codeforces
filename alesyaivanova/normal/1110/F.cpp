#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = (1 << 19);
int d[2 * MAX_N];
int p[2 * MAX_N];
int n, m;
vector<pair<int, int> > g[MAX_N];
vector<pair<pair<int, int>, int> > q[MAX_N];
int ans[MAX_N];
int tout[MAX_N];
int t;
int inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;

void dfs(int v, int cur_d)
{
    d[MAX_N + v] = cur_d;
    if (v == 0)
        d[MAX_N + v] = inf;
    t++;
    for (auto to : g[v])
    {
        d[MAX_N + v] = inf;
        dfs(to.first, cur_d + to.second);
    }
    tout[v] = t;
}

void push(int i)
{
    p[i * 2] += p[i];
    p[i * 2 + 1] += p[i];
    d[i] += p[i];
    p[i] = 0;
}

void update(int i, int l, int r, int left, int right, int x)
{
    if (l == left && r == right)
    {
        p[i] += x;
        return;
    }
    push(i);
    int mid = (l + r) / 2;
    if (right <= mid)
        update(i * 2, l, mid, left, right, x);
    else if (left >= mid)
        update(i * 2 + 1, mid, r, left, right, x);
    else
    {
        update(i * 2, l, mid, left, mid, x);
        update(i * 2 + 1, mid, r, mid, right, x);
    }
    d[i] = min(d[i * 2] + p[i * 2], d[i * 2 + 1] + p[i * 2 + 1]);
}

int get_min(int i, int l, int r, int left, int right)
{
    if (l == left && r == right)
        return d[i] + p[i];
    push(i);
    int mid = (l + r) / 2;
    if (right <= mid)
        return get_min(i * 2, l, mid, left, right);
    if (left >= mid)
        return get_min(i * 2 + 1, mid, r, left, right);
    return min(get_min(i * 2, l, mid, left, mid), get_min(i * 2 + 1, mid, r, mid, right));
}

void dfs1(int v)
{
    for (int e = 0; e < (int)q[v].size(); e++)
    {
        ans[q[v][e].second] = get_min(1, 0, MAX_N, q[v][e].first.first, q[v][e].first.second);
    }
    for (auto to : g[v])
    {
        update(1, 0, MAX_N, 0, MAX_N, to.second);
        update(1, 0, MAX_N, to.first, tout[to.first], -2 * to.second);
        dfs1(to.first);
        update(1, 0, MAX_N, 0, MAX_N, -to.second);
        update(1, 0, MAX_N, to.first, tout[to.first], 2 * to.second);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        g[a].emplace_back(i, b);
    }
    dfs(0, 0);
    for (int i = MAX_N - 1; i >= 1; i--)
        d[i] = min(d[i * 2], d[i * 2 + 1]);
    for (int j = 0; j < m; j++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        q[a].emplace_back(make_pair(b, c), j);
    }
    dfs1(0);
    for (int j = 0; j < m; j++)
        cout << ans[j] << "\n";
}