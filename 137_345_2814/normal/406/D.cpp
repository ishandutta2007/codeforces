#include<cstdio>
#include<algorithm>
using namespace std;
struct edge{
	int t,next;
}ed[400004];
int head[200004],v[200004],m,n,a,b,c,cnt,f[200004][19],dep[200005],ans[200005];
void adde(int f,int t)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	head[t]=cnt;
}
void dfs(int u,int fa)
{
	f[u][0]=fa;dep[u]=dep[fa]+1;
	for(int i=1;i<=18;i++)
	f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	dfs(ed[i].t,u);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=18;i>=0;i--)
	if(dep[x]-dep[y]>=1<<i)
	x=f[x][i];
	if(x==y)
	return x;
	for(int i=17;i>=0;i--)
	if(f[x][i]!=f[y][i])
	x=f[x][i],y=f[y][i];
	return f[x][0];
}
long long s[100001][2],q[100001],tl;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld%lld",&s[i][0],&s[i][1]);
	q[++tl]=n;
	for(int i=n-1;i>=1;i--)
	{
		while(tl>=2&&(s[q[tl-1]][0]-s[i][0])*(s[q[tl]][1]-s[i][1])-(s[q[tl]][0]-s[i][0])*(s[q[tl-1]][1]-s[i][1])<0)tl--;
		adde(i,q[tl]);
		q[++tl]=i;
	}
	dfs(n,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d",&a,&b),ans[i]=LCA(a,b);
	for(int i=1;i<=m;i++)
	printf("%d ",ans[i]);
}