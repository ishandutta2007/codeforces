#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int q;

bool c[N][N][N];
int a[N][N][N];

int rec(int x, int y, int z)
{
    if (c[x][y][z])
        return a[x][y][z];
    c[x][y][z] = true;
    if (x >= 1 && y >= 2)
        a[x][y][z] = max(a[x][y][z], 3 + rec(x - 1, y - 2, z));
    if (y >= 1 && z >= 2)
        a[x][y][z] = max(a[x][y][z], 3 + rec(x, y - 1, z - 2));
    return a[x][y][z];
}

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        printf("%d\n", rec(x, y, z));
    }
    return 0;
}