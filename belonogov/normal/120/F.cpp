#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[200][200];
int d[200];
bool check[200];
int och[200];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int res = 0, n, m, i, j, k, x, y, uk1, uk2;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> m;
        for (j = 0; j < m; j++)
            for (k = 0; k < m; k++)
                a[j][k] = 0;
        for (j = 0; j < m - 1; j++)
        {
            cin >> x >> y;
            x--;
            y--;
            a[x][y] = 1;
            a[y][x] = 1;
        }
        for (j = 0; j < m; j++)
            check[j] = false;
        uk1 = 0;
        uk2 = 1;
        och[0] = 0;
        check[0] = true;
        d[0] = 0;
        while (uk1 < uk2)
        {
            for (j = 0; j < m; j++)
                if ((! check[j]) && a[och[uk1]][j])
                {
                    och[uk2++] = j;
                    check[j] = true;
                    d[j] = d[och[uk1]] + 1;
                }
            uk1++;
        }
        x = 0;
        for (j = 0; j < m; j++)
            if (d[x] < d[j])
                x = j;
        //2
        for (j = 0; j < m; j++)
            check[j] = false;
        memset(d, 0, sizeof d);
        memset(och, 0, sizeof och);
        uk1 = 0;
        uk2 = 1;
        och[0] = x;
        check[x] = true;
        d[x] = 0;
        while (uk1 < uk2)
        {
            for (j = 0; j < m; j++)
                if ((! check[j]) && a[och[uk1]][j])
                {
                    och[uk2++] = j;
                    check[j] = true;
                    d[j] = d[och[uk1]] + 1;
                }
            uk1++;
        }
        x = 0;
        for (j = 0; j < m; j++)
            if (d[x] < d[j])
                x = j;
        res += d[x];

    }
    cout << res;
    return 0;
}