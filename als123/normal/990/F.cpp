#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200005*2;
int n,m;
int a[N];
int f[N];
struct qq
{
	int x,y,z,last;
}e[N];int num,last[N];
int find (int x)	{return f[x]==x?f[x]:f[x]=find(f[x]);}
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int X[N],Y[N];
int sum=0;
int dep[N];
void dfs (int x,int fa)
{
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa) continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
		a[x]=a[x]+a[y];
	}
}
bool used[N];
int main()
{
	memset(used,false,sizeof(used));
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	for (int u=1;u<=n;u++)	
	{
		scanf("%d",&a[u]);
		sum=sum+a[u];
	}
	for (int u=1;u<=n;u++)	f[u]=u;
	scanf("%d",&m);
	for (int u=1;u<=m;u++)
	{
		scanf("%d%d",&X[u],&Y[u]);
		int fx=find(X[u]),fy=find(Y[u]);
		if (fx==fy) continue;
		f[fx]=fy;
		init(X[u],Y[u]);init(Y[u],X[u]);
		used[u]=true;
	}
	if (sum!=0)	{printf("Impossible\n");return 0;}
	printf("Possible\n");
	dfs(1,0);
	for (int u=1;u<=m;u++)
	{
		if (used[u]==false) printf("0\n");
		else
		{
			if (dep[X[u]]>dep[Y[u]])
			{
				printf("%d\n",-a[X[u]]);
			}
			else
			{
				printf("%d\n",a[Y[u]]);
			}
		}
	}
	return 0;
}