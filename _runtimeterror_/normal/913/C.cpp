#include<iostream>
using namespace std;


const int N=31;
long long val[N];

int main()
{
    int n,L;
    scanf("%d %d",&n,&L);

    for(int i=0;i<n;++i)
        scanf("%lld",val+i);

    for(int i=1;i<=30;++i)
        val[i]=min(val[i]==0?(long long)(5e18):val[i],val[i-1]*2);

    long long ans=1e18,u=0;

    for(int i=30;i>=0;--i)
    {
        if(L&(1<<i))
        {
            u+=val[i];
        }
        else
            ans=min(ans,u+val[i]);
    }
    ans=min(ans,u);

    printf("%lld",ans);

}