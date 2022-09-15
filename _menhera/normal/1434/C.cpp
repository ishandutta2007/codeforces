#include <bits/stdc++.h>
using namespace std;


long long solve(long long a, long long b, long long c, long long d)
{
    if(a>b*c) return -1;
    // ceil ((a/bd)-1)
    // only possible when k <= floor(c/d)
    long long k = min(c/d, (a-1)/(b*d));
    long long cost = a*(k+1) - k*(k+1)/2*b*d;
    return cost;
}
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%lld\n", solve(a, b, c, d));
    }
}