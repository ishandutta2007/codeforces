#include<bits/stdc++.h>
#define pb push_back

const int N=100005;

int n,m,ans[N],tot,stack[N],top,dep[N],d;
bool vis[N],del[N];
std::vector<int> e[N];

void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	stack[++top]=x;
	vis[x]=1;
	int s=0;
	for (int to:e[x])
		if (!vis[to]) dfs(to,x);
		else if (dep[to]<dep[x]) s++;
	if (s<d-1&&!del[x])
	{
		ans[++tot]=x;
		for (int to:e[x]) del[to]=1;
	}
	else if (s>=d-1)
	{
		int mn=x;
		for (int to:e[x])
			if (dep[to]<dep[mn]) mn=to;
		printf("%d\n%d\n",2,dep[x]-dep[mn]+1);
		while (stack[top]!=mn) printf("%d ",stack[top--]);
		printf("%d\n",mn);
		exit(0);
	}
	top--;
}

int main()
{
	scanf("%d%d",&n,&m);
	d=ceil(sqrt(n));
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
	}
	dfs(1,0);
	puts("1");
	for (int i=1;i<=d;i++) printf("%d ",ans[i]);
	return 0;
}