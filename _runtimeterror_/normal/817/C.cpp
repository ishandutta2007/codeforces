#include<iostream>

using namespace std;

int main()
{
    long long ans = 0;
    long long n,s;
    scanf("%lld %lld",&n,&s);
    if(s+180<=n)
        ans += n-(s+180);

    auto good = [&](long long x) {
        long long y = x;
        while(y)
            x-=y%10,y/=10;
        return x>=s;
    };
    for(long long i = min(n,s);i<=min(n,s+180);++i)
        ans += good(i);
    printf("%lld\n",ans);
}