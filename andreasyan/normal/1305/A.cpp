#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
int a[N], b[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf("\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}