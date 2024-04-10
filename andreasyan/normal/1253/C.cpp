#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m;
int a[N];

long long p[N];
long long ans[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (i - m >= 0)
            ans[i] = ans[i - m];
        ans[i] += p[i];
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}