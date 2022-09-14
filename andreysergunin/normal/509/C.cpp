#include <bits/stdc++.h>
#define sqr(a) ((a) * (a))

using namespace std;
const int MAXN = 500;
const int MAXC = 500;

int d[MAXC];

void f(int a[MAXC], int c)
{
    for (int i = 0; i < MAXC; i++)
        d[i] = 0;
    int l = (c - 1) / 9 + 1;
    for (int i = 0; i < l - 1; i++)
        d[i] = 9;
    d[l - 1] = (c - 1) % 9 + 1;

    int p;
    for (p = MAXC - 1; p >= 0; p--)
        if (a[p] != d[p])
            break;
    if (p != -1 && a[p] < d[p])
        return;


    for (p = MAXC - 1; p >= 0; p--)
        if (a[p] != 0)
            break;

    //printf("%d\n", p);

    for (int i = 0; i <= p; i++)
    {
        if (a[i] < 9)
        {
            int u = c;
            for (int j = 0; j < MAXC; j++)
                d[j] = 0;
            for (int j = i + 1; j <= p; j++)
            {
                d[j] = a[j];
                u -= a[j];
            }
            d[i] = a[i] + 1;
            u = u - a[i] - 1;
            //printf("%d %d\n", i, u);
            int r = (u == 0) ? 0 : (u - 1) / 9 + 1;
            if (u >= 0 && r <= i + 1)
            {
                for (int j = 0; j < r - 1; j++)
                    d[j] += 9;
                if (r > 0)
                    d[r - 1] += (u - 1) % 9 + 1;
                int q;
                for (q = MAXC - 1; q >= 0; q--)
                    if (a[q] != d[q])
                        break;
                if (q != -1 && a[q] < d[q] && d[i] < 10)
                    return;
            }
        }
    }

    //printf("%d\n", p);

    for (int i = 0; i < MAXC; i++)
        d[i] = 0;
    d[p + 1] = 1;
    c--;
    l = (c - 1) / 9 + 1;
    for (int i = 0; i < l - 1; i++)
        d[i] = 9;
    d[l - 1] = (c - 1) % 9 + 1;

}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int a[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int l;
    int b[MAXC];
    l = (a[0] - 1) / 9 + 1;

    for (int i = 0; i < MAXC; i++)
        b[i] = 0;
    for (int i = 0; i < l - 1; i++)
        b[i] = 9;
    b[l - 1] = (a[0] - 1) % 9 + 1;

    int p;
    for (p = MAXC - 1; p >= 0; p--)
        if (b[p] != 0)
            break;

    for (int i = p; i >= 0; i--)
        printf("%d", b[i]);
    printf("\n");

    for (int i = 1; i < n; i++)
    {
        f(b, a[i]);
        for (int j = 0; j < MAXC; j++)
            b[j] = d[j];
        int p;
        for (p = MAXC - 1; p >= 0; p--)
            if (b[p] != 0)
                break;
        for (int j = p; j >= 0; j--)
            printf("%d", b[j]);
        printf("\n");
    }

}