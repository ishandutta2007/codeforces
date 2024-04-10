#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
int n,t,a[1000005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		a[0]=a[n+1]=0;
		ans=0;
		for (int i=1;i<=n;++i)
			if (a[i]>a[i-1]&&a[i]>a[i+1])
			{
				ans+=(a[i]-max(a[i-1],a[i+1]));
				a[i]=max(a[i-1],a[i+1]);
			}
		for (int i=0;i<=n;++i)
			ans+=abs(a[i]-a[i+1]);
		cout<<ans<<endl;
	}
	return 0;
}