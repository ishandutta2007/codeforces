#include <bits/stdc++.h>
using namespace std;


bool solve(long long s, long long e, bool init)
{
    long long from = e+1, to = 2*e;
    bool even = init, odd = init; // is winning
    while(true)
    {
        long long nfrom = (from+1)/2, nto = from-1;
        bool neven, nodd;
        if(!even) neven = nodd = true;
        else if(nto%2 == 0) { neven = !odd; nodd = odd; }
        else{ nodd = !even; neven = even; }
        from = nfrom; to = nto; even = neven; odd = nodd;
        if(from <= s && s <= to)
        {
            if(s%2 == 0) return even;
            else return odd;
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    bool pwin = false, plose = true;
    while(T--)
    {
        if(pwin == plose) continue;
        bool first = plose;
        long long a, b; scanf("%lld%lld", &a, &b);
        pwin = (first == solve(a, b, true)), plose = (first == solve(a, b, false));
    }
    printf("%d %d\n", (int) pwin, (int) plose);
}