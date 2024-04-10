#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};
struct ban
{
    int x, y, d;
    ban(){}
    ban(int x, int y, int d)
    {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

int n, m;
char a[N][N];

int d[4][N][N];
bool c[4][N][N];
void bfs(int u)
{
    priority_queue<ban> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] - '0' == u)
            {
                q.push(ban(i, j, 0));
            }
        }
    }
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
                return;
            t = q.top();
            q.pop();
        } while (c[u][t.x][t.y]);
        c[u][t.x][t.y] = true;
        d[u][t.x][t.y] = t.d;
        for (int i = 0; i < 4; ++i)
        {
            ban h = t;
            h.x += xx[i];
            h.y += yy[i];
            if (h.x >= 0 && h.x < n && h.y >= 0 && h.y < m && !c[u][h.x][h.y] && a[h.x][h.y] != '#')
            {
                if (a[h.x][h.y] == '.')
                    ++h.d;
                q.push(h);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i <= 3; ++i)
        bfs(i);
    int ans = n * m * 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (c[1][i][j] && c[2][i][j] && c[3][i][j])
            {
                if (a[i][j] == '.')
                    ans = min(ans, d[1][i][j] + d[2][i][j] + d[3][i][j] - 2);
                else
                    ans = min(ans, d[1][i][j] + d[2][i][j] + d[3][i][j]);
            }
        }
    }
    if (ans == n * m * 2)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}