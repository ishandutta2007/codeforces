#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[2][N];

bool c[2][N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s %s", a[0], a[1]);
    for (int i = 0; i <= n; ++i)
        c[0][i] = c[1][i] = false;
    c[0][0] = true;
    for (int i = 0; i < n; ++i)
    {
        if (c[0][i])
        {
            if (a[0][i] <= '2')
                c[0][i + 1] = true;
            else
            {
                if (a[1][i] > '2')
                    c[1][i + 1] = true;
            }
        }
        if (c[1][i])
        {
            if (a[1][i] <= '2')
                c[1][i + 1] = true;
            else
            {
                if (a[0][i] > '2')
                {
                    c[0][i + 1] = true;
                }
            }
        }
    }
    if (c[1][n])
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}