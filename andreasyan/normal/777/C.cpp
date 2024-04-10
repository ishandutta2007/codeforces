#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
int ** a;

void sar(int**& a)
{
    a = new int*[n + 5];
    for (int i = 0; i < n + 5; ++i)
    {
        a[i] = new int[m + 5];
    }
    for (int i = 0; i < n + 5; ++i)
    {
        for (int j = 0; j < m + 5; ++j)
            a[i][j] = 0;
    }
}

int ** t;

int ll[N];

int main()
{
    scanf("%d%d", &n, &m);
    sar(a);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    sar(t);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1)
                t[i][j] = i;
            else
            {
                if (a[i][j] >= a[i - 1][j])
                {
                    t[i][j] = t[i - 1][j];
                }
                else
                {
                    t[i][j] = i;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ll[i] = i;
        for (int j = 1; j <= m; ++j)
            ll[i] = min(ll[i], t[i][j]);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (ll[r] <= l)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}