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
#define N (500000+5)
#define M (500000+5)
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
using namespace std;vector<int> S[N+5];
int n,m,Q,Op[N+5],fa[N+5][20],lg[N+5],d[N+5],Bg[N+5],En[N+5],Df[N+5],Bh,X[N+5],un,wn,cnt,A[N+5],F[N+5],W[N+5];
struct Ques{int x,y,w;}G[N+5];I bool cmp(Ques x,Ques y){return x.w>y.w;}
I int GF(int x){return x^F[x]?F[x]=GF(F[x]):x;}
I void dfs(int x,int La){d[x]=d[La]+1;fa[x][0]=La;for(RI i=1;fa[x][i-1];i++) fa[x][i]=fa[fa[x][i-1]][i-1];Bg[x]=Bh+1;x<=n&&(Df[++Bh]=x);for(RI i:S[x]) dfs(i,x);En[x]=Bh;}
struct Pa{int w,Id;Pa operator +(const Pa &B)const{return w>B.w?(Pa){w,Id}:B;};}Cl,Pus;
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	Pa W[N+5<<2];I void Up(int now){W[now]=W[ls]+W[rs];}
	I void BD(int l=1,int r=n,int now=1){if(l==r) {W[now]=(Pa){A[Df[l]],l};return;}int m=l+r>>1;BD(l,m,ls);BD(m+1,r,rs);Up(now);}
	I Pa Qry(int x,int y,int l=1,int r=n,int now=1){if(x<=l&&r<=y) return W[now];int m=l+r>>1;Pa Ns=Cl;x<=m&&(Ns=Ns+Qry(x,y,l,m,ls),0);y>m&&(Ns=Ns+Qry(x,y,m+1,r,rs),0);return Ns;}
	I void Ins(int x,int l=1,int r=n,int now=1){if(l==r){W[now].w=0;return;}int m=l+r>>1;x<=m?Ins(x,l,m,ls):Ins(x,m+1,r,rs);Up(now);}
	#undef ls
	#undef rs
}
I int Jp(int x,int T){for(RI i=lg[d[x]];~i;i--) W[fa[x][i]]>=T&&(x=fa[x][i]);return x;}
int main(){
//	freopen("1.in","r",stdin);
	Cl=(Pa){-(int)1e9,0};RI i;scanf("%d%d%d",&n,&m,&Q);cnt=n;for(i=2;i<=n*2;i++) lg[i]=lg[i/2]+1;for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=m;i++) scanf("%d%d",&G[i].x,&G[i].y),G[i].w=1e9;
	for(i=1;i<=Q;i++) scanf("%d%d",&Op[i],&X[i]),Op[i]^1&&(G[X[i]].w=i);for(i=1;i<=2*n;i++) F[i]=i;sort(G+1,G+m+1,cmp);
	for(i=1;i<=m;i++) un=GF(G[i].x),wn=GF(G[i].y),un^wn&&(W[++cnt]=G[i].w,S[cnt].PB(un),S[cnt].PB(wn),F[un]=cnt,F[wn]=cnt);for(i=cnt;i;i--)!Bg[i]&&(dfs(i,0),0);
	Tree::BD();for(i=1;i<=Q;i++){if(Op[i]==2) continue;X[i]=Jp(X[i],i);Pus=Tree::Qry(Bg[X[i]],En[X[i]]);printf("%d\n",Pus.w);Tree::Ins(Pus.Id);}
}