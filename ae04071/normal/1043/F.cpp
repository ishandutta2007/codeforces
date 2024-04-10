#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

const lli mod=1e9+7;

int n,cnt[300001],ccnt[300001];
lli dp[10][300001],fact[300001];

lli power(lli a,lli p){
    lli res=1;
    while(p) {
        if(p&1)res=res*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return res;
}
lli inv(lli a){
    return power(a,mod-2);
}
lli comb(lli n,lli k){
    if(k<0 || n<k) return 0;
    return fact[n]*inv(fact[k])%mod*inv(fact[n-k])%mod;
}
int main(){
    fact[0]=1;
    for(int i=1;i<=300000;i++)
        fact[i] = fact[i-1]*i%mod;

    scanf("%d",&n);
    for(int i=0,v;i<n;i++){
        scanf("%d",&v);
        cnt[v]++;
    }

    for(int i=1;i<=300000;i++) {
        for(int j=i;j<=300000;j+=i){
            ccnt[i] += cnt[j];
        }
    }

    for(int i=1;i<10;i++) for(int j=300000;j;j--){
        dp[i][j]=comb(ccnt[j],i);
        for(int k=j+j;k<=300000;k+=j)
            dp[i][j] = (dp[i][j]-dp[i][k]+mod)%mod;
    }

    lli mx=mod;
    for(int i=1;i<10;i++) if(dp[i][1]!=0)
        mx=min(mx,1ll*i);
    if(mx==mod)mx=-1;
    printf("%lld\n",mx);

    return 0;
}