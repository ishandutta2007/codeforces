#include<bits/stdc++.h>
using namespace std;
#define int long long
int taxi,n,a[100009];
int init[35],cnt[35],ans;
signed main()
{
	cin>>taxi;
	init[0]=1;
	for(int i=1;i<=32;i++)init[i]=init[i-1]*2;
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		ans=0;
		cin>>n;
		for(int i=0;i<=32;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=0;j<=32;j++)
			{
				if(init[j]>a[i])
				{
					cnt[j]++;break;
				}
			}
		for(int i=1;i<=32;i++)ans+=(cnt[i]*(cnt[i]-1)/2);
		cout<<ans<<endl;
	}
	return 0;
}