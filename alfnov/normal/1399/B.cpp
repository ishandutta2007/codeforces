#include<bits/stdc++.h>
using namespace std;
int a[55],b[55];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ma=2147483647,mb=2147483647;
		long long ans=0;
		for(int i=1;i<=n;i++)cin>>a[i],ma=min(ma,a[i]);
		for(int i=1;i<=n;i++)cin>>b[i],mb=min(mb,b[i]);
		for(int i=1;i<=n;i++)if(a[i]>ma||b[i]>mb)ans+=max(a[i]-ma,b[i]-mb);
		cout<<ans<<endl;
	}
	return 0;
}