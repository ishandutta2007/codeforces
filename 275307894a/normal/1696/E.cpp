#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (400000+5)
#define M (30000+5)
#define K (6)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,A[N];ll Ans,ToT,frc[N],Inv[N];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
I ll C(int x,int y){return frc[x+y]*Inv[y]%mod*Inv[x]%mod;}
int main(){
/////	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=0;i<=n;i++) scanf("%d",&A[i]),A[i]--;for(frc[0]=Inv[0]=1,i=1;i<=A[0]+n;i++) frc[i]=frc[i-1]*i%mod,Inv[i]=mpow(frc[i]);
	A[n+1]--;ToT=1;for(i=1;i<=n+1;i++){
		if(A[i]>=0)ToT+=C(A[i],i);for(j=A[i-1];j>A[i];j--) ToT+=C(i-1,j);
	}printf("%lld\n",(ToT-1+mod)%mod);
}