#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
int a[N];

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}