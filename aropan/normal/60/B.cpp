#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 11;


char a[MAXN][MAXN][MAXN];
int k, n, m, ans;

int rec(int x, int y, int z)
{
    if (x < 1 || y < 1 || z < 1 || k < x || n < y || m < z || a[x][y][z] != '.') return 0;
    
    a[x][y][z] = '#';
    ans++;
    
    rec(x + 1, y, z);
    rec(x - 1, y, z);
    rec(x, y + 1, z);
    rec(x, y - 1, z);
    rec(x, y, z + 1);
    rec(x, y, z - 1);
    
    return 0;
}

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    scanf("%d %d %d\n", &k, &n, &m);
    
    for (int z = 1; z <= k; z++)
    {
        scanf("\n");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                scanf("%c", &a[z][i][j]);
            scanf("\n");
        }
    }
    
    int x, y;
    scanf("%d %d", &x, &y);
    
    rec(1, x, y);
    
    printf("%d\n", ans);
    return 0;
}