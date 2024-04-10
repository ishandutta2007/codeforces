#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=500005;

int n,m,a[N];
bool vis[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n*3;i++) vis[i]=0;
		int top=0;
		for (int i=1;i<=m;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			if (!vis[x]&&!vis[y]) vis[x]=vis[y]=1,a[++top]=i;
		}
		if (top>=n)
		{
			puts("Matching");
			for (int i=1;i<=n;i++) printf("%d ",a[i]);
			puts("");
		}
		else
		{
			puts("IndSet");
			int cnt=0;
			for (int i=1;i<=n*3;i++) if (!vis[i]&&cnt<n) cnt++,printf("%d ",i);
			puts("");
		}
	}
	return 0;
}