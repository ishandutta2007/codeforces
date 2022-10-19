#include<cstdio>
#include<algorithm>
#include<cstring>
#define I inline
#define re register 
#define M 1000039
#define N 100039
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f[N],un,wn,fa[N][20],lg[N],maxn[N][20],w[N],fl[M],ans[M],d[N];
struct ques{int x,y,w,id;}g[M];
I bool cmp(ques x,ques y){return x.w<y.w;}
struct yyy{int to,w,z;};
struct ljb{
	int head,h[N];yyy f[N*2];
	I void add(int x,int y,int z){f[++head]=(yyy){y,z,h[x]};h[x]=head;} 
}s;
I int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
I void dfs(int x,int last){
	int i,cur;yyy tmp;fa[x][0]=last;maxn[x][0]=w[x];d[x]=d[last]+1;
	for(i=1;i<=lg[d[x]];i++) fa[x][i]=fa[fa[x][i-1]][i-1],maxn[x][i]=max(maxn[x][i-1],maxn[fa[x][i-1]][i-1]);
	for(cur=s.h[x];cur;cur=tmp.z) tmp=s.f[cur],tmp.to^last&&(w[tmp.to]=tmp.w,dfs(tmp.to,x),0);
}
I void swap(int &x,int &y){x^=y^=x^=y;}
I int lca(int x,int y){
	int ans=0;d[x]<d[y]&&(swap(x,y),0);while(d[x]^d[y]) ans=max(ans,maxn[x][lg[d[x]-d[y]]]),x=fa[x][lg[d[x]-d[y]]];
	if(x==y) return ans;for(int i=lg[d[x]];i>=0;i--) fa[x][i]^fa[y][i]&&(ans=max(ans,max(maxn[x][i],maxn[y][i])),x=fa[x][i],y=fa[y][i]);return max(ans,max(maxn[x][0],maxn[y][0]));
}
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	re int i;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) f[i]=i;for(i=2;i<=n;i++)lg[i]=lg[i/2]+1;
	for(i=1;i<=m;i++) scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].w),g[i].id=i;sort(g+1,g+m+1,cmp);
	for(i=1;i<=m;i++){
		un=find(g[i].x);wn=find(g[i].y);
		if(un==wn) continue;
		f[un]=wn;s.add(g[i].x,g[i].y,g[i].w);s.add(g[i].y,g[i].x,g[i].w);fl[g[i].id]=1;
	}
	dfs(1,1);
	for(i=1;i<=m;i++)(!fl[g[i].id])&&(ans[g[i].id]=lca(g[i].x,g[i].y),0);
	for(i=1;i<=m;i++) (!fl[i])&&(printf("%d\n",min(ans[i],(int)1e9)));
}