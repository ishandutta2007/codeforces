#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
const int N=100005;
struct qq
{
	int x,y,last;
}e[N*2];int num,last[N];
int n;
void init (int x,int y)
{
	num++;
	e[num].x=x;
	e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
double ans=0;
void dfs (int x,int fa,int dep)
{
	ans=ans+1/(double)dep;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dfs(y,x,dep+1);
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);
		init(y,x);
	}
	dfs(1,0,1);
	printf("%lf\n",ans);
	return 0;
}