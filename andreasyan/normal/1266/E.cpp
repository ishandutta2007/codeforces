#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];
int qq;

long long ans;
map<int, int> u[N];
int q[N];

void han(int x)
{
    ans -= max(a[x] - q[x], 0);
    --q[x];
    ans += max(a[x] - q[x], 0);
}

void ave(int x)
{
    ans -= max(a[x] - q[x], 0);
    ++q[x];
    ans += max(a[x] - q[x], 0);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    scanf("%d", &qq);
    while (qq--)
    {
        int x, t, y;
        scanf("%d%d%d", &x, &t, &y);
        if (u[x][t] != 0)
        {
            han(u[x][t]);
        }
        u[x][t] = y;
        if (u[x][t] != 0)
        {
            ave(u[x][t]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}