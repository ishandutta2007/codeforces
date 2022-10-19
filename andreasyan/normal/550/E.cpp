#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (a[n] == 1)
    {
        printf("NO\n");
        return 0;
    }
    if (n == 1)
    {
        printf("YES\n");
        printf("0\n");
        return 0;
    }
    if (a[n - 1] == 1)
    {
        printf("YES\n");
        printf("(");
        for (int i = 1; i < n - 1; ++i)
            printf("%d->", a[i]);
        printf("%d)", a[n - 1]);
        printf("->%d\n", a[n]);
        return 0;
    }
    for (int i = n - 2; i >= 1; --i)
    {
        if (a[i] == 0)
        {
            printf("YES\n");
            for (int j = 1; j < i; ++j)
                printf("%d->", a[j]);
            printf("(%d->(", a[i]);
            for (int j = i + 1; j < n - 1; ++j)
                printf("%d->", a[j]);
            printf("%d))", a[n - 1]);
            printf("->%d\n", a[n]);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}