#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n;
int a[N];

int b[N];
void solv0()
{
    for (int q = 0; ; ++q)
    {
        b[1] = a[1];
        b[n] = a[n];
        for (int i = 2; i < n; ++i)
        {
            int z[2] = {};
            z[a[i - 1]]++;
            z[a[i]]++;
            z[a[i + 1]]++;
            if (z[0] > z[1])
                b[i] = 0;
            else
                b[i] = 1;
        }
        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] != b[i])
            {
                z = false;
                a[i] = b[i];
            }
        }
        if (z)
        {
            printf("%d\n", q);
            for (int i = 1; i <= n; ++i)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            return;
        }
    }
}

bool c[N];
int l[N], r[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    /*srand(time(0));
    n = 500000;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = rand() % 2;
    }*/
    int z = 0, m = 0;
    c[1] = true;
    c[n] = true;
    for (int i = 2; i < n; ++i)
    {
        if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1)
            z++;
        else if (a[i - 1] == 0 && a[i] == 1 && a[i + 1] == 0)
            m++;
        else
            c[i] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
        {
            if (i != 1)
                ans = max(ans, max(z, m));
            z = 0;
            m = 0;
        }
        else
        {
            if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1)
                z++;
            else if (a[i - 1] == 0 && a[i] == 1 && a[i + 1] == 0)
                m++;
        }
    }
    l[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            l[i] = l[i - 1];
        else
            l[i] = i;
    }
    r[n] = n;
    for (int i = n; i >= 1; --i)
    {
        if (!c[i])
            r[i] = r[i + 1];
        else
            r[i] = i;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
        {
            printf("%d ", a[i]);
            continue;
        }
        if (i - l[i] < r[i] - i)
            printf("%d ", a[l[i]]);
        else
            printf("%d ", a[r[i]]);
    }
    return 0;
}