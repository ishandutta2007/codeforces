#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define N 333333
struct edge{int f,t,next,v;}ed[N*3],ed2[N*3],ed3[N*3];
int vis[N],head[N],cnt,head2[N],cnt2,head3[N],cnt3,f[N][20],dep[N],sz[N],in[N],n,m,s,a,b,c,as;long long dis[N];
vector<int> g[N];
void adde(int f,int t,int v){ed[++cnt]=(edge){f,t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){t,f,head[t],v};head[t]=cnt;}
void adde2(int f,int t){ed2[++cnt2]=(edge){f,t,head2[f],0};head2[f]=cnt2;}
void adde3(int f,int t){ed3[++cnt3]=(edge){f,t,head3[f],0};head3[f]=cnt3;ed3[++cnt3]=(edge){t,f,head3[t],0};head3[t]=cnt3;}
void dijkstra(int s)
{
	priority_queue<pair<long long,int> > s1;
	memset(dis,0x3f,sizeof(dis));memset(vis,0,sizeof(vis));
	s1.push(make_pair(0,s));dis[s]=0;
	while(!s1.empty())
	{
		int s=s1.top().second;s1.pop();
		if(vis[s])continue;vis[s]=1;
		for(int i=head[s];i;i=ed[i].next)
		if(dis[ed[i].t]>dis[s]+ed[i].v)
		dis[ed[i].t]=dis[s]+ed[i].v,s1.push(make_pair(-dis[ed[i].t],ed[i].t));
	}
}
int LCA(int x,int y){if(dep[x]<dep[y])x^=y^=x^=y;for(int i=19;i>=0;i--)if(dep[x]-dep[y]>=1<<i)x=f[x][i];if(x==y)return x;for(int i=19;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];return f[x][0];}
int dfs(int u,int fa){int sz=1;for(int i=head3[u];i;i=ed3[i].next)if(ed3[i].t!=fa)sz+=dfs(ed3[i].t,u);if(u!=s&&sz>as)as=sz;return sz;}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&a,&b,&c),adde(a,b,c);
	dijkstra(s);
	for(int i=1;i<=cnt;i++)
	if(dis[ed[i].f]+ed[i].v==dis[ed[i].t])
	adde2(ed[i].f,ed[i].t),in[ed[i].t]++,g[ed[i].t].push_back(ed[i].f);
	queue<int> s1;
	for(int i=1;i<=n;i++)
	if(in[i]==0)s1.push(i);
	while(!s1.empty())
	{
		int s=s1.front();s1.pop();
		int tmp=g[s].size(),ans;
		if(tmp)
		{
			if(tmp==1)ans=g[s][0];
			else
			{
				ans=LCA(g[s][0],g[s][1]);
				for(int i=2;i<tmp;i++)
				ans=LCA(ans,g[s][i]);
			}
			f[s][0]=ans;dep[s]=dep[ans]+1;adde3(s,ans);
			for(int i=1;i<=19;i++)f[s][i]=f[f[s][i-1]][i-1];
		}
		for(int i=head2[s];i;i=ed2[i].next)
		{
			in[ed2[i].t]--;
			if(in[ed2[i].t]==0)
			s1.push(ed2[i].t);
		}
	}
	dfs(s,0);printf("%d\n",as);
}