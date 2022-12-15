#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MOD = 1e9+7;
lli power(lli a,lli p) {
    lli ret=1;
    while(p){
        if(p&1) ret=ret*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ret;
}
lli inv(lli a) {return power(a,MOD-2);}

int n;
lli arr[200002];
lli T,fact[200002];

int check(lli a,int idx) {
    int lo=-1,up=idx+1;
    while(up-lo>1) {
        int md=(lo+up)>>1;
        if(a+md>T) up=md;
        else lo=md;
    }
    return lo;
}

int main(){
    scanf("%d%lld",&n,&T);
    for(int i=1;i<=n;i++) scanf("%lld",arr+i),arr[i]+=arr[i-1];
    arr[n+1] = T+1;

    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%MOD;

    lli ans=0;
    for(int i=1;i<=n;i++) {
        int k=check(arr[i], i);
        for(int j=k;j>=0 && arr[i+1]+j>T;j--) {
            lli prob = fact[i]*inv(fact[j])%MOD*inv(fact[i-j])%MOD*inv(power(2,i))%MOD;
            ans = (ans + prob*inv(2)%MOD*i%MOD)%MOD;
        }
        for(int j=k;j>=0 && arr[i+1]+j+1>T;j--) {
            lli prob = fact[i]*inv(fact[j])%MOD*inv(fact[i-j])%MOD*inv(power(2,i))%MOD;
            ans = (ans + prob*inv(2)%MOD*i%MOD)%MOD;
        }
    }
    printf("%lld\n",ans);

    return 0;
}