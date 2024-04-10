#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, k, m, t;

int main()
{
    scanf("%d%d%d%d", &n, &k, &m, &t);
    while (t--)
    {
        int ty, x;
        scanf("%d%d", &ty, &x);
        if (ty == 0)
        {
            if (k <= x)
            {
                n = x;
            }
            else
            {
                n -= x;
                k -= x;
            }
        }
        else
        {
            if (x <= k)
            {
                ++n;
                ++k;
            }
            else
            {
                ++n;
            }
        }
        printf("%d %d\n", n, k);
    }
    return 0;
}