#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 300000
#define K 400
#define mod 998244353
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Pc(x) putchar(x) 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
using namespace std;
int n,m,k,A[N+5],B[N+5],Bh,tr[N+5];ll ToT,Pus,C[4][N+5],D[4][N+5],T2[4][N+5],T1[4][N+5],F[4][N+5],Gs[N+5],InvG[N+5],Po[N+5];
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}const ll G=3,invG=mpow(G),inv2=mpow(2);
I void NTT(ll *F,int n,int flag){
	re int i,j,h;re ll key,pus,now;for(i=0;i<n;i++)i<tr[i]&&(swap(F[i],F[tr[i]]),0);for(i=2;i<=n;i<<=1){
		for(key=flag?Gs[i]:InvG[i],j=0;j<n;j+=i){
			for(now=1,h=j;h<j+i/2;h++) pus=now*F[h+i/2]%mod,F[h+i/2]=(F[h]-pus<0?F[h]-pus+mod:F[h]-pus),F[h]=(F[h]+pus>mod?F[h]+pus-mod:F[h]+pus),now=now*key%mod;
		}
	}if(!flag){ll inv=Po[n];for(i=0;i<n;i++) F[i]=F[i]*inv%mod;}
}
I void Solve(int l,int r){
	if(l==r){B[l]^1?(F[3][l]=2):(F[0][l]=1);return;}int m=l+r>>1;Solve(l,m);Solve(m+1,r);re int i,j,h,now;
	for(k=1;k<=(r-l+2);k<<=1);for(i=0;i<k;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?k/2:0);for(i=0;i<4;i++){ for(j=l;j<=m;j++) C[i][j-l+1]=F[i][j],F[i][j]=0;for(j=m+1;j<=r;j++)D[i][j-m]=F[i][j],F[i][j]=0;}for(i=0;i<4;i++) NTT(C[i],k,1),NTT(D[i],k,1);
	for(i=0;i<4;i++) for(j=0;j<4;j++) for(now=((i>>1)<<1)|(j&1),h=0;h<k;h++) T1[now][h]+=C[i][h]*D[j][h],T2[now][h]+=C[i][h]*D[j][h]%mod*((i&1)^(j>>1)?1:(i&1?inv2:2));for(i=0;i<4;i++) for(j=0;j<k;j++) T1[i][j]%=mod,T2[i][j]%=mod;
	for(i=0;i<4;i++) NTT(T1[i],k,0),NTT(T2[i],k,0);if(l+1==r){for(i=0;i<k;i++) T2[3][i]=(T2[0][i]+T2[1][i]+T2[2][i]+T2[3][i])%mod,T2[1][i]=T2[2][i]=T2[0][i]=0;}
	if(l+2==r){for(i=0;i<k;i++) T2[1][i]=(T2[1][i]+T2[0][i])%mod,T2[3][i]=(T2[3][i]+T2[2][i])%mod,T2[2][i]=T2[0][i]=0;}for(i=0;i<4;i++)for(j=l;j<=r;j++) F[i][j]=(T1[i][j-l+1]+T2[i][j-l+2])%mod;
	for(i=0;i<4;i++) for(j=0;j<k;j++)T1[i][j]=T2[i][j]=C[i][j]=D[i][j]=0; 
}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d",&n);for(i=1;i<=n;i++)scanf("%d",&A[i]);for(i=1;i<=n;i=j){
		for(j=i;j<=i+A[i]-1;j++) if(A[i]^A[j]){puts("0");return 0;}B[++Bh]=A[i];}for(i=2;i<=(n<<1);i<<=1) Gs[i]=mpow(G,(mod-1)/i),InvG[i]=mpow(invG,(mod-1)/i),Po[i]=mpow(i);Solve(1,Bh);
	for(Pus=i=1;i<=Bh;i++) Pus=Pus*i%mod,ToT=(ToT+((Bh-i)&1?mod-Pus:Pus)*(F[0][i]+F[1][i]+F[2][i]+F[3][i]))%mod;printf("%lld\n",ToT);
}