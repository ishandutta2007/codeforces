#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 300000
#define K 50
#define mod 998244353
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,m,x;ll A[N+5],B[N+5],C[N+5];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
namespace Poly{
	int tr[N+5],k;const int G=3,invG=mpow(G);ll C[N+5],D[N+5],invn;I void Init(int n){for(k=1;k<=(n<<1);k<<=1);for(RI i=0;i<k;i++) tr[i]=(tr[i>>1]>>1)|(i&1?k/2:0),C[i]=D[i]=0;}
	I void NTT(ll *F,int n,int flag){
		RI i,j,h;ll pus,now,key;for(i=0;i<n;i++) i<tr[i]&&(swap(F[i],F[tr[i]]),0);for(i=2;i<=n;i<<=1){
			for(key=mpow(flag?G:invG,(mod-1)/i),j=0;j<n;j+=i){
				for(now=1,h=j;h<j+i/2;h++) pus=now*F[h+i/2]%mod,F[h+i/2]=(F[h]-pus+mod)%mod,F[h]=(F[h]+pus)%mod,now=now*key%mod;
			}
		}if(flag) return;invn=mpow(n);for(i=0;i<n;i++)F[i]=F[i]*invn%mod;
	}
	namespace Inv{
		I void Sl(ll *A,ll *B,int n){
			if(n==1){B[0]=mpow(A[0]);return;}Sl(A,B,n+1>>1);Init(n);RI i;for(i=0;i<n;i++) C[i]=A[i],D[i]=B[i];NTT(C,k,1);NTT(D,k,1);for(i=0;i<k;i++) C[i]=(2-C[i]*D[i]%mod+mod)*D[i]%mod;NTT(C,k,0);for(i=0;i<n;i++)B[i]=C[i]; 
		}
	}
	namespace Sqrt{
		ll F[N+5];const ll inv2=mpow(2);I void Sl(ll *A,ll *B,int n){
			if(n==1){B[0]=1;return;}Sl(A,B,n+1>>1);RI i;for(i=0;i<n;i++) F[i]=0;Inv::Sl(B,F,n);Init(n);for(i=0;i<n;i++) C[i]=F[i],D[i]=A[i];NTT(C,k,1);NTT(D,k,1);for(i=0;i<k;i++) C[i]=C[i]*D[i]%mod;NTT(C,k,0);for(i=0;i<n;i++) B[i]=(B[i]+C[i])*inv2%mod;
		}
	}
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d",&m,&n);while(m--)scanf("%d",&x),x<=n&&(A[x]=1);for(i=0;i<=n;i++) A[i]=(!i-4*A[i]+mod)%mod;Poly::Sqrt::Sl(A,B,n+1);B[0]++;
	Poly::Inv::Sl(B,C,n+1);for(i=1;i<=n;i++) printf("%lld\n",C[i]*2%mod);
}