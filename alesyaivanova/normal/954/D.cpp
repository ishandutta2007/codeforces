#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool g[1000][1000] = {};

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = true;
        g[b][a] = true;
    }
    int dist1[n];
    int dist2[n];
    bool used[n] = {};
    queue<int> q;
    q.push(s);
    dist1[s] = 0;
    used[s] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (g[v][i] && !used[i])
            {
                dist1[i] = dist1[v] + 1;
                q.push(i);
                used[i] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        used[i] = false;
    used[t] = true;
    dist2[t] = 0;
    q.push(t);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (g[v][i] && !used[i])
            {
                dist2[i] = dist2[v] + 1;
                q.push(i);
                used[i] = true;
            }
        }
    }
    int d = dist1[t];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int e = i + 1; e < n; e++)
        {
            if (g[i][e])
                continue;
            if ((dist1[i] + dist2[e] + 1 >= d) && (dist1[e] + dist2[i] + 1 >= d))
                ans++;
        }
    }
    cout << ans;
}