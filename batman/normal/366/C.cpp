#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define K (101*1000)
int n,k,a[111],x,dp[2][3*K];
int main()
{
	cin>>n>>k;
	memset(dp,1000,sizeof dp);
	dp[1][K]=0;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>x;
		x=a[i]-x*k;
		for(int j=2*K;j>=0;j--)
			dp[i&1][j]=max(dp[!(i&1)][j],dp[!(i&1)][j-x]+a[i]);	
	}
	cout<<((dp[(n-1)&1][K])?dp[(n-1)&1][K]:-1);
    return 0;
}