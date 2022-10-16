#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int t,k,a,b,dp[100002],sum[100002];
int main()
{
	cin>>t>>k;
	dp[0]=1;
	for(int i=1;i<=100000;i++)
		dp[i]=(dp[i-1]+(i>=k?dp[i-k]:0))%mod,sum[i]=(sum[i-1]+dp[i])%mod;
	for(int i=0;i<t;i++)
		cin>>a>>b,cout<<(sum[b]+mod-sum[a-1])%mod<<endl;
	return 0;
}