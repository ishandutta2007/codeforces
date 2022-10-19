#include <bits/stdc++.h>
using namespace std;
const int N = 102;
const int xx[8] = {1, 2, -1, -2, -1, 2, 1, -2};
const int yy[8] = {2, 1, -2, -1, 2, -1, -2, 1};

int n;
char a[N][N];

void dfs(int x, int y, int t)
{
    if (!t)
        a[x][y] = 'W';
    else
        a[x][y] = 'B';
    for (int i = 0; i < 8; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (hx >= 0 && hx < n && hy >= 0 && hy < n && !a[hx][hy])
        {
            dfs(hx, hy, (t ^ 1));
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!a[i][j])
                dfs(i, j, 0);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << endl;
    return 0;
}