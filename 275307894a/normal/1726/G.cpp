#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=6e5+5,M=(1<<18)+5,K=1e5+5,mod=998244353,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;
int n,x,A[N],Mi=1e9,Mx,S1[N],S2[N],Ct;ll frc[N],Inv[N],ToT;
ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}
ll C(int x,int y){return frc[x]*Inv[x-y]%mod;}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),Mi=min(Mi,A[i]);Mx=Mi+n-1;
	for(i=1;i<=n;i++) if(A[i]>Mx){puts("0");return 0;}for(i=1;i<=n;i++) scanf("%d",&x),x?S2[A[i]]++:S1[A[i]]++;
	for(frc[0]=Inv[0]=i=1;i<=n;i++) frc[i]=frc[i-1]*i%mod,Inv[i]=mpow(frc[i]);int ZJAKIOI=0;for(i=1;i<=n;i++) if(A[i]^Mi) ZJAKIOI=1;if(!ZJAKIOI){printf("%lld\n",frc[n]);return 0;}
	for(i=Mi;i<Mx;i++) {if((Ct<Mx-i&&S1[i])||S2[i]>1) {puts("0");return 0;}Ct+=S1[i];if(Ct<i-Mi&&S2[i]){puts("0");return 0;}Ct+=S2[i];}
	ToT=frc[S1[Mx]];for(i=Mi;i<Mx;i++) ToT=ToT*frc[S1[i]]%mod*frc[S2[i]]%mod;printf("%lld\n",ToT*C(n,S2[Mx])%mod);
}