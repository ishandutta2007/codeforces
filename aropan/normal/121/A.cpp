#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    long long l, r;
    long long ans = 0;
    
    scanf("%I64d %I64d", &l, &r);

    for (int i = 1; i <= 10 && (l <= r); i++)
    {
        for (int j = 0; j < (1 << i) && (l <= r); j++)
        {
            long long x = 0;
            for (int k = i - 1; k >= 0; k--)
            {
                (x *= 10) += 4;
                if (j & (1 << k)) x += 3;
            }

            if (x >= l)
            {
                ans += x * (min(x, r) - l + 1);
                l = x + 1;
            }
        }
    }
    printf("%I64d\n", ans);

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}