#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += a[i];
    long long ans = 0;
    long long minu = 0;
    long long u = 0;
    for (int i = 1; i < n; ++i)
    {
        u += a[i];
        ans = max(ans, u - minu);
        minu = min(minu, u);
    }
    minu = 0;
    u = 0;
    for (int i = n; i > 1; --i)
    {
        u += a[i];
        ans = max(ans, u - minu);
        minu = min(minu, u);
    }
    if (sum > ans)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}