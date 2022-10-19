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
#define N ((1<<19)+5)
#define M (100+5)
#define K (200000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
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
int n,m,A[K],B[K],E[N],D[N],frc[K],Inv[K],P[K],G1[M][K],G2[M][K],F1[K],F2[K];ll Ans;char S[M];
I int mpow(int x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=1ll*Ans*x%mod),y>>=1,x=1ll*x*x%mod;return Ans;}const int G=3,InvG=mpow(G);
I int C(int x,int y){return 1ll*frc[x]*Inv[y]%mod*Inv[x-y]%mod;}
int tr[N],k;I void Init(int n){k=1;while(k<=n+1)k<<=1;for(RI i=0;i<k;i++) tr[i]=(tr[i>>1]>>1)|(i&1?k/2:0),E[i]=D[i]=0;}
I void NTT(int *A,int n,int flag){
	RI i,j,h,key,now,pus;for(i=0;i<n;i++) i<tr[i]&&(swap(A[i],A[tr[i]]),0);for(i=2;i<=n;i<<=1){
		for(key=mpow(flag?G:InvG,(mod-1)/i),j=0;j<n;j+=i){
			for(now=1,h=j;h<j+i/2;h++) pus=1ll*now*A[h+i/2]%mod,A[h+i/2]=(A[h]-pus+mod)%mod,A[h]=(A[h]+pus)%mod,now=1ll*now*key%mod;
		}
	}if(flag) return;RI invn=mpow(n);for(i=0;i<n;i++) A[i]=1ll*A[i]*invn%mod;
}
I void Solve(int l,int r,int op,int *F){
	if(l==r){if(op){for(RI i=1;i<=min(m,l-1);i++) F[l]=(1ll*(G2[i][l]-P[l-i+1]+mod)*F[i]%mod*C(l-2,i-1)+F[l])%mod;}if(l==1) F[1]=1;return;}
	RI i,m=l+r>>1,L1=m-l+1,L2=r-m;Solve(l,m,op,F);Init(L1*2+L2);for(i=0;i<L1;i++) E[i]=1ll*F[l+i]*Inv[l+i-1]%mod;for(i=0;i<L1+L2;i++) D[i]=1ll*P[i+1]*(i?Inv[i-1]:0)%mod;
	NTT(E,k,1);NTT(D,k,1);for(i=0;i<k;i++) E[i]=1ll*E[i]*D[i]%mod;NTT(E,k,0);for(i=L1;i<L1+L2;i++) F[l+i]=(1ll*E[i]*frc[l+i-2]+F[l+i])%mod;
	Solve(m+1,r,op,F);
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d%s",&n,&m,S+1);for(i=1;i<n;i++)i>m?(A[i]=B[i]=1):(S[i]^'<'?(A[i]=1):(B[i]=1));
	for(frc[0]=Inv[0]=i=1;i<=n;i++) frc[i]=1ll*frc[i-1]*i%mod,Inv[i]=mpow(frc[i]);
	for(P[2]=P[3]=1,i=4;i<=n;i++) P[i]=P[i-1]*2%mod;
	for(i=m;i;i--){G2[i][i+1]=A[i];G1[i][i+1]=B[i];G1[i][i+2]=G2[i][i+2]=B[i]*A[i+1];
		for(j=i+3;j<=n;j++)G1[i][j]=G2[i][j]=B[i]*A[j-1]*((i^m?G2[i+1][j]:P[j-i])+G1[i][j-1])%mod;
	}
	Solve(1,n,1,F1);Solve(1,n-m,0,F2);reverse(F2+1,F2+n+1);for(i=m;i;i--) for(j=i+1;j<=n;j++) F2[i]=(F2[i]+1ll*F2[j]*G1[i][j]%mod*C(n-i-1,n-j))%mod;
	//for(F1[1]=1,i=2;i<=n;i++) for(j=1;j<i;j++) F1[i]=(F1[i]+F1[j]*(j<=m?G2[j][i]:P[i-j+1])%mod*C(i-2,j-1))%mod;
	for(i=1;i<=n;i++)Ans+=1ll*F1[i]*F2[i]%mod*C(n-1,i-1)%mod;printf("%lld\n",Ans%mod);
}