#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
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
int n,X[N],V[N],Z[N],Qh;ll Ans;
I ll mpow(ll x,int y=mod-2){ll Ans=1;while(y) y&1&&(Ans=Ans*x%mod),y>>=1,x=x*x%mod;return Ans;}const int Inv=mpow(100);
struct MaT{
	ll F[2][2];I MaT(){Me(F,0);}
	MaT operator *(const MaT &B)const{MaT C;int i,j,h;for(h=0;h<2;h++) for(i=0;i<2;i++) for(j=0;j<2;j++) C.F[i][j]=(F[i][h]*B.F[h][j]+C.F[i][j])%mod;return C;}
}P[N],Ps;I MaT calc(int x){MaT P;P.F[0][0]=P.F[1][0]=x;P.F[0][1]=P.F[1][1]=(1-x+mod)%mod;return P;}
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	MaT F[N<<2];I void Up(int now){F[now]=F[ls]*F[rs];}
	I void BD(int l=0,int r=n,int now=1){if(l==r) {l?(F[now]=P[l],0):(F[now].F[0][0]=1);return;}int m=l+r>>1;BD(l,m,ls);BD(m+1,r,rs);Up(now);}
	I void Ins(int x,MaT y,int l=0,int r=n,int now=1){if(l==r){F[now]=y;return;}int m=l+r>>1;x<=m?Ins(x,y,l,m,ls):Ins(x,y,m+1,r,rs);Up(now);}
	#undef ls
	#undef rs
}
struct Ques{db w;int O1,O2,Id;ll T;}Q[N<<2];I bool cmp(Ques x,Ques y){return x.w<y.w;}
int main(){
//	freopen("1.in","r",stdin);
	int i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d%d%d",&X[i],&V[i],&Z[i]),P[i]=calc(1ll*Inv*Z[i]%mod);Tree::BD();
	for(i=1;i<n;i++) Q[++Qh]=(Ques){(X[i+1]-X[i])*1.0/(V[i]+V[i+1]),0,1,i+1,(X[i+1]-X[i])*mpow(V[i]+V[i+1])%mod},Q[++Qh]=(Ques){(X[i]-X[i+1])*1.0/(V[i+1]+V[i]),1,0,i+1,(X[i]-X[i+1])*mpow(V[i+1]+V[i])%mod},
	V[i]^V[i+1]&&(Q[++Qh]=(Ques){(X[i+1]-X[i])*1.0/(V[i+1]-V[i]),1,1,i+1,(X[i+1]-X[i])*mpow(V[i+1]-V[i])%mod},Q[++Qh]=(Ques){(X[i]-X[i+1])*1.0/(V[i+1]-V[i]),0,0,i+1,(X[i+1]-X[i])*mpow(V[i]-V[i+1])%mod},0);
	sort(Q+1,Q+Qh+1,cmp);for(i=1;i<=Qh;i++){if(Q[i].w<0) continue;
		Ps=P[Q[i].Id],Ps.F[Q[i].O1][Q[i].O2^1]=Ps.F[Q[i].O1^1][Q[i].O2]=Ps.F[Q[i].O1^1][Q[i].O2^1]=0,Tree::Ins(Q[i].Id,Ps),Ans+=(Tree::F[1].F[0][0]+Tree::F[1].F[0][1])*Q[i].T%mod;
		P[Q[i].Id].F[Q[i].O1][Q[i].O2]=0;Tree::Ins(Q[i].Id,P[Q[i].Id]);
	}printf("%lld\n",(Ans%mod+mod)%mod);
}