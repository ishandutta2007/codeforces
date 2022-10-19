#include<bits/stdc++.h>
using namespace std;
int a[100005];
int log2(int x)
{
	int ans=0,bas=2;
	while(bas<=x)
	{
		bas*=2;
		ans++;
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int aa;
			scanf("%d",&aa);
			a[log2(aa)]++;
		}
		long long ans=0;
		for(int i=0;i<=100;i++)ans+=1ll*a[i]*(a[i]-1)/2;
		cout<<ans<<endl;
	}
	return 0;
}