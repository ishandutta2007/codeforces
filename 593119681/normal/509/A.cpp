#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n, ans, Map[99][99];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            if (i == 1 || j == 1) Map[i][j] = 1;
                else Map[i][j] = Map[i][j - 1] + Map[i - 1][j];
            ans = max(ans, Map[i][j]);
        }
    printf("%d\n", ans);
    return 0;
}