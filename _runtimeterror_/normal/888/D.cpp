#include<iostream>
using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    long long ans = 0;

    auto F = [&](int x)
    {
        long long u = 1;
        for(int i=2;i<=x;++i)
            u*=i;
        return u;
    };

    auto C = [&](int n,int k)
    {
        long long u = 1;
        for(int i=1;i<=k;++i)
            u = u*(n-i+1);
        return u/F(k);
    };

    auto D = [&](int x)
    {
        if(x==0)
            return 1ll;
        long long u = F(x),v = 0;
        for(int i=0;i<=x;++i)
            v += u/F(i)*(i&1?-1:1);
        return v;
    };

    for(int i=0;i<=k;++i)
        ans += C(n,i)*D(i);
    printf("%lld",ans);
}