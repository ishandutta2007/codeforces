#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int dpl[N], dpr[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    dpl[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] > a[i - 1])
            dpl[i] = dpl[i - 1] + 1;
        else
            dpl[i] = 1;
    }
    dpr[n] = 1;
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i] < a[i + 1])
            dpr[i] = dpr[i + 1] + 1;
        else
            dpr[i] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dpl[i]);
    for (int i = 2; i <= n - 1; ++i)
    {
        if (a[i - 1] < a[i + 1])
            ans = max(ans, dpl[i - 1] + dpr[i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}