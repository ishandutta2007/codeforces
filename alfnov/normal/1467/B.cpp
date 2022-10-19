#include<bits/stdc++.h>
using namespace std;
int a[300005],b[300005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=0;
		if(n==1)
		{
			puts("0");
			continue;
		}
		for(int i=2;i<=n-1;i++)
		{
			if(a[i-1]<a[i]&&a[i]>a[i+1])b[i]=1;
			if(a[i-1]>a[i]&&a[i]<a[i+1])b[i]=-1;
		}
		int ans=1;
		for(int i=2;i<=n-1;i++)
		{
			int tt=a[i];
			a[i]=a[i-1];
			if(i!=n-1)
			{
				ans=max(ans,abs(b[i-1])+abs(b[i])+abs(b[i+1])-((a[i]<a[i+1]&&a[i+1]>a[i+2])+(a[i]>a[i+1]&&a[i+1]<a[i+2])));
			}else ans=max(ans,abs(b[i-1])+abs(b[i]));
			a[i]=a[i+1];
			if(i!=2)
			{
				ans=max(ans,abs(b[i-1])+abs(b[i])+abs(b[i+1])-((a[i-2]<a[i-1]&&a[i-1]>a[i])+(a[i-2]>a[i-1]&&a[i-1]<a[i])));
			}else ans=max(ans,abs(b[2])+abs(b[3]));
			a[i]=tt;
		}
		ans=-ans;
		for(int i=1;i<=n;i++)ans+=abs(b[i]);
		cout<<max(ans,0)<<endl;
	}
	return 0;
}