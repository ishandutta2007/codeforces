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
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,x,A[N+5],B[N+5],Bh;ll Ans,ToT,P1,P2,T1,T2;
I ll calc(){
	ToT=1;RI i,j,h;for(i=0;i<=Bh;i=j){
		for(j=i+1;j<=Bh;j++) if(B[j]!=-1) break;if(i+1==j) {ToT=ToT*(B[i]!=B[j]);continue;}
		x=j-i-2;if(i) P1=0,P2=1;else P1=1,P2=1;for(h=1;h<=x;h++) T1=P1,T2=P2,P1=T2*(k-1)%mod,P2=(T1+T2*(k-2))%mod;
		if(j==Bh+1) ToT=(P2*(k-1)+P1)%mod*ToT%mod;else ToT=ToT*(B[i]^B[j]?(P2*(k-2)+P1)%mod:P2*(k-1)%mod)%mod;
	}return ToT;
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=n;i+=2) B[++Bh]=A[i];
	Ans=calc();Me(B,0);Bh=0;for(i=2;i<=n;i+=2) B[++Bh]=A[i];Ans=Ans*calc()%mod;printf("%lld\n",Ans);
}