#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+10,mod=1e9+7;
ll k[N],invk[N];
ll qpow(ll x,ll y){
    ll ans=1;
    while(y){
        if(y&1)(ans*=x)%=mod;
        (x*=x)%=mod;
        y>>=1;
    }
    return ans;
}
ll C(int n,int m){return k[n]*invk[m]%mod*invk[n-m]%mod;}
int n,m;
int get(){
    scanf("%d%d",&n,&m);
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(i==1){ans++;continue;}
        if(n-(m-1)*(i-1)<i)break;
        (ans+=C(n-(m-1)*(i-1),i)*qpow(C(n,i),mod-2)%mod)%=mod;
    }
    return printf("%lld\n",ans+1),0;
}
int main(){
    k[0]=1;
    for(int i=1;i<N;i++)k[i]=k[i-1]*i%mod;
    invk[N-1]=qpow(k[N-1],mod-2);
    for(int i=N-2;i>=0;i--)invk[i]=invk[i+1]*(i+1)%mod;
    int T;scanf("%d",&T);
    while(T--)get();
    return 0;
}