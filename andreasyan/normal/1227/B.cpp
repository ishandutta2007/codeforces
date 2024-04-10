#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];
int p[N];
bool c[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = 0;
        c[i] = false;
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] != p[i - 1])
        {
            a[i] = p[i];
            c[a[i]] = true;
        }
    }
    int j = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i])
            continue;
        while (c[j])
            ++j;
        a[i] = j;
        c[j] = true;
    }
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        maxu = max(maxu, a[i]);
        if (maxu != p[i])
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
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