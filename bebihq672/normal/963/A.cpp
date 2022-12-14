#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000009;
int ksm(int n,int k)
{
    int ret=1;
    while(k)
    {
        if(k&1)
            ret=1ll*ret*n%mod;
        n=1ll*n*n%mod;
        k/=2;
    }
    return ret;
}
char S[101010];
int main()
{
    int n,a,b,k;
    scanf("%d%d%d%d",&n,&a,&b,&k);
    scanf("%s",S);
    long long tmp=0;
    for(int i=0;i<k;i++)
    {
        if(S[i]=='+')
            tmp+=1ll*ksm(a,n-i)*ksm(b,i)%mod;
        else
            tmp-=1ll*ksm(a,n-i)*ksm(b,i)%mod;
        if(tmp>=mod)
            tmp-=mod;
        if(tmp<0)
            tmp+=mod;
    }
    long long K=1ll*ksm(a,1ll*k*(mod-2)%(mod-1))*ksm(b,k)%mod;
    int ans;
    if(K==1)
        ans=tmp*((n+1)/k)%mod;
    else
        ans=tmp*(ksm(K,(n+1)/k)-1)%mod*ksm(K-1,mod-2)%mod;
    printf("%d\n",ans);
    return 0;
}