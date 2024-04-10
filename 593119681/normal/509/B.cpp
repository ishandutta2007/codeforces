#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5

int n, k, Min, Max, A[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", A + i);
        Min = min(i == 1 ? A[i] : Min, A[i]);
        Max = max(i == 1 ? A[i] : Max, A[i]);
    }
    bool ok = 1;
    if (Max - Min > k) ok = 0;
    if (!ok) puts("NO");
    else
    {
        puts("YES");
        for (int i = 1; i <= n; i ++)
        {
            int u = A[i] / k, v = A[i] % k, col = 1, t = 0;
            for (int j = 1; j <= A[i]; j ++)
            {
                if (col <= v && t >= (u + 1))
                    t = 0, col ++;
                else if (col > v && t >= u)
                    t = 0, col ++;
                t ++;
                printf("%d%c", col, j == A[i] ? '\n' : ' ');
            }
        }
    }
    
//    while (1) ;
    return 0;
}