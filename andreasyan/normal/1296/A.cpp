#include <bits/stdc++.h>
using namespace std;
const int N = 2003;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int s = 0;
    bool z0 = false, z1 = false;
    for (int i = 1; i <= n; ++i)
    {
        s += a[i];
        if (a[i] % 2 == 0)
            z0 = true;
        else
            z1 = true;
    }
    if (z0 && z1)
    {
        printf("YES\n");
        return;
    }
    if (s % 2 == 1)
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