#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int N=200005;
int a[N],f[N],l,r,t,n,k,g[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			f[i]=a[i];
		}
		sort(f+1,f+1+n);
		int sum=(n+k+1)/2;
		int mn=inf;
		for (int i=1;i+sum-1<=n;++i)
			if (f[i+sum-1]-f[i]<=mn)
			{
				mn=f[i+sum-1]-f[i];
				r=f[i+sum-1];
				l=f[i];
			}
		printf("%d %d\n",l,r);
		f[0]=0;
		for (int i=1;i<=n;++i)
			if (a[i]>=l&&a[i]<=r)
				f[i]=f[i-1]+1;
			else
				f[i]=f[i-1]-1;
		for (int i=n;i>=1;--i)
			if (f[i]>0)
				g[f[i]]=i;
		printf("1 ");
		for (int i=1;i<k;++i)
			printf("%d\n%d ",g[i],g[i]+1);
		printf("%d\n",n);
	}
	return 0;
}