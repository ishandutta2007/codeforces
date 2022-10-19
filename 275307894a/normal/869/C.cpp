#include<cstdio>
#include<cstring>
#define mod 998244353
#define ll unsigned long long
#define N 2000000
#define I inline
#define re register 
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int a,b,c,maxn;ll frc[N+5],inv[N+5],ans;
I ll mpow(ll x,int y=mod-2){ll ans=1;while(y) (y&1)&&(ans=ans*x%mod),x=x*x%mod,y>>=1;return ans;}
I ll make(int x,int y){
    re int i,maxn=max(x,y),minn=min(x,y);re ll ans=0,now=frc[minn]*frc[maxn]%mod;
    for(i=0;i<=minn;i++)ans+=inv[minn-i]*inv[maxn-i]%mod*inv[i]%mod;
    return ans%mod*now%mod;
}
int main(){
//  freopen("love20.in","r",stdin);freopen("love20.out","w",stdout);
    register int i,j;scanf("%d%d%d",&a,&b,&c);maxn=max(a,max(b,c));frc[0]=1;
    for(i=1;i<=maxn;i++) frc[i]=frc[i-1]*i%mod;ans=mpow(frc[maxn]);
    for(i=maxn;~i;i--) inv[i]=ans,ans=ans*i%mod;
    printf("%llu\n",make(b,c)*make(a,b)%mod*make(a,c)%mod);
}