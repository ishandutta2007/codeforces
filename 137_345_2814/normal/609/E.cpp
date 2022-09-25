#include<cstdio>
#include<algorithm>
using namespace std;
struct edge{
	int t,next,v;
}ed[400004];
int head[200004],sz[200004],v[200004],m,n,a,b,c,cnt,f[200004][19],mx[200004][19],fa[200005],dep[200005];
long long ans;
void adde(int f,int t,int v)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	ed[cnt].v=v;
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	ed[cnt].v=v;
	head[t]=cnt;
}
int finds(int x)
{
	return fa[x]==x?x:fa[x]=finds(fa[x]);
}
bool un(int x,int y)
{
	int a=finds(x),b=finds(y);
	if(a==b)
	return 0;
	fa[a]=b;
	return 1;
}
struct edg2{
	int f,t,v;
}e[200005],e2[200005];
bool cmp(edg2 a,edg2 b)
{
	return a.v<b.v;
}
void dfs(int u,int fa)
{
	f[u][0]=fa;dep[u]=dep[fa]+1;
	for(int i=1;i<=18;i++)
	mx[u][i]=max(mx[u][i-1],mx[f[u][i-1]][i-1]),f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	mx[ed[i].t][0]=ed[i].v,dfs(ed[i].t,u);
}
int query(int x,int y)
{
	int ans=0;
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=18;i>=0;i--)
	if(dep[x]-dep[y]>=1<<i)
	ans=max(ans,mx[x][i]),x=f[x][i];
	if(x==y)
	return ans;
	for(int i=17;i>=0;i--)
	if(f[x][i]!=f[y][i])
	ans=max(ans,max(mx[x][i],mx[y][i])),x=f[x][i],y=f[y][i];
	return max(ans,max(mx[x][0],mx[y][0]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].v),e2[i]=e[i];
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	if(un(e[i].f,e[i].t))
	adde(e[i].f,e[i].t,e[i].v),ans+=e[i].v;
	dfs(1,0);
	for(int i=1;i<=m;i++)
	printf("%lld\n",ans+e2[i].v-query(e2[i].f,e2[i].t));
}