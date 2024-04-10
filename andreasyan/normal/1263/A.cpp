#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int x[3];
        for (int i = 0; i < 3; ++i)
            scanf("%d", &x[i]);
        sort(x, x + 3);
        int ans = x[0];
        if (x[2] - x[0] >= x[1])
            x[2] -= x[0];
        else
        {
            x[0] -= (x[2] - x[1]);
            x[2] = x[1];
            x[1] -= (x[0] / 2);
            x[2] -= (x[0] / 2 + x[0] % 2);
        }
        ans += min(x[1], x[2]);
        printf("%d\n", ans);
    }
    return 0;
}