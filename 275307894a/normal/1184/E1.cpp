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
int n,m,k,x,y,z,f[N],un,wn,fa[N][20],lg[N],sum[N][20],maxn[N][20],w[N],fl[M],ans[M],d[N];
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
I void get(int x,int y,int w){
	d[x]<d[y]&&(swap(x,y),0);while(d[x]^d[y]) sum[x][lg[d[x]-d[y]]]=min(w,sum[x][lg[d[x]-d[y]]]),x=fa[x][lg[d[x]-d[y]]];
	if(x==y) return;for(int i=lg[d[x]];i>=0;i--) fa[x][i]^fa[y][i]&&(sum[x][i]=min(sum[x][i],w),sum[y][i]=min(sum[y][i],w),x=fa[x][i],y=fa[y][i]);sum[x][0]=min(sum[x][0],w);sum[y][0]=min(sum[y][0],w);
}
I void push(){
	re int i,j;
	for(i=19;i;i--) {
		for(j=1;j<=n;j++) sum[j][i]<=1e9&&(sum[j][i-1]=min(sum[j][i-1],sum[j][i]),sum[fa[j][i-1]][i-1]=min(sum[fa[j][i-1]][i-1],sum[j][i]));
	}
}
int main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	re int i;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) f[i]=i;for(i=2;i<=n;i++)lg[i]=lg[i/2]+1;memset(sum,0x3f,sizeof(sum));
	for(i=1;i<=m;i++) scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].w),g[i].id=i;sort(g+1,g+m+1,cmp);
	for(i=1;i<=m;i++){
		un=find(g[i].x);wn=find(g[i].y);
		if(un==wn) continue;
		f[un]=wn;s.add(g[i].x,g[i].y,g[i].w);s.add(g[i].y,g[i].x,g[i].w);fl[i]=1;
	}
	dfs(1,1);
	for(i=1;i<=m;i++)(!fl[i])&&(ans[g[i].id]=lca(g[i].x,g[i].y),get(g[i].x,g[i].y,g[i].w),0);push();
	for(i=1;i<=m;i++) fl[i]&&(ans[g[i].id]=(d[g[i].x]>d[g[i].y]?sum[g[i].x][0]:sum[g[i].y][0]));
	printf("%d\n",min(ans[1],(int)1e9));
}