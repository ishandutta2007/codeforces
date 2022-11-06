#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=1e6+9;
int dp[N];
int n,a[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0)
				dp[a[i]/j]=(dp[a[i]/j]+dp[a[i]/j-1])%mod;
		int k=sqrt(a[i]-1);
		for(int j=k;j>=1;j--)
			if(a[i]%j==0)
				if(j*j==a[i])continue;
				else dp[j]=(dp[j]+dp[j-1])%mod;
	}
	ans=0;
	for(int i=1;i<=n;i++)ans=(ans+dp[i])%mod;
	cout<<ans<<endl;
	return 0;
}