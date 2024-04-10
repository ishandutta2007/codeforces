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
#define N 200000
#define M 100000
#define mod 1000000007
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
int n,m,W[N+5],Bg[N+5],En[N+5],cnt,fa[N+5],x,y,T[N+5],Fl[N+5];ll ToT;
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
I void dfs(int x,int La){yyy tmp;Bg[x]=1e9;En[x]=0;for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(dfs(tmp.to,x),Bg[x]=min(Bg[x],Bg[tmp.to]),En[x]=max(En[x],En[tmp.to]));Bg[x]>n&&(Bg[x]=En[x]=++cnt);}
struct Edge{int x,y,w,id;}S[N+5];I bool cmp(Edge x,Edge y){return x.w<y.w;}I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
int main(){
	//freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&W[i]),fa[i]=i;for(i=1;i<n;i++)scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);dfs(1,0);
	for(i=1;i<=n;i++) S[i]=(Edge){Bg[i],En[i]+1,W[i],i};sort(S+1,S+n+1,cmp);for(i=1;i<=n;i=j){
		for(j=i+1;j<=n;j++) if(S[j].w^S[i].w) break;for(h=i;h<j;h++) GF(S[h].x)^GF(S[h].y)&&(Fl[S[h].id]=1);for(h=i;h<j;h++) GF(S[h].x)^GF(S[h].y)&&(fa[GF(S[h].x)]=GF(S[h].y),ToT+=S[h].w);
	}printf("%lld ",ToT);for(cnt=0,i=1;i<=n;i++) cnt+=Fl[i];printf("%d\n",cnt);for(i=1;i<=n;i++) Fl[i]&&(printf("%d ",i));
}