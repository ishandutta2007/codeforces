#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    li a, b;
    cin >> a >> b;
    
#if 0
    li areal = a, breal = b;
    
    li ansreal = 0;
    while (breal > 0)
    {
        breal -= __gcd(areal, breal);
        ansreal++;
    }
    printf("real ans %lld\n", ansreal);
#endif
    
    li answer = 0;
    while (true)
    {
        if (b == 0)
            break;
        
        li g = __gcd(a, b);
        a /= g;
        b /= g;
        
        li a_rest = a;
        vector<li> primes;
        for (li div = 2; div * div <= a_rest; div++)
            while (a_rest % div == 0)
            {
                a_rest /= div;
                primes.push_back(div);
            }
            
        if (a_rest > 1)
            primes.push_back(a_rest);
        
        li go = b;
        for (li p: primes)
            go = min(go, b % p);
        
        assert(go > 0);
        b -= go;
        answer += go;
    }
    
    cout << answer << endl;
    
    return 0;
}