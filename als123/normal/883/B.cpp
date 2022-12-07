#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef pair<int,int> PI;
const int N=200005;
int n,m,k;
int a[N];
bool o[N];// 
struct qq
{
	int x,y,last;
}e[N];int num,last[N];
qq E[N];int Last[N];
int d[N],D[N];
void init (int x,int y)
{
	num++;d[y]++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
	
	swap(x,y);
	D[y]++;
	E[num].x=x;E[num].y=y;
	E[num].last=Last[x];
	Last[x]=num;
}
priority_queue<PI,vector<PI>,greater<PI> >Q,Q1 ;
int tt[N];
int g[N];
void solve1 ()
{
/*	for (int i=1;i<=n;i++) printf("%d ",a[i]);
			printf("\n");*/
	memset(g,0,sizeof(g));
	for (int u=1;u<=n;u++)
	{
		if (D[u]==0)
		{
			Q.push(make_pair(a[u],u));
			g[u]=1;
		}
		tt[a[u]]++;
	}
	for (int u=1;u<=k;u++)
		if (tt[u]==0)// 
		{
			while (!Q1.empty())
			{
				int x=Q1.top().first,y=Q1.top().second;
				if (x>u) break;
				Q1.pop();Q.push(make_pair(a[y],y));
			}
			while (!Q.empty())
			{
				int x=Q.top().first,xx=Q.top().second;Q.pop();
				if (x<u||o[xx]) 
				{
					for (int i=Last[xx];i!=-1;i=E[i].last)
					{
						int y=E[i].y;
						D[y]--;
						g[y]=max(g[y],a[xx]+1);
						if (D[y]==0)
							Q1.push(make_pair(g[y],y));
					}
					continue;
				}
				else
				{
					tt[a[xx]]--;
					a[xx]=u;
					tt[u]++;
					for (int i=Last[xx];i!=-1;i=E[i].last)
					{
						int y=E[i].y;
						D[y]--;
						g[y]=max(g[y],a[xx]+1);
						if (D[y]==0)
							Q1.push(make_pair(g[y],y));
					}
					break;
				}
			}
		/*	for (int i=1;i<=n;i++) printf("%d ",a[i]);
			printf("\n");
			system("pause");*/
			if (tt[u]==0) {printf("-1");return ;}
		}
	for (int u=1;u<=n;u++) printf("%d ",a[u]);
}
queue<int> q;
void solve ()
{
	int tot=0;
	for (int u=1;u<=n;u++) 
		if (d[u]==0) 
		{
			q.push(u);
			if (o[u]==false) a[u]=k;
		}
/*	for (int u=1;u<=n;u++) printf("%d ",a[u]);
		printf("\n");*/
	while (!q.empty())
	{
		tot++;int x=q.front();
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			if (o[y])
			{
				if (a[y]>=a[x])
				{
					printf("-1");
					return ;
				}
			}
			else	a[y]=min(a[y],a[x]-1);
			d[y]--;
			if (d[y]==0)	q.push(y);
		}
		//printf("%d\n",x);
		q.pop();/*
		*/
	}
	for (int u=1;u<=n;u++)
		if (a[u]<=0)
		{
			printf("-1");
			return ;
		}
	
	if (tot!=n)
	{
		printf("-1");
		return ;
	}/*for (int u=1;u<=n;u++) printf("%d ",a[u]);
		printf("\n");*/
	solve1();
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	memset(Last,-1,sizeof(Last));
	scanf("%d%d%d",&n,&m,&k);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u]);
		if (a[u]==0) 
		{
			a[u]=k+1;
			o[u]=false;
		}
		else o[u]=true;
	}
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);
	}
	solve();
	return 0;
}