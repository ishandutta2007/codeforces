#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n, m;
int a[N];

int main()
{
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ans + (i - 1) / 2 >= m)
        {
            a[i] = (i - 1 + i - (m - ans) * 2);
            a[n + 1] = 1000000000;
            for (int j = n; j > i; --j)
                a[j] = a[j + 1] - 10000;
            for (int i = 1; i <= n; ++i)
                printf("%d ", a[i]);
            printf("\n");
            return 0;
        }
        a[i] = i;
        ans += (i - 1) / 2;
    }
    printf("-1\n");
    return 0;
}