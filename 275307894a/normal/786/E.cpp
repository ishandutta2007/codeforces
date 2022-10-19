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
#define N 30000
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
int n,m,k,fa[N+5][20],x,y,lg[N+5],Id[N+5][20],d[N+5],cnt,H;
struct yyy{int to,w,z;}tmp;struct ljb{int head,h[N+5<<4];yyy f[N+5<<6];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}s,g;
I void con(int x,int y,int z){g.add(x,y,z);g.add(y,x,0);}
namespace Dicnic{
	int S,T,ToT,vis[N+5<<4],d[N+5<<4],Ns[N+5<<4];queue<int> Q;I int BFS(){
		RI i;while(!Q.empty()) Q.pop();Q.push(S);Me(d,0x3f);d[S]=0;Ns[S]=s.h[S];while(!Q.empty()) for(x=Q.front(),Q.pop(),i=s.h[x];i;i=tmp.z){
			tmp=s.f[i];if(!tmp.w||d[tmp.to]<1e9) continue;d[tmp.to]=d[x]+1;Ns[tmp.to]=s.h[tmp.to];Q.push(tmp.to);if(tmp.to==T) return 1; 
		}return 0;
	}
	I int DFS(int x,int Sum){
		if(x==T)return Sum;RI i,pus=0,k;yyy tmp;for(i=Ns[x];i;i=tmp.z){
			Ns[x]=i;tmp=s.f[i];if(!tmp.w||d[tmp.to]!=d[x]+1) continue;k=DFS(tmp.to,min(tmp.w,Sum));if(!k) d[tmp.to]=1e9;Sum-=k;pus+=k;s.f[i].w-=k;s.f[i^1].w+=k;if(!Sum) break;
		}return pus; 
	}
	I int calc(){S=0;T=n+m+1;while(BFS()) ToT+=DFS(S,1e9);return ToT;}
	I void dfs(int x){vis[x]=1;yyy tmp;for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.w&&!vis[tmp.to]&&(dfs(tmp.to),0);}
}
I void Make(int x,int La){
    yyy tmp;RI i;for(fa[x][0]=La,i=1;fa[x][i-1];i++)fa[x][i]=fa[fa[x][i-1]][i-1],fa[x][i]&&(Id[x][i]=++cnt,con(Id[x][i]+m,Id[x][i-1]+m,1e9),con(Id[x][i]+m,Id[fa[x][i-1]][i-1]+m,1e9),0);d[x]=d[La]+1;
	for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^La&&(Id[tmp.to][0]=tmp.w,Make(tmp.to,x),0);
}
int  main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	RI i,j;s.head=g.head=1;scanf("%d%d",&n,&m);cnt=n+m+1;for(i=2;i<=n;i++) lg[i]=lg[i/2]+1,scanf("%d%d",&x,&y),s.add(x,y,i-1),s.add(y,x,i-1);Make(1,0);for(i=1;i<n;i++) con(i+m,n+m+1,1);
	for(i=1;i<=m;i++){
		con(0,i,1);scanf("%d%d",&x,&y);d[x]<d[y]&&(swap(x,y),0);while(d[x]>d[y]) con(i,Id[x][lg[d[x]-d[y]]]+m,1e9),x=fa[x][lg[d[x]-d[y]]];if(x==y) continue;
		for(j=lg[d[x]];~j;j--) fa[x][j]^fa[y][j]&&(con(i,Id[x][j]+m,1e9),con(i,Id[y][j]+m,1e9),x=fa[x][j],y=fa[y][j]);con(i,Id[x][0]+m,1e9);con(i,Id[y][0]+m,1e9);
	}s=g;printf("%d\n",Dicnic::calc());Dicnic::dfs(Dicnic::S);for(i=1;i<=m;i++) H+=!Dicnic::vis[i];printf("%d ",H);for(i=1;i<=m;i++) !Dicnic::vis[i]&&(printf("%d ",i));Pc('\n');
  	H=0;for(i=m+1;i<=m+n;i++) H+=Dicnic::vis[i];printf("%d ",H);for(i=m+1;i<=m+n;i++) Dicnic::vis[i]&&(printf("%d ",i-m));
}