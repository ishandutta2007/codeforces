#include<bits/stdc++.h>
#define mp std::make_pair

typedef std::pair<int,int> pi;

const int N=100005;

int n,m,nx[N],ls[N];
bool vis[N];
std::map<pi,bool> ma;
std::queue<int> que;

void bfs(int x)
{
	int h=0,t=n+1;
	nx[h]=t;
	for (int i=1;i<=n;i++)
		if (!vis[i]) nx[i]=nx[h],ls[nx[h]]=i,nx[h]=i,ls[i]=h;
	vis[x]=1;que.push(x);
	nx[ls[x]]=nx[x];ls[nx[x]]=ls[x];
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=nx[h];i!=t;i=nx[i])
			if (!ma[mp(i,x)])
			{
				vis[i]=1;que.push(i);
				nx[ls[i]]=nx[i];ls[nx[i]]=ls[i];
			}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ma[mp(x,y)]=ma[mp(y,x)]=1;
	}
	int s=0;
	for (int i=1;i<=n;i++)
		if (!vis[i]) bfs(i),s++;
	printf("%d\n",s-1);
	return 0;
}