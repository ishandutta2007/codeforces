#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define M 50000
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define R(x) (rand()*rand()%x+1)
using namespace std;
int T,n,rs,x,y,nowx,nowy;ll ans,tot,pus,frc[N+5],inv[N+5],l,r;
I ll mpow(ll x,int y=mod-2){ll ans=1;while(y) (y&1)&&(ans=ans*x%mod),y>>=1,x=x*x%mod;return ans;}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);frc[0]=1;for(i=1;i<=N;i++) frc[i]=frc[i-1]*i%mod;inv[N]=mpow(frc[N]);for(i=N-1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;
	while(T--){
		scanf("%d%lld%lld",&n,&l,&r);rs=max(min(1-l,r-n),1);
		ans=(rs-1)*frc[n]%mod*inv[n/2]%mod*inv[(n+1)/2]%mod;x=rs+l;y=r-rs;
		while(1){
			if(x>y+1||y+1<(n)/2||x-1>(n)/2)break;nowx=max(x,1);nowy=min(y,n);
			pus=nowy-nowx+1;ans+=frc[pus]*inv[pus-(n/2-nowx+1)]%mod*inv[n/2-nowx+1]%mod;
			/*printf("%d %d %lld %lld\n",x,y,(n/2-nowx+1),frc[pus]*inv[pus-(n/2-nowx+1)]%mod*inv[n/2-nowx+1]%mod);*/x++;y--;
		}
		if(n&1){
			rs=max(min(1-l,r-n),1);
	    	ans+=(rs-1)*frc[n]%mod*inv[n/2]%mod*inv[(n+1)/2]%mod;x=rs+l;y=r-rs;
    		while(1){
    			if(x>y+1||y+1<(n+1)/2||x-1>(n+1)/2)break;nowx=max(x,1);nowy=min(y,n);
    			pus=nowy-nowx+1;ans+=frc[pus]*inv[pus-((n+1)/2-nowx+1)]%mod*inv[((n+1)/2-nowx+1)]%mod;
    			/*printf("%d %d %lld %lld\n",x,y,pus,frc[pus]*inv[pus-((n+1)/2-nowx+1)]%mod*inv[((n+1)/2-nowx+1)]%mod);*/x++;y--;
    		}
		}
		printf("%lld\n",ans%mod);
	}
}