#include<iostream>

using namespace std;

int main()
{
    long long l,r,ans = 0;
    scanf("%lld %lld",&l,&r);
    long long v = 0;
    for(int j=60;j>=0;--j)
    {
        long long u = (1LL<<j);
        if(u+v<=r && u-1+v>=l)
        {
            ans = (u<<1)-1;
            break;
        }
        if(u+v<=r)
            v += u;
    }
    printf("%lld\n",ans);
}