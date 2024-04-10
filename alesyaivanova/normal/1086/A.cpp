#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 1009;
//const int MAX_N = 10;
int d[3][MAX_N][MAX_N];
pair<int, int> a[3];
int inf = 1000 * 1000 * 1000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in_field(int x, int y)
{
    return x >= 0 && y >= 0 && x < MAX_N && y < MAX_N;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 3; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < MAX_N; j++)
        {
            for (int e = 0; e < MAX_N; e++)
                d[i][j][e] = inf;
        }
        queue<pair<int, int> > q;
        q.emplace(a[i]);
        d[i][a[i].first][a[i].second] = 0;
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            //cout << q.size() << endl;
            //cout << cur.first << " " << cur.second << endl;
            for (int j = 0; j < 4; j++)
            {
                int x = cur.first + dx[j];
                int y = cur.second + dy[j];
                if (in_field(x, y) && d[i][x][y] == inf)
                {
                    d[i][x][y] = d[i][cur.first][cur.second] + 1;
                    q.emplace(x, y);
                }
            }
        }
    }
    int x, y;
    int ans = inf;
    for (int i = 0; i < MAX_N; i++)
    {
        for (int e = 0; e < MAX_N; e++)
        {
            if (d[0][i][e] + d[1][i][e] + d[2][i][e] + 1 < ans)
            {
                ans = d[0][i][e] + d[1][i][e] + d[2][i][e] + 1;
                x = i;
                y = e;
            }
        }
    }
    cout << ans << "\n";
    cout << x << " " << y << "\n";
    for (int j = 0; j < 3; j++)
    {
        int i = x;
        int e = y;
        while (i != a[j].first || e != a[j].second)
        {
            for (int u = 0; u < 4; u++)
            {
                int xx = i + dx[u];
                int yy = e + dy[u];
                if (in_field(xx, yy) && d[j][xx][yy] + 1 == d[j][i][e])
                {
                    i = xx;
                    e = yy;
                    cout << i << " " << e << "\n";
                    break;
                }
            }
        }
    }
}