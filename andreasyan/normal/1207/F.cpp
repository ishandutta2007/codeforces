#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 500005, m = 710;

int n;
int ans[m][m];
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int ty, x, y;
        scanf("%d%d%d", &ty, &x, &y);
        if (ty == 2)
        {
            if (x < m)
                printf("%d\n", ans[x][y]);
            else
            {
                int yans = 0;
                for (int i = y; i < N; i += x)
                {
                    yans += a[i];
                }
                printf("%d\n", yans);
            }
        }
        else
        {
            for (int i = 1; i < m; ++i)
            {
                ans[i][x % i] += y;
            }
            a[x] += y;
        }
    }
    return 0;
}