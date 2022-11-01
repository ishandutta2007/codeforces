#include<bits/stdc++.h>
#define pb push_back

const int N=2005;

int n,mx1[N],mx2[N],id1[N],id2[N],mn1[N],mn2[N],f1[N][N],f2[N][N],f[N],t1,t2;
std::vector<int> vec1[N],vec2[N],e1[N],e2[N];

void dfs1(int x)
{
	if (id1[x]) mn1[x]=mx1[x]=id1[x];
	else mn1[x]=n+1,mx1[x]=0;
	for (auto to:e1[x])
	{
		dfs1(to);
		mn1[x]=std::min(mn1[x],mn1[to]);
		mx1[x]=std::max(mx1[x],mx1[to]);
	}
	if (x!=1) vec1[mx1[x]].pb(mn1[x]);
}

void dfs2(int x)
{
	if (id2[x]) mn2[x]=mx2[x]=id2[x];
	else mn2[x]=n+1,mx2[x]=0;
	for (auto to:e2[x])
	{
		dfs2(to);
		mn2[x]=std::min(mn2[x],mn2[to]);
		mx2[x]=std::max(mx2[x],mx2[to]);
	}
	if (x!=1) vec2[mx2[x]].pb(mn2[x]);
}

void dp()
{
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
		{
			f1[i][j]=f1[i][j-1];f2[i][j]=f2[i][j-1];
			for (auto k:vec1[j]) f1[i][j]+=k>=i;
			for (auto k:vec2[j]) f2[i][j]+=k>=i;
		}
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++)
			f[i]=std::max(f[i],f[j]+std::max(f1[j+1][i],f2[j+1][i]));
	printf("%d\n",f[n]);
}

int main()
{
	scanf("%d",&n);
	scanf("%d",&t1);
	for (int i=2;i<=t1;i++)
	{
		int x;scanf("%d",&x);
		e1[x].pb(i);
	}
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		id1[x]=i;
	}
	scanf("%d",&t2);
	for (int i=2;i<=t2;i++)
	{
		int x;scanf("%d",&x);
		e2[x].pb(i);
	}
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		id2[x]=i;
	}
	dfs1(1);dfs2(1);
	dp();
	return 0;
}