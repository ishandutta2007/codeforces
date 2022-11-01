#include<bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef std::pair<int,int> pi;

const int N=200005;

int n,m,mx;
bool vis[N];
std::vector<int> e[N];
pi a[N];

void dfs(int x)
{
	vis[x]=1;
	mx=std::max(mx,x);
	for (auto to:e[x])
		if (!vis[to]) dfs(to);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
	}
	int tot=0;
	for (int i=1;i<=n;i++)
		if (!vis[i]) mx=0,dfs(i),a[++tot]=mp(i,mx);
	std::sort(a+1,a+tot+1);
	int s=0;mx=0;
	for (int i=1;i<=tot;i++)
	{
		if (a[i].first>mx) s++;
		mx=std::max(mx,a[i].second);
	}
	printf("%d\n",tot-s);
}