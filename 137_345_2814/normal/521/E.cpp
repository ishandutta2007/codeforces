#include<cstdio>
#include<stack>
using namespace std;
#define N 205000
struct sth{int l,r;}s[N][2],tp1,tp2;
int ct[N],n,m,head[N],fa[N],dep[N],id[N],g[N][2],is[N],cnt,f[N],fg,v[3],c1;
struct edge{int t,next,id;}ed[N*2];
void adde(int f,int t,int id){ed[++cnt]=(edge){t,head[f],id};head[f]=cnt;ed[++cnt]=(edge){f,head[t],id};head[t]=cnt;}
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;f[u]=fa;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)id[ed[i].t]=ed[i].id,dfs(ed[i].t,u);
}
void col(int l,int r)
{
	sth tp=(sth){l,r};
	while(l!=r)
	{
		if(dep[l]<dep[r])l^=r^=l^=r;
		s[id[l]][ct[id[l]]++]=tp;
		if(ct[id[l]]==2)fg=1;
		l=f[l];
	}
}
void dfs2(int u,int fa,int vl)
{
	int fg=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&(s[vl][0].l==s[ed[i].id][0].l&&s[vl][1].r==s[ed[i].id][1].r))dfs2(ed[i].t,u,vl),fg=1;
	if(!fg)v[++c1]=u;
}
int dis(int l,int r){int as=0;while(l!=r){if(dep[l]<dep[r])l^=r^=l^=r;l=f[l],as++;}return as;}
void solve(int i,int j)
{
	stack<int> s;
	while(i!=j)
	{
		if(dep[i]<dep[j])s.push(j),j=f[j];
		else printf(" %d",i),i=f[i];
	}
	printf(" %d",i);
	while(!s.empty())printf(" %d",s.top()),s.pop();
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){scanf("%d%d",&g[i][0],&g[i][1]);if(finds(g[i][0])!=finds(g[i][1]))fa[finds(g[i][0])]=finds(g[i][1]),is[i]=1,adde(g[i][0],g[i][1],i);}
	for(int i=1;i<=n;i++)if(!dep[i])dfs(i,0);
	for(int i=1;i<=m;i++)
	if(!is[i])
	{
		col(g[i][0],g[i][1]);
		if(fg)
		{
			int t1,s1=-1,s2;
			for(int j=1;j<=n;j++)if(ct[j]==2)t1=j;
			for(int j=1;j<=cnt;j++)if(ed[j].id==t1)if(s1==-1)s1=ed[j].t;else s2=ed[j].t;
			for(int j=head[s1];j;j=ed[j].next)
			if(ed[j].t==s2)
			tp1=s[t1][0],tp2=s[t1][1];
			dfs2(s1,s2,t1);
			dfs2(s2,s1,t1);
			printf("YES\n");
			printf("%d",dis(v[1],v[2])+1);solve(v[1],v[2]);printf("\n");
			if(dis(g[i][0],v[1])+2+dis(g[i][1],v[2])<dis(g[i][1],v[1])+2+dis(g[i][0],v[2]))
			printf("%d",dis(g[i][0],v[1])+2+dis(g[i][1],v[2])),solve(v[1],g[i][0]),solve(g[i][1],v[2]);
			else printf("%d",dis(g[i][1],v[1])+2+dis(g[i][0],v[2])),solve(v[1],g[i][1]),solve(g[i][0],v[2]);
			printf("\n");
			g[i][0]=tp1.l,g[i][1]=tp1.r;
			if(dis(g[i][0],v[1])+2+dis(g[i][1],v[2])<dis(g[i][1],v[1])+2+dis(g[i][0],v[2]))
			printf("%d",dis(g[i][0],v[1])+2+dis(g[i][1],v[2])),solve(v[1],g[i][0]),solve(g[i][1],v[2]);
			else printf("%d",dis(g[i][1],v[1])+2+dis(g[i][0],v[2])),solve(v[1],g[i][1]),solve(g[i][0],v[2]);
			return 0;
		}
	}
	printf("NO\n");
}