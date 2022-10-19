#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1502;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;
char a[N][N];
int sx, sy;

int c[N][N];
int k;
void dfs(int x, int y)
{
    c[x][y] = k;
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (hx >= 0 && hx < n && hy >= 0 && hy < m && a[hx][hy] != '#' && !c[hx][hy])
            dfs(hx, hy);
    }
}

vector<pair<int, int> > g[N * N];

pair<int, int> c1[N * N];
bool c2[N * N];

bool dfs1(int x, int y, int kk)
{
    c2[kk] = true;
    c1[kk] = m_p(x, y);
    for (int i = 0; i < g[kk].size(); ++i)
    {
        int hkk = g[kk][i].first;
        int hx = x + xx[g[kk][i].second];
        int hy = y + yy[g[kk][i].second];
        if (c2[hkk] == false)
        {
            if (dfs1(hx, hy, hkk))
                return true;
        }
        else
        {
            if (c1[hkk] != m_p(hx, hy))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'S')
            {
                sx = i;
                sy = j;
                a[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!c[i][j] && a[i][j] != '#')
            {
                ++k;
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '#')
                continue;
            for (int k = 0; k < 4; ++k)
            {
                int hi = i + xx[k];
                int hj = j + yy[k];
                if (!(hi >= 0 && hi < n && hj >= 0 && hj < m))
                {
                    if (hi < 0)
                        hi = n - 1;
                    if (hi == n)
                        hi = 0;
                    if (hj < 0)
                        hj = m - 1;
                    if (hj == m)
                        hj = 0;
                    if (a[hi][hj] == '#')
                        continue;
                    g[c[i][j]].push_back(m_p(c[hi][hj], k));
                }
            }
        }
    }

    if (dfs1(0, 0, c[sx][sy]))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}