#include <bits/stdc++.h>

using namespace std;

long long n, a, b, q;

int main()
{
    scanf("%lld", &q);
    for(int i=0; i<q; ++i)
    {
        scanf("%lld%lld%lld", &n, &a, &b);
        if(a*2<=b)
        {
            printf("%lld\n", n*a);
        }
        else
        {
                if(n&1)
                {
                    printf("%lld\n", n/2*b+a);
                }
                else
                {
                    printf("%lld\n", n/2*b);
                }
        }
    }
    return 0;
}