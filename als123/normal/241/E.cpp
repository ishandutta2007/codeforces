#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=5005;
int n,m;
struct qq
{
	int x,y,z,last;
}e[N*2];int num,last[N];
qq E[N*2];int Last[N];
void init (int x,int y,int z)
{
	num++;
	e[num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];
	last[x]=num;
}
int cnt[N];
int f[N];
int X[N],Y[N];
bool in[N];
bool ok[N];
bool o[N];
bool bfs ()
{
	memset(f,127,sizeof(f));
	queue<int> q;
	q.push(n);f[n]=0;
	while (!q.empty())
	{
		int x=q.front();q.pop();in[x]=false;
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			if (ok[y]==false) continue;
			if (f[y]>f[x]+e[u].z)
			{
				f[y]=f[x]+e[u].z;
				cnt[y]++;
				if (cnt[y]>n) return false;
				if (in[y]==false)
				{
					in[y]=true;
					q.push(y);
				}
			}
		}
	}
	return true;
}
void Init (int x,int y)
{
	num++;
	E[num].x=x;E[num].y=y;
	E[num].last=Last[x];
	Last[x]=num;
}

void bfs1 (int x)
{
	memset(o,false,sizeof(o));
	queue<int> q;q.push(x);o[x]=true;
	while (!q.empty())
	{
		int xx=q.front();q.pop();
		if (x==1&&xx==n) continue;
		if (x==n&&xx==1) continue;
		for (int u=Last[xx];u!=-1;u=E[u].last)
		{
			int y=E[u].y;
			if (o[y]) continue;
			o[y]=true;
			q.push(y);
		}
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		scanf("%d%d",&X[u],&Y[u]);
		init(Y[u],X[u],2);init(X[u],Y[u],-1);
	}
	num=0;memset(Last,-1,sizeof(Last));
	for (int u=1;u<=m;u++)	Init(X[u],Y[u]);
	bfs1(1);
	for (int u=1;u<=n;u++) ok[u]=o[u];
	
	num=0;memset(Last,-1,sizeof(Last));
	for (int u=1;u<=m;u++)	Init(Y[u],X[u]);
	bfs1(n);
	for (int u=1;u<=n;u++) ok[u]&=o[u];
	
	if (bfs()==false)	{printf("No\n");return 0;}
	printf("Yes\n");
	for (int u=1;u<=m;u++)	
	{
		if (ok[X[u]]&ok[Y[u]])	printf("%d\n",f[X[u]]-f[Y[u]]);
		else printf("1\n");
	}
	return 0;
}