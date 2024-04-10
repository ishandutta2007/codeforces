#include <bits/stdc++.h>

using namespace std;

vector<int> g[100000];

int ans = 0;

int dfs(int v, int pr)
{
    if (g[v].size() == 1 && pr != -1)
        return 1;
    int k = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (to == pr)
            continue;
        int b = dfs(to, v);
        if (b % 2 == 1)
            k += b;
        else
            ans++;
    }
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (n % 2 == 1)
    {
        cout << -1;
        return 0;
    }
    dfs(0, -1);
    cout << ans;
}