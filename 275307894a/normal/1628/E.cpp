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
#define N (600000+5)
#define M (1<<23)+5
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
using namespace std;
int n,m,k,op,x,y,Ro,fa[N+5],D[N+5],W[N+5],H,Bg[N],lg[N<<1],Df[N<<1],st[N<<1][22];vector<int> S[N+5];
struct Edge{int x,y,w;}P[N];I bool cmp(Edge x,Edge y){return x.w<y.w;}
I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
I void Make(int x,int La){D[x]=D[La]+1;Df[Bg[x]=++H]=x;for(RI i:S[x]) Make(i,x),Df[++H]=x;}
I int LCA(int x,int y){x=Bg[x];y=Bg[y];x>y&&(swap(x,y),0);int d=lg[y-x+1];return D[st[x][d]]<D[st[y-(1<<d)+1][d]]?st[x][d]:st[y-(1<<d)+1][d];}
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	int F[N+5<<2],G[N+5<<2],Fl[N+5<<2];I void Up(int now){if(!F[ls]&&!F[rs]) F[now]=0;else if(F[ls]&&F[rs]) F[now]=LCA(F[ls],F[rs]);else F[now]=F[ls]|F[rs];}
	I void PF(int now,int w){Fl[now]=w;F[now]=(~w?G[now]:0);};I void P(int now){Fl[now]&&(PF(ls,Fl[now]),PF(rs,Fl[now]),Fl[now]=0);}
	I void BD(int l=1,int r=n,int now=1){if(l==r) {G[now]=l;return;}int m=l+r>>1;BD(l,m,ls);BD(m+1,r,rs);G[now]=LCA(G[ls],G[rs]);}
	I void Ins(int x,int y,int w,int l=1,int r=n,int now=1){if(x<=l&&r<=y) return PF(now,w);int m=l+r>>1;P(now);x<=m&&(Ins(x,y,w,l,m,ls),0);y>m&&(Ins(x,y,w,m+1,r,rs),0);Up(now);}
	#undef ls
	#undef rs
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&m);Ro=n;for(i=1;i<n;i++) scanf("%d%d%d",&P[i].x,&P[i].y,&P[i].w);sort(P+1,P+n,cmp);
	for(i=1;i<=n*2;i++) fa[i]=i;for(i=1;i<n;i++) W[++Ro]=P[i].w,S[Ro].PB(GF(P[i].x)),S[Ro].PB(GF(P[i].y)),fa[GF(P[i].x)]=fa[GF(P[i].y)]=Ro;
	Make(Ro,0);for(i=H;i;i--) for(st[i][0]=Df[i],j=1;i+(1<<j)-1<=H;j++) st[i][j]=(D[st[i][j-1]]<D[st[i+(1<<j-1)][j-1]]?st[i][j-1]:st[i+(1<<j-1)][j-1]);
	for(i=2;i<=H;i++) lg[i]=lg[i/2]+1;Tree::BD();while(m--){
		scanf("%d%d",&op,&x),op<=2?(scanf("%d",&y),Tree::Ins(x,y,op^1?-1:1),0):(printf("%d\n",Tree::F[1]&&Tree::F[1]^x?W[LCA(x,Tree::F[1])]:-1));
	}
}