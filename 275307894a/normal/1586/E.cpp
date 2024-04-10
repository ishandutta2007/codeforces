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
#define M 30
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,k,fa[N+5],x,y,z,un,wn,Fl,X[N+5],Y[N+5],W[N+5],d[N+5],Fa[N+5],B[N+5],Bh,C[N+5],Ch,Ws[N+5];
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
I int Getfa(int x){return fa[x]==x?x:fa[x]=Getfa(fa[x]);}
I void Make(int x,int LA){Ws[x]=W[x]^Ws[LA];Fa[x]=LA;d[x]=d[LA]+1;yyy tmp;for(int i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^LA&&(Make(tmp.to,x),0);}
I void print(int x,int y){
	RI i;Bh=Ch=0;while(d[x]^d[y]) d[x]>d[y]?(B[++Bh]=x,x=Fa[x]):(C[++Ch]=y,y=Fa[y]);
	while(x^y) B[++Bh]=x,C[++Ch]=y,x=Fa[x],y=Fa[y];printf("%d\n",Bh+Ch+1);
	for(i=1;i<=Bh;i++) printf("%d ",B[i]);printf("%d ",x);for(i=Ch;i;i--) printf("%d ",C[i]);puts("");
}
I void Solve(){
	puts("YES");for(RI i=1;i<=m;i++)print(X[i],Y[i]);exit(0);
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) fa[i]=i;for(i=1;i<=m;i++) scanf("%d%d",&x,&y),un=Getfa(x),wn=Getfa(y),un^wn&&(s.add(x,y),s.add(y,x),fa[un]=wn);
	scanf("%d",&m);for(i=1;i<=m;i++)  scanf("%d%d",&X[i],&Y[i]),W[X[i]]^=1,W[Y[i]]^=1;Make(1,0);
	for(i=1;i<=n;i++)Fl|=Ws[i];if(!Fl)Solve();puts("NO");
	for(Fl=0,i=1;i<=n;i++) Fl+=W[i];printf("%d\n",Fl/2);
}