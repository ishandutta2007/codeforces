#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
vector<int> g[MAX_N];
int s[MAX_N];
int n;
int inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
int ans;

bool dfs(int v, int pr)
{
    if (g[v].empty())
        return true;
    int mi = inf;
    for (int to : g[v])
        mi = min(s[to], mi);
    if (mi < s[pr])
        return false;
    ans += mi - s[pr];
    for (int to : g[v])
        ans += s[to] - mi;
    for (int to : g[v])
    {
        for (int u : g[to])
        {
            if (!dfs(u, to))
                return false;
        }
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int v;
        cin >> v;
        v--;
        g[v].push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> s[i];
    ans += s[0];
    bool u = true;
    for (int to : g[0])
        u &= dfs(to, 0);
    if (!u)
        cout << -1;
    else
        cout << ans;
}