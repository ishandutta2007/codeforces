#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=100005;
int a[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		if (n==3&&a[2]%2==1)
		{
			puts("-1");
			continue;
		}
		int mx=0;
		for (int i=2;i<n;++i)
			mx=max(mx,a[i]);
		if (mx==1)
		{
			puts("-1");
			continue;
		}
		long long ans=0;
		for (int i=2;i<n;++i)
			ans+=(a[i]+1)/2;
		cout<<ans<<endl;
	}
}