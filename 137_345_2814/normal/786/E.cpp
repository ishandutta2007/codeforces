#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 25050
#define M 500020
struct edg{int t,next,id;}e[N*2];
struct edge{int t,next,v;}ed[M*8];
int head2[N],cnt2,head[M],cnt=1,dep[M],vis[M],f[N][17],id[N][17],cnt3,a,b,n,m,s,t,tp1,tp2,cur[M];
void adde(int f,int t,int id){e[++cnt2]=(edg){t,head2[f],id};head2[f]=cnt2;e[++cnt2]=(edg){f,head2[t],id};head2[t]=cnt2;}
void adde2(int f,int t,int w){if(!f||!t)return;ed[++cnt]=(edge){t,head[f],w};head[f]=cnt;ed[++cnt]=(edge){f,head[t],0};head[t]=cnt;}
void dfs1(int u,int fa)
{
	f[u][0]=fa;dep[u]=dep[fa]+1;for(int i=1;i<=14;i++)id[u][i]=++cnt3,f[u][i]=f[f[u][i-1]][i-1],adde2(id[u][i],id[u][i-1],1e9),adde2(id[u][i],id[f[u][i-1]][i-1],1e9);
	for(int i=head2[u];i;i=e[i].next)
	if(e[i].t!=fa)id[e[i].t][0]=e[i].id+m,dfs1(e[i].t,u);
}
void query(int x,int y,int s)
{
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=14;i>=0;i--)if(dep[x]-dep[y]>=1<<i)adde2(s,id[x][i],1e9),x=f[x][i];
	if(x==y)return;
	for(int i=14;i>=0;i--)if(f[x][i]!=f[y][i])adde2(s,id[x][i],1e9),adde2(s,id[y][i],1e9),x=f[x][i],y=f[y][i];
	adde2(s,id[x][0],1e9);adde2(s,id[y][0],1e9);
}
bool bfs(int s,int t)
{
	queue<int> s1;
	memset(dep,-1,sizeof(dep));
	memcpy(cur,head,sizeof(head));
	dep[s]=0;s1.push(s);
	while(!s1.empty())
	{
		int r=s1.front();s1.pop();
		for(int i=head[r];i;i=ed[i].next)
		if(ed[i].v&&dep[ed[i].t]==-1)
		{dep[ed[i].t]=dep[r]+1,s1.push(ed[i].t);if(ed[i].t==t)return 1;}
	}
	return 0;
}
int dfs(int u,int t,int f)
{
	if(u==t)return f;
	if(!f)return 0;
	int ans=0,tmp;
	for(int& i=cur[u];i;i=ed[i].next)
	if(ed[i].v&&dep[ed[i].t]==dep[u]+1&&(tmp=dfs(ed[i].t,t,min(f,ed[i].v))))
	{
		ans+=tmp,f-=tmp;
		ed[i].v-=tmp,ed[i^1].v+=tmp;
		if(!f)return ans;
	}
	return ans;
}
int dinic(int s,int t)
{
	int ans=0;
	while(bfs(s,t))ans+=dfs(s,t,1e9);
	return ans;
}
void dfs(int s)
{
	vis[s]=1;
	for(int i=head[s];i;i=ed[i].next)
	if(ed[i].v&&!vis[ed[i].t])dfs(ed[i].t);
}
int main()
{
	scanf("%d%d",&n,&m);cnt3=n+m;s=++cnt3;t=++cnt3;
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b,i);
	dfs1(1,0);
	for(int i=1;i<n;i++)adde2(i+m,t,1);
	for(int i=1;i<=m;i++)adde2(s,i,1),scanf("%d%d",&a,&b),query(a,b,i);
	printf("%d\n",dinic(s,t));
	dfs(s);
	for(int i=1;i<=m;i++)if(!vis[i])tp1++;
	printf("%d",tp1);
	for(int i=1;i<=m;i++)if(!vis[i])printf(" %d",i);
	for(int i=1;i<n;i++)if(vis[i+m])tp2++;
	printf("\n%d",tp2);
	for(int i=1;i<n;i++)if(vis[i+m])printf(" %d",i);
}//???