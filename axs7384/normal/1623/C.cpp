#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],t,n;
long long f[N];
inline bool pd(int x)
{
	for (int i=1;i<=n;++i)
		f[i]=a[i];
	for (int i=n;i>=3;--i)
	{
		if (f[i]<x)
			return false;
		long long p=min((f[i]-x)/3,(long long)a[i]/3);
		f[i-1]+=p;
		f[i-2]+=2*p;
	}
	return (f[1]>=x)&&(f[2]>=x);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int l=1,r=1e9;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (pd(mid))
				l=mid+1;
			else
				r=mid-1;
		}
		printf("%d\n",r);
	}
	return 0;
}