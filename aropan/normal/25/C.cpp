#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 333;

int a[MAXN][MAXN];
long long s, n;

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

    int k;
    scanf("%d", &k);
    while (k--)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = min(a[i][j], 
                    min(
                        a[i][x] + a[y][j] + z,
                        a[i][y] + a[x][j] + z
                    ));
            }


        s = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                s += a[i][j];

        printf("%I64d ", s);
    }
    
    return 0;
}