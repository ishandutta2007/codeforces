#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
int a[N][N];

int b[N];
bool stg(int x)
{
    b[1] = x;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i][1] % x != 0)
            return false;
        b[i] = a[i][1] / x;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            if (b[i] * 1LL * b[j] != a[i][j])
                return false;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf("\n");
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i * i <= a[1][2]; ++i)
    {
        if (a[1][2] % i == 0)
        {
            if (stg(i))
                return 0;
            if (stg(a[1][2] / i))
                return 0;
        }
    }
    return 0;
}