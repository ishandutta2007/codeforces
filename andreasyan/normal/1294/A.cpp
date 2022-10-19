#include <bits/stdc++.h>
using namespace std;

int a[3];
int n;

bool solv()
{
    for (int i = 0; i < 3; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &n);
    int maxu = a[0];
    for (int i = 1; i < 3; ++i)
        maxu = max(maxu, a[i]);
    int q = 0;
    for (int i = 0; i < 3; ++i)
        q += (maxu - a[i]);
    n -= q;
    if (n < 0)
        return false;
    return (n % 3 == 0);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}