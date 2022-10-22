#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int nNumbers;
    scanf ("%d", &nNumbers);
    nNumbers *= 2;
    
    int nIntegers = 0;
    long long sum = 0;
    
    for (int i = 0; i < nNumbers; i++)
    {
        int integer, fraction;
        scanf ("%d.%d", &integer, &fraction);
        if (fraction == 0)
            nIntegers++;
        else
            sum += fraction;
    }
    
    long long nMinuses = nNumbers / 2;
    long long nFree = nNumbers - nIntegers;
    long long nTaken = nIntegers;
    
    long long minAdd = -min (nFree, nMinuses);
    long long maxAdd = -(nMinuses - min (nTaken, nMinuses));
    
    //printf ("frac sum %lld min add %lld, max add %lld\n", sum, minAdd, maxAdd);
    
    long long minSum = sum;
    for (long long x = minAdd; x <= maxAdd; x++)
        if (x == minAdd || abs (sum + x * 1000) < abs (minSum))
        {
            minSum = abs (sum + x * 1000);
        }
        
    printf ("%lld.%03lld\n", minSum / 1000, minSum % 1000);
    
    return 0;
}