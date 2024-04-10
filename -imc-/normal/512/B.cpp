#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif
    
    const int inf = 1e9;
    
    int n;
    scanf("%d", &n);
    
    vector<int> a(n), c(n);
    
    int g = 0;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        g = __gcd(a[i], g);
    }
    
    if (g > 1)
    {
        printf("-1\n");
        return 0;
    }
    
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    
    int answer = inf;
    
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        vector<int> primes;
        
        for (int d = 2; d * d <= num; d++)
            while (num % d == 0)
            {
                num /= d;
                primes.push_back(d);
            }
            
        if (num != 1)
            primes.push_back(num);
            
        sort(primes.begin(), primes.end());
        primes.erase(unique(primes.begin(), primes.end()), primes.end());
        
        if (primes.empty())
        {
            //printf("can %d\n", c[i]);
            answer = min(answer, c[i]);
            continue;
        }
        
        int nMasks = 1 << primes.size();
        
        vector<int> d(nMasks, inf);
            
        for (int j = 0; j < n; j++)
        {
            int mask = 0;
            for (int k = 0; k < (int)primes.size(); k++)
                if (a[j] % primes[k] == 0)
                    mask |= (1 << k);
                
            d[mask] = min(d[mask], c[j]);
        }
        
        for (int i = nMasks - 1; i >= 0; i--)
            for (int j = i + 1; j < nMasks; j++)
                d[i & j] = min(d[i & j], d[i] + d[j]);
            
        answer = min(answer, c[i] + d[0]);
    }
    
    if (answer != inf)
        printf("%d\n", answer);
    else
        printf("-1\n");
    
    return 0;
}