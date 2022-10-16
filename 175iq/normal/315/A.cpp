#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10001], b[10001];
int ans = 0;
int n;
int main( )
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        int flag = 0;
        for (int j = 1; j <= n; j ++)
            if (b[j] == a[i] && i != j) 
            {
                flag = 1; break;
            }
        if (!flag) ans ++;
    }
    printf("%d\n", ans);
    return 0;
}