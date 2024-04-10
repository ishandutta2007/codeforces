#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int a[N],aa[N],b[N],bb[N],f[N],p[N],sum[N],ans[N],n,l,cnt;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		++aa[a[i]];
	}
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&b[i]);
		++bb[b[i]];
	}
	for (int i=1;i<=n;++i)
		if (a[i]==b[i])
		{
			--aa[a[i]];
			--bb[b[i]];
			f[i]=a[i];
			p[a[i]]=1;
		}
		else
			ans[++l]=i;
	for (int i=1;i<=n;++i)
		if (!p[i])
			sum[++cnt]=i;
	if (l==1)
		f[ans[1]]=sum[1];
	else
	{
		f[ans[1]]=sum[1];
		f[ans[2]]=sum[2];
		int x=(f[ans[1]]!=a[ans[1]])+(f[ans[2]]!=a[ans[2]]),y=(f[ans[1]]!=b[ans[1]])+(f[ans[2]]!=b[ans[2]]);
		if (x!=1||y!=1)
		{
			f[ans[1]]=sum[2];
			f[ans[2]]=sum[1];
		}
	}
	for (int i=1;i<=n;++i)
		printf("%d ",f[i]);
	return 0;
}