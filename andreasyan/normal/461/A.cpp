#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    long long ans = 0;
    long long s = 0;
    for (int i = n; i >= 1; --i)
    {
        s += a[i];
        ans += s;
    }
    for (int i = 1; i < n; ++i)
        ans += a[i];
    printf("%lld\n", ans);
    return 0;
}