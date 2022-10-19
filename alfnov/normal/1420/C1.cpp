#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[0]=a[n+1]=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])ans+=a[i];
			else if(a[i]<a[i-1]&&a[i]<a[i+1])ans-=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}