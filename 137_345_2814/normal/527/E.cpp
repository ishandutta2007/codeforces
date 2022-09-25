#include<cstdio>
using namespace std;
#define N 400050
int fa[N],head[N],cnt,n,h[N][2],in[N],m,as[N][2],ct,ls,s[N][2];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs(ed[i].t,u);
		s[u][0]^=s[ed[i].t][1];
		s[u][1]^=s[ed[i].t][0];
	}
	if(u!=1)
	{
		if(s[u][0])as[++ct][0]=u,as[ct][1]=fa;
		else as[++ct][0]=fa,as[ct][1]=u;
	}
	else if(s[u][0])as[++ct][0]=1,as[ct][1]=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&h[i][0],&h[i][1]),in[h[i][0]]++,in[h[i][1]]++;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		if(in[i]&1)
		if(ls)h[++m][0]=ls,h[m][1]=i,ls=0;
		else ls=i;
	}
	for(int i=1;i<=m;i++)
	if(finds(h[i][0])!=finds(h[i][1]))adde(h[i][0],h[i][1]),fa[finds(h[i][0])]=finds(h[i][1]);
	else s[h[i][0]][0]^=1,s[h[i][1]][1]^=1,as[++ct][0]=h[i][0],as[ct][1]=h[i][1];
	dfs(1,0);
	printf("%d\n",ct);
	for(int i=1;i<=ct;i++)printf("%d %d\n",as[i][0],as[i][1]);
}