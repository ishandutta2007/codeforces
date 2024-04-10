#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PI;
const int N=2005*2005;
int r,c;
int n,m;
int xx,yy;
char ss[2005][2005];
int P (int x,int y)	{return (x-1)*m+y;}
int fa[N];
int find_fa (int x)	{return fa[x]==x?fa[x]:fa[x]=find_fa(fa[x]);}
struct qq
{
	int x,y,z,last;
}e[N*2];int num,last[N];
int tot[N];
void init (int x,int y,int z)
{
	num++;
	e[num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];
	last[x]=num;
}
int f[N];
void bfs ()
{
	memset(f,-1,sizeof(f));
	priority_queue<PI,vector<PI>,greater<PI> > q;
	int x=find_fa(P(r,c));
	//printf("YES:%d %d %d %d\n",r,c,P(r,c),find_fa(P(r,c)));
	q.push({0,x});f[x]=0;
	while (!q.empty())
	{
		int x=q.top().second,x1=q.top().first;q.pop();
		if (f[x]<x1) continue;
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			if (f[y]==-1||f[y]>f[x]+e[u].z)
			{
				f[y]=f[x]+e[u].z;
				q.push({f[y],y});
			}
		}
	}
}
bool vis[N];
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n*m;u++) 	{fa[u]=u;tot[u]=1;}
	scanf("%d%d",&r,&c);
	scanf("%d%d",&xx,&yy);
	for (int u=1;u<=n;u++)	scanf("%s",ss[u]+1);
	for (int u=2;u<=n;u++)
		for (int i=1;i<=m;i++)
			if (ss[u][i]=='.'&&ss[u-1][i]=='.')
			{
				int x=P(u,i),y=P(u-1,i);
				x=find_fa(x);y=find_fa(y);
				tot[y]=tot[y]+tot[x];
				fa[x]=y;
			}
	
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=m;i++)
		if (ss[u][i]=='.'&&ss[u][i+1]=='.')
		{
			int x=find_fa(P(u,i)),y=find_fa(P(u,i+1));
			init(x,y,0);init(y,x,1);
		}
	}
		/*printf("\n");
		for (int u=1;u<=n*m;u++) printf("%d ",fa[u]);
		printf("\n");*/
	bfs();
	int ans=0;
	for (int u=1;u<=n;u++)
		for (int i=1;i<=m;i++)
		{
			int x=find_fa(P(u,i));
			if (f[x]==-1) continue;
			int dis=c-i;
			int a=f[x],b=f[x]-dis;
			if (a<=xx&&b<=yy) 
			{
				//printf("%d %d %d %d %d\n",u,i,f[x],a,b);
				ans+=tot[x];
			}
			
			f[x]=-1;
		}
	printf("%d\n",ans);
	return 0;
}