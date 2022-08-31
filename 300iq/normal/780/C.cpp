#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
vector <int> g[N];
int res[N];
int ans = 0;

void dfs(int v, int pr, int col1, int col2)
{
    int cur = 1;
    res[v] = col1;
    ans = max(ans, col1);
    for (auto to : g[v])
    {
        if (to != pr)
        {
            while (cur == col1 || cur == col2)
            {
                cur++;
            }
            dfs(to, v, cur, col1);
            cur++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1, 1, -1);
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
    cout << '\n';
}