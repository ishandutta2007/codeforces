#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,M2=1004535809,M3=469762049,E=524288,N=10000005;
const int iv2=(M+1)/2;
int t,n,m,a[N],b[N],z,x,y,u,v,w;
long long g[505][505],f[505][505],s[N],ans[N];
// long long qpow(long long a,long long b){
//     long long s=a,ans=1;
//     while(b)
//         if(b&1)
//             ans
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        s[0]=1;
        for(int i=1;i<=n;++i)
            s[i]=s[i-1]*iv2%M;
        long long sum=0;
        int las=n;
        for(int i=n;i>=1;--i){
            for(int j=2*i;j<=las;++j)
                sum=(sum+ans[j])%M;
            ans[i]=s[(i-1)/2]*(i==n?1:iv2)%M;
            ans[i]=ans[i]*(1-sum)%M;
            las=min(las,2*i-1);
        }
        for(int i=1;i<=n;++i)
            printf("%lld\n",(ans[i]%M+M)%M);
    }
}