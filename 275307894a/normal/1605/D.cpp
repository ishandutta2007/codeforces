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
#define N 1100000
#define M 300000
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int T,n,Fl[N+5],x,y,H,cnt,B[N+5],Bh,m,C[N+5],Ch,D[N+5],Fs[N+5];
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
I void dfs(int x,int La){yyy tmp;for(int i=s.h[x];i;i=tmp.z)tmp=s.f[i],tmp.to^La&&(Fl[tmp.to]=Fl[x]^1,dfs(tmp.to,x),0);}
I void Solve(){
	RI i,j;scanf("%d",&n);s.head=0;for(i=1;i<=n;i++) D[i]=Fs[i]=s.h[i]=0;for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);dfs(1,0);
	cnt=0;for(i=1;i<=n;i++) cnt+=Fl[i],Fl[i]&&(C[++Ch]=i);m=n;Bh=0;for(i=1;;i++) if(m<=(1<<i-1)){B[++Bh]=m;break;}else B[++Bh]=(1<<i-1),m-=(1<<i-1);
	m=cnt;for(i=Bh;i;i--){
		if(m<B[i]) continue;m-=B[i];for(j=1;j<=B[i];j++) D[C[Ch--]]=j+(1<<i-1)-1,Fs[j+(1<<i-1)-1]=1;
	}H=1;
	for(i=1;i<=n;i++){
		if(D[i]) continue;while(Fs[H]) H++;D[i]=H;Fs[H]=1;
	}for(i=1;i<=n;i++) printf("%d ",D[i]);puts("");
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}