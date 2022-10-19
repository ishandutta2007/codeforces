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
    int x = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        x ^= a[i];
    }
    printf("2\n");
    printf("%d ", x);
    sum += x;
    printf("%lld\n", sum);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}