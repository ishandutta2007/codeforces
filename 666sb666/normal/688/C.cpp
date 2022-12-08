#include<cstdio>
#include<cstring>
const int maxn=100001;
struct E
{
	int to,next;
}edge[maxn<<1];
int n,m,hd[maxn],visit[maxn],tot=0,ans1[maxn],ans2[maxn];
struct Q
{
	int x,y;
}q[maxn<<2];
inline bool bfs(int u)
{
	int head=0,tail=1;
	q[1]=(Q){u,1};
	visit[u]=1;
	while(head<tail)
	{
		int x=q[++head].x,y=q[head].y;
		for(int i=hd[x];i!=-1;i=edge[i].next)
		{
			int v=edge[i].to;
			if(visit[v]==visit[x])return false;
			if(!visit[v])visit[v]=3-visit[x],q[++tail]=(Q){v,visit[v]};
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(hd,-1,sizeof(hd));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge[++tot]=(E){y,hd[x]};
		hd[x]=tot;
		edge[++tot]=(E){x,hd[y]};
		hd[y]=tot;
	}
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=n;i++)if((!visit[i])&&hd[i]!=-1)
	{
		if(!bfs(i))
		{
			printf("-1\n");
			return 0;
		}
	}
	int tot1=0,tot2=0;
	for(int i=1;i<=n;i++)if(visit[i]==1)ans1[++tot1]=i;
	else if(visit[i]==2)ans2[++tot2]=i;
	printf("%d\n",tot1);
	for(int i=1;i<tot1;i++)printf("%d ",ans1[i]);
	printf("%d\n%d\n",ans1[tot1],tot2);
	for(int i=1;i<tot2;i++)printf("%d ",ans2[i]);
	printf("%d\n",ans2[tot2]);
	return 0;
}