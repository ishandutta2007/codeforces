#include<bits/stdc++.h>
#define mp std::make_pair

typedef std::pair<int,int> pi;

const int N=300005;

int n,m,bin[10],a[N][10],vis[1005];

pi check(int mid)
{
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
	{
		int s=0;
		for (int j=1;j<=m;j++)
			if (a[i][j]>=mid) s^=bin[j-1];
		vis[s]=i;
	}
	for (int i=0;i<bin[m];i++) if (vis[i])
		for (int j=i;j<bin[m];j++)
			if (vis[j]&&(i|j)==bin[m]-1) return mp(vis[i],vis[j]);
	return mp(0,0);
}

int main()
{
	scanf("%d%d",&n,&m);
	bin[0]=1;
	for (int i=1;i<=m;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int l=0,r=1e9;
	while (l<=r)
	{
		int mid=(l+r)/2;
		pi ans=check(mid);
		if (ans.first) l=mid+1;
		else r=mid-1;
	}
	pi ans=check(l-1);
	printf("%d %d\n",ans.first,ans.second);
	return 0;
}