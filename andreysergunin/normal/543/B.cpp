#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int n, m;
vector<int> edge[MAXN];

int dist[MAXN][MAXN];

void bfs(int v)
{
    int vis[MAXN];
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    vis[v] = 1;
    int q[MAXN];
    q[0] = v;
    int l = 0;
    int r = 1;
    dist[v][v] = 0;
    while (l < r)
    {
        for (int i = 0; i < (int)edge[q[l]].size(); i++)
            if (vis[edge[q[l]][i]] == 0)
            {
                q[r] = edge[q[l]][i];
                dist[v][edge[q[l]][i]] = dist[v][q[l]] + 1;
                vis[edge[q[l]][i]] = 1;
                r++;
            }
        l++;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int s1, s2, t1, t2, l1, l2;
    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;
    s1--;
    s2--;
    t1--;
    t2--;
    for (int i = 0; i < n; i++)
        bfs(i);
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << ' ';
        cout << endl;
    }*/
    if (dist[s1][t1] > l1 || dist[s2][t2] > l2)
    {
        cout << -1;
        return 0;
    }
    int ans = dist[s1][t1] + dist[s2][t2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int p = dist[s1][i] + dist[i][j] + dist[j][t1];
            int q = dist[s2][i] + dist[i][j] + dist[j][t2];
            int r = dist[s1][i] + dist[i][j] + dist[j][t1] + dist[s2][i] + dist[j][t2];
            if (p <= l1 && q <= l2)
                ans = min(ans, r);

            p = dist[s1][i] + dist[i][j] + dist[j][t1];
            q = dist[t2][i] + dist[i][j] + dist[j][s2];
            r = dist[s1][i] + dist[i][j] + dist[j][t1] + dist[t2][i] + dist[j][s2];
            if (p <= l1 && q <= l2)
                ans = min(ans, r);
        }
    cout << m - ans;
    return 0;
}