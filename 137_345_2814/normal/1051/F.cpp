#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 111111
int vis[N],head[N],cnt,ds[N],f[N][21],dep[N],n,m,a,b,c,q,ct=0;long long dis[44][N],dist[N];
struct edge{int t,next,v;}ed[N*2];
set<int> st;
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;}
void dfs(int u,int fa){vis[u]=1;dep[u]=dep[fa]+1;f[u][0]=fa;for(int i=1;i<=18;i++)f[u][i]=f[f[u][i-1]][i-1];for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa){if(vis[ed[i].t])st.insert(ed[i].t),st.insert(u);else dist[ed[i].t]=dist[u]+ed[i].v,dfs(ed[i].t,u);};}
int LCA(int x,int y){if(dep[x]<dep[y])x^=y^=x^=y;for(int i=18;i>=0;i--)if(dep[x]-dep[y]>=1<<i)x=f[x][i];if(x==y)return x;for(int i=18;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];return f[x][0];}
long long getdis(int x,int y){return dist[x]+dist[y]-2*dist[LCA(x,y)];}
void dijkstra(int s,int a)
{
    priority_queue<pair<long long,int> > s1;
    memset(dis[a],0x3f,sizeof(dis[a]));memset(vis,0,sizeof(vis));
    s1.push(make_pair(0,s));dis[a][s]=0;
    while(!s1.empty())
    {
        int s=s1.top().second;s1.pop();
        if(vis[s])continue;vis[s]=1;
        for(int i=head[s];i;i=ed[i].next)
        if(dis[a][ed[i].t]>dis[a][s]+ed[i].v)
        dis[a][ed[i].t]=dis[a][s]+ed[i].v,s1.push(make_pair(-dis[a][ed[i].t],ed[i].t));
    }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),adde(a,b,c);
	dfs(1,0);
	for(set<int>::iterator it=st.begin();it!=st.end();it++)
	dijkstra(*it,++ct);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		long long as=getdis(a,b);
		for(int j=1;j<=ct;j++)
		as=min(as,dis[j][a]+dis[j][b]);
		printf("%lld\n",as);
	}
}