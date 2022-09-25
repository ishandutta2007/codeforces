#include<cstdio>
#include<algorithm>
using namespace std;
struct edge{
	int t,next,v,id;
}ed[400004];
int head[200004],sz[200004],v[200004],m,n,a,b,c,cnt,f[200004][19],mx[200004][19],fa[200005],dep[200005],q,fg=1,id[200005];
long long ans2=5e9,ans;
void adde(int f,int t,int v,int id)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	ed[cnt].v=v;
	ed[cnt].id=id;
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	ed[cnt].v=v;
	ed[cnt].id=id;
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
	int f,t,v,v2,id;
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
	id[ed[i].t]=i,mx[ed[i].t][0]=ed[i].v,dfs(ed[i].t,u);
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
void query2(int x,int y,int v)
{
	if(dep[x]<dep[y])x^=y^=x^=y;
	while(dep[x]>dep[y])
	{
		if(ed[id[x]].v==v)
		{
			ed[id[x]].v=2e9;
			return;
		}
		x=f[x][0];
	}
	while(1)
	{
		if(ed[id[x]].v==v)
		{
			ed[id[x]].v=2e9;
			return;
		}
		x=f[x][0];x^=y^=x^=y;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d",&e[i].v);
	for(int i=1;i<=m;i++)scanf("%d",&e[i].v2);
	for(int i=1;i<=m;i++)
	scanf("%d%d",&e[i].f,&e[i].t),e2[i]=e[i],e[i].id=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	if(un(e[i].f,e[i].t))
	adde(e[i].f,e[i].t,e[i].v,e[i].id),ans+=e[i].v,ans2=min(ans2,1ll*e[i].v2);
	dfs(1,0);
	scanf("%d",&q);
	long long tmp=1e11,id;
	for(int i=1;i<=m;i++)
	if(e[i].v2<=ans2)
	{
		int tmp1=e[i].v-query(e[i].f,e[i].t)-q/e[i].v2;
		if(tmp1<=tmp)tmp=tmp1,id=i;
	}
	printf("%lld\n",ans+tmp);
	query2(e[id].f,e[id].t,query(e[id].f,e[id].t));
	for(int i=1;i<=cnt;i+=2)
	if(ed[i].v<1.5e9&&ed[i+1].v<1.5e9)
	printf("%d %d\n",ed[i].id,ed[i].v);
	printf("%d %d\n",e[id].id,e[id].v-q/e[id].v2);
}