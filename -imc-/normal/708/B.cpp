#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll getn(ll axx)
{
    for (ll n = 1; n <= 100000; n++)
        if (n * (ll)(n - 1) / 2 == axx)
            return n;
        
    return -1;
}

int main()
{
    ll a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    
    ll n0 = getn(a00), n1 = getn(a11);
    
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0)
    {
        printf("0\n");
        return 0;
    }
    
    if (a00 == 0 && a01 == 0 && a10 == 0)
        n0 = 0;
    
    if (a10 == 0 && a11 == 0 && a01 == 0)
        n1 = 0;
    
    if (a00 == 0 && a11 == 0)
    {
        if (a10 != 0 || a01 != 0)
            n1 = n0 = 1;
    }
    
    if (n0 == -1 || n1 == -1 || n0 * n1 != a10 + a01)
    {
        printf("Impossible\n");
        return 0;
    }
    
    if (n0 == 0)
    {
        for (int i = 0; i < n1; i++) printf("1");
        printf("\n");
        return 0;
    }
    
    if (n1 == 0)
    {
        for (int i = 0; i < n0; i++) printf("0");
        printf("\n");
        return 0;
    }
    
    //printf("%lld %lld\n", n0, n1);
    
    ll inFront = a10 / n0;
    a10 -= inFront * n0;
    
    //printf("%lld wtf %lld %lld\n", inFront, a10, n0 - a10);
    int n0orig = n0;
    
    for (int i = 0; i < inFront; i++) { printf("1"); n1--; }
    for (int i = 0; i < n0orig - a10; i++) { printf("0"); n0--; }
    if (a10 != 0)
    {
        printf("1");
        n1--;
    }
    for (int i = 0; i < a10; i++) { printf("0"); n0--; }
    while (n1) { printf("1"); n1--; }
    
    assert(n0 == 0 && n1 == 0);
    
    printf("\n");
    
    return 0;
}