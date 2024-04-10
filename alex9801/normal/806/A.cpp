#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    long long x, y, p, q, k, t, i;
    scanf("%lld", &t);
    for(i = 0; i<t; i++)
    {
        scanf("%lld%lld%lld%lld", &x, &y, &p, &q);

        if(p == 0)
        {
            if(x == 0)
                printf("0\n");
            else
                printf("-1\n");
            continue;
        }

        if(p == q)
        {
            if(x == y)
                printf("0\n");
            else
                printf("-1\n");
            continue;
        }

        k = max({ (x + p-1)/p, (y + q-1)/q, (y-x + q-p-1)/(q-p) });
        printf("%lld\n", 1LL*k*q-y);
    }
	return 0;
}