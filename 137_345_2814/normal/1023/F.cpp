#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 500050
struct edg{int f,t,v,use,is;}e[N*2];
struct edge{int t,next,is;}ed[N*2];
int head[N],cnt,f[N][19],mx[N][19],fa[N],ans[N],dep[N],fg[N][19],is[N],n,k,m;
void adde(int f,int t,int is){ed[++cnt]=(edge){t,head[f],is};head[f]=cnt;ed[++cnt]=(edge){f,head[t],is};head[t]=cnt;}
void dfs(int u,int fa)
{
	f[u][0]=fa;dep[u]=dep[fa]+1;
	for(int i=1;i<=18;i++)
	f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)is[ed[i].t]=ed[i].is,dfs(ed[i].t,u);
}
void LCA(int a,int b,int s)
{
	if(dep[a]<dep[b])a^=b^=a^=b;
	for(int i=18;i>=0;i--)
	if(dep[a]-dep[b]>=1<<i)
	fg[a][i]=min(fg[a][i],s),a=f[a][i];
	if(a==b)return;
	for(int i=18;i>=0;i--)
	if(f[a][i]!=f[b][i])
	fg[a][i]=min(fg[a][i],s),fg[b][i]=min(fg[b][i],s),a=f[a][i],b=f[b][i];
	fg[a][0]=min(fg[a][0],s);fg[b][0]=min(fg[b][0],s);
}
void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)dfs2(ed[i].t,u);
	int i=u;
	for(int j=18;j>0;j--)
	fg[i][j-1]=min(fg[i][j-1],fg[i][j]),fg[f[i][j-1]][j-1]=min(fg[f[i][j-1]][j-1],fg[i][j]);
}
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
bool cmp(edg a,edg b){return a.v<b.v;}
int main()
{
	memset(fg,0x3f,sizeof(fg));
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++)scanf("%d%d",&e[i].f,&e[i].t),e[i].is=1;
	for(int i=1+k;i<=m+k;i++)scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].v);
	sort(e+1,e+m+k+1,cmp);
	for(int i=1;i<=m+k;i++)
	if(finds(e[i].f)!=finds(e[i].t))
	fa[finds(e[i].f)]=finds(e[i].t),e[i].use=1,adde(e[i].f,e[i].t,e[i].is);
	dfs(1,0);
	for(int i=1;i<=m+k;i++)
	if(!e[i].use)LCA(e[i].f,e[i].t,e[i].v);
	dfs2(1,0);
	long long ans=0;
	for(int i=1;i<=n;i++)if(is[i])
	if(fg[i][0]>1e9){printf("-1\n");return 0;}
	else ans+=fg[i][0];
	printf("%lld\n",ans);
}