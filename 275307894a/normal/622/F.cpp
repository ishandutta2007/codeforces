#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 1000000
#define M 200000
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define IT set<ques>::iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int k;ll n,frc[N+5],inv[N+5],ans,tot,pus,a[N+5],b[N+5];
I ll mpow(ll x,int y=mod-2){ll ans=1;while(y) (y&1)&&(ans=ans*x%mod),x=x*x%mod,y>>=1;return ans;}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%lld%d",&n,&k);for(i=1;i<=k+2;i++) a[i]=i,b[i]=(mpow(i,k)+b[i-1])%mod;if(n<=k+2){printf("%lld\n",b[n]);return 0;}frc[0]=1;
	for(i=1;i<=k+2;i++) frc[i]=frc[i-1]*i%mod;inv[k+2]=mpow(frc[k+2]);for(i=k+1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;for(ans=i=1;i<=k+2;i++) ans=ans*(n-i)%mod;
	for(i=1;i<=k+2;i++)tot+=ans*mpow(n-i)%mod*inv[i-1]%mod*((k-i)&1?mod-inv[k+2-i]:inv[k+2-i])%mod*b[i]%mod;printf("%lld\n",tot%mod);
}