#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100000
#define M 30
#define mod 998244353
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,k,now,tot,pus,T,A[N+5],odd;ll frc[N+5],inv[N+5];char c;
I ll mpow(ll x,int y=mod-2){ll ans=1;while(y) (y&1)&&(ans=ans*x%mod),x=x*x%mod,y>>=1;return ans;}
I void solve(){
	re int i;scanf("%d",&n);A[n+1]=0;pus=odd=now=0;for(i=1;i<=n;i++){
		c=Gc();while(c<'0'||c>'9') c=Gc();A[i]=c-'0'; pus+=A[i]^1;
	}
	for(i=1;i<=n;i++) !A[i]?(odd+=now/2,now=0):(now++);odd+=now/2;printf("%lld\n",frc[odd+pus]*inv[odd]%mod*inv[pus]%mod);
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;for(frc[0]=i=1;i<=N;i++)frc[i]=frc[i-1]*i%mod;inv[N]=mpow(frc[N]);for(i=N-1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod; 
	scanf("%d",&T);while(T--) solve();
}