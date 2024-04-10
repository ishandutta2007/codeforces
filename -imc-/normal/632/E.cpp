#include <bits/stdc++.h>

using namespace std;

const int maxSum = 1000500;
const unsigned bitsetSize = maxSum / 32;

struct myBitset
{
    unsigned v[bitsetSize];
    
    void zeroes()
    {
        memset(v, 0, sizeof(v));
    }
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    const int aBitsetSize = 1000 / 32 + 2;
    static unsigned aBitset[32][aBitsetSize];
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    int aMin = *min_element(a.begin(), a.end());
    
    for (int i = 0; i < n; i++)
        a[i] -= aMin;
    
    for (int i = 0; i < n; i++)
    {   
        for (int shift = 0; shift < 32; shift++)
            aBitset[shift][(a[i] + shift) / 32] |= 1 << ((a[i] + shift) % 32);
    }
    
    myBitset can;
    can.zeroes();
    can.v[0] = 1;
    
    myBitset scan = can;
    for (int it = 0; it < k; it++)
    {
        myBitset next = can;
        
        unsigned i = 0;
        for (;;)
        {
            // find next in scan >= i
                
            if (!(scan.v[i / 32] >> (i % 32)))
            {
                i = (i / 32 + 1) * 32;
                while (!scan.v[i / 32])
                {
                    i += 32;
                    if (i + 128 > maxSum) goto breakAll;
                }
            }
            
            while (!((scan.v[i / 32] >> (i % 32)) & 1)) i++;
            
            //printf("relax %d\n", i);
            
            if (can.v[i / 32] & (1 << (i % 32)))
                for (unsigned j = 0; j < aBitsetSize; j++)
                    next.v[i / 32 + j] |= aBitset[i % 32][j];
                
            //printf("next %d\n", next.v[0]);
            
            i++;
        }
        
        breakAll:;
                
        for (unsigned i = 0; i < bitsetSize; i++)
        {
            scan.v[i] = next.v[i] & ~can.v[i];
            can.v[i] = can.v[i] | next.v[i];
        }
        
        //printf("iteration\n");
    }
    
    for (int i = 0; i <= 1000000; i++)
        if (can.v[i / 32] & (1 << (i % 32)))
            printf("%d ", aMin * k + i);
    printf("\n");
    
    return 0;
}