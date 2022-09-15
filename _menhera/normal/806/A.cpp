#include<bits/stdc++.h>
using namespace std;
long long solve(long long x, long long y, long long p, long long q)
{
    if(p==0)
    {
        if(x==0) return 0;
        else return -1;
    }
    if(p==q)
    {
        if(x==y) return 0;
        else return -1;
    }
    long long no1 = (q*x+p-1)/p - y;
    long long no2 = (p*y-q*x + q - p - 1) / (q - p);
    long long ans = max(no1, no2);
    ans += (q - ((y+ans)%q))%q;
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int x, y, p, q;
        scanf("%d%d%d%d", &x, &y, &p, &q);
        printf("%lld\n", solve(x, y, p, q));
    }
    return 0;
}