#include<iostream>
#include<cstdio>
using namespace std;
struct Edge{
	int to,next;
}e[202020];
int cnt=0,head[101010];
void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int sum[2]={0};
int dep=0;
void dfs(int x,int fa)
{
	dep^=1;
	sum[dep]++;
	for(int i=head[x];i!=0;i=e[i].next)
	{
		int to=e[i].to;
		if(to!=fa)
		{
			dfs(to,x);
		}
	}
	dep^=1;
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
	dfs(1,0);
	printf("%I64d\n",1ll*sum[0]*sum[1]-n+1);
	return 0;
}