#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int maxn=205,maxm=50000;
struct E
{
	int to,next,vis;
}edge[maxm<<1];
int n,m,head[maxn],tot,g[maxn][maxn],vis[maxn],a[maxn],tt,d[maxn],b[maxn],ttt,p[maxm],q[maxm],total,ans;
inline void addedge(int x,int y)
{
	edge[++tot]=(E){y,head[x],0};
	head[x]=tot;
	edge[++tot]=(E){x,head[y],0};
	head[y]=tot;
}
inline void addans(int x,int y)
{
	total++;
	p[total]=x,q[total]=y;
}
void dfs(int u)
{
	for(int i=head[u];i!=-1;i=edge[i].next)if(!edge[i].vis)
	{
		edge[i].vis=1;
		edge[i^1].vis=1;
		if(g[u][edge[i].to])addans(u,edge[i].to),g[u][edge[i].to]--,g[edge[i].to][u]--;
		dfs(edge[i].to);
	}
}
void find(int u)
{
	a[++tt]=u;
	vis[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next)if(!vis[edge[i].to])find(edge[i].to);
}
int main()
{
	int T;
	read(T);
	while(T--)
	{
		memset(head,-1,sizeof(head));
		tot=-1;
		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		total=0;
		ans=0;
		read(n),read(m);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			read(x),read(y);
			g[x][y]++,g[y][x]++;
			d[x]++,d[y]++;
			addedge(x,y);
		}
		for(int i=1;i<=n;i++)if(!vis[i])
		{
			tt=0;
			find(i);
			ttt=0;
			for(int j=1;j<=tt;j++)if(d[a[j]]%2)b[++ttt]=a[j];
			for(int j=1;j<=ttt/2;j++)addedge(b[j*2-1],b[j*2]);
			ans+=tt-ttt;
			dfs(a[1]);
		}
		write(ans);
		for(int i=1;i<=total;i++)printf("%d %d\n",p[i],q[i]);
	}
	return 0;
}