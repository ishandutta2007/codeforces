#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n;
int a[N];

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 2; j <= n; ++j)
        {
            if (a[i] == a[j])
                return true;
        }
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