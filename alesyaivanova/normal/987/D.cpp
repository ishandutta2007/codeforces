#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> q[k];
    vector<int> g[n];
    int col[n];
    for (int i = 0; i < n; i++)
    {
        cin >> col[i];
        col[i]--;
        q[col[i]].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int d[n][k];
    for (int c = 0; c < k; c++)
    {
        queue<int> u;
        bool used[n] = {};
        for (int e : q[c])
        {
            u.push(e);
            used[e] = true;
            d[e][c] = 0;
        }
        while (!u.empty())
        {
            int v = u.front();
            u.pop();
            for (int to : g[v])
            {
                if (!used[to])
                {
                    used[to] = true;
                    d[to][c] = d[v][c] + 1;
                    u.push(to);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        sort(d[i], d[i] + k);
        long long ans = 0;
        for (int e = 0; e < s; e++)
            ans += d[i][e];
        cout << ans << " ";
    }
}