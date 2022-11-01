#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    scanf("%I64d%I64d",&n,&k);
    long long l,r,res=1;
    //odd
    l=0; r=n+1;
    while(l<r-1)
    {
        long long m=(l+r)/2;
        long long t=2*m+1;
        long long cnt=0;
        for(long long i=0;(t<<i)<=n;i++) //shift
        {
            cnt+=min((1ll<<i),n-(t<<i)+1ll);
        }
        if(cnt>=k) l=m;
        else r=m;
    }
    res=max(res,2*l+1);
    //even
    l=0; r=n+1;
    while(l<r-1)
    {
        long long m=(l+r)/2;
        long long t=2*m;
        long long cnt=0;
        for(long long i=0;(t<<i)<=n;i++) //shift
        {
            cnt+=min((1ll<<i),n-(t<<i)+1ll);
            if(((t<<i)+(1ll<<i))<=n)
            {
                t++;
                cnt+=min((1ll<<i),n-(t<<i)+1ll);
                t--;
            }
        }
        if(cnt>=k) l=m;
        else r=m;
    }
    res=max(res,2*l);
    printf("%I64d\n",res);
    return 0;
}