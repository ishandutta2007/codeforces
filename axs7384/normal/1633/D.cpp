#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int b[N],c[N],f[N],t,n,k;
int dis[N];
inline void prework()
{
	int n=1000;
	for (int i=2;i<=n;++i)
		dis[i]=1e9+7;
	for (int i=1;i<n;++i)
		for (int j=1;j<=i;++j)
			if (i+i/j<=n)
				dis[i+i/j]=min(dis[i+i/j],dis[i]+1);
}
int main()
{
	prework();
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		for (int i=1;i<=n;++i)
			scanf("%d",&c[i]);
		if (k>=12*n)
		{
			int ans=0;
			for (int i=1;i<=n;++i)
				ans+=c[i];
			printf("%d\n",ans);
			continue;
		}
		for (int i=0;i<=k;++i)
			f[i]=0;
		for (int i=1;i<=n;++i)
			for (int j=k;j>=dis[b[i]];--j)
				f[j]=max(f[j],f[j-dis[b[i]]]+c[i]);
		printf("%d\n",f[k]);
	}
	return 0;
}