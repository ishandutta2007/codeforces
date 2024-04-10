#include <iostream>
#include <cstdio>

using namespace std;
const int INF = 1e9;
int a[1000];
int b[102][102];

int main()
{
   int n, m, i, j, k, sum = INF, x, y;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        b[x][y] = 1;
        b[y][x] = 1;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
            {
                if (k != i && k != j && i != j && b[i][j] == 1 && b[i][k] == 1 && b[j][k] == 1 && (a[i] + a[j] + a[k]) < sum)
                    sum = a[i] + a[j] + a[k];
            }
    if (sum != INF)
        cout << sum;
    else
        cout << -1;
    return 0;
}