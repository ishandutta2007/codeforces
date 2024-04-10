#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=605*2;
const int MAX=1e9;
struct qq
{
	int x,y,z,last;
}e[N*20];int num,last[N];
void init (int x,int y,int z)
{
//	printf("add:%d %d %d\n",x,y,z);
	e[++num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];last[x]=num;
	swap(x,y);z=0;
	e[++num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];last[x]=num;
}
int du[N];
int st,ed;
int h[N];
bool bt ()
{
	for (int u=1;u<=ed;u++) h[u]=-1;
	queue<int> q;q.push(st);
	h[st]=0;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			if (h[y]==-1&&e[u].z>0)
			{
				h[y]=h[x]+1;
				q.push(y);
			}
		}
	}
	return h[ed]!=-1;
}
int flow (int x,int t)
{
	if (x==ed) return t;
	int sum=0;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (e[u].z>0&&h[y]==h[x]+1&&sum<t)
		{
			int d=flow(y,min(t-sum,e[u].z));
			e[u].z-=d;	e[u^1].z+=d;
			sum=sum+d;
		}
	}
	if (sum==0) h[x]=-1;
	return sum;
}
int col[N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		num=1;memset(last,-1,sizeof(last));
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		st=n+m+1;ed=st+1;
		for (int u=1;u<=n;u++) du[u]=0;
		for (int u=1;u<=m;u++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			du[a]++;du[b]++;
			init(a,u+n,1);init(b,u+n,1);
			init(u+n,ed,1);
		}
		int tot=0;
		for (int u=1;u<=n;u++) if (du[u]>k)
		{
			tot=tot+2*(du[u]-k);
			init(st,u,2*(du[u]-k));
		}
		int ans=0;
		while (bt()) 
		{
			int p=flow(st,MAX);
		//	printf("p:%d ",p);
			ans=ans+p;
			//ans=ans+flow(st,MAX);
			
		}
		//printf("ans:%d %d\n",ans,tot);
		if (ans!=tot)
		{
			for (int u=1;u<=m;u++) printf("0 ");
			printf("\n");
			continue;
		}
		for (int u=1;u<=m;u++) col[u]=-1;
		int col_cnt=1;
		for (int u=1;u<=n;u++)
		{
			int p=0;
			for (int i=last[u];i!=-1;i=e[i].last)
			{
				int y=e[i].y;
				if (y==st) continue;
				if (e[i].z==0) 
				{
				//	printf("%d %d\n",y-n,u);
					col[y-n]=col_cnt;
					p++;
					if (p%2==0) col_cnt++;
				}
				
			}
		}
		for (int u=1;u<=m;u++) if (col[u]==-1) col[u]=col_cnt++;
		for (int u=1;u<=m;u++) printf("%d ",col[u]);
		printf("\n");
	}
	return 0;
}