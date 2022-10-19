#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[200005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)scanf("%lld",a+i);
		ll ans=0,sum=0;
		for(int i=1;i<n;i++)
		{
			sum+=abs(a[i]-a[i-1]);
		}
		ans=sum;
		ans=min(sum-abs(a[1]-a[0]),sum-abs(a[n-1]-a[n-2]));
		for(int i=1;i<n-1;i++)
		{
			ll ans2=sum;
			ans2-=abs(a[i]-a[i-1]);
			ans2-=abs(a[i]-a[i+1]);
			ans2+=abs(a[i+1]-a[i-1]);
			ans=min(ans,ans2);
		}
		cout<<ans<<endl;
	}
	return 0;
}