#include <cstdio>

const int maxN = 100500;
long long a[maxN];
int n;

bool canPlay (long long t)
{
    long long rest = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > t)
            return false;
        rest += t - a[i];
    }
    return rest >= t;
}

int main()
{
    scanf ("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf ("%lld", &a[i]);
    
    long long minCan = 0, maxCan = 2000000000;
    
    while (minCan != maxCan)
    {
        long long middle = (minCan + maxCan) / 2;
        if (canPlay (middle))
            maxCan = middle;
        else
            minCan = middle + 1;
    }
    
    printf ("%lld\n", minCan);
    
    return 0;
}