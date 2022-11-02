#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 150009;
vector<int> g[MAX_N];
int n;
int p[MAX_N];
pair<int, int> ed[MAX_N];
int sz[MAX_N];

int find_p(int a)
{
    if (p[a] == a)
        return a;
    p[a] = find_p(p[a]);
    return p[a];
}

void dfs(int v, int pr)
{
    cout << v + 1 << " ";
    for (int to : g[v])
    {
        if (to != pr)
            dfs(to, v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        sz[i] = 1;
        ed[i].first = i;
        ed[i].second = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        a = find_p(a);
        b = find_p(b);
        pair<int, int> cur(ed[a].first, ed[b].first);
        g[ed[a].second].push_back(ed[b].second);
        g[ed[b].second].push_back(ed[a].second);
        if (sz[a] > sz[b])
        {
            p[b] = a;
            ed[a] = cur;
        }
        else
        {
            p[a] = b;
            ed[b] = cur;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 1)
        {
            dfs(i, -1);
            return 0;
        }
    }
}