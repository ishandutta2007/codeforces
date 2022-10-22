#include <bits/stdc++.h>

using namespace std;

typedef long long li;

int main()
{
    int n;
    cin >> n;
    
    for (li i = 1; i <= n; i++)
    {
        if (i == 1)
            printf("2\n");
        else
            printf("%lld\n", (i + 1) * (i + 1) * i - (i - 1));
    }
    
    /*int level = 1;
    li x = 2;
    
    li np = 0;
    while (level < n)
    {
        assert(x % level == 0);
        
        if (level % 1000 == 0) printf("!\n");
        
        li s = sqrtl(x);
        if (s * s == x && s % (level + 1) == 0)
        {
            //printf("%lld\n", np);
            np = 0;
            level++;
            continue;
        }
        else if (s * s == x)
        {
            li add = (2 * s + 1) % (level + 1);
            // + add, + add + 2, + add + 4 ...
            
            li nskip = level + 2;
            li newx = (s + nskip) * (s + nskip);
            x = newx;
            np += (x - newx) / level;
        }
        else
        {
            li n = max((s * s - x) / level, 1LL);
            x += level * n;
            np += n;
        }
    }*/
    
    return 0;
}