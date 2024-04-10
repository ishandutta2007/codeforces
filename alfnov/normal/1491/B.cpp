#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,u,v;
		cin>>n>>u>>v;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int flag=0,ans=INT_MAX;
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i+1])flag=max(flag,1);
			if(abs(a[i]-a[i+1])>1)flag=2;
		}
		if(flag==2)ans=0;
		else if(flag==1)ans=min(u,v);
		else ans=v+min(u,v);
		cout<<ans<<endl;
	}
	return 0;
}