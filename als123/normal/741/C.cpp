#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005*2;
int n;
struct qq
{
	int x,y,last;
}e[N*5];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int f[N];
int X[N],Y[N];
void dfs (int x)
{
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (f[y]!=-1) continue;
		f[y]=(f[x]^1);
		dfs(y);
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		X[u]=x;Y[u]=y;
		init(x,y);init(y,x);
	}
	n<<=1;
	for (int u=1;u<=n;u+=2)	{init(u,u+1);init(u+1,u);}
	memset(f,-1,sizeof(f));
	for (int u=1;u<=n;u+=2)	
		if (f[u]==-1)
		{
			f[u]=0;
			dfs(u);
		}
	n>>=1;
	for (int u=1;u<=n;u++)	printf("%d %d\n",f[X[u]]+1,f[Y[u]]+1);
	return 0;
}