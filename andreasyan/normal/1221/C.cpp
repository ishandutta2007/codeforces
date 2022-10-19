#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int l = 0, r = 100000008;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m <= x && m <= y && m <= z + (x - m) + (y - m))
            {
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}