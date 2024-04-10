#include<bits/stdc++.h>
using namespace std;
int a[100005],dp[505][505],bz[505][505];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int flag=1;
		for(int i=1;i<n;i++)if(a[i+1]<x&&a[i]>a[i+1])
		{
			flag=0;
			puts("-1");
			break;
		}
		if(!flag)continue;
		int wz=0;
		for(int i=1;i<=n;i++)if(a[i]>=x)
		{
			wz=i;
			break;
		}
		if(!wz)
		{
			puts("0");
			continue;
		}
		for(int i=wz;i<=n;i++)a[i-wz+1]=a[i];
		n=n-wz+1;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=x&&a[i]<a[i-1])
			{
				flag=0;
				puts("-1");
				break;
			}
			if(a[i]<=x)continue;
			for(int j=i+1;j<=n;j++)if(a[j]<a[j-1])
			{
				ans++;
				swap(x,a[i]);
				break;
			}
		}
		if(!flag)continue;
		printf("%d\n",ans);
	}
	return 0;
}