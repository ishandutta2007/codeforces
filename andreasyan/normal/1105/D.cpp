#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};
struct ban
{
    int x, y;
    ban()
    {
        x = y = 0;
    }
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int n, m, k;
int s[11];
char a[N][N];
int d[N][N];
queue<ban> q[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ('1' <= a[i][j] && a[i][j] <= '9')
                q[a[i][j] - '0'].push(ban(i, j));
        }
    }
    for (int u = 1; ; ++u)
    {
        bool z = false;
        for (int i = 1; i <= k; ++i)
        {
            queue<ban> qq;
            while (!q[i].empty())
            {
                ban t = q[i].front();
                q[i].pop();
                if (d[t.x][t.y] == u * s[i])
                {
                    qq.push(t);
                    continue;
                }
                for (int j = 0; j < 4; ++j)
                {
                    ban h = t;
                    h.x += xx[j];
                    h.y += yy[j];
                    if (0 <= h.x && h.x < n && 0 <= h.y && h.y < m && a[h.x][h.y] == '.')
                    {
                        a[h.x][h.y] = i + '0';
                        d[h.x][h.y] = d[t.x][t.y] + 1;
                        q[i].push(h);
                        z = true;
                    }
                }
            }
            q[i] = qq;
        }
        if (!z)
            break;
    }
    //for (int i = 0; i < n; ++i)
    //    cout << a[i] << endl;
    int ans[11] = {};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ('1' <= a[i][j] && a[i][j] <= '9')
                ans[a[i][j] - '0']++;
        }
    }
    for (int i = 1; i <= k; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}