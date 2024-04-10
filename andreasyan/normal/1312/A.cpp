#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        if (m % n == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}