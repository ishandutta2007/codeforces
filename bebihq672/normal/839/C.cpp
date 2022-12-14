#include<iostream>
#include<cstdio>
using namespace std;
struct Edge{
	int to,next;
}e[404040];
int head[202020],cnt;
void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
double dp[202020];
void dfs(int x,int fa)
{
	int num=0;
	for(int i=head[x];i!=0;i=e[i].next)
	{
		int to=e[i].to;
		if(to!=fa)
		{
			dfs(to,x);
			dp[x]+=dp[to];
			num++;
		}
	}
	if(num!=0)
	{
		dp[x]/=num;
		dp[x]+=1.0;
	}
	else
		dp[x]=0.0;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	printf("%.10f\n",dp[1]);
	return 0;
}