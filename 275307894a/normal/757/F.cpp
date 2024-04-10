#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 300000
#define K 150
#define mod 1000000007
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,m,k,x,y,z,S,fa[N+5][20],dep[N+5],lg[N+5],in[N+5],siz[N+5],lcas,Ans;ll d[N+5];
struct yyy{int to,w,z;}tmp;queue<int> Q;I void swap(int &x,int &y){x^=y^=x^=y;}
struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;}}S1,S2,G,Cl;
I int lca(int x,int y){dep[x]<dep[y]&&(swap(x,y),0);while(dep[x]^dep[y]) x=fa[x][lg[dep[x]-dep[y]]];if(x==y) return x;for(int i=lg[dep[x]];~i;i--) fa[x][i]&&fa[y][i]&&fa[x][i]^fa[y][i]&&(x=fa[x][i],y=fa[y][i]);return fa[x][0];}
I void dfs(int x){siz[x]=1;yyy tmp;for(int i=G.h[x];i;i=tmp.z)tmp=G.f[i],dfs(tmp.to),siz[x]+=siz[tmp.to];}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d%d%d",&n,&m,&S);for(i=2;i<=n;i++) lg[i]=lg[i/2]+1;for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),G.add(x,y,z),G.add(y,x,z);Me(d,0x3f);d[S]=0;Q.push(S);
	while(!Q.empty())for(x=Q.front(),Q.pop(),i=G.h[x];i;i=tmp.z)tmp=G.f[i],d[tmp.to]>d[x]+tmp.w&&(Q.push(tmp.to),d[tmp.to]=d[x]+tmp.w); 
	for(i-1;i<=n;i++) for(j=G.h[i];j;j=tmp.z)tmp=G.f[j],(d[tmp.to]==d[i]+tmp.w)&&(S1.add(i,tmp.to,0),S2.add(tmp.to,i,0),in[tmp.to]++); G=Cl;Q.push(S);
	while(!Q.empty()){x=Q.front();Q.pop();for(lcas=0,i=S2.h[x];i;i=tmp.z) tmp=S2.f[i],lcas=(lcas?lca(lcas,tmp.to):tmp.to);fa[x][0]=lcas;for(i=1;fa[x][i-1];i++) fa[x][i]=fa[fa[x][i-1]][i-1];dep[x]=dep[lcas]+1;G.add(lcas,x,0);for(i=S1.h[x];i;i=tmp.z) tmp=S1.f[i],!(--in[tmp.to])&&(Q.push(tmp.to),0);}
	dfs(S);for(i=1;i<=n;i++) i^S&&(Ans=max(Ans,siz[i]));printf("%d\n",Ans);
}