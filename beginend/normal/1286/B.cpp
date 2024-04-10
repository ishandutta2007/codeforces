#include<bits/stdc++.h>
#define pb push_back

const int N=2005;

int n,c[N],size[N],s[N][N],a[N];
std::vector<int> e[N];

void dfs(int x)
{
	for (auto to:e[x])
	{
		dfs(to);
		for (int j=1;j<=size[to];j++)
			s[x][size[x]+j]=s[to][j];
		size[x]+=size[to];
	}
	if (c[x]>size[x])
	{
		puts("NO");
		exit(0);
	}
	for (int i=size[x];i>c[x];i--) s[x][i+1]=s[x][i];
	s[x][c[x]+1]=x;
	size[x]++;
}

int main()
{
	scanf("%d",&n);
	int rt;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d%d",&x,&c[i]);
		if (!x) rt=i;
		else e[x].pb(i);
	}
	dfs(rt);
	puts("YES");
	for (int i=1;i<=n;i++) a[s[rt][i]]=i;
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}