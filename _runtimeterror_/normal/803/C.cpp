#include<iostream>

using namespace std;

int main()
{
    long long n,k,x;

    scanf("%lld %lld",&n,&k);

    x = k*(k+1)/2;
    if(n<x || k>1e9)
    {
        printf("-1\n");
        return 0;
    }
    x = n/x;
    long long u = 0;
    for(long long i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(i<=x)
                u = max(u,i);
            if(n/i<=x)
                u = max(u,n/i);
        }
    }
    for(int i=1;i<=k-1;++i)
        printf("%lld ",i*u);
    printf("%lld\n",u*(n/u-k*(k-1)/2));
}