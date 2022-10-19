#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (50000+5)
#define K (20+5)
#define mod 1000000007
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
using namespace std;vector<int> S[N];
int n,m,k,X[N<<2],Y[N<<2],R,Mn,Mk,Fl[N],phi[N],ph,pr[N];ll dp[K][N],Ans[N<<2];
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	ll F[N<<2],G[N<<2];I void Up(int now){F[now]=min(F[ls],F[rs])+G[now];}I void PF(int now,ll z){F[now]+=z;G[now]+=z;}
	I void Cl(int x,ll y,int l=0,int r=Mn,int now=1){if(l==r) {F[now]=y;return;}int m=l+r>>1;x<=m?Cl(x,y,l,m,ls):Cl(x,y,m+1,r,rs);Up(now);}
	I void Ins(int x,int y,ll z,int l=0,int r=Mn,int now=1){if(x<=l&&r<=y) return PF(now,z);int m=l+r>>1;x<=m&&(Ins(x,y,z,l,m,ls),0);y>m&&(Ins(x,y,z,m+1,r,rs),0);Up(now);} 
	#undef ls
	#undef rs
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) {scanf("%d%d",&X[i],&Y[i]);if(Y[i]>20||(1<<Y[i])>=X[i]) Ans[i]=X[i];else Mn=max(Mn,X[i]),Mk=max(Mk,Y[i]);}
	phi[1]=1;for(i=2;i<=Mn;i++){
		!Fl[i]&&(pr[++ph]=i,phi[i]=i-1);for(j=1;j<=ph&&i*pr[j]<=Mn;j++) {Fl[i*pr[j]]=1;if(i%pr[j]==0){phi[i*pr[j]]=phi[i]*pr[j];break;}phi[i*pr[j]]=phi[i]*(pr[j]-1);}
	}for(i=1;i<=Mn;i++) for(j=i;j<=Mn;j+=i) S[j].PB(i);Me(dp,0x3f);dp[0][0]=0;
	for(i=1;i<=Mk;i++){
		R=0;Me(Tree::F,0x3f);Me(Tree::G,0);for(j=0;j<=Mn;j++) {for(int h:S[j]) Tree::Ins(0,h-1,phi[j/h]);dp[i][j]=Tree::F[1];Tree::Cl(j,dp[i-1][j]);}
		for(j=1;j<=n;j++) Y[j]==i&&(Ans[j]=dp[i][X[j]]);
	}for(i=1;i<=n;i++) printf("%lld\n",Ans[i]);
}