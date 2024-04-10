#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005*5;
int n,m;
bool vis[N];
int belong[N];
struct qq
{
	int x,k,o;
}s[N];
bool cmp (qq x,qq y)	{return x.x<y.x;}
struct qt
{
	int x,y,last;
}e[N];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
	//printf("YES:%d %d\n",x,y);
	swap(x,y);
	
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
	
//	printf("YES:%d %d\n",x,y);
}
int ans[N];
void dfs (int x)
{
	vis[x]=true;
	while (last[x]!=-1)
	{
		int u=last[x],y=e[u].y;
		if (ans[u]!=0) {last[x]=e[u].last;continue;}
		ans[u]=1;ans[u^1]=2;
		dfs(y);
	}
}
int main()
{
	memset(vis,false,sizeof(vis));
	memset(ans,0,sizeof(ans));
	num=1;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		s[u].x=x;s[u].k=1;s[u].o=u;
		s[u+n].x=y+1;s[u+n].k=-1;s[u+n].o=u;
	}
	sort(s+1,s+1+2*n,cmp);
	/*for (int u=1;u<=2*n;u++)
		printf("YES:%d %d %d\n",s[u].x,s[u].k,s[u].o);*/
	for (int u=1;u<=2*n;u++)
	{
		if (u==1||s[u].x>s[u-1].x)
		{
			m++;
			if (!(u&1)) init(m-1,m);
		}
		if (s[u].k==1) belong[s[u].o]=m;
		else init(belong[s[u].o],m),belong[s[u].o]=num-1;
	}
	for (int u=1;u<=m;u++)
		if (vis[u]==false)
			dfs(u);
	for (int u=1;u<=n;u++)
		printf("%d ",ans[belong[u]]&1);
	return 0;
}