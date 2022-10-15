#include <cstdio>

using namespace std;

const int MAXN = 111;

int a[MAXN][MAXN];
int n, m, k;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d", &n, &m);
    if (3 <= n *n + m * m && n * n + m * m <= 10)
    {
        puts("-1");
        return 0;
    }
    
    for (int i = n; i--; )
        for (int j = m; j--; )
            if (((i + j) & 1) == 0)
                a[i][j] = ++k;
    
    for (int i = n; i--; )
        for (int j = m; j--; )
            if (((i + j) & 1) == 1)
                a[i][j] = ++k;
                
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
            printf("%d ", a[i][j]);
        printf("%d\n", a[i][m - 1]);
    }
    return 0;
}