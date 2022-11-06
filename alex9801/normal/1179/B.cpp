#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i;
    scanf("%d%d", &n, &m);

    int l, r;
    if(m % 2 == 1)
    {
        int y = 1;
        int x1 = 1;
        int x2 = n;
        while(1)
        {
            printf("%d %d\n", x1, y);
            if(x1 == x2)
                break;
            x1++;

            printf("%d %d\n", x2, y);
            if(x1 == x2)
                break;
            x2--;
        }

        l = 2;
        r = m;

        while(l < r)
        {
            int x1 = 1;
            int x2 = n;
            for(i = 1; i <= n; i++)
            {
                printf("%d %d\n", i, r);
                printf("%d %d\n", n - i + 1, l);
            }

            l++;
            r--;
        }
    }
    else
    {
        l = 1;
        r = m;
        while(l < r)
        {
            int x1 = 1;
            int x2 = n;
            for(i = 1; i <= n; i++)
            {
                printf("%d %d\n", i, l);
                printf("%d %d\n", n - i + 1, r);
            }

            l++;
            r--;
        }
    }

    return 0;
}