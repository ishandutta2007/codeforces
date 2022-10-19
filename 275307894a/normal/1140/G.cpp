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
#define K 500
#define mod 10000
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
int n,Q,lg[N+5],d[N+5],fa[N+5][20],x,y;ll z1,z2,W[N+5];
struct yyy{int to;ll w1,w2;int z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y,ll z1,ll z2){f[++head]=(yyy){y,z1,z2,h[x]};h[x]=head;}}s;
struct MaT{
	ll A[2][2];MaT(){Me(A,0x3f);}
	MaT operator *(const MaT &B)const{
		RI i,j,h;MaT C;for(h=0;h<2;h++){
			for(i=0;i<2;i++) for(j=0;j<2;j++) C.A[i][j]=min(C.A[i][j],A[i][h]+B.A[h][j]);
		}return C;
	}
}F[N+5][20],W1[N+5],W2[N+5],Pus,Cl;I MaT M1(ll x){Pus.A[0][0]=Pus.A[1][1]=0;Pus.A[0][1]=Pus.A[1][0]=x;return Pus;}I MaT M2(ll x,ll y){Me(Pus.A,0x3f);Pus.A[0][0]=x;Pus.A[1][1]=y;return Pus;}
I void dfs1(int x,int La){d[x]=d[La]+1;yyy tmp;for(RI i=s.h[x];i;i=tmp.z)tmp=s.f[i],tmp.to^La&&(dfs1(tmp.to,x),W[x]=min(W[x],W[tmp.to]+tmp.w1+tmp.w2));}
I void dfs2(int x,int La){RI i;W1[x]=M1(W[x]);for(fa[x][0]=La,F[x][0]=W1[x]*W2[x],i=1;fa[x][i-1];i++) fa[x][i]=fa[fa[x][i-1]][i-1],F[x][i]=F[x][i-1]*F[fa[x][i-1]][i-1];
yyy tmp;for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(W2[tmp.to]=M2(tmp.w1,tmp.w2),W[tmp.to]=min(W[tmp.to],W[x]+tmp.w1+tmp.w2),dfs2(tmp.to,x),0);}
I MaT LCA(int x,int y){
	MaT P1=Cl,P2=Cl;while(d[x]>d[y]) P1=P1*F[x][lg[d[x]-d[y]]],x=fa[x][lg[d[x]-d[y]]];while(d[x]<d[y]) P2=P2*F[y][lg[d[y]-d[x]]],y=fa[y][lg[d[y]-d[x]]];
	if(x^y) {for(RI i=lg[d[x]];~i;i--) fa[x][i]^fa[y][i]&&(P1=P1*F[x][i],P2=P2*F[y][i],x=fa[x][i],y=fa[y][i]);P1=P1*F[x][0];P2=P2*F[y][0];}swap(P2.A[0][1],P2.A[1][0]);return P1*W1[x^y?fa[x][0]:x]*P2;
}
int main(){
	//freopen("1.in","r",stdin);
	RI i;scanf("%d",&n);Cl.A[0][0]=Cl.A[1][1]=0;for(i=1;i<=n;i++) scanf("%lld",&W[i]);for(i=2;i<=n;i++) lg[i]=lg[i/2]+1,scanf("%d%d%lld%lld",&x,&y,&z1,&z2),s.add(x,y,z1,z2),s.add(y,x,z1,z2);
	dfs1(1,0);dfs2(1,0);scanf("%d",&Q);while(Q--)scanf("%d%d",&x,&y),printf("%lld\n",LCA((x+1)/2,(y+1)/2).A[(x+1)&1][(y+1)&1]);
}