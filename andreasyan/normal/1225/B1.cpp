#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, k, d;
int a[N];

int qq;
int q[N];

void ave(int x)
{
    ++q[x];
    if (q[x] == 1)
        ++qq;
}
void han(int x)
{
    --q[x];
    if (q[x] == 0)
        --qq;
}

void solv()
{
    scanf("%d%d%d", &n, &k, &d);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        q[a[i]] = 0;
    qq = 0;
    int ans = k;
    for (int i = 1; i <= d; ++i)
        ave(a[i]);
    ans = min(ans, qq);
    for (int i = d + 1; i <= n; ++i)
    {
        han(a[i - d]);
        ave(a[i]);
        ans = min(ans, qq);
    }
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}