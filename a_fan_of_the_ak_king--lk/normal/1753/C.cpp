#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353;
int n,x,a[N],t;
long long qpow(long long a,long long b){
    long long s=a,ans=1;
    while(b){
        if(b&1)
            ans=ans*s%M;
        s=s*s%M;
        b>>=1;
    }
    return ans;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            s+=(a[i]==0);
        }
        int p=0;
        for(int i=1;i<=s;++i)
            if(a[i]==1)
                ++p;
        long long u=1ll*n*(n-1)/2%M,ans=0;
        for(int i=1;i<=p;++i)
            ans=(ans+u*qpow(1ll*i*i%M,M-2))%M;
        printf("%lld\n",(ans%M+M)%M);
    }
}