#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxN = 1000500;
ll a[maxN], pSum[maxN];

ll A, B;

ll getPSum(int i)
{
    if (i <= 0) return 0;
    return A * i + B * (i - 1) * i / 2;
}

ll getSum(int l, int r)
{
    //printf("sum %d..%d is %lld - %lld\n", l, r, getPSum(r), getPSum(l - 1));
    return getPSum(r) - getPSum(l - 1);
}

bool canEat(int l, int r, int nBites, int biteCount)
{
    biteCount = min(biteCount, r - l + 1);
    //printf("can eat %d..%d %d %d (sum %lld)\n", l, r, nBites, biteCount, getSum(l, r));
    
    if (A + (r - 1) * B > nBites) return false;
    if (getSum(l, r) > nBites * (ll)biteCount) return false;
    
    return true;
}
    
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    
    int n;
    int aa, bb;
    scanf("%d %d %d", &aa, &bb, &n);
    A = aa; B = bb;
    
    for (int i = 0; i < maxN; i++)
        a[i] = A + B * i;
    
    //for (int i = 0; i < 10; i++)
    //    printf("%lld ", a[i]);
    //printf("\n");
    
    /*for (int i = 0; i < maxN; i++)
    {
        pSum[i] = (i ? pSum[i - 1] : 0) + a[i];
    
        //printf("%lld %lld\n", pSum[i], A * (i + 1) + B * i * (i + 1) / 2);
        assert(pSum[i] == A * (i + 1) + B * i * (i + 1) / 2);
    }
    
    printf("ok\n");*/
    
    for (int i = 0; i < n; i++)
    {
        int l, nBites, biteCount;
        scanf("%d %d %d", &l, &nBites, &biteCount);
        
        //printf("can %lld\n", can);
        
        int rMin = l, rMax = maxN;
        
        if (!canEat(l, rMin, nBites, biteCount))
        {
            printf("-1\n");
            continue;
        }
        
        while (rMin != rMax)
        {
            int m = (rMin + rMax + 1) / 2;
            //printf("%d: %lld\n", m, pSum[m] - ((l - 1) ? pSum[l - 1] : 0));
            
            if (canEat(l, m, nBites, biteCount))
                rMin = m;
            else
                rMax = m - 1;
        }
        
        printf("%d\n", rMin);
    }
    
    return 0;
}