#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int g[N];

bool stg1()
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[1])
            return false;
    }
    for (int i = 1; i <= n; ++i)
        g[i] = 1;
    return true;
}

bool stg2()
{
    int q = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i + 1])
            ++q;
    }
    if (a[n] != a[1])
        ++q;
    if (q == n && n % 2 == 1)
        return false;
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; ++i)
            g[i] = (i % 2) + 1;
        return true;
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
        {
            for (int j = i + 1; j <= n; ++j)
            {
                g[j] = (j - i) % 2 + 1;
            }
            for (int j = 1; j <= i; ++j)
            {
                g[j] = (n - i + j) % 2 + 1;
            }
            return true;
        }
    }
    for (int i = 1; i <= n; ++i)
        g[i] = (i % 2) + 1;
    return true;
}

bool stg3()
{
    for (int i = 1; i < n; ++i)
    {
        g[i] = (i % 2) + 1;
    }
    g[n] = 3;
    return true;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (stg1())
        printf("1\n");
    else if (stg2())
        printf("2\n");
    else if (stg3())
        printf("3\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", g[i]);
    printf("\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}