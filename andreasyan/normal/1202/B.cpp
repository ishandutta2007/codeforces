#include <bits/stdc++.h>
using namespace std;
const int N = 2000006;
 
int n;
char a[N];
 
int u[10][10];
bool c[10][10];
int ans[10][10];
int solv(int x, int y)
{
    c[x][y] = true;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            u[i][j] = N;
        }
        for (int qx = 0; qx < 40; ++qx)
        {
            for (int qy = 0; qy < 40; ++qy)
            {
                if (qx == 0 && qy == 0)
                    continue;
                u[i][(i + qx * x + qy * y) % 10] = min(u[i][(i + qx * x + qy * y) % 10], qx + qy);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (u[a[i] - '0'][a[i + 1] - '0'] == N)
            return -1;
        ans += u[a[i] - '0'][a[i + 1] - '0'] - 1;
    }
    return ans;
}
 
int main()
{
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (c[j][i])
            {
                printf("%d ", ans[j][i]);
                continue;
            }
            ans[i][j] = solv(i, j);
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}