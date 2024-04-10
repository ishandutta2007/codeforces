#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;

int n,m,k,a[N],b[N];
bool vis[N];

bool cmp(int x,int y)
{
	return a[x]>a[y];
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=i;
	std::sort(b+1,b+n+1,cmp);
	LL ans=0;
	for (int i=1;i<=m*k;i++) vis[b[i]]=1,ans+=a[b[i]];
	printf("%lld\n",ans);
	int now=0,s=0;
	for (int i=1;i<=n;i++)
		if (vis[i])
		{
			s++;
			if (s==m)
			{
				if (now==k-1) break;
				else printf("%d ",i),now++,s=0;
			}
		}
	return 0;
}