#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;
const int xx[4] = {1, 0, 0, -1};
const int yy[4] = {0, -1, 1, 0};
const char cc[4] = {'D', 'L', 'R', 'U'};

int n, m, k;
char a[N][N];
int sx, sy;

int d[N][N];
bool c[N][N];
void bfs()
{
    queue<pair<int, int> > q;
    q.push(m_p(sx, sy));
    c[sx][sy] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (hx >= 0 && hx < n && hy >= 0 && hy < m && a[hx][hy] == '.' && !c[hx][hy])
            {
                q.push(m_p(hx, hy));
                c[hx][hy] = true;
                d[hx][hy] = d[x][y] + 1;
            }
        }
    }
}

bool stg(int x, int y, int k)
{
    if (k < d[x][y])
        return false;
    return ((d[x][y] - k) % 2 == 0);
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'X')
            {
                sx = i;
                sy = j;
                a[i][j] = '.';
            }
        }
    }
    bfs();

    string ans;
    int x = sx, y = sy;
    for (int ii = 1; ii <= k; ++ii)
    {
        bool z = false;
        for (int i = 0; i < 4; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            int mn = k - ii;
            if (hx >= 0 && hx < n && hy >= 0 && hy < m && a[hx][hy] == '.' && stg(hx, hy, mn))
            {
                ans += cc[i];
                x = hx;
                y = hy;
                z = true;
                break;
            }
        }
        if (!z)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}