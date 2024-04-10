#include <stdio.h>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

const int maxN = 205;
int f[maxN], g[maxN];

typedef unsigned long long ll;

ll gcd(ll a, ll b)
{
    while (a && b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    
    return a + b;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f[i]);
        f[i]--;
        g[i] = f[i];
    }
    
    ll lcm = 1;
    
    ll xMin = 1;
    
    for (int i = 0; i < n; i++)
    {
        static int was[maxN];
        for (int j = 0; j < n; j++) was[j] = -1;
        int cur = i;
        
        int loop = 0;
        int pre = 0;
        
        for (int t = 0; t < n; t++)
        {
            was[cur] = t;
            cur = f[cur];
            
            if (was[cur] >= 0)
            {
                loop = t - was[cur] + 1;
                pre = t - loop + 1;
                break;
            }
        }
        
        //printf("%d: loop %d pre %d\n", i, loop, pre);
        
        assert(pre >= 0);
        xMin = max(xMin, (ll)pre);
        
        if (lcm % loop != 0)
        {
            ll g = gcd(lcm, loop);
            loop /= g;
            lcm *= loop;
        }
    }
    
    ll tt = lcm;
    while (lcm < xMin)
        lcm += tt;
    
    printf("%llu\n", lcm);
    
    return 0;
}