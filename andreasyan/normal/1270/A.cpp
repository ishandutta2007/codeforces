#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n, n1, n2;
int a[N], b[N];

bool solv()
{
    scanf("%d%d%d", &n, &n1, &n2);
    for (int i = 1; i <= n1; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n2; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n1; ++i)
    {
        if (a[i] == n)
            return true;
    }
    return false;
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