#include <bits/stdc++.h>
using namespace std;

long long n,dp[200000][2],c[200000],k;
string a[200000],ra[200000];
int main() {
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		reverse(a[i].begin(),a[i].end());
		ra[i]=a[i];
		reverse(a[i].begin(),a[i].end());
	}
	dp[1][0]=0;
	dp[1][1]=c[1];
	for (int i=2;i<=n;i++)
	{
		dp[i][0]=1e18;
		dp[i][1]=1e18;
	}
	for (int i=2;i<=n;i++)
	{
		k=0;
		if (a[i]>=a[i-1])
		{dp[i][0]=min(dp[i][0],dp[i-1][0]); k++;}
		if (a[i]>=ra[i-1])
		{dp[i][0]=min(dp[i][0],dp[i-1][1]); k++;}
		if (ra[i]>=a[i-1])
		{dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]); k++;}
		if (ra[i]>=ra[i-1])
		{dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);k++;}
		if (k==0)
		{
			cout<<-1;
			return(0);
		}

	}
	if (min(dp[n][0],dp[n][1])>=100000000000000000) cout<<-1; else
	 cout<<min(dp[n][0],dp[n][1]);
}