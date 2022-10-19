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
#define N 200000
#define K 1000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int T,T1,T2,n,dp[N+5][2],F1,F2;ll frc[N+5],Inv[N+5],Ans,ToT=1;char A[N+5][2];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
I ll C(int x,int y){return frc[x]*Inv[y]%mod*Inv[x-y]%mod;}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%s",A[i]),T1+=(A[i][0]=='B')+(A[i][1]=='B'),T2+=(A[i][0]=='W')+(A[i][1]=='W');
	for(frc[0]=Inv[0]=1,i=1;i<=2*n;i++) frc[i]=frc[i-1]*i%mod,Inv[i]=Inv[i-1]*mpow(i)%mod;
	if(T1>n||T2>n){puts("0");return 0;}Ans=C(2*n-T1-T2,n-T1);
	for(i=1;i<=n;i++) if(A[i][0]==A[i][1]&&A[i][0]^'?'){printf("%lld\n",Ans);return 0;}
	ToT=1;for(i=1;i<=n;i++) if(A[i][0]=='?'&&A[i][1]=='?') ToT=ToT*2%mod;
	Ans=(Ans-ToT+mod)%mod;for(i=1;i<=n;i++){ if((A[i][0]=='W'||A[i][1]=='B')&&!F1) F1=1; if((A[i][0]=='B'||A[i][1]=='W')&&!F2)F2=1;}Ans+=(!F1)+(!F2);printf("%lld\n",Ans%mod);
}