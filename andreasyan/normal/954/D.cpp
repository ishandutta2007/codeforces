#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;
vector<int> a[N];

int s, t;

int d[2][N];

void bfs(int x, int t)
{
    queue<int> q;
    d[t][x] = 1;
    q.push(x);
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (!d[t][h])
            {
                d[t][h] = d[t][x] + 1;
                q.push(h);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        d[t][i]--;
}

bool c[N][N];
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        c[x][y] = true;
        c[y][x] = true;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bfs(s, 0);
    bfs(t, 1);
    int ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            if (x == y || c[x][y])
                continue;
            if (d[0][t] > min(d[0][x] + 1 + d[1][y], d[1][x] + 1 + d[0][y]))
                continue;
            ++ans;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}