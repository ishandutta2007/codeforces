#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 200050
struct edg{int f,t,v,use,id;}e[N];
struct edge{int t,next,v,id;}ed[N*2];
int head[N],cnt,f[N][19],mx[N][19],fa[N],ans[N],dep[N],fg[N][19],id[N],n,m;
void adde(int f,int t,int v,int id){ed[++cnt]=(edge){t,head[f],v,id};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v,id};head[t]=cnt;}
void dfs1(int u,int fa)
{
	f[u][0]=fa;dep[u]=dep[fa]+1;
	for(int i=1;i<=18;i++)
	f[u][i]=f[f[u][i-1]][i-1],mx[u][i]=max(mx[u][i-1],mx[f[u][i-1]][i-1]);
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	mx[ed[i].t][0]=ed[i].v,id[ed[i].id]=ed[i].t,dfs1(ed[i].t,u);
}
void LCA1(int a,int b,int s)
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
int LCA2(int a,int b)
{
	int ans=0;
	if(dep[a]<dep[b])a^=b^=a^=b;
	for(int i=18;i>=0;i--)
	if(dep[a]-dep[b]>=1<<i)ans=max(mx[a][i],ans),a=f[a][i];
	if(a==b)return ans;
	for(int i=18;i>=0;i--)
	if(f[a][i]!=f[b][i])ans=max(ans,max(mx[a][i],mx[b][i])),a=f[a][i],b=f[b][i];
	return max(ans,max(mx[a][0],mx[b][0]));
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].v),e[i].id=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	if(finds(e[i].f)!=finds(e[i].t))
	fa[finds(e[i].f)]=finds(e[i].t),e[i].use=1,adde(e[i].f,e[i].t,e[i].v,i);
	dfs1(1,0);
	for(int i=1;i<=m;i++)
	if(!e[i].use)
	ans[e[i].id]=LCA2(e[i].f,e[i].t)-1,LCA1(e[i].f,e[i].t,e[i].v);
	dfs2(1,0);
	for(int i=1;i<=m;i++)
	if(e[i].use)ans[e[i].id]=fg[id[i]][0]>1059999999?-1:fg[id[i]][0]-1;
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
}