#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10005;
int t[N],a[N],f[N];
int T,n;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&t[i]);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
			f[i]=t[i]-a[i]+1;
		for (int i=n-1;i;--i)
			f[i]=min(f[i+1],f[i]);
		int l=f[1];
		ll ans=0;
		for (int i=1;i<=n;++i)
		{
			if (i==n||f[i+1]>t[i])
			{	
				int len=t[i]-l+1;
				ans+=(ll)len*(len+1)/2;
				l=f[i+1];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}