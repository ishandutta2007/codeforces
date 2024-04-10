#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000005],ans[1000005],vis[1000005],k,i;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			a[i]+=n-i+1;
			vis[i]=0;
		}
		int x=1;
		while(x)
		{
			if(vis[x])
				break;
			ans[++k]=x;
			vis[x]=k;
			x=n-a[x]+1;
		}
		printf("%d\n",k-vis[x]+1);
		for(i=vis[x];i<=k;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
}