#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N ((1<<19)+5)
#define M (100+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k;ll Ans,F[N],G[N],B[N],D[N],frc[N],Inv[N],tr[N];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
const int g=3,Invg=mpow(3);
I void Init(int x){for(k=1;k<=2*x;k<<=1);for(int i=0;i<k;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?(k/2):0);}
I void NTT(ll *A,int n,int Fl){
	int i,j,h;ll pus,key,now;for(i=0;i<n;i++) i>tr[i]&&(swap(A[i],A[tr[i]]),0);for(i=2;i<=n;i<<=1){
		for(key=mpow(Fl?g:Invg,(mod-1)/i),j=0;j<n;j+=i){
			for(now=1,h=j;h<j+i/2;h++) pus=now*A[h+i/2]%mod,A[h+i/2]=(A[h]-pus+mod)%mod,A[h]=(A[h]+pus)%mod,now=now*key%mod;
		}
	}if(Fl) return;int Invn=mpow(n);for(i=0;i<n;i++) A[i]=A[i]*Invn%mod;
}
int main(){
////	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(frc[0]=Inv[0]=i=1;i<=n;i++) frc[i]=frc[i-1]*i%mod,Inv[i]=mpow(frc[i]);Init(n);
	for(i=1;i<=n;i++)G[i]=frc[i-1]*(1-Ans+mod)%mod,i>n/2&&(Ans=(Ans+mpow(i))%mod);
	for(i=n/2+1;i<=n;i++) B[i]=Inv[i-1]*G[i]%mod*frc[n-i-1]%mod;for(i=0;i<=n;i++) D[i]=Inv[i]%mod;
	NTT(B,k,1);NTT(D,k,1);for(i=0;i<k;i++) B[i]=B[i]*D[i]%mod;NTT(B,k,0);for(i=1;i<=n;i++) printf("%lld ",i^1?B[n-i+1]*frc[n-i]%mod*(i-1)%mod:G[n]);
	/*for(i=1;i<=n;i++){if(i==1){printf("%lld ",(G[n]+mod)%mod);continue;}
		Ans=0;for(j=n/2+1;j<=n-i+1;j++) Ans+=Inv[j-1]*Inv[n-i-(j-1)]%mod*G[j]%mod*frc[n-j-1]%mod;printf("%lld ",(Ans%mod*frc[n-i]%mod*(i-1)%mod+mod)%mod);
	}*/
}