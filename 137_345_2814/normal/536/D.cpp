#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2050
#define M 100050
struct edge{int t,next,v;}ed[M*2];
int head[N],cnt,id1[N],id2[N],c1,v[N],n,m,a,b,c,s,t,su1[N][N],pt1[N][N],pt2[N][N],fg1,fg2,fg3;
long long dis[N],vis[N],s1[N],s2[N],su[N][N],dp[N][N][2],mx[N][N],mn[N][N];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;}
void dij(int s)
{
	priority_queue<pair<long long,int> > st;
	st.push(make_pair(0,s));
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while(!st.empty())
	{
		int v=st.top().second;st.pop();
		if(vis[v])continue;vis[v]=1;
		for(int i=head[v];i;i=ed[i].next)
		if(dis[ed[i].t]>dis[v]+ed[i].v)
		dis[ed[i].t]=dis[v]+ed[i].v,st.push(make_pair(-dis[ed[i].t],ed[i].t));
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),adde(a,b,c);
	dij(s);for(int i=1;i<=n;i++)s1[i]=dis[i];sort(s1+1,s1+n+1);
	c1=0;dis[0]=-1;for(int i=1;i<=n;i++)if(s1[i]!=s1[i-1])s2[++c1]=s1[i];
	for(int i=1;i<=n;i++)id1[i]=upper_bound(s2+1,s2+c1+1,dis[i])-s2;
	dij(t);for(int i=1;i<=n;i++)s1[i]=dis[i];sort(s1+1,s1+n+1);
	c1=0;dis[0]=-1;for(int i=1;i<=n;i++)if(s1[i]!=s1[i-1])s2[++c1]=s1[i];
	for(int i=1;i<=n;i++)id2[i]=upper_bound(s2+1,s2+c1+1,dis[i])-s2;
	for(int i=1;i<=n;i++)su[id1[i]][id2[i]]+=v[i],su1[id1[i]][id2[i]]++;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)su[i][j]=su[i-1][j]+su[i][j-1]-su[i-1][j-1]+su[i][j],su1[i][j]=su1[i-1][j]+su1[i][j-1]-su1[i-1][j-1]+su1[i][j];
	memset(dp,-0x3f,sizeof(dp));
	memset(mx,-0x3f,sizeof(mx));
	memset(mn,-0x3f,sizeof(mn));
	for(int i=0;i<n;i++)
	{
		dp[i][n][0]=0;mn[i][n]=-su[n][n]+su[i][n];
		dp[n][i][1]=0;mx[n][i]=su[n][n]-su[n][i];
		pt1[n][i]=pt2[i][n]=n;
	}
	for(int i=n-1;i>=0;i--)
	for(int j=n-1;j>=0;j--)
	{
		int s1=pt1[i+1][j];
		while(su1[s1-1][n]-su1[s1-1][j]-su1[i][n]+su1[i][j]>0)s1--;
		pt1[i][j]=s1;
		if(su1[s1][n]-su1[s1][j]-su1[i][n]+su1[i][j]>0)
		{
			dp[i][j][0]=mx[s1][j]-su[i][n]+su[i][j];
			mn[i][j]=min(dp[i][j][0]-su[n][j]+su[i][j],mn[i][j+1]);
		}
		else mn[i][j]=mn[i][j+1];
		s1=pt2[i][j+1];
		while(su1[n][s1-1]-su1[i][s1-1]-su1[n][j]+su1[i][j]>0)s1--;
		pt2[i][j]=s1;
		if(su1[n][s1]-su1[i][s1]-su1[n][j]+su1[i][j]>0)
		{
			dp[i][j][1]=mn[i][s1]+su[n][j]-su[i][j];
			mx[i][j]=max(dp[i][j][1]+su[i][n]-su[i][j],mx[i+1][j]);
		}
		else mx[i][j]=mx[i+1][j];
	}
	if(dp[0][0][0]>0)printf("Break a heart");
	else if(dp[0][0][0]<0)printf("Cry");
	else printf("Flowers");
}