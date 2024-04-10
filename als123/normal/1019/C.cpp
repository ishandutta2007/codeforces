#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int N=1000005;
int n,m;
struct qq
{
	int x,y,last;
}e[N];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
bool del[N];
bool ok[N];
stack<int> sta;
int ans[N];
int main()
{
	memset(ok,true,sizeof(ok));
	memset(del,false,sizeof(del));
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);
	}
	for (int u=1;u<=n;u++)
		if (del[u]==false)
		{
			sta.push(u);
			//printf("%d\n",u);
			for (int i=last[u];i!=-1;i=e[i].last)
			{
				int y=e[i].y;
				del[y]=true;
			}
		}
	while (!sta.empty())
	{
		int x=sta.top();sta.pop();
		if (ok[x]==true)
		{
			//printf("x:%d %d\n",x,ok[x]);
			for (int u=last[x];u!=-1;u=e[u].last)
			{
				int y=e[u].y;
				ok[y]=false;
				//printf("y:%d %d\n",y,ok[y]);
			}
			ans[++ans[0]]=x;
		}
	}
	printf("%d\n",ans[0]);
	for (int u=1;u<=ans[0];u++)
		printf("%d ",ans[u]);
	return 0;
}