#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int x, y, a;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d %d", &a, &x, &y);
    if (y % a == 0)
    {
        puts("-1");
        return 0;
    }


    int k = y / a;
    if (k == 0 || (k & 1))
    {
        if (- a < x * 2 && x * 2 < a)
        {
            printf("%d\n", k == 0? 1 : 3 * (k / 2) + 2);
        }
        else
        {
            puts("-1");
        }
    }
    else
    {
        if (-a < x && x < 0)
        {
            printf("%d\n", 3 * (k / 2));
        }
        else
        if (0 < x && x < a)
        {
            printf("%d\n", 3 * (k / 2) + 1);
        }
        else
        {
            puts("-1");
        }
    }
    return 0;
}