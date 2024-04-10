#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N], ta[N];
int b[N], tb[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    if (a[1] != b[1] || a[n] != b[n])
    {
        printf("No\n");
        return 0;
    }
    for (int i = 2; i <= n; ++i)
        ta[i] = a[i] - a[i - 1];
    for (int i = 2; i <= n; ++i)
        tb[i] = b[i] - b[i - 1];
    sort(ta + 2, ta + n + 1);
    sort(tb + 2, tb + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (ta[i] != tb[i])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}