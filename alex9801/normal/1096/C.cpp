#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, i, j;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        int x;
        scanf("%d", &x);
        for(j = 3;; j++)
        {
            if(j * x % 180 == 0 && x <= 180 * (j - 2) / j)
            {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}